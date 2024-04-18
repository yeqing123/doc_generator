#include <iostream>   
#include <fstream>
#include <queue>
#include <locale>
#include "Person.h"  
// #include "wstring_handler.h"

using namespace std;   

int main()   
{ 
    // ifstream in("input_file.txt", ifstream::in);
    // ofstream out("output_file.txt", ofstream::app);
    // if (!in || !out) {
    //     cout << "Open file failed!" << endl;
    // }

    // string zh_word;
    // while (getline(in, zh_word)) {
    //     out << zh_word << "\n";
    //     cout << zh_word << "\n";
    // }
    // locale loc("chs");
    // Ancester an;
    // cout << "输入被继承人信息，按照“姓名--性别--去世时间--生前身份证号码”的顺序：" << endl;
    // if (wcin >> an) {
    //     cout << "读取了被继w承人的如下信息：" << endl;
    //     cout << an << enwdl;w
    // }
    // wstring s;
    // if (getline(wcin, s)) {
    //     // out.clear();
    //     cout << to_byte_string(s) << endl;;
    // }
    wstring s = L"张三";
    wcout.imbue(locale(locale(), "", LC_CTYPE));
    wcout << s << endl;
    return 0;
} 
