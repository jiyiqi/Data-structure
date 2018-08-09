
#include<iostream>
#include<ctime>
#include<stack>
using namespace std;

void mazeGenerator(int a[][100],int m,int n)
{
			int i,j;
		 for(i=0;i<m+2;i++)
		  for(j=0;j<n+2;j++)
		   a[i][j]=1;
 
		 for(int i=1;i<m+1;i++)
		  for(int j=1;j<n+1;j++)
		   {
			   if(rand()%3==1)
			 a[i][j]=1;
			else 
				a[i][j]=0;
		  }
		 a[1][1]=0;
		 a[m][n]=0;
 
		 for(i=0;i<m+2;i++)
		  {
			  for(j=0;j<n+2;j++)
		      cout<<a[i][j];
			  cout<<endl;
		 }
	
}


class step
{
		public:
			int i,j;
			int di;
};

void mazeTraverse(int a[][100],int m,int n)
{
		step Stack[100];
		int count=0;
		 int i,j,di,find,k;
		 int top=-1;
		 top++;
		 Stack[top].i=1;Stack[top].j=1;Stack[top].di=-1;
		 int d[100][100]={};
		  for(int p=0;p<m+2;p++)
		  {
			  for(int q=0;q<n+2;q++)
			 d[p][q]=a[p][q];
		  }

			a[1][1]=-1;
		 int c=0;
	 while(top>-1)
{
		  i=Stack[top].i;
		  j=Stack[top].j;
		  di=Stack[top].di;
		  if(i==m &&j==n)
		  {
			 c=1;
		   for(k=0;k<=top;k++)
		   {
		   d[Stack[k].i][Stack[k].j]=2;
		   cout<<"("<<Stack[k].i<<","<<Stack[k].j<<") ";
		   }
		   cout<<endl;
		   break;
		  }
		  find=0;
		  while(di<9 && find==0)
		  {
		   di++;
		   switch(di)
		   {
		   case 0:i=Stack[top].i+1;j=Stack[top].j+1;break;
		   case 1:i=Stack[top].i;j=Stack[top].j+1;break;
		   case 2:i=Stack[top].i+1;j=Stack[top].j;break;
		   case 3:i=Stack[top].i;j=Stack[top].j-1;break; 
		   case 4:i=Stack[top].i-1;j=Stack[top].j;break;
		   case 5:i=Stack[top].i-1;j=Stack[top].j-1;break;
		   case 6:i=Stack[top].i-1;j=Stack[top].j+1;break;
		   case 7:i=Stack[top].i+1;j=Stack[top].j-1;break;
		   }
		   if(di==8)
		   break;

		   if(a[i][j]==0)
			   find=1;
		  }
         
		  if (find==1)
   
		  { 
		  Stack[top].di=di;
		  top++;
		  Stack[top].i=i;
		  Stack[top].j=j;
		  Stack[top].di=-1;
		  a[i][j]=-1;
		  count++;
		  }
		  else
		  {
			if(di==8)
		   {
			   a[i][j]=-1;
			   top--;
		     count++;
		   }
			else
			{
		   a[Stack[top].i][Stack[top].j]=0;
		   top--;
			}
		  }

		  if(count>200)
		  {
			  c=0;
		  break;
		  }
		 }
		 
		if(c==0)
			cout<<"此迷宫无解"<<endl;
	 if(c==1)
		{
	   for(int p=0;p<m+2;p++)
	   {
		  for(int q=0;q<n+2;q++)
			cout<< d[p][q];
		  cout<<endl;
	   }
		}
}

void main()
{
			int m,n;
			cout<<"输入迷宫的长度和宽度"<<endl;
			cin>>m>>n;
		  int a[100][100];      
		  srand (time (0));                                 
		   mazeGenerator(a,m,n);
		   mazeTraverse(a,m,n);

		 system("pause");
}
