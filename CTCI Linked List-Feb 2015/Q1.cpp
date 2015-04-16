#include "linked_list.h"

void remove_duplicates(node* head)
{
	if(head==NULL)
		return;
	node* p=head->next;
	node* prev=head;
	map<nodedatatype,bool> mymap;
	mymap[head->data]=1;
	while(p)
	{
		if(mymap.find(p->data)!=mymap.end())
		{
			prev->next=p->next;
			free(p);
			p=prev->next;

		}
		else
		{
			mymap[p->data]=1;
			prev=p;
			p=p->next;
		}
	}
}

/*
int main()
{
	node* head = create_list();
	cout<<"The list after removing duplicates is: ";
	remove_duplicates(head);
	print_list(head);
	return 0;
}
*/
