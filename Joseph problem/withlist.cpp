/*
 *有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
 *以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
 *
 * 约瑟夫环问题，使用list容器解答
*/

#include <iostream>
#include <list>

using namespace std;

int main1()
{
    list<int> joselists;
    int n,count=0;
    cin>>n;
    if(n>1000)
        n=1000;
    if(n<0)
        return 0;

    for(int i=0;i<n;i++)
    {
        joselists.push_back(i);
    }
    for(list<int>::iterator it=joselists.begin();joselists.size()!=1;it++)
    {
        if(it==joselists.end())
            it = joselists.begin();

        if(count ==2)
        {
            joselists.erase(it);
            count=0;
            continue;
        }
        count++;
    }
    //只有一个元素，输出头元素即可
    cout<< *joselists.begin();
    return 0;
}