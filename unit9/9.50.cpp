#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> vi = {"1", "2", "3", "4", "5"};
    vector<string> vd = {"1.1", "2.5", "3.0"};
    auto iter = vi.begin();
    auto iter1 = vd.begin();

    int sum = 0;
    while(iter != vi.end()) {
        sum += stoi(*iter);
        iter++;
    }

    cout << sum << endl;

    double dsum = 0;
    while(iter1 != vd.end()) {
        dsum += stod(*iter1);
        iter1++;
    }

    cout << dsum << endl;

    return 0;
}
