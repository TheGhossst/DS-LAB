#include <stdio.h>
int table[20];
int tableSize;
void insert(int key){
    int index=key%tableSize;
    while(table[index]!=0)
        index=(index+1)%tableSize;
    table[index]=key;
}
int search(int item){
    int index=item%tableSize;
    int c;
    while(table[index]!=item){
        index=(index+1)%tableSize;
        c++;
        if(c==tableSize)    return -1;
    }
    return index;
}
void main(){
    int c,key,item;
    printf("\nEnter the table size: ");
    scanf("%d",&tableSize);
    printf("\nMenu");
    printf("\n...............");
    printf("\n1.Insert\n2.Search\n3.Display\n4.Exit");
    printf("\n................");
    do{
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter key to be inserted: ");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("\nEnter element to be searched: ");
                scanf("%d",&item);
                if(search(item)==-1) printf("Item Not Found");
                else    printf("Item Found");
                break;
            case 3:
                for(int i=0;i<tableSize;i++)
                        printf("%d\t",table[i]);
                break;
            case 4:
                printf("\nExiting..");
                break;
            default:
                printf("\nInvaluid choice: ");
                break;
        }
    }while(c!=4);
}
/*Output
Enter the table size: 10
Menu
...............
1.Insert
2.Search
3.Display
4.Exit
................
Enter the choice: 1
Enter key to be inserted: 5
Enter the choice: 1
Enter key to be inserted: 25
Enter the choice: 3
0       0       0       0       0       5       25      0       0       0
Enter the choice: 1
Enter key to be inserted: 3
Enter the choice: 1
Enter key to be inserted: 2
Enter the choice: 1
Enter key to be inserted: 4
Enter the choice: 1
Enter key to be inserted: 6
Enter the choice: 1
Enter key to be inserted: 8
Enter the choice: 1
Enter key to be inserted: 1
Enter the choice: 3
0       1       2       3       4       5       25      6       8       0
Enter the choice: 1
Enter key to be inserted: 6
Enter the choice: 1
Enter key to be inserted: 19
Enter the choice: 3
19      1       2       3       4       5       25      6       8       6
Enter the choice: 2
Enter element to be searched: 25
Item Found
Enter the choice: 2
Enter element to be searched: 26
Item Not Found
Enter the choice: 4
Exiting..*/