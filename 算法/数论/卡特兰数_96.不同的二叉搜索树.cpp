//令h(0)=1,h(1)=1，卡塔兰数满足递归式：
// h(n) = h(0) * h(n - 1) + h(1) * h(n - 2) + ... + h(n - 1) h(0)(其中n >= 2), 这是n阶递推关系;
// 卡塔兰数的一般公式为 C(2n,n)/(n+1)。
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, …
// 设为G(n) = C(2n,n)/(n+1)
// 那么 G(n+1) = C(2(n+1),n+1) / (n+2)
// 组合数公式 C(m,n) = m! / (n! * (m-n)!)
// 得到 G(n+1) = 2(2n+1) / (n+2) * G(n)
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        long long catalan = 1;
        for (int i = 0; i < n; i++)
        {
            // i = n-1时, 可求得 Catalan(n)
            catalan = catalan * (4 * i + 2) / (i + 2);
        }
        return catalan;
    }
};