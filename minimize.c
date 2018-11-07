#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{ int s1,s2;
                     char t;
}node;

typedef struct STATES{ int s;
                       char t;
                       struct STATES *ptr;
}state;

int final_state(int , int[],int);
state* trans(int, node[], int);

void main()
{
	int n,s,fin[20];
    node t[20];
    printf("Enter the number of states and transitions: ");
    scanf("%d %d", &s,&n);
    printf("Enter the transitions ");
    int k,j;
    for(k=0;k<n;k++)
    {
        scanf("%d %c %d ",&t[k].s1, &t[k].t, &t[k].s2);
    }
    int i;
    int **mat = (int **)malloc(s * sizeof(int *)); 
    for (i=0; i<s; i++) 
         mat[i] = (int *)malloc(s * sizeof(int));
    int f;
    printf("\nEnter number of final states");
    scanf("%d", &f); 
    
    printf("Enter all final states: ");
    for(k=0;k<f;k++)
    {
        scanf("%d ",&fin[k]);
    }

    for(j=0;j<s;j++)
    {
    	for(k=0;k<j;k++)
    	{
    		if((final_state(j,fin,f)&&!final_state(k,fin, f))||(!final_state(j,fin ,f)&&final_state(k,fin, f)))
    		    mat[j][k]=1;
    		else
    		    mat[j][k]=0;
		}
	}
	state *one, *two, *temp;
	int flag;
	//int count=0;
	while(1)
	{
		flag=0;
		for(j=0;j<s;j++)
        {
    	    for(k=0;k<j;k++)
    	    {
    		    if(mat[j][k]==0)
    		    {
    			    one=trans(j,t,n);
    			    two=trans(k,t,n);
    			    while(one!=NULL)
    			    {
    			        temp=two;
    			        while(temp!=NULL)
    			        {
    			    	    if(one->t==temp->t)
    			         	{
    			    		    if(mat[one->s][temp->s]==1)
    			    		    {
    			    			    mat[j][k]=1;
    			    			    flag=1;
    			    			   // break;
							    }     			    		    
						     }
						    temp=temp->ptr;
					    }
					    one=one->ptr;
					}
			    }		
		    }
	    }
	    if(flag==0)
	        break;
	        
	}
	for(j=0;j<s;j++)
    {
    	for(k=0;k<j;k++)
    	{
    		printf("%d  ",mat[j][k]);
		}
		printf("\n");
	}
}

//to check if a given state is a final state
final_state(int s , int fin[],int f)
{
	int i;
	for(i=0;i<f;i++)
	{
		if(fin[i]==s)
		   return 1;
	}
	return 0;
}

state* trans(int s, node t[], int n)
{
	state *head=NULL, *temp, *new, *end;
	int i;
	for(i=0;i<n;i++)
	{
		if(t[i].s1==s)
		{
			new=(state*)malloc(sizeof(state));
			new->s=t[i].s2;
			new->t=t[i].t;
			new->ptr=NULL;
			if(head==NULL)
			{
				head=new;
				end=head;
			}
			else
			{
				end->ptr=new;
				end=new;
			}
		}
	}
	return head;
}
