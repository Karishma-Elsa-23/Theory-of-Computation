//Program to convert nfa to dfa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{ int s1,s2;
                     char t;
}node;                                        //structure to store transitions

void trans(int , char );
void sort(int[]);
int compare(int , int[]);                  

int a[20][5];                            // a is a 2D array used to store the unique states of dfa. reason why it is a 2d array is that if we get a state[1,2], it is represented as a[i][0]=1,a[i][1]=2, a[i][2]=-1
int top=0,n;                            //top points to the end of the array a
node t[20];                             //t stores all transitions

void main()
{
    int s,start;
    char symbols[20];
    int sym; 
    a[0][0]=0;                     //storing start symbol
    a[0][1]=-1;                    //-1 indicates end of that array
    int p=0;                       //p points to the state in a that has to be processed
    printf("Enter the number of states and transitions: ");
    scanf("%d %d", &s,&n);
    printf("Enter the transitions ");
    int k,j;
    for(k=0;k<n;k++)              //reading all transitions
    {
        scanf("%d %c %d ",&t[k].s1, &t[k].t, &t[k].s2);
    } 
    printf("Enter number of symbols ");
    scanf("%d ",&sym);
    printf("\nEnter symbols: ");
    for(k=0;k<sym;k++)             //reading all input symbols
        scanf("%c ",&symbols[k]);
        
    for(k=0;k<sym;k++)            //displaying input symbols(so that they are the first row of the dfa transition table)
	    printf("\t %c",symbols[k] );
	printf("\n");
    while(p<=top)               
    {  
        int y=0;
        while(a[p][y]!=-1)              
        {
        	printf("%d,",a[p][y]);     //displaying the current state whose transition is being found
        	y++;
		}    
        printf("\t ");
        for(k=0;k<sym;k++)              //looking at each input symbol
        {
            trans(p,symbols[k]);        //finding the transition for that perticular symbol from the current state
            printf("\t");
        }
        printf("\n");
        p++;
    }
        
}

void trans(int p, char c)            //finding the transition on symbol 'c' from the state a[p]
{
	int temp[5];
    //printf("LOL");
	int i,j,k;
    j=0;
    i=-1;
    while(a[p][j]!=-1)             //looking at each individual states thet make up state a[p]
    {
       for(k=0;k<n;k++)           //looking at each transition in t
       {
           if(t[k].s1==a[p][j] && t[k].t==c)       
           {
           	    int d=0,f=0;
           	    while(d<=i)        //checking if that transition has already been stored or not
           	    {
           	    	if(temp[d]==t[k].s2)
           	    	{
           	    		f=1;
           	    		break;
					}
					d++;
				}
				if(f==0)              //if not adding that transition
                    temp[++i]=t[k].s2;
           }
       }
       j++;
    }
    temp[++i]=-1;           //marking the end of the array
    //printf("hai");
    k=0;
    while(temp[k]!=-1)
    {
       printf("%d,",temp[k]);
       k++;
    }
    int g=0,flag=0;
    while(g<=top)               //checking if the newly found state is an already discovered state or not
    {
       if(compare(g,temp)==1)
       {
           flag=1;
           break;
       }
       g++;
    }
    //printf("outside while");
    if(flag==0)                 //if it is not an already discovered state then add it to the set of states (ie array a)
    {
       top++;
       k=0;
       while(temp[k]!=-1)
       {
           a[top][k]=temp[k];
           k++;
       }
       a[top][k]=-1;
    }
}


int compare(int g, int temp[])                //comparing whether two states(where a state is represented as a 1D integer array) is same or not
{
    sort(a[g]);
    sort(temp);
    int flag=1;
    int k=0;
    while(a[g][k]!=-1 || temp[k]!=-1)
    {
        if(a[g][k]!=temp[k])
        {
           flag=0;
           break;
        }
        k++;
    }
    return flag;
} 

void sort(int b[])                            //sorting is done to make comparison easy. here each state is sorted such that each individual states are in asceneding order
{
    int i,j,count=0;
    i=0;
    while(b[i]!=-1)
    {
    	count++;
    	i++;
	 } 
    i=0;
    while(b[i]!=-1)
    {
       j=0;
       while(j<count-i-1)
       {
          if(b[j]>b[j+1])
          {
              int te=b[j];
              b[j]=b[j+1];
              b[j+1]=te;
          }
          j++;
       }
       i++;
    }
}
