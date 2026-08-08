#include <iostream>
using namespace std;

void fun2(int n);

void fun1(int n) {
    if (n > 0) {
        cout << n << " ";
        fun2(n - 1);   // fun1 → fun2
    }
}

void fun2(int n) {
    if (n > 0) {
        cout << n << " ";
        fun1(n - 1);   // fun2 → fun1
    }
}

int main() {
    fun1(5);
    return 0;
}