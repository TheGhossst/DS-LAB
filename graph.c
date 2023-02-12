//Nandu Krishna M B21CS12353
#include <stdio.h>
int n;
void bfs(int adj[n][n],int visited[n],int i){
    int q[n],rear=-1,front=-1,j,k;
    for(k=0;k<n;k++)
        visited[k]=0;
    q[++rear]=i;
    ++front;
    visited[i]=1;
    while(front<=rear){
        i=q[front++];
        printf("%c\t",i+65);
        for(j=0;j<n;j++){
            if(adj[i][j]==1 && visited[j]==0){
                q[++rear]=j;
                visited[j]=1;
            }
        }
    }
}
/*void dfs(int adj[n][n],int visited[n],int i){
    int s[n],top=-1,j,k;
    for(k=0;k<n;k++)
        visited[k]=0;
    s[++top]=i;
    visited[i]=1;
    while(top!=-1){
        i=s[top--];
        printf("%c\t",i+65);
        for(j=0;j<n;j++){
            if(adj[i][j] && visited[j]==0){
                s[++top]=j;
                visited[j]=1;
            }
        }
    }
}*/
void main(){
    printf("Enter the number of edges: ");
    scanf("%d",&n);
    int visited[n];
    int adj[n][n],i,j,c;
    printf("\nMain Menu");
    printf("\n...............");
    printf("\n1.Insert\n2.BFS\n3.DFS\n4.Exit");
    printf("\n................");
    do{ 
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
               for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        printf("Enter 1 if there is a relation between %c and %c: ",i+65,j+65);
                        scanf("%d",&adj[i][j]);
                    }
               }
               break;
            case 2:
                printf("\nBFS:\n");
                bfs(adj,visited,0);
                break;
            case 3:
                printf("\nDFS:\n");
                //dfs(adj,visited,0);
                break;
            case 4:
                printf("\nExiting,");
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }while(c!=4);
}
/*Output
Enter the number of edges: 5
Main Menu
...............
1.Insert
2.BFS
3.DFS
4.Exit
................
Enter the choice: 1
Enter 1 if there is a relation between A and A: 0
Enter 1 if there is a relation between A and B: 1
Enter 1 if there is a relation between A and C: 1
Enter 1 if there is a relation between A and D: 1
Enter 1 if there is a relation between A and E: 0
Enter 1 if there is a relation between B and A: 0
Enter 1 if there is a relation between B and B: 0
Enter 1 if there is a relation between B and C: 1
Enter 1 if there is a relation between B and D: 1
Enter 1 if there is a relation between B and E: 0
Enter 1 if there is a relation between C and A: 1
Enter 1 if there is a relation between C and B: 0
Enter 1 if there is a relation between C and C: 0
Enter 1 if there is a relation between C and D: 0
Enter 1 if there is a relation between C and E: 1
Enter 1 if there is a relation between D and A: 1
Enter 1 if there is a relation between D and B: 0
Enter 1 if there is a relation between D and C: 1
Enter 1 if there is a relation between D and D: 0 
Enter 1 if there is a relation between D and E: 1
Enter 1 if there is a relation between E and A: 0
Enter 1 if there is a relation between E and B: 0
Enter 1 if there is a relation between E and C: 0
Enter 1 if there is a relation between E and D: 1
Enter 1 if there is a relation between E and E: 0
Enter the choice: 2
BFS:
A       B       C       D       E
Enter the choice: 3
DFS:
A       D       E       C       B
Enter the choice: 4
Exiting,*/