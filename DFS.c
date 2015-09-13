#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROW 8
#define COL 8

int Graph[ROW][COL] = { 0, 0, 0, 0, 1, 0, 0, 1,
                        1, 0, 1, 1, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0,
                        0, 1, 1, 0, 0, 0, 0, 1,
                        0, 0, 0, 0, 0, 0, 1, 1,
                        0, 0, 0, 0, 1, 0, 0, 0,
                        0, 0, 0, 0, 0, 1, 0, 0,
                        0, 0, 0, 0, 0, 1, 0, 0
                      };

bool visit[8];


void DFS(int *G ,int vertex){

   visit[vertex] = true;
   printf(" %d ",vertex);
  
   int j;
   for(j = vertex*COL ; j < vertex*COL+ROW ; j++){
     if(G[j]==1 && !visit[j-vertex*COL])DFS(G,j-vertex*COL);
   }

}




int main()
{
    int i;
    for (i = 0; i < 8; i++)visit[i] = false;
    DFS((int*)Graph,1);


  return 0;
}
