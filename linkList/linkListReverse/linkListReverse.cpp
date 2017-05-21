/*
    链表的反转,普通循环法和递归法
*/

#include <iostream>

using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode * next;
    ListNode(int val):data(val),next(NULL){}
}node;

void prt(node * head);
node * linkListReverse1(node * phead);//使用一般方法反转
node * linkListReverse2(node * phead,node* & new_head);//使用递归方式反转
node * createNode(int val);

int main()
{
    int in;
    cin>>in;
    node * head = new node(in);
    node * phead = head;
    while(cin>>in)
    {
        if(in == 0)
            break;
        node * pnode = new node(in);
        phead -> next = pnode;
        phead = pnode;
    }
    phead ->next =NULL;
    //cout<<"phead:"<<phead<<endl;
    //cout<<"head:"<<head<<endl;
    prt(head);
    cout<<endl;
    //cout<<"phead:"<<phead<<endl;
    //cout<<"head:"<<head<<endl;

    node * res = linkListReverse1(head);
    //cout<<"phead:"<<phead<<endl;
    //cout<<"head:"<<head<<endl;
    prt(res);
    cout<<endl;
    //cout<<"res:"<<res<<endl;
    node * res2;
    linkListReverse2(res,res2);
    prt(res2);
    cout<<endl;
    return 0;
}

void prt(node * head)
{
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    return (prt(head->next));
}

node * createNode(int val)
{
    node * pnode = NULL;

    pnode -> data = val;
    pnode -> next = NULL;
    return pnode;
}

node * linkListReverse1(node * phead)
{
    node * resHead;
    node * pnode;
    node * pre = NULL;

    pnode = phead;
    
    while(pnode != NULL)
    {
        node * pnext = pnode->next;
        if(pnext ==NULL)//找到尾节点,新链表头结点,存起来
            resHead = pnode;//把pnext传给resHead的是傻逼

        pnode -> next = pre;
        
        pre = pnode;
        pnode = pnext;    
    }
    return resHead;
}
//递归转置
node * linkListReverse2(node * phead,node* & new_head)
{
    if(phead==NULL)
        return NULL;        //如果上层phead->next = NULL则返回,相当于运行到最后一个节点的后一个节点
    if(phead->next == NULL) //找到旧链表尾节点,
    {
        new_head = phead;   //尾节点为新链表的头结点
        return phead;       //递归的起点,同时也是最后一个节点
        //return phead;
    }
    node * new_tail = linkListReverse2(phead->next,new_head);//运行结束返回一个新尾巴
    //递归最深一层,new_tial是尾节点,new_tial->next = 尾节点,无意义,
    new_tail -> next = phead;
    phead->next = NULL;//将当前节点的下一个指向切断
    return phead; //返回该节点
}

/*
 *  以1,2,3,4 四个节点为例,讲解递归循环:

 *  1.  递归最深处,phead==NULL,phead由上一级phead = phead->next得到,上一级phead是尾节点[4],
            返回 NULL.
 *  2.  递归,phead == 4,phead由上一级phead = phead->next得到,phead的尾节点为[3],
            返回 phead = 4; phead = 4 -> NULL;
 *  3.  递归,phead ==3, new_tial= 递归2得到的值digui(2) = 4,4->next = phead = s3;
            3->next = NULL,返回3
 *  4.  递归,phead ==2, new_tial= 递归3得到的值digui(3) = 3,2->next = phead = 2;
            2->next = NULL,返回2
 *  5.  递归,phead == 1,new_tail= 递归4得到的值digui(4) = 2,2->next = phead = 1;
            1->next = NULL,返回1
    6.  上述递归5为起始节点,即传入的head值  
 *
 */