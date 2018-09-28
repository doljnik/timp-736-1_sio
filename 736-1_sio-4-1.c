#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
	int value; 
	struct node *next; 
}node; 
typedef node* steck; 

int init(steck *top) 
{ 
	*top=NULL; 
	return 0; 
} 


int delete(steck *top) 
{ 
	steck p; 
	while(*top!=NULL) 
	{ 
		p=*top; 
		*top=(*top)->next; 
		free(p); 

	} 

	return 0; 
} 




_Bool isEmpty(steck top) 
{ 
	if (top==NULL) return 1; 

	return 0; 
} 


int last(steck top) 
{ 
	if(!isEmpty(top))
	 return top->value; 

} 

int print(steck top) 
{ 
	steck p; 
	p=top; 
	while(p!=NULL) 
	{ 
		printf("%d\n", p->value); 
		p=p->next; 

	} 

	return 0; 
}
int push(steck *top, int value2) 
{ 
	steck p; 
	if(!isEmpty(*top)) 
	{ 
		p=*top; 
		*top=malloc(sizeof(node)); 
		(*top)->next=p; 
	} 
	else 
	{ 
		*top=malloc(sizeof(node)); 
		(*top)->next=NULL; 
	} 

	(*top)->value=value2; 
	return 0; 
} 
	
int delete_elem(steck *top) 
{ 
	steck p; 
	if(!isEmpty(*top)) 
	{ 
		p=*top; 
		*top=(*top)->next; 
		free(p); 
	} 
	return 0; 

} 

int main() 
{ 
	int kolvoel,k,i,value2; 
	steck first; 
	init(&first); 
	printf("number of elements\n"); 
	scanf("%d\n", &kolvoel); 
	printf("elements" ); 
	for (i=0; i<kolvoel; i++) 
	{ 
		scanf("%d\n", &value2); 
		push(&first, value2); 
	} 
	printf("stack\n"); 
	print(first); 
	printf("last element\n"); 
	k=last(first); 

	printf("%d\n",k); 


	delete_elem(&first); 
	printf("delete last  element\n"); 
	print(first); 

	delete(&first); 
	printf("delete stack \n"); 
	print(first); 
	return 0; 
}
