#include "linked_list.h"

node* create_list()
{
	cout<<"Enter number of elements in the linked list: "<<endl;
	int n;
	cin>>n;
	cout<<"Enter the elements: "<<endl;
	nodedatatype data;
	node *first=NULL,*last=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		node* p = new node;
		p->data=data;
		p->next=NULL;
		if(first==NULL)
		{
			first=last=p;
		}
		else
		{
			last->next=p;
			last=p;
		}
	}
	cout<<"The list you created is: ";
	print_list(first);
	return first;

}

void print_list(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void reverse(node** headptr)
{
	node* p = *headptr;
	node* prev = NULL;
	node* ahead;
	while(p)
	{
		ahead=p->next;
		p->next=prev;
		prev=p;
		p=ahead;
	}
	*headptr = prev;
}

node* recursive_reverse(node* head)
{
	if(head==NULL)
		return NULL;
	else if(head->next==NULL)
		return head;
	else
	{
		node * newhead = recursive_reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}

}


