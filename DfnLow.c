#include<stdio.h>
#include<stdlib.h>
#define ROWS 10
#define COLS 10
#define Min(x,y)(x > y ? y : x)

int Graph[ROWS][COLS] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                        1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                        0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 
                        0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 
                        0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                        0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 
                        0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
                        0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
                        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 1, 0, 0
                      };




int dfn[COLS];
int low[COLS];
int num;

void DfnLow(const int u,const int v){    

    dfn[u] = low[u] = num++;
    int w;
    for(w = 0; w < COLS; w++){
           if(Graph[u][w]!=0){
                if(dfn[w] == 0){
                    DfnLow(w,u);
                    low[u] = Min(low[u],low[w]);
                }
            
            else if(w!=v)low[u] = Min(low[u],dfn[w]); //back edge.
           }

     }

}





int main()
{

  num = 1;
  int j;
  for(j = 0; j < COLS; j++)dfn[j] = 0;
  for(j = 0; j< COLS; j++)low[j] = 0;
  DfnLow(5,-1);
  for(j = 0; j < COLS; j++){
     printf(" %d ",dfn[j]);

  }
   printf("\n");
   for(j = 0; j < COLS; j++){
     printf(" %d ",low[j]);

  }
  printf("\n");

  return 0;
}
