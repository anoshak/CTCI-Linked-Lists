/*
 * Q5.cpp
 *
 *  Created on: Feb 22, 2015
 *      Author: Anoshak
 */

#include "linked_list.h"

node* iterative_add(node* first, node* second)
{
	node *result=NULL;
	int sum=0,carry=0;
	while(first || second || carry)
	{
		if(first)
		{
			sum+=first->data;
			first=first->next;
		}
		if(second)
		{
			sum+=second->data;
			second=second->next;
		}
		sum+=carry;
		carry = sum/10;
		node * p = new node;
		p->data=sum%10;
		p->next=result;
	    result=p;
		sum=0;
	}
	return result;
}

node* recursive_add(node* first, node* second, int carry)
{
	//returns number from least significant to most significant digit
	if(first==NULL && second==NULL && carry==0)
		return NULL;

	int sum = 0;
	if(first)
		sum += first->data;
	if(second)
		sum += second->data;
	sum += carry;
	node* p = new node;
	p->data = sum%10;
	carry = sum/10;

	node* more;

	if(first && second)
		more = recursive_add(first->next,second->next,carry);
	else if(first)
		more = recursive_add(first->next,NULL,carry);
	else if(second)
		more = recursive_add(NULL,second->next,carry);
	else more = recursive_add(NULL,NULL,carry);

	p->next = more;

	return p;

}

/*FOLLOW UP */

node* recursive_add2(node* first, node* second, int* carry)
{
	//assuming the shorter list is padded with zeroes at the beginning to make both listts of equal length
	if(first==NULL)
		return NULL;
	static node* start = first;
	node* more = recursive_add2(first->next, second->next, carry);
	node* p = new node;
	int sum = first->data +second->data + *carry;
	p->data = sum%10;
	p->next = more;
	*carry = sum/10;
	if(start == first)
	{
		if(*carry)
		{
			node* q = new node;
			q->data = 1;
			q->next = p;
			return q;
		}
		else return p;
	}

	return p;



}
/*
int main()
{
	cout<<"Enter first number backwards: "<<endl;
	node* first = create_list();
	cout<<"Enter second number backwards: "<<endl;
	node* second = create_list();
	cout<<"Result is: ";
	node* result = iterative_add(first,second);
	print_list(result);
	result = recursive_add(first,second,0);
	reverse(&result);
	print_list(result);
	int carry = 0;
	result = recursive_add2(first,second,&carry);
	print_list(result);
	return 0;
}

*/


