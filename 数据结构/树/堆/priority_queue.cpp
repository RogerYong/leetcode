// #include <bits/stdc++.h>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q1; // 小顶堆
    priority_queue<int, vector<int>, less<int>> q2;    // 大顶堆
    for (int i = 0; i < 5; ++i)
    {
        q1.push(i);
        q2.push(i);
    }
    while (!q1.empty())
    {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;

    while (!q2.empty())
    {
        cout << q2.top() << " ";
        q2.pop();
    }
    return 0;
}