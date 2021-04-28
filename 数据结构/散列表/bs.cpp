#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main()
{
    bitset<16> foo;
    bitset<16> bar(0xfa2);                 // 0000 1111 1010 0010
    bitset<16> baz(string("01011111001")); // 0000 0010 1111 1001

    // bitset同样是有位权重的
    //
    cout << foo << endl;
    cout << bar << endl;
    cout << baz << endl;

    // 运算
    // 1. 位运算
    bitset<4> f(string("1001"));
    bitset<4> b(string("0011"));

    cout << (f ^ b) << endl;
    cout << (f & b) << endl;
    cout << (f | b) << endl;

    cout << (f << 2) << endl; // 无符号的, 左移溢出
    cout << (f >> 1) << endl; // 无符号

    cout << (~f) << endl;

    // 比较
    cout << (f == b) << endl;
    cout << (f != b) << endl;

    // 内置函数
    bool x = false;

    cout << f.count() << endl;     // 1的数量
    cout << f.any() << endl;       // 是否存在1
    cout << f.none() << endl;      // 是否没有1
    cout << f.set() << endl;       // 全置1
    cout << f.set(1) << endl;      // 第 1 位 置1
    cout << f.set(1, x) << endl;   // 第 1 位 置 某个值
    cout << f.reset() << endl;     // 全置0
    cout << f.reset(1) << endl;    // 某一位置0
    cout << f.flip() << endl;      // f = ~f  取反
    cout << f.flip(1) << endl;     // 某一位 取反
    cout << f.to_string() << endl; // 转字符串
    cout << f.to_ulong() << endl;  // 转ulong
    cout << f.to_ullong() << endl; // 转ullong

    cout << f.test(3) << endl; // 某一位是否是1
    return 0;
}