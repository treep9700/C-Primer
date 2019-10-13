#include <iostream>
#include <string>
#include "9.51.h"

using namespace std;

int main() {
    string dates[] = {"1998年4月30号", "Jan 1, 2014", "2018年3月24号", "February 1 2014", "3/1/2014", "2015年 4 2"};

    try {
        for (auto ds : dates) {
            date dl(ds);
            cout << dl;
        }
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    return 0;

}
