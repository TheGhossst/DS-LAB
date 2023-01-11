//Nandu Krishna M B21CS1235
//Stack Queue Array
#include <stdio.h>
int stack[50],q[50],n,n1,top=-1,front=-1,rear=-1;
void Stack();
void Queue();
void push();
void pop();
void display();
void enqu();
void dequ();
void show();
void main()
{
	int c;
	
	do
	{
		
		printf("\n....................................\n");
		printf("\n Main Menu\n");
		printf("\n....................................\n");
		printf("\n1.Stack\n2.Queue\n3.Exit\n");
		printf("\n.....................................\n");
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				Stack();
				break;
			case 2:
				Queue();
				break;
			case 3:
				printf("Exit\n");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(c!=3);
}
void Stack()
{
	int ch;
	printf("Enter the size of the stack: ");
	scanf("%d",&n);
	printf("\n....................................\n");
	printf("\nStack Operations\n");
	printf("\n....................................\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Main Menu\n");
	printf("\n.....................................\n");
	do
	{
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Returning to main menu");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(ch!=4);
}
void Queue()
{
	int ch;
	printf("Enter the size of the queue: ");
	scanf("%d",&n1);
	printf("\n....................................\n");
	printf("\nQueue Operations\n");
	printf("\n....................................\n");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Main Menu\n");
	printf("\n.....................................\n");
	do
	{
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqu();
				break;
			case 2:
				dequ();
				break;
			case 3:
				show();
				break;
			case 4:
				printf("Returning to Main Menu");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(ch!=4);
}
void push()
{
	int num;
	if(top==n-1)
		printf("Overflow\n");
	else
	{
		printf("Enter an element to be pushed in the stack: ");
		scanf("%d",&num);
		top++;
		stack[top]=num;
	}
}
void pop()
{
	if(top>=0)
	{
		printf("The element to be popped is %d",stack[top]);
		top--;
	}
	else
	{
		printf("Underflow");
	}
}
void display()
{
	if(top==-1)
	{
		printf("Empty stack");
	}
	else
	{
		printf("The elements in the stack are:\n");
		for(int i=0;i<=top;i++)
		{
			printf("%d\t",stack[i]);
		}
	}
}
void enqu()
{
	int num;
	if(rear==n-1)
	{
		printf("Overflow");
	}
	else
	{
		if(front==-1)
			front=0;
		printf("Enter an element to be enqueued: ");
		scanf("%d",&num);
		rear++;
		q[rear]=num;
	}
}
void dequ()
{
	if(front==-1 || front>rear)
		printf("Underflow");
	else
	{
		printf("Element to be dequeued is %d",q[front]);
		front++;
	}
}
void show()
{
	if(rear==-1)
	{
		printf("Empty Queue\n");
	}
	else
	{
		printf("The Elements in the queue are:\n");
		for(int i=front;i<=rear;i++)
		{
			printf("%d\t",q[i]);
		}
	}
}
/*OUTPUT
...........
....................................
 Main Menu
....................................

1.Stack
2.Queue
3.Exit
.....................................
Ebter the choice: 1
Enter the size of the stack: 3
...................................
Stack Operations
....................................
1.Push
2.Pop
3.Display
4.Main Menu
.....................................
Enter the choice: 1
Enter an element to be pushed in the stack: 2

Enter the choice: 1
Enter an element to be pushed in the stack: 4

Enter the choice: 1
Enter an element to be pushed in the stack: 3

Enter the choice: 1
Overflow

Enter the choice: 2
The element to be popped is 3
Enter the choice: 2
The element to be popped is 4
Enter the choice: 2
The element to be popped is 2
Enter the choice: 2
Underflow
Enter the choice: 2
Underflow
Enter the choice: 3
Empty stack
Enter the choice: 4
Returning to main menu

....................................
 Main Menu
....................................

1.Stack
2.Queue
3.Exit

.....................................

Enter the choice: 2
Enter the size of the queue: 3 

....................................

Queue Operations

....................................

1.Enqueue
2.Dequeue
3.Display
4.Main Menu

.....................................

Enter the choice: 1
Enter an element to be enqueued: 2

Enter the choice: 3
The Elements in the queue are:
2	
Enter the choice: 1
Enter an element to be enqueued: 2

Enter the choice: 3
The Elements in the queue are:
2	2	
Enter the choice: 2
Element to be dequeued is 2
Enter the choice: 2
Element to be dequeued is 2
Enter the choice: 4
Returning to Main Menu
....................................

 Main Menu

....................................

1.Stack
2.Queue
3.Exit

.....................................

Enter the choice: 3
Exit
*/
				
	
