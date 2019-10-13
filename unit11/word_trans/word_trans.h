#ifndef WORD_TRANS_H_INCLUDED
#define WORD_TRANS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

/******* 建立转换映射：读入存放规则的文本，
按行读取文本中的内容。将每行的第一个单词
存为键值，剩余部分存为value值  ******/
string rule(const string &filename, const string &word_input) {
    ifstream in(filename);
    if(!in) {
        cout << "打开输入文件失败" << endl;
        exit(1);
    }

    string line;
    string word;
    map<string, string> m;

    while(getline(in, line)) { //读取一行
        if(line.empty())
            throw invalid_argument("规则错误");
        stringstream ss(line);     //构建字符串流
        ss >> word;                //读取流中的key值，也就是第一个单词
        m[word] = line.substr(word.size() + 1);       //获取value值
        //cout << word << ":  " << m[word] << endl;
    }

    if(m.find(word_input) == m.end())    //如果单词不在映射文件中，则返回它本身
        return word_input;

    return m[word_input];
}

/**** 读入要转换的文件，根据rule函数的映射规则，
如单词在映射规则中，返回它的映射值；若不在，则
返回单词本身  ******/
void output(const string &filename1, const string &filename2)
{
    fstream out(filename1);
    if(!out) {
        cout << "打开文件失败";
        exit(1);
    }

    string word;
    string line;
    while(getline(out, line)) {
        bool firstword = true;
        stringstream ss(line);
        while (ss >> word) {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << rule(filename2, word);
        }
        cout << endl;
    }
}


#endif // WORD_TRANS_H_INCLUDED
