/*
 *有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
 *以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
 *
 * 约瑟夫环问题，使用链表解答
*/
#include <iostream>

using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
    //struct ListNode(int d):data(d),next(NULL){}
}Node;

int main2()
{
    int n;
    while(cin>>n) {
        if (n > 1000)
            n = 1000;
        if (n <= 0)
            return 0;

        Node *head = new Node;
        head->next = NULL;
        head->data = 0;
        Node *phead = head;

        for (int i = 1; i < n; i++) {
            Node *tmp = new Node;
            tmp->data = i;
            tmp->next = NULL;
            head->next = tmp;
            head = tmp;
        }
        head->next = phead;

        while (phead != phead->next) {
            //改变指向即可删除元素,从p开始删除第3个元素，避免node结构向前指
            phead->next->next = phead->next->next->next;//将p的向下第二个指向位置改为指向第三个，替换第二个
            phead = phead->next->next;
        }
        cout << phead->data<<endl;
    }
    return 0;
}