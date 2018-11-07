#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct NODE{char s;
                    int v;
}node;
int find(char);
node sym[4]={{'i',0},{'+',1},{'*',2},{'$',3}};

int main()
{
	
	char str[20];
	printf("Enter input string: ");
	scanf("%s",str);
	char stack[20];
	stack[0]='$';
	strcat(str,"$");
	char mat[4][4]={{' ','>','>','>'},{'<','>','<','>'},{'<','>','>','>'},{'<','<','<',' '}};
	int top=0;
	int point=0;
	int i,j;
	printf("precedence table:\n  ");
	for(i=0;i<4;i++)
	  printf("%c ",sym[i].s);
	for(i=0;i<4;i++)
	{
		printf("\n%c ",sym[i].s);
		for(j=0;j<4;j++)
		{
			printf("%c ",mat[i][j]);
		}
	}
	while(1)
	{
		if(stack[top]=='$'&&str[point]=='$')
		{
			printf("\n\nString is accepted by the grammar");
			return 0;
		}
		else
		{
			char d=mat[find(stack[top])][find(str[point])];
			if(d=='<'|| d=='=')
			{
				stack[++top]=str[point];
				point++;
			}    
			else if(d=='>')
			{
				char pop=stack[top];
				--top;
				while(mat[find(stack[top])][find(pop)]!='<')
				{
					pop=stack[top];
					top--;
				}
				//stack[++top]=pop;
			}
			else
			{
				printf("\n\nString NOT accepted by the grammar");
				return -1;
			}    
		}
	}
}

int find(char d)
{
    int i;
	for(i=0;i<4;i++)
	{
		if(sym[i].s==d)
			return sym[i].v;
		  
	}
	return -1;	
}
