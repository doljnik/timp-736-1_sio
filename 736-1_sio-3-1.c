#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
typedef struct node 
{ 
	int value; 
	struct node *next; 
	struct node *prev; 
} node; 
typedef node* list; 
//typedef enum {false, true} bool; 

list head=NULL;// начало списка 
list tail=NULL;// конец списка 

int init(list *root) 
{ 

	*root=NULL; 
	return 0; 
} 


int destroy(list *root) 
{ 
	list tmp, buff; 
	tmp=*root; 
	buff=*root;//чтобы не потерять указатель на следующий элемент 
	while (tmp!=NULL) 
	{ 
		buff=tmp->next; 
		free(tmp); 
		tmp=buff; 
	} 
	*root=NULL; 
	return 0; 
} 


bool isEmpty(list root) 
{ 
	if (root==NULL) 
	{ 
		return true; 
	} 
	else 
	{ 
		return false; 
	} 
}
list find(list root, int value2) 
{ 
	list tmp=root; 
	while (tmp!=NULL) 
	{ 

		if (tmp->value==value2) 
	{ 
		return tmp; 
	} 
		else 
	{ 
		tmp=tmp->next; 
	}	 

	} 
		return NULL; 
} 





int append(list *lst, int value2) 
{ 
	if ((*lst)==NULL) 
	{ 
		list tmp=(list)malloc(sizeof(node)); 
		tmp->next=NULL; 
		tmp->value=value2; 
		tmp->prev=NULL; 
		head=tmp; 
		tail=tmp; 
		return 0; 
	} 
	list tmp=malloc(sizeof(node));// , 
	tmp->value=value2; 
	tmp->prev=(*lst); 
	if((*lst) == tail) 
	{ 
		tmp->next=NULL; 
		((*lst)->next) = tmp; 
		tail = (*lst)-> next; 
	} 
	else 
	{ 
		tmp->next=((*lst)->next); 
		((*lst)->next)->prev=tmp; 
		((*lst)->next)=tmp; 
	} 
	return 0; 
}
int prepend(list *lst, int value2) 
{ 
	if ((*lst) == NULL) 
	{ 
		list tmp = (list)malloc(sizeof(node)); 
		tmp->next=NULL; 
		tmp->value=value2; 
		tmp->prev=NULL; 
		head=tmp; 
		tail=tmp; 
		return 0; 
	} 

	list tmp = malloc(sizeof(node)); 
	tmp -> value = value2; 
	tmp-> next = (*lst); 
	if((*lst)==head) 
	{ 
		tmp->prev=NULL; 
		(*lst)->prev=tmp; 
		head=(*lst)->prev; 
	} 
	else 
	{ 
		tmp->prev=(*lst)->prev; 
		((*lst)->prev)->next=tmp; 
		(*lst)->prev=tmp; 
	} 
	return 0; 
} 

int remove1(list *lst) 
{ 
	list tmp = (*lst); 
	if ((*lst)==head) 
	{ 
		((*lst)->next)->prev = NULL; 
		head = ((*lst)->next); 
		free((tmp)); 
	} 
	else if ((*lst)==tail) 
	{	 
	((*lst)->prev)->next=NULL; 
	tail=((*lst)->prev); 
	free((tmp)); 
	} 
	else 
	{ 
		((*lst)->next)->prev=((*lst)->prev); 
		((*lst)->prev)->next=((*lst)->next); 
		free((tmp)); 
	} 
	return 0; 
}
int remove_po_pos(list *lst, int value2) 
{ 

	list tmp; 
	int i=1; 
	tmp=(*lst); 
	while(true) 
	{ 
		if(i==value2) 
		{ 
			remove1(&tmp); 
			break; 
		} 
		(tmp)=(tmp)->next; 
		i++; 
	}; 
	return 0; 
} 



int print(list *lst) 
{ 

	list tmp; 
	tmp= *lst; 
	while (tmp!=NULL) 
	{ 
		printf("%d", (tmp)->value); 
		printf(" "); 
		(tmp)=(tmp)->next; 
	} 
	printf("\n"); 

	return 0; 
}
int main() 
{ 
	int i,kolvoel, value2,pos, zn,push1,push2; 
	init(&head); 
	scanf("%d\n", &kolvoel); 
	for (i=0; i<kolvoel; i++) 
	{	 
		scanf("%d", &value2); 
		append(&tail, value2); 
	} 

	print(&head);// удаление введенного элемена 
	scanf("%d", &pos); 
	remove_po_pos(&head, pos); 
	print(&head); 
	scanf("%d", &zn);// удаление по значению 
	list p=head; 
	while(true) 
	{ 
		if(p->value==zn) 
		{ 
			remove1(&p); 
			break; 
		} 
		p=p->next; 
	} 
	p=NULL; 
	print(&head); 
	scanf("%d", &push1); 
	scanf("%d", &push2); 
	p= head; 
	for (i=1; i<(push1); i++) 
	{ 
		p=(p->next); 
	}	 
	append(&p,push2); 
	p=NULL; 
	print(&head); 
	scanf("%d", &push1); 
	scanf("%d", &push2); 
	p = head; 
	for (i=1; i<(push1); i++) 
	{ 
		p=(p->next); 
	} 
	prepend(&p,push2); 
	p=NULL; 
	print(&head); 
	
	return 0; 
}
