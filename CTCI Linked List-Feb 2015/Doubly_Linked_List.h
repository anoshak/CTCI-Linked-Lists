/*
 * Doubly_Linked_List.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Anoshak
 */

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

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
	node *next,*prev;
};

class DQ_dll
{
	//Double ended queue implemented using doubly linked list
protected:
	node *left,*right;
public:
	DQ_dll();
	bool addleft(nodedatatype no);
	bool addright(nodedatatype no);
	bool delleft(nodedatatype *noptr);
	bool delright(nodedatatype *noptr);
	void print();

};





#endif /* DOUBLY_LINKED_LIST_H_ */
