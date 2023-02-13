//Nandu Krishna M B21CS1235
#include <stdio.h>

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	int i, j, k;
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1, j;
	int temp, temp1;

	for (j = low; j <= high - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return i + 1;
}

int quicksort(int a[], int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high);
		quicksort(a, p + 1, high);
		quicksort(a, low, p - 1);
	}
}

void main()
{
	int n, data;
	printf("\nEnter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	printf("\nMenu");
	printf("\n..................");
	printf("\n1,Read elements\n2.Quick Sort\n3.Merge Sort\n4.Exit");
	printf("\n.....................");
	int c;
	do
	{
		printf("\nEnter the choice :");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				printf("\nEnter the element a[%d] :", i + 1);
				scanf("%d", &a[i]);
			}
			printf("\nThe unsorted array is:\n");
			display(a, n);
			break;
		case 2:
			quicksort(a, 0, n - 1);
			printf("\nThe sorted array by quick sort is:\n");
			display(a, n);
			break;
		case 3:
			mergeSort(a, 0, n - 1);
			printf("\nThe sorted array by merge sort is:\n");
			display(a, n);
			break;
		case 4:
			printf("\nExitnggg");
			break;
		default:
			printf("Invalud:");
			break;
		}
	} while (c != 4);
}
/*oUTPUT
Enter the size of the array: 5
Menu
..................
1,Read elements
2.Quick Sort
3.Merge Sort
4.Exit
.....................
Enter the choice :1

Enter the element a[1] :3
Enter the element a[2] :2
Enter the element a[3] :1
Enter the element a[4] :6
Enter the element a[5] :89
The unsorted array is:
3       2       1       6       89

Enter the choice :2
The sorted array by quick sort is:
1       2       3       6       89
Enter the choice :1

Enter the element a[1] :3
Enter the element a[2] :9
Enter the element a[3] :7
Enter the element a[4] :5
Enter the element a[5] :1
The unsorted array is:
3       9       7       5       1

Enter the choice :3

The sorted array by merge sort is:
1       3       5       7       9

Enter the choice :4

Exitnggg
*/