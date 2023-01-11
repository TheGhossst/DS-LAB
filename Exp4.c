//Nandu Krishna M B21CS1235
//Circular Queue
#include <stdio.h>
int q[50],n,front=-1,rear=-1;
void enqu();
void dequ();
void display();
void main()
{
	int c;
	printf("Enter the limit of the Circular Queue: ");
	scanf("%d",&n);
	printf("\n..........................\n");
	printf("\nCircular Queue Operations\n");
	printf("\n...........................\n");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	do
	{
		printf("\nEnter The choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				enqu();
				break;
			case 2:
				dequ();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exit\n");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(c!=4);
}
void enqu()
{
	int num;
	if(front==(rear+1)%n || (front==0 &&rear==n-1))
	{
		printf("Overflow\n");
	}
	else
	{
		if(front==-1)
			front=0;
		rear=(rear+1)%n;
		printf("Enter an element to be enqueued: ");
		scanf("%d",&num);
		q[rear]=num;
		printf("Sucess");
	}
}
void dequ()
{
	int item;
	item=q[front];
	if(front==-1)
		printf("Underflow\n");
	
	else
	{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front=(front+1)%n;
		}
		
	}
	printf("The dequ element is :%d",item);
}

void display(){
	int i;
	if(front==-1)
		printf("Empty queue");
	else
	{
		for(i=front;i!=rear;i=(i+1)%n)
			printf("%d\t",q[i]);
		printf("%d",q[i]);
	}
	
}
/*OUTPUT
..........
Enter the limit of the Circular Queue: 4

..........................

Circular Queue Operations

...........................

1.Enqueue
2.Dequeue
3.Display
4.Exit

Enter The choice: 1 
Enter an element to be enqueued: 2
Sucess
Enter The choice: 1
Enter an element to be enqueued: 4
Sucess
Enter The choice: 1
Enter an element to be enqueued: 3
Sucess
Enter The choice: 1
Enter an element to be enqueued: 5 
Sucess
Enter The choice: 1
Overflow

Enter The choice: 7
Invalid Choice
Enter The choice: 3
2	4	3	5
Enter The choice: 2
The dequ element is :2
Enter The choice: 2
The dequ element is :4
Enter The choice: 1
Enter an element to be enqueued: 9
Sucess
Enter The choice: 3
3	5	9
Enter The choice: 2
The dequ element is :3
Enter The choice: 2
The dequ element is :5
Enter The choice: 4
Exit
*/
	
	
