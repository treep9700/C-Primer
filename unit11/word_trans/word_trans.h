#ifndef WORD_TRANS_H_INCLUDED
#define WORD_TRANS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

/******* ����ת��ӳ�䣺�����Ź�����ı���
���ж�ȡ�ı��е����ݡ���ÿ�еĵ�һ������
��Ϊ��ֵ��ʣ�ಿ�ִ�Ϊvalueֵ  ******/
string rule(const string &filename, const string &word_input) {
    ifstream in(filename);
    if(!in) {
        cout << "�������ļ�ʧ��" << endl;
        exit(1);
    }

    string line;
    string word;
    map<string, string> m;

    while(getline(in, line)) { //��ȡһ��
        if(line.empty())
            throw invalid_argument("�������");
        stringstream ss(line);     //�����ַ�����
        ss >> word;                //��ȡ���е�keyֵ��Ҳ���ǵ�һ������
        m[word] = line.substr(word.size() + 1);       //��ȡvalueֵ
        //cout << word << ":  " << m[word] << endl;
    }

    if(m.find(word_input) == m.end())    //������ʲ���ӳ���ļ��У��򷵻�������
        return word_input;

    return m[word_input];
}

/**** ����Ҫת�����ļ�������rule������ӳ�����
�絥����ӳ������У���������ӳ��ֵ�������ڣ���
���ص��ʱ���  ******/
void output(const string &filename1, const string &filename2)
{
    fstream out(filename1);
    if(!out) {
        cout << "���ļ�ʧ��";
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
