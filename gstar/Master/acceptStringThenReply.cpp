#include "acceptStringThenReply.h"
#include "dealCsv.h"
#include <cerrno>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

using namespace::std;

string acceptStringThenReply()
{
    struct sockaddr_in this_address, client_address;

    int this_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(this_sockfd < 0){
        printf("create socket error!\n");
        return false;
    }
    this_address.sin_family = AF_INET;
    this_address.sin_addr.s_addr = INADDR_ANY;
    this_address.sin_port = htons(getIntValue("../settings.csv", "ThisPort", 1)); //need to rewrite

    cout << "Open port : " << getIntValue("../settings.csv", "ThisPort", 1) << endl;
    //设置close()后无需TIME_WAIT
    linger lin;
    lin.l_onoff = 1;
    lin.l_linger = 0;

    cout << "setsockopt waiting..." << endl;
    if(setsockopt(this_sockfd, SOL_SOCKET, SO_LINGER, (const char*)&lin, sizeof(linger)) == -1)
        printf("set_so_linger error: %s\n" , strerror(errno));

    int this_sockfd_len = sizeof(this_address);

    cout << "bind waiting..." << endl;
    if(bind(this_sockfd, (struct sockaddr*)&this_address, this_sockfd_len) < 0){
        printf("bind socket error!:%s\n", strerror(errno));
        close(this_sockfd);
        return false;
    }

    cout << "listen waiting..." << endl;
    listen(this_sockfd, /*MAX_CONNECTION*/1);
////////////
    cout << "waiting..." << endl;

    int client_sockfd_len = sizeof(client_address);
    int client_sockfd = accept(this_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_sockfd_len);
    if(client_sockfd < 0){
        cout << "client accept failed!" << endl;
        close(client_sockfd);
        return false;
    }

    char recvMsg[MAX_BUFFER_SIZE];
    memset(recvMsg, 0, MAX_BUFFER_SIZE * sizeof(char));
    recv(client_sockfd, recvMsg, sizeof(recvMsg), 0);

    string getStr(recvMsg);
    string sendStr;
    cout << getStr << endl;
    vector<string> content=split(getStr, ',');
    if(content.size() == 5) {
        string ip = content[3];
        string portStr = content[4];
        stringstream ss;
        ss.str("");
        ss << portStr;
        int port;
        ss >> port;
        cout << "addr = " << ip << ", port = " << port << endl;//有问题
    }
    if(content[0] == "Register") {
        if(! isRecordExisting("../users.csv", content[1])) {
            content.erase(content.begin());
            string insertCsvStr = "";
            for(int i = 0; i < content.size() - 1; i ++) {
                insertCsvStr += content[i];
                insertCsvStr += ",";
            }
            insertCsvStr += content[content.size() - 1];
            if(appendInfoToCsv("../users.csv", insertCsvStr)) {
                cout << "Add user successfully!" << endl;
//              sendString("AddUserSuccessfully", port, ip);
                sendStr = "New,192.168.1.130,22222,tcx,tcx,";
                send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
            }
            else {
                cout << "Add user unsuccessfully!" << endl;
//              sendString("AddUserUnsuccessfully", port, ip);
                sendStr = "AddUserUnsuccessfully";
                send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
            }
        }
        else {
            cout << "Username already exists!" << endl;
//          sendString("Exist", port, ip);
            sendStr = "Exist";
            send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
        }
    }
    else if(content[0] == "LogIn") {
//        cout << isRecordExisting("../users.csv", content[1]) << endl;
//        cout << !isRecordExisting("../users.csv", content[1]) << endl;
//        cout << getStringValue("../users.csv", content[1], 1) << endl;
//        cout << (getStringValue("../users.csv", content[1], 1) != content[2]) << endl;
//        cout << !isRecordExisting("../users.csv", content[1]) || (getStringValue("../users.csv", content[0], 1) != content[2]) << endl;
        if(!isRecordExisting("../users.csv", content[1]) || (getStringValue("../users.csv", content[1], 1) != content[2])) {
            sendStr = "LogInUnsuccessfully";
            send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
        }
        else {
            sendStr = "Allow,192.168.1.130,22222,tcx,tcx,";
            send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
        }
    }
    close(client_sockfd);
    close(this_sockfd);
    cout << "abc" << endl;
    return "getStr";

/*
    string sendStr = "get";
    send(client_sockfd, sendStr.c_str(), sendStr.size(), 0);
    close(client_sockfd);
    close(this_sockfd);
    string str(recvMsg);
    return str;
    */
}
