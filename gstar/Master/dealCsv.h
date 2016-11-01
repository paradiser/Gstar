#ifndef _DEALCSV_H_
#define _DEALCSV_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace::std;

vector<string> split(string rawString, char spliter);
string join(vector<string> vec, char joiner);
vector<vector<string>> readCsv(string filePath);
string getCsvValue(string filePath, int row, int col);
bool setCsvValue(string filePath, int row, int col, string setValue);
bool appendInfoToCsv(string filePath, string info);
bool deleteInfoFromCsv(string filePath, string keyword);
bool isRecordExisting(string filePath, string keyword);
int getIntValue(string filePath, string keyword, int location);
string getStringValue(string filePath, string keyword, int location);

#endif
