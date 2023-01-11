//Nandu Krishna M B21CS1235
//Linear,Binary Search
#include <stdio.h>
int linear();
int binary();
void main()
{
	int c;
	do
	{
		printf("\nThe Choices\n");
		printf("\n1.Linear\n2.Binary\n3.Exit\n");
		printf("Enter the choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				linear();
				break;
			case 2:
				binary();
				break;
			case 3:
			 	printf("\nExit\n");
			 	break;
			 default:
			 	printf("\nInvalid choice");
			 	break;
		}
	}while(c!=3);
}
int linear()
{
	int a[50],n,i,e,f=0;
	printf("\nEnter the limit: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element a[%d]: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
	printf("\nEnter the element to be searched: ");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		if(e==a[i])
		{
			f=1;
			break;
		}
		else
		{
			f=0;
		}
	}
	if(f==1)
	{
		printf("\n%d found in %dth postion",e,i+1);
	}
	else
	{
		printf("\nElement not found");
	}
}
int binary()
{
	
	int a[50],n,i,e,f=0,t,j;
	printf("\nEnter the limit: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element a[%d]: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("\nThe sorted array is:\n ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
	printf("\nEnter the element to be searched: ");
	scanf("%d",&e);
	int low=0,high=n-1;
	int mid=(low+high)/2;
	if(e==a[mid])
	{
		printf("\n%d Found ",e);
	}
	else if(e<a[mid])
	{
		high=mid-1;
		for(i=0;i<high;i++)
		{
			if(e==a[i])
			{
				f=1;
				break;
			}
			else
			{
				f=0;
			}
		}
		if(f==1)
		{
			printf("\n%d Found ",e);
		}	
		else
		{
			printf("\nElement not found");
		}
	}
	else if(e>a[mid])
	{
		low=mid+1;
		for(i=low;i<n;i++)
		{	
			if(e==a[i])
			{
				f=1;
				break;
			}
			else
			{	
				f=0;
			}
		}
		if(f==1)
		{
			printf("\n%d Found ",e);
		}
		else
		{
			printf("\nElement not found");
		}
	}
}
		
/* OUTPUT
.............
The Choices

1.Linear
2.Binary
3.Exit
Enter the choice: 1

Enter the limit: 2
Enter the element a[1]: 1
Enter the element a[2]: 2
1	2	
Enter the element to be searched: 2

2 found in 2th postion
The Choices

1.Linear
2.Binary
3.Exit
Enter the choice: 2

Enter the limit: 3
Enter the element a[1]: 1
Enter the element a[2]: 2
Enter the element a[3]: 3

The sorted array is:
 1	2	3	
Enter the element to be searched: 2

2 Found 
The Choices

1.Linear
2.Binary
3.Exit
Enter the choice: 3

Exit
*/
