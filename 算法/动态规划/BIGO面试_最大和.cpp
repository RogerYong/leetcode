#include <vector>
#include <iostream>
using namespace std;
int maxSum(int *nums, int n)
{
    if (nums == nullptr || n < 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        return max(nums[0], 0);
    }
    int *A = new int[n];

    A[0] = max(nums[0], 0);
    A[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        A[i] = max(A[i - 2] + nums[i], A[i - 1]);
    }
    int ms = A[n - 1];
    delete[] A;
    return ms;
}

int maxSum1(vector<int> &nums, vector<int> &result)
{
    int n = nums.size();
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        return max(nums[0], 0);
    }

    vector<int> A(n, 0);
    vector<int> select(n, 0);
    A[0] = max(nums[0], 0);
    if (nums[0] > 0)
    {
        select[0] = 1;
    }
    A[1] = max(nums[0], nums[1]);
    if (nums[0] < nums[1])
    {
        select[1] = 1;
    }

    for (int i = 2; i < n; ++i)
    {
        if (A[i - 2] + nums[i] > A[i - 1])
        {
            A[i] = A[i - 2] + nums[i];
            select[i] = 1;
        }
        else
        {
            A[i] = A[i - 1];
            select[i] = 0;
        }
    }

    result.clear();
    for (int i = n - 1; i >= 0;)
    {
        if (select[i] == 1)
        {
            result.insert(result.begin(), {nums[i]});
            i = i - 2;
        }
        else
        {
            --i;
        }
    }

    return A[n - 1];
}

int main()
{
    vector<int> nums = {3, 5, 7, 9, -2};
    vector<int> res;
    int ns = maxSum1(nums, res);
    cout << ns << endl;

    for (auto it = res.begin(); it != res.end(); ++it)
    {
        cout<< *it <<endl;
    }
}