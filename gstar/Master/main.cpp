#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include "../Client/dealCsv.h"
#include "../Client/sendString.h"
#include "../Client/acceptStringThenReply.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*
    string getStr;
    vector<string> content;
    string ip, portStr;
    stringstream ss;
    */
//  sendString("Exist", 1668, "192.168.199.211");
    if(argc == 0) {
        while(1) {
            acceptStringThenReply();
        }
    }

    else if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        cout << "-l" << endl;
    }
    return 0;
}
