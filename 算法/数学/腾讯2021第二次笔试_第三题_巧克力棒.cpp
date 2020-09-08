#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double a, b;
        scanf("%lf %lf", &a, &b);
        if(a<=b) printf("0.000000\n");
        else
        {
            double ans = log(a) - log(b) + 1.0;
            printf("%.6f\n", ans);
        }
    }
    return 0;
}
