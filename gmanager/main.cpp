#include <iostream>
#include "master.h"
#include <string.h>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[])
{
    if(argc == 0) {
        return 0;
    }
    if(strcmp(argv[0] , "-h") == 0 || strcmp(argv[0] , "--help") == 0) {

        listAllOperations();
        return 0;
    }

    return 0;
}
