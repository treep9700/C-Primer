#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

string &trans(string &s) {
    for (int p = 0; p < s.size(); p++) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');              //����д��ֱ�Ӽ�һ����ֵ��ֱ��
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main( ) {
    ifstream in("word.txt");
    if (!in) {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    map<string, list<int>> word_lineno;     //���ʵ��кŵ�ӳ��
    string line;
    string word;
    int lineno = 0;
    while (getline(in, line))   //��ȡһ��
    {
        lineno++;               //�кŵ���
        istringstream l_in(line);     //�����ַ���������ȡ����
        while (l_in >> word) {
            trans(word);
            word_lineno[word].push_back(lineno);     //�����к�
        }
    }

    for(const auto &w : word_lineno) {     //��ӡ�����к�
        cout << w.first << "�����У�";
        for (const auto &i : w.second)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}