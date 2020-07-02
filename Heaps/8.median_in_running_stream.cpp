#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> leftheap;  //max_heap
    priority_queue<int> rightheap; //min_heap
    int in, d;
    cin >> in;
    leftheap.push(in);
    float med = in;
    cout << "Median is " << med;
    cin >> in;

    while (in != -1)
    {

        if (leftheap.size() > rightheap.size())
        {
            if (in < med)
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(in);
            }
            else
            {
                rightheap.push(in);
            }

            med = (leftheap.top() + rightheap.top()) / 2.0;
        }

        else if (leftheap.size() == rightheap.size())
        {
            if (in < med)
            {
                leftheap.push(in);
                med = leftheap.top();
            }
            else
            {
                rightheap.push(in);
                med = rightheap.top();
            }
        }
        else
        {
            if (in > med)
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(in);
            }

            else
            {
                leftheap.push(in);
            }

            med = (leftheap.top() + rightheap.top()) / 2.0;
        }

        cout << "Median is " << med;
        cin >> in;
    }
}
