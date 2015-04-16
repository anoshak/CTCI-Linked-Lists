#include "linked_list.h"

node* kthtolast(node* head, int k)
{
	if(head==NULL)
		return NULL;
	node* p = head;
	for(int i=0;i<k;i++)
		p=p->next;
	node* q = head;

	while(p)
	{
		q=q->next;
		p=p->next;
	}

	return q;
}

node* kthtolast_recursive(node* head, int* k)
{
	if(head==NULL)
		return head;
	node* result = NULL;
	if(head->next!=NULL)
	{
		result = kthtolast_recursive(head->next,k);
	}
	if(*k==1)
	{
		*k=*k - 1;
		return head;

	}
	*k=*k-1;
	return result;

}


/*
int main()
{
	node*  head = create_list();
	cout<<"Enter k: "<<endl;
	int k;
	cin>>k;
	node* result = kthtolast_recursive(head,&k);
	if(result)
		cout<<"kth to last element is: "<<result->data;
	return 0;
}

*/
