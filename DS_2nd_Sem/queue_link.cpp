#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *nxt;
};
node *head=NULL;
node *tail=NULL;
void insert(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	if(head==NULL)
	{
		temp->nxt=NULL;
		head=temp;
		tail=temp;
	}
	else
	{
		tail->nxt=temp;
		temp->nxt=NULL;
		tail=temp;
	}
}
void del()
{
	if(head==NULL)
	{
		cout<<"Queue underflow";
		exit(1);
	}
	else
		head=head->nxt;
}
void print()
{
	node *itr=head;
	while(itr!=NULL)
	{
		cout<<itr->data<<" ";
		itr=itr->nxt;
	}
}
int main()
{
	//1 --> insert
	//2 -->delete
	//3 -->print
	//0 -->exit
	while(1)
	{
		int x;
		cin>>x;
		if(x==0)
			break;
		else
		{
			switch(x)
			{
				case 1:
				int q;
				cin>>q;
				insert(q);
				break;
				case 2:
				del();
				break;
				case 3:
				print();
				break;
			}

		}
	}
}