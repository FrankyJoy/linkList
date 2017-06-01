/*
 *有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
 *以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
 *
 * 约瑟夫环问题，使用队列解答
*/
// Created by 何鹏 on 2017/5/31.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,count=0;
    while(cin >>n)
    {
        queue<int> qlist;
        for (int i = 0; i < n; ++i) {
            qlist.push(i);
        }

        //循环结束的条件是里面只有一个元素
        while (qlist.size() != 1) {
            if (count != 2) {
                //如果不是第三个元素，则把当前元素放到队尾
                int front = qlist.front();
                qlist.pop();
                qlist.push(front);
                count++;
            } else {
                qlist.pop();
                count = 0;
            }
        }
        cout << qlist.front() << endl;
    }
    return 0;
}
