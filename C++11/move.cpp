#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {
    string test1 = "test1";
    cout << "test1 is " << test1 << endl;
    cout << "The address of test1 is: " << &test1 << endl;
    cout << "The address of its data is: " << reinterpret_cast<long long>(test1.c_str()) << endl;
    string test2(move(test1));
    cout << "test2 is " << test2 << endl;
    cout << "The address of test2 is: " << &test2 << endl;
    cout << "The address of its data is: " << reinterpret_cast<long long>(test2.c_str()) << endl;
//    test2 = move(test1);

    cout << "After move..." << endl;

    //undefined behaviour
    cout << "test1 is " << test1 << endl;
    cout << "The address of test1 is: " << &test1 << endl;
    cout << "The address of its data is: " << reinterpret_cast<long long>(test1.c_str()) << endl;
    cout << "test2 is " << test2 << endl;
    cout << "The address of test2 is: " << &test2 << endl;
    cout << "The address of its data is: " << reinterpret_cast<long long>(test2.c_str()) << endl;


    return 0;
}
