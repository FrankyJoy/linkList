// linklist.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
    Node(int val):data(val),next(NULL){};
    Node(){};
};
typedef struct Node node;

void printlist(node *head);
bool addNodeInTail(node *head,int val);
bool findValue(node *head,int val);
bool deleteNode(node *head,int value);
void deletelist(node* pnode);

using namespace std;

int main()
{
    struct Node *phead = new Node();
    struct Node *head = new Node();
    if(head == NULL || phead ==NULL)
    {
        cerr<<"head is null"<<endl;
        return -1;
    }    
    cout<<"Insert you linklist's num ,end with 0"<<endl;
    int in;
    cin>>in;
    head->data = in;
    head->next = NULL;
    
    phead = head;
    while(cin>>in)
    {   
        if(in==0)
            break;
        // struct Node * tmp = new Node(in);
        // phead->next = tmp;
        // phead = tmp;        
        addNodeInTail(phead,in);
        phead = phead ->next;
    }
    cout<<"Now ,add one to the tail."<<endl;
    cin>>in;
    addNodeInTail(head,in);//传入head的副本
    printlist(head);
    cout<<endl;
    cout<<"Now ,input a value and ,we will check if it is in the list"<<endl;
    cin>>in;
    if(findValue(head,in))
        cout<<"find it!"<<endl;
    else
        cout<<"Ooops,it doesn't exist"<<endl;    
    cout<<"Now ,input a value and we will delete it!"<<endl;
    cin>>in;
    if(deleteNode(head,in))
        cout<<"Yes,we delete it!"<<endl;
    else
        cout<<"Ooops,the value is not in the list"<<endl; 
    printlist(head);
    cout<<endl;
	deletelist(head);

//	system("pause");

    return 0;
}
//在尾部增加一个节点
bool addNodeInTail(node *head,int val)
{
    node *tmp = new node(val);
    if(tmp == NULL)
        return false;
    while(1)
    {
        if(head->next ==NULL)
        {
            head->next = tmp;
            return true;
        }
        head = head -> next;
    }
}

bool findValue(node *head,int val)
{
    if(head == NULL)
        return false;
    if(head->data == val)
        return true;
    else
        return findValue(head->next,val);
}

bool deleteNode(node *head,int value)
{	
	node * phead = new node();
	node * pbefore = new node();
	if(phead == NULL || pbefore == NULL)
		return false;

	phead = head;
	while(phead !=NULL)
	{
		if(phead->data == value)
		{
			break;
		}
		pbefore = phead;
		phead = phead->next;
	}

	if(phead == NULL)
		return false;

	//phead即为待删除节点,pbefore为删除节点前一个节点
	pbefore->next = phead->next;
	free(phead);
	return true;
}

void deletelist(node* pnode)
{
	node *tmp = NULL;
	node *pnext = NULL;
	pnext = pnode;
	while(pnext != NULL)
	{
		tmp = pnext;
		pnext = pnext ->next;
		delete tmp;
	}
}


//打印节点
void printlist(node *head)
{
    if(head != NULL)
    {
        cout<<head->data<<" ";
        printlist(head->next);
    }    
    //cout<<endl;
}


