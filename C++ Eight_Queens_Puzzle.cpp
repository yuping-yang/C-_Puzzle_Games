#include<stdio.h>
#include<windows.h>
#define N 8 // The number of squares on the chessboard can be modified according to N
int count = 0;// count 
int chess[N][N] = {0}; 
	int k = 0;
void print()
{	
	int i = 0;
	int j = 0;
	printf("*****************************************\n");
	for(i = 0; i<N ;i++)
	{
		for(j = 0; j<N ; j++)
		{
			printf("%d ",chess[i][j]);
		}
		printf("\n");
	}
	printf("*****************************************\n");
}

// Determine whether chess pieces will capture each other
int check(int i, int j)//i = 7,j = 4 
{	
	if(i == 0)
		return 0;// 
  

	for(k = 0; k<i ; k++)
	{
		if(chess[k][j] == 1)//(0,4)(1,4)...
			return 1;
	}
	for( int s = 0,k = j+1; k<N ;k++)
	{	
						//(7,4)(6,5),(5,6),(4,7)
		if(chess[i-s-1][k] == 1)//(0,11),(1,10),(2,9),(3,8),(4,7)
			return 1;
		s++;
	}
	for(k = 0; k<j ;k++)
	{
		if(chess[i-k-1][j-k-1] == 1)//(6,3)(5,2)(4,1)(3,0)
			return 1;	
	}
	for(k = 0; k<N ; k++)
	{
		if(chess[k][j]==1)
			return 1;
	}
	return 0;
}
// Determine whether there is a row on the chessboard without a queen
int check_all()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i = 0; i<N ;i++)
	{	
		flag = 0;
		for(j = 0; j<N ; j++)
		{
			if(chess[i][j]==1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			return 1;
	}
	return 0;
}
// Check if a row has a queen
int check_line(int line)
{	
	if(line==0)
		return 0;
	int k = 0;
	int s = 0;
	int flag = 1;
	for(s = 0; s<line-1 ; s++)
	{	
		flag = 1;
		for(k = 0; k<N ;k++)
		{
			if(chess[s][k]==1)
				flag = 0;
		}
		if(flag==1)
			return 1;
	}
	return 0;
}

// Recursive Operation
void queen(int i,int j)
{		
	if(check_line(i)==1) 
		return ;
	if((i==(N-1))) 
	{		
		if(check(i,j)==0	
		{
			chess[i][j] = 1;
			print();
			count++;
		}
	}		
	if(check(i,j)==0) 
	{	
		chess[i][j] = 1;
		//print();
		//Sleep(1000);
		queen(i+1,0);	
}
 	if(j==N) 
		return ;
		
	chess[i][j] = 0;
	//print();
	//Sleep(500);
		queen(i,j+1); 
}
int main(void)
{	
	queen(0,0);
	printf("\ncount = %d\n",count);
	return 0;
}
