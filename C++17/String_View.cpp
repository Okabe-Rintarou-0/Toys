#include <string_view>
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include <random>

using namespace std;

int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

string randomString(int min, int max) {
    int randomLen = randRange(min, max);
    string str(randomLen, 0);
    for (char &ch:str) {
        ch = randRange(1, 127);
    }
    return str;
}

vector<string> prepare() {
    vector<string> ret;
    for (int i = 0; i < 50000; ++i)
        ret.push_back(randomString(1000, 2000));
    return ret;
}

/**
 * String view's substr is O(1)
 * String's substr will allocate an extra string to store, so O(n)
 */

int main() {
    auto strs = prepare();
    double st, et;
    cout << "Testing string's substr:" << endl;
    st = clock();
    for (const string &str:strs) {
        str.substr(500);
    }
    et = clock();
    cout << "Take " << (et - st) / CLOCKS_PER_SEC << " in total." << endl;

    cout << "Testing string_view's substr:" << endl;
    st = clock();
    for (string_view sv:strs) {
        sv.substr(500);
    }
    et = clock();
    cout << "Take " << (et - st) / CLOCKS_PER_SEC << " in total." << endl;
}
