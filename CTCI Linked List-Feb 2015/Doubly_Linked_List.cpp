/*
 * Doubly_Linked_List.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: Anoshak
 */

#include "Doubly_Linked_List.h"

DQ_dll::DQ_dll()
{
	left = right = NULL;
}

bool DQ_dll::addleft(nodedatatype no)
{
	node* p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data = no;
		p->prev = NULL;
		p->next = left;
		if(left==NULL)
			right =p;
		else left->prev = p;
		left = p;
		return 1;
	}
}

bool DQ_dll::addright(nodedatatype no)
{
	node* p = new node;
	if(p==NULL)
		return 0;
	p->data = no;
	p->prev = right;
	p->next = NULL;
	if(right==NULL)
		left = p;
	else right->next =  p;
	right = p;
	return 1;
}

bool DQ_dll::delleft(nodedatatype *noptr)
{
	node* p = left;
	if(p==NULL)
		return 0;
	*noptr = p->data;
	if(left==right)
		left=right=NULL;
	else
	{
		left = p->next;
		left->prev = NULL;
	}
	delete p;
	return 1;
}

bool DQ_dll::delright(nodedatatype *noptr)
{
	node* p = right;
	if(p==NULL)
		return 0;
	*noptr = p->data;
	if(left==right)
		left = right = NULL;
	else
	{
		right = right->prev;
		right->next = NULL;
	}
	delete p;
	return 1;
}

void DQ_dll::print()
{
	node *p = left;
	while(p)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;
}

