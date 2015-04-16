#include "linked_list.h"

node* circular_list(node* list)
{
	//first check if link list is cicurlar
	node *sr=list, *fr=list;
	while(fr && fr->next)
	{
		sr = sr->next;
		fr = fr->next->next;
		if(sr==fr)
			break;
	}
	if(fr==NULL || fr->next == NULL)
		return NULL;

	//List is circular, return beginning of loop

	fr = list;
	while(fr!=sr)
	{
		sr=sr->next;
		fr=fr->next;
	}

	return sr;
}
