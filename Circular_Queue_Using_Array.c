#include<stdio.h>
#include<stdlib.h>
#define Max 5

int flag=0;

struct Queue
{
	int rear;
	int front;
	int* arr;
}*s=NULL;

struct Queue* initialise_structure()
{
	s=(struct Queue*)calloc(1,sizeof(struct Queue));
	s->rear=s->front=-1;
	
	return s;
}

int* initialise_array()
{
	s->front=0;
	return s->arr=(int*)calloc(Max,sizeof(int));
}

//1
struct Queue* push(int val)
{
	if((s->rear+1)%Max==s->front)	
	{
		printf("\n\nError: Overflow.");
		return NULL;
	}
	
	if(s->rear==-1)
	{
		if(!initialise_array())
		{
			printf("\n\nError: Dynamic allocation failed.");
			return NULL;	
		}
		else
		flag=1;
	}
	
	s->rear=(s->rear+1)%Max;
	s->arr[s->rear]=val;
	
	return s;
	
}

//2
struct Queue* pop(int* val)
{
	if(s->rear==-1)
	{
		if(flag==1)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->front];
	
	if(s->front==s->rear)
	{
		s->front=s->rear=-1;
		free(s->arr);
		s->arr=NULL;
	}
	
	else
	s->front=((s->front)+1)%Max;	
	
	return s;
}

//3
struct Queue* front(int* val)
{	
	if(s->rear==-1)
	{
		if(flag==1)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->front];
	
	return s;
}

//4
struct Queue* back(int* val)
{
	if(s->rear==-1)
	{
		if(flag==1)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->rear];
	
	return s;
}

//5
int size()
{	
	if(s->rear==-1)
	{
		printf("\n\nError: The circular queue is empty.");
		return 0;
	}
	
	int cnt=0,ind=s->front;
	
	while(ind!=s->rear)
	{
		ind=(ind+1)%Max;
		cnt++;
	}
	
	cnt++;
	
	return cnt;
}

//6
int* empty()
{
	return s->arr;
}

//7
int* full()
{
	if((s->rear+1)%Max!=s->front)	
	return NULL;
	
	return s->arr;
	
}

//8
struct Queue* display()
{
	if(s->rear==-1)
	{
		if(flag==1)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	int ind=s->front;
	
	printf("\n\n");
	
	while(ind!=s->rear)
	{
		printf("%d ",s->arr[ind]);
		ind=(ind+1)%Max;
	}
	
	printf("%d ",s->arr[ind]);
	
	return s;
}

void free_all()
{
	if(s->arr)
	free(s->arr);
	
	free(s);
}

void menu()
{
	printf(" MENU:\n-------\n");
	printf("\n1) Push.");
	printf("\n2) Pop.");
	printf("\n3) Front.");
	printf("\n4) Back.");	
	printf("\n5) Size.");
	printf("\n6) Empty.");
	printf("\n7) Full.");
	printf("\n8) Display.");
	printf("\n9) Re-display the menu.");
	printf("\n0) Exit.");
}

int main()
{
	if(!(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return 0;
	}
	
	menu();
	
	printf("\n\n");
	int i,ch,val;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be pushed: ");
						scanf("%d",&val);
						if(push(val))
						printf("\n\nMessage: Successfully pushed the value '%d' inside the circular queue.",val);
						break;
			
			case 2: 	if(pop(&val))						
						printf("\n\nMessage: The item successfully popped out of the circular queue is: %d",val);
						break;
			
			case 3:		if(front(&val))
						printf("\n\nMessage: The item pointed by the front in the circular queue is: '%d'",val);
						break;
						
			case 4:		if(back(&val))
						printf("\n\nMessage: The item pointed by the rear in the circular queue is: '%d'",val);
						break;
			
			case 5:		printf("\n\nMessage: The number of elements present in the circular queue is: '%d'",size());
						break;
						
			case 6:		if(!empty())
						{
							if(flag==1)
							printf("\n\nMessage: Underflow.");
							
							else
							printf("\n\nMessage: The circular queue is empty.");
						}
						
						else
						printf("\n\nMessage: The circular queue is not empty.");
						break;
			
			case 7:		if(!full())
						printf("\n\nMessage: The circular queue is not full.");
						
						else
						printf("\n\nMessage: Overflow.");
						break;
			
			case 8:		printf("\n\nMessage: Displaying the whole queue.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole queue.");
						break;
				
			case 9:		printf("\n\nMessage: Re-displaying the menu.\n\n");
						menu();
						break;
			
			default:	printf("\n\nError: Wrong choice.");
						break;
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	free_all();
	
	printf("\n\nMessage: Program successfully exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\n");
}
