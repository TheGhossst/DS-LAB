//Nandu Krishna M B21CS1235
//Polynomial Addtion Multiplication
#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int expo;
	struct node* link;
};
struct node* create(struct node*);
struct node* insert(struct node*,int,int);
void display(struct node*);
struct node* add(struct node*,struct node*);
struct node* mult(struct node*,struct node*);
void main(){
	 struct node* head1=NULL;
	 struct node* head2=NULL;
	 struct node* head3=NULL;
	 struct node* head4=NULL;
	 printf("The first polynomial\n");
	 head1=create(head1);
	 display(head1);
	 printf("The second polynomial\n");
	 head2=create(head2);
	 display(head2);
	 head3=add(head1,head2);
	 printf("The resultant polynomial from addition is:\n");
	 display(head3);
	 head4=mult(head1,head2);
	 printf("The resultant polynomial from multiplication is:\n");
	 display(head4);
}
struct node* create(struct node* head){
	int i,n,coeff,expo;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the coeff: ");
		scanf("%d",&coeff);
		printf("Enter the exponent: ");
		scanf("%d",&expo);
		head=insert(head,coeff,expo);
	}
	return head;
}
struct node* insert(struct node* head,int coeff,int expo){
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	struct node* temp;
	p->coeff=coeff;
	p->expo=expo;
	p->link=NULL;
	if(head==NULL || expo>head->expo){
		p->link=head;
		head=p;
	}
	else{
		temp=head;
		while(temp->link!=NULL && expo<=temp->link->expo)
			temp=temp->link;
		p->link=temp->link;
		temp->link=p;
	}
	return head;
}
void display(struct node* head){
	struct node*temp;
	temp=head;
	if(temp==NULL){
		printf("Empty Polynomial");
	}
	else{
		while(temp!=NULL){
			printf("%dx^%d",temp->coeff,temp->expo);
			temp=temp->link;
			if(temp!=NULL)
				printf("+");
			else
				printf("\n");
		}
	}
}	 
struct node* add(struct node* poly1,struct node* poly2){
	struct node* head3=NULL;
	struct node* p1;
	struct node* p2;
	p1=poly1;
	p2=poly2;
	while(p1!=NULL && p2!=NULL){
		if(p1->expo==p2->expo){
			head3=insert(head3,p1->coeff+p2->coeff,p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->expo>p2->expo){
			head3=insert(head3,p1->coeff,p1->expo);
			p1=p1->link;
		}
		else if(p1->expo<p2->expo){
			head3=insert(head3,p2->coeff,p2->expo);
			p2=p2->link;
		}
	}
	while(p1!=NULL){
		head3=insert(head3,p1->coeff,p1->expo);
		p1=p1->link;
	}
	while(p2!=NULL){
		head3=insert(head3,p2->coeff,p2->expo);
		p2=p2->link;
	}
	return head3;
}
struct node* mult(struct node* poly1,struct node* poly2){
	struct node* head4=NULL;
	struct node* p1;
	struct node* p2;
	struct node* p3;
	struct node* temp;
	int res1,res2;
	p1=poly1;
	while(p1!=NULL){
		p2=poly2;
		while(p2!=NULL){
			res1=p1->coeff*p2->coeff;
			res2=p1->expo+p2->expo;
			head4=insert(head4,res1,res2);
			p2=p2->link;
		}
		p1=p1->link;
	}
	p3=head4;
	while(p3->link!=NULL){
		if(p3->expo==p3->link->expo){
			p3->coeff=p3->coeff+p3->link->coeff;
			temp=p3->link;
			p3->link=p3->link->link;
			free(temp);
		}
		else{
			p3=p3->link;
		}
	}
	return head4;
}
/*OUTPUT
........
The first polynomial
Enter the number of terms: 3
Enter the coeff: 4
Enter the exponent: 2
Enter the coeff: 4
Enter the exponent: 5
Enter the coeff: 2
Enter the exponent: 3
4x^5+2x^3+4x^2
The second polynomial
Enter the number of terms: 2
Enter the coeff: 4
Enter the exponent: 2
Enter the coeff: 6
Enter the exponent: 7
6x^7+4x^2
The resultant polynomial from addition is:
6x^7+4x^5+2x^3+8x^2
The resultant polynomial from multiplication is:
24x^12+12x^10+24x^9+16x^7+8x^5+16x^4
*/


