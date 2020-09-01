#include <stack>
#include <iostream>

using namespace std;

class CQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s2.empty())
        {
            // 把s1数据转移到s2
            while (!s1.empty())
            {
                int value = s1.top();
                s1.pop();
                s2.push(value);
            }
        }

        if (s2.empty())
        {
            return -1;
        }

        int result = s2.top();
        s2.pop();

        return result;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue *obj = new CQueue();
    obj->appendTail(10);
    int param_2 = obj->deleteHead();
    return 0;
}
