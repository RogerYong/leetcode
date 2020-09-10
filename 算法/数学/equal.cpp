// 两个浮点数相等
#include <math.h>

static const double EPS = 1e-7;
bool Equal(double num1, double num2)
{

    if (fabs(num1 - num2) < EPS)
    {
        return true;
    }
    else
    {
        return false;
    }
}