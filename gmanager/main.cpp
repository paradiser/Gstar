#include <iostream>
#include "master.h"
#include <string.h>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

map <string , int> optionMap;

void wrongUsageWarning(int argc , char *argv[]) {
    cout << "gmanager:无效选项 --";
    for(int i=1; i<argc; i++) {
        cout << " " << argv[i];
    }
    cout << endl;
    cout << "请输入'gmanager -h'或者'gmanager --help'查看详细说明." << endl;
}

void wrongUsageDelete() {
    cout << "gmanager:无效选项 -- d" << endl;
    cout << "  -d, --delete\t" << "[ip | id]\t" << "从服务器列表中移除指定的服务器" << endl;
}

void wrongUsageAppend() {
    cout << "gmanager:无效选项 -- p" << endl;
    cout << "  -p, --append\t" << "[ip]     \t" << "添加指定的服务器" << endl;
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
        printf("%5d\t%5s\t%5d\t%5d\n" , i , getServerIp(i).c_str() , getServerConsViaId(i) , MAX_CONNECTION);
    }
}

void optionMapInt() {
    optionMap[string("-d")] = 1;
    optionMap[string("-delete")] = 1;
    optionMap[string("-h")] = 2;
    optionMap[string("-help")] = 2;
    optionMap[string("-i")] = 3;
    optionMap[string("-init")] = 3;
    optionMap[string("-l")] = 4;
    optionMap[string("-list")] = 4;
    optionMap[string("-p")] = 5;
    optionMap[string("-append")] = 5;
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
    optionMapInt(); //
    if(argc == 1) {
        //Todo
        return 0;
    }
    int option;
    option = optionMap[argv[1]];
    switch (option) {
    //delete
    case 1:
        if(argc == 2) {
            wrongUsageDelete();
        } else {
            for(int i=2; i<argc; i++) {
                removeServer(argv[i]);
            }
        }
        break;
    //help
    case 2:
        if(argc > 2) {
            wrongUsageWarning(argc , argv);
        } else {
            listAllOperations();
        }
        break;
    //init
    case 3:
        if(argc > 2) {
            wrongUsageWarning(argc , argv);
        } else {
            serverInit();
        }
        break;
    //list
    case 4:
        if(argc > 2) {
            wrongUsageWarning(argc , argv);
        } else {
            listAllServerInfo();
        }
        break;
    //append
    case 5:
        if(argc == 2) {
            wrongUsageAppend();
        } else {
            for(int i=2; i<argc; i++) {
                addServer(argv[i]);
            }
        }
        break;
    default:
        wrongUsageWarning(argc , argv);
        break;
    }
    return 0;
}
