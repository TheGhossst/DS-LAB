//Nandu Krishna M B21CS1235
//Infix to Postfix and Postfix Evaluation
#include <stdio.h>
#include <ctype.h>
#include <math.h>
char stack[50];
int top=-1;
void push(char);
char pop();
void ev(char[50]);
int pri(char);
void main(){
	char infix[50],postfix[50]="";
	printf("Enter the infix exprsssion: ");
	scanf("%s",infix);
	char *p;
	int k=0;
	p=infix;
	while(*p!='\0'){
		if(isdigit(*p)){
			postfix[k++]=*p;
			
		}
		else if(*p=='('){
			push(*p);
		}
		else if(*p==')'){
			while(stack[top]!='(')
				postfix[k++]=pop();
			pop();
		}
		else{
			while(pri(stack[top])>=pri(*p))
				postfix[k++]=pop();
			push(*p);
			
	
		}
		p++;
	}

	while(stack[top]!=-1)
		postfix[k++]=pop();
		
	printf("The postfix expression is: %s",postfix);
	printf("\n");
	ev(postfix);

}
void push(char c){
	stack[++top]=c;
}
char pop(){
	return stack[top--];
}
int pri(char c){
	if(c=='(')
		return 0;
	else if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='^')
		return 3;
}
void ev(char postfix[50]){
	char *p;
	int num;
	int n1,n2,res=0;
	p=postfix;
	while(*p!='\0'){
		if(isdigit(*p)){
			num=*p-48;
			push(num);
			
		}
		else{
			n1=pop();
			n2=pop();
			switch(*p){
				case '+':
					res=n1+n2;
					break;
				case '-':
					res=n2-n1;
					break;
				case '*':
					res=n1*n2;
					break;
				case '/':
					res=n2/n1;
					break;
				case '^':
					res=pow(n2,n1);
					break;
			}
			push(res);
			
		}
		p++;
		
	}
	printf("The result is: %d\n",pop());
}





		
		
