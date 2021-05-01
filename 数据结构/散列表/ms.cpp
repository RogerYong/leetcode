#include <bits/stdc++.h>

using namespace std;



int main()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
