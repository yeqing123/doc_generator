#include <iostream>   
#include <fstream>   
#include <locale>
using namespace std;   
int main()   
{ 
    ifstream inf("zh_file.doc");
    if (!inf) {
        cout << "File open failed!" << endl;
    }
    string text;
    while (getline(inf, text)) {;
        cout << text << endl;
    }
    ofstream outf("zh_file.doc");
    outf << "你好，世界！";
    return 0;
} 
