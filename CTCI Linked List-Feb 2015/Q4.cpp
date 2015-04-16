#include "linked_list.h"

node* partition_list(node* head, int x)
{
	node *less_first=NULL,*less_last=NULL,*more_first=NULL,*more_last=NULL;
	while(head)
	{
		if(head->data < x)
		{
			if(less_first==NULL)
			{
				less_first=less_last=head;
			}
			else
			{
				less_last->next=head;
				less_last=head;
			}
		}
		else
		{
			if(more_first==NULL)
			{
				more_first=more_last=head;
			}
			else
			{
				more_last->next=head;
				more_last=head;
			}
		}
		head=head->next;
	}
	if(less_first==NULL){
		if(more_last)
			(more_last)->next=NULL;
		return more_first;
	}
	less_last->next=more_first;
	if(more_last)
		more_last->next=NULL;
	return less_first;
}
/*
int main()
{
	node* head = create_list();
	cout<<"Enter value for partition: "<<endl;
	int x;
	cin>>x;
	cout<<"Partitioned list is: ";
	node* result = partition_list(head,x);
	print_list(result);
	return 0;
}*/
