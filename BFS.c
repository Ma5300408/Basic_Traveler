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




struct node{
   int data;
  struct node *next;
};

struct node * head = NULL;
struct node * tail = NULL;

int enqueue(int v){
  
  struct node * temp = (struct node*)malloc(sizeof(struct node));
   temp->data = v;
   if(head == NULL)head = tail = temp;
   
  else{
     tail->next = temp;
     tail = temp;

   }

   temp->next = NULL;
   return 0;

}

int dequeue(){

  if(head == NULL){

      tail = NULL;
      return -1;
    }
 

  else{
      struct node * temp;
     temp = head;
     int pop_value  = temp->data;
     head = head->next;
     free(temp);     
     return pop_value;
   }

}

int IsEmpty(){


   if(head == NULL)return 1;
   else return 0;


}



void BFS(int * G,int start){
   
     bool visit[ROW];
     int i;
    for(i = 0; i < ROW; i++){visit[i] = false;}
     visit[start] = true;
     enqueue(start);
 //    printf(" %d ",start);
     while(!IsEmpty()){
       
        int value;
        int j;
        value = dequeue();
        printf(" %d ", value);
        for(j = value*COL; j < value*COL+ROW; j++){
            if(G[j]==1 && !visit[j-value*COL]){
                        enqueue(j-value*COL);
                       //printf(" %d ", j-value*COL);    
                        visit[j-value*COL] = true;
            }
        }

     }

}



int main(){



   BFS((int*)Graph,1);

 
}
