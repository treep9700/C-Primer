#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {
    map<string, int> m = {{"hehao: ", 179}};
    auto map_it = m.begin();

    //map_it->first = "hehao";    ����,����ͨ���������޸Ĺؼ���ֵ
    map_it->second = 180;

    cout << map_it->first << map_it->second << endl;

    return 0;
}
