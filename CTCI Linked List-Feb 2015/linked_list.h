/*
 * linked_list.h
 *
 *  Created on: Feb 22, 2015
 *      Author: Anoshak
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <cstdio>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int nodedatatype;

struct node
{
	nodedatatype data;
	node* next;
};

node* create_list();

void print_list(node*);

void reverse(node** headptr);


#endif /* LINKED_LIST_H_ */
