#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

int main() {
    multimap<string, string> m;

    m.insert({"he", "hao"});
    m.insert({"he", "yawen"});

    for(auto &i : m){
        cout << i.first << i.second << endl;
    }
    return 0;
}
