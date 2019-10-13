#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, int>> v;

    pair<string, int> p1= {"hehao", 180};
    pair<string, int> p2{"hehao", 180};
    pair<string, int> p3 = make_pair("hehao", 180);

    return 0;
}
