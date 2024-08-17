# Maze_v1
/*
 * Solve maze problems using sequential stacks
*/
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
#define m 6
#define n 8
// Define the elements in the stack, d is the direction
typedef struct{
 int x,y,d;
}point;
// Define the structure of the stack
typedef struct{
 point data[MAXSIZE];
 int top;
}MazeStack;
// Define the moving array to facilitate the movement of pointstypedef struct{
 int x,y;
}item;
// Set the stack to empty
void setNULL(MazeStack *s){
 s->top = -1;
}
// Determine whether the stack is empty
bool isEmpty(MazeStack *s){
 if(s->top>=0) return false;
 else return true;
}
// Push operation
MazeStack * push(MazeStack *s,point x){
 if(s->top>MAXSIZE-1){
    printf("Stack overflow! \n");
    return s;
 }else{
  s->top++;
  s->data[s->top] = x;
  return s;

 }
}
// Unstack Operation
point * pop(MazeStack *s){
 if(isEmpty(s)){
    printf("stack is empty!\n");
    return NULL;
 }else{
  s->top--;
  return &(s->data[s->top+1]);
 }
}
// Get the top element of the stack
point * getTop(MazeStack *s){
 if(isEmpty(s)){
    printf("stack is empty!\\n");
    return NULL;
 }else{
  return &(s->data[s->top]);
 }
}
// Define the location of the move
void defineMove(item xmove[8]){
 xmove[0].x = 0,xmove[0].y =1;
 xmove[1].x = 1,xmove[1].y =1;
 xmove[2].x = 1,xmove[2].y =0;
 xmove[3].x = 1,xmove[3].y =-1;
 xmove[4].x = 0,xmove[4].y =-1;
 xmove[5].x = -1,xmove[5].y =-1;
 xmove[6].x = 1,xmove[6].y =0;
 xmove[7].x = -1,xmove[7].y =1;
}
// Test all operations
int main(){
  //Defining the maze
  int maze[m+2][n+2],x,y,i,j,d;
  // Define the location of the move
  item xmove[8];
  // Define the starting point of the stack
  point start,*p;
  // Define the stack
  MazeStack *s;
  s = (MazeStack*)malloc(sizeof(MazeStack));
  setNULL(s);
  // Define the location of the move
  defineMove(xmove);
  // Input into the maze
  printf("Input into the maze: \n");
  for(i = 0;i<m+2;i++)
    for(j = 0;j<n+2;j++)
        scanf("%d",&maze[i][j]);
  start.x = 1;
  start.y = 1;
  start.d = -1;
  p = (point*)malloc(sizeof(point));
  // Push the starting point onto the stack
  s = push(s,start);
  while(!isEmpty(s)){
    p = pop(s);
    x = p->x;
    y = p->y;
    d = p->d+1;
    while(d<8){
        i = xmove[d].x+x;
        j = xmove[d].y+y;
        if(maze[i][j]==0){
            p->d = d;
            s = push(s,*p);
            x = i;
            y = j;
            maze[x][y] = -1;
            point nw;
            nw.x = x;
            nw.y = y;
            nw.d = -1;
            s = push(s,nw);
            if(x==m&&y==n){
                printf("Find the exit!\n");
                while(!isEmpty(s)){
                    p = pop(s);
                    printf("%d %d %d\n",p->x,p->y,p->d);
                }
                return 1;
            }else{
             break;
            }
        }else{
         d++;
        }
    }
  }
 return 0;
}
