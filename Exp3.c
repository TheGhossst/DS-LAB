//Nandu Krishna M B21CS1235
//Stack Queue Linked List
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *head;
struct node *front;
struct node *rear;
void stack();
void q();
void push();
void pop();
void display();
void enqu();
void dequ();
void show();
int n;
void main(){
	int c;
	
	do{
		printf("\nMain Menu\n");
		printf("\n..............................\n");
		printf("1.Stack\n2.Queue\n3.Exit");
		printf("\n..............................\n");
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				stack();
				break;
			case 2:
				q();
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
void stack(){
	int c;
	printf("\nStakc Menu\n");
	printf("\n..............................\n");
	printf("1.Push\n2.pop\n3.Duisplay\n4.Exit");
	printf("\n..............................\n");
	do{
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c){
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
				printf("Exit To Main Menu\n");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(c!=4);
}
void push(){
	int item;
	int i;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter item: ");
		scanf("%d",&item);
		if(ptr==NULL){
			printf("Push not possible\n");
		}
		else if(head==NULL){
			
			ptr->data=item;
			ptr->link=NULL;
			head=ptr;
		}
		else{
			
			ptr->data=item;
			ptr->link=head;
			head=ptr;
		}
	
}
void pop(){
	int item;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(head ==NULL){
		printf("Underflow\n");
	}
	else{
		
		ptr=head;
		head=head->link;
		item=ptr->data;
		free(ptr);
		printf("Element poped is %d",item);
	}
}
void display(){
	struct node *ptr;
	ptr=head;
	if(ptr==NULL){
		printf("Epty list\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}
void q(){
	int c;
	printf("\nQueue Menu\n");
	printf("\n..............................\n");
	printf("1.Enqu\n2.Dequ\n3.Display\n4.Exit");
	printf("\n..............................\n");
	do{
		
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c){
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
				printf("Exit To Main Menu\n");
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}while(c!=4);
}
void enqu(){
	int item;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("Overflow\n");
	}
	else{
		printf("Enter item: ");
		scanf("%d",&item);
		ptr->data=item;
		if(front==NULL){
			front=ptr;
			rear=ptr;
			front->link=NULL;
			rear->link=NULL;
		}
		else{
			rear->link=ptr;
			rear=ptr;
			rear->link=NULL;
		}
	}
}
void dequ(){
	int item;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(front==NULL){
		printf("Underflow\n");
	}
	else{
		ptr=front;
		front=front->link;
		item=ptr->data;
		printf("The dequed element is %d",item);
		free(ptr);
	}
}
void show(){
	struct node *ptr;
	ptr=front;
	if(front==NULL){
		printf("Empty Queue");
	}
	else{
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}
/*OUTPUT
.............
Main Menu

..............................
1.Stack
2.Queue
3.Exit
..............................

Enter the choice: 1

Stakc Menu

..............................
1.Push
2.pop
3.Duisplay
4.Exit
..............................

Enter the choice: 1
Enter item: 2

Enter the choice: 1
Enter item: 3

Enter the choice: 1
Enter item: 4

Enter the choice: 3
4	3	2	
Enter the choice: 2
Element poped is 4
Enter the choice: 2
Element poped is 3
Enter the choice: 2
Element poped is 2
Enter the choice: 2
Underflow

Enter the choice: 4
Exit To Main Menu

Main Menu
.............................
1.Stack
2.Queue
3.Exit
..............................
Enter the choice: 2
Queue Menu
..............................
1.Enqu
2.Dequ
3.Display
4.Exit
..............................

Enter the choice: 1
Enter item: 2

Enter the choice: 1
Enter item: 3

Enter the choice: 1
Enter item: 5

Enter the choice: 3
2	3	5	
Enter the choice: 2
The dequed element is 2
Enter the choice: 2
The dequed element is 3
Enter the choice: 2
The dequed element is 5
Enter the choice: 2
Underflow

Enter the choice: 4
Exit To Main Menu

Main Menu
.............................
1.Stack
2.Queue
3.Exit
..............................
Enter the choice: 3
Exit
*/
	
	
		

	

