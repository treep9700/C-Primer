#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void add_word(map<string, list<int>> &m, const string &word) {
  //  if(m.find(word) == m.end())
   //     m[word] = list<int>();
    m[word];
}

void add_list(map<string, list<int>> &m, const string &word, const list<int> &l) {
    m[word] = l;
}

int main() {
    map<string, list<int>> m;
    list<int> v = {1, 2, 5, 7};

    add_word(m, "hehao");
    add_list(m, "hehao", v[0]);

    add_word(m, "zhangsan");
    add_list(m, "zhangsan", v[1]);

    add_word(m, "lisi");
    add_list(m, "lisi", v[2]);

    for(auto f : m) {
        cout << f.first() << ": " << f.second() << end;
    }

    return 0;
}
