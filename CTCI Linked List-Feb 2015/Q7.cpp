#include "linked_list.h"

#include <stack>

bool palindrome(node* list)
{
   if(list==NULL || list->next==NULL)
	   return 1;
   node *sr=list, *fr=list;

   while(fr && fr->next)
   {
	   sr=sr->next;
	   fr=fr->next->next;
   }

   if(fr)
   {
	   sr=sr->next;
   }

   stack<node*> mystack;

   while(sr)
   {
	   mystack.push(sr);
	   sr=sr->next;
   }

   sr = list;

   while(mystack.size())
   {
	   fr = mystack.top();
	   if(sr->data!=fr->data)
		   break;
	   else
	   {
		   mystack.pop();
		   sr=sr->next;
	   }
   }

   if(mystack.empty())
	   return 1;
   else return 0;



}

/*
int main()
{
	node* list = create_list();
	cout<<palindrome(list);
	return 0;
}
*/
