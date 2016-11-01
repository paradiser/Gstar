#include <iostream>
#include "master.h"
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;


void wrongUsageWarning(int argc , char *argv[]) {
    cout << "gmanager:无效选项 --";
    for(int i=1; i<argc; i++) {
        cout << " " << argv[i];
    }
    cout << endl;
    cout << "请输入'gmanager -h'或者'gmanager --help'查看详细说明." << endl;
}

void listAllOperations() {
    cout << "用法:gmanager [选项]... [参数]..." << endl;
    cout << "管理服务器集群." << endl << endl;
    cout << "长选项必须用的参数在使用短选项时也是必须的." << endl;
    cout << "  -d, --delete\t" << "[ip | id]\t" << "从服务器列表中移除指定的服务器" << endl;
    cout << "  -h, --help\t" << "         \t" << "打印gmanager用法" << endl;
    cout << "  -i, --init\t" << "         \t" << "初始化服务器列表信息" << endl;
    cout << "  -l, --list\t" << "         \t" << "打印服务器列表信息" << endl;
    cout << "  -p, --append\t" << "[ip]     \t" << "添加指定的服务器" << endl;
    cout << endl;
}

void listAllServerInfo() {
    int servNum = getServerNum();
    cout << "服务器编号" << "\t" << "服务器ip" << "\t" << "当前连接数" << "\t" << "最大连接数" << endl;
    for(int i=1; i<=servNum; i++) {
        cout << "  " << i << "  \t  " << getServerIp(i) << "  \t  " << getServerConsViaId(i)
             << "  \t  " << MAX_CONNECTION << endl;
    }
}

//Debug
void printArgv(int argc , char *argv[]) {
    for(int i=0; i<argc; i++) {
        cout << argv[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    switch (argc) {
    case 1:
        //Todo
        cout << "1 options" << endl;
        break;
    case 2:
        if(strcmp(argv[1] , "-h") == 0 || strcmp(argv[1] , "--help") == 0) {
            listAllOperations();
        } else if(strcmp(argv[1] , "-i") == 0 || strcmp(argv[1] , "--init") == 0) {
            //Todo
            if(serverInit() == 0) {
                cout << "初始化服务器列表成功." << endl;
            } else {
                cout << "初始化服务器列表失败." << endl;
            }
        } else if(strcmp(argv[1] , "-l") == 0 || strcmp(argv[1] , "--list") == 0) {
            //Todo
            listAllServerInfo();
        } else {
            wrongUsageWarning(argc , argv);
        }
        break;
    case 3:
        if(strcmp(argv[1] , "-d") == 0 || strcmp(argv[1] , "--delete") == 0) {
            //Todo
            printArgv(argc , argv);
        } else if(strcmp(argv[1] , "-p") == 0 || strcmp(argv[1] , "--append") == 0) {
            //Todo
            printArgv(argc , argv);
        } else {
            wrongUsageWarning(argc , argv);
        }
        break;
    default:
        wrongUsageWarning(argc , argv);
        break;
    }
    return 1;
}
