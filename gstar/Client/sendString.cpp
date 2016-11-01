#include "sendString.h"
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
#include <iostream>
//#include <QDebug>
//#include <QDir>

#define MAX_BUFFER_SIZE 1024

using namespace::std;

string sendStringToMaster(string sendStr)
{
//  qDebug() << QDir::currentPath();
//    printf("ready to get info!\n");
    int port = getIntValue("../settings.csv", "MasterPort", 1);
    string addr = getStringValue("../settings.csv", "MasterIp", 1);
//    printf("get info successfully!\n");
    cout << "addr = " << addr << ", port = " << port << endl;
    string resultStr = sendString(sendStr, port, addr);
    if(resultStr == "false") {
        return "false";
    }
    else {
        return resultStr;
    }
}

//发送sengStr字符串到addr地址的port端口
string sendString(string sendStr, int port, string addr)
{
    int this_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(this_sockfd < 0){
        cout << "client_master_socket create error!" << endl;
        return "false";
    }
    else {
        cout << "socket create successfully!" << endl;
    }

    struct sockaddr_in this_address;
    this_address.sin_family = AF_INET;
    this_address.sin_port = htons(port);
    this_address.sin_addr.s_addr = inet_addr(addr.c_str());

    //设置close()后无需TIME_WAIT

    linger lin_m;
    lin_m.l_onoff = 1;
    lin_m.l_linger = 0;
    if(setsockopt(this_sockfd,SOL_SOCKET,SO_LINGER,(const char*)&lin_m,sizeof(linger)) == -1) {
        cout << "set_so_linger error: " << strerror(errno) << endl;
    }

//  int flags = fcntl(this_sockfd,F_GETFL,0);//获取建立的sockfd的当前状态（非阻塞）
//  fcntl(this_sockfd,F_SETFL,flags|O_NONBLOCK);//将当前sockfd设置为非阻塞
//  不可用，无论如何都返回失败

    cout << "string = \"" << sendStr << "\", addr = " << addr << ", port = " << port << ", ready to connect." << endl;
    if(connect(this_sockfd, (struct sockaddr*)&this_address, sizeof(struct sockaddr_in)) < 0){
        cout << "connect error: " << errno << strerror(errno) << endl;
        close(this_sockfd);
        return "false";
    }

    send(this_sockfd, sendStr.c_str(), sendStr.size(), 0);
//    printf("%s\n", sendStr.c_str());
    char recvMsg[MAX_BUFFER_SIZE];
    memset(recvMsg, 0, MAX_BUFFER_SIZE * sizeof(char));
    recv(this_sockfd, recvMsg, sizeof(recvMsg), 0);
/*    if(strcmp(recvMsg, "get") == 0) {
//        cout << "get" << endl;
        close(this_sockfd);
        return true;
    }
    */
    string getStr(recvMsg);
    return getStr;
}
