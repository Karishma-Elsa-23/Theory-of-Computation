#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* ident(char[]);

void main()
{
	FILE *f = fopen("lexical_analyser.c","r");
	char c[50],key[20],temp[50];
	while(fgets(c,50,f))
	{
		while(c[0]!='\n'&& c[0]!='\0')
		{
		   int i=0;
		   while(isspace(c[i]))
		        i++;
		   int k=i,j=0;
		   while(c[k]!='\0')
		   {
		    	temp[j]=c[k];
			    j++;
			    k++;
		   }
		   temp[j]='\0';
		   strcpy(c,temp);
		   if(c[0]=='\"')
		   {
		   	  j=1;
		   	  while(c[j]!='\"')
		   	  {
		   	  	temp[j-1]=c[j];
		   	  	j++;
			  }
			  temp[j]='\0';
			  printf("< literal , %s > ",temp);
			  i=j+1;
			  j=0;
		        while(c[i]!='\0')
             	{
		            temp[j]=c[i];
		            i++;
	            	j++;
	            }
		            temp[j]='\0';
		        strcpy(c,temp); 
		   }
		   else if(c[0]=='\"')
		   {
		   	  j=1;
		   	  while(c[0]!='\"')
		   	  {
		   	  	temp[j-1]=c[j];
		   	  	j++;
			  }
			  temp[j]='\0';
			  printf("< literal , %s > ",temp);
			  i=j+1;
			  j=0;
		        while(c[i]!='\0')
             	{
		            temp[j]=c[i];
		            i++;
	            	j++;
	            }
		            temp[j]='\0';
		        strcpy(c,temp);
		   }
		  
		   else if(isalpha(c[0]))
		   {
		    	int i=1;
			    while(isalpha(c[i]))
			        i++;
			    memcpy(key,c,i);
			    key[i]='\0';
			    FILE *kf= fopen("keywords.txt","r");
			    int flag=0;
			    char k[20];
			    while(fgets(k,20,kf))
			    { 
			        k[strlen(k)-1]='\0';
				    if(strcmp(k,key)==0)
			    	{ 
				    	flag=1;
					    printf("<keyword, %s >  ",key);
				    }
			    }
			    fclose(kf);
			    if(flag==0)
			        strcpy(c,ident(c));
			    else
			    {
				    j=0;
				    while(c[i]!='\0')
				    {
					    temp[j]=c[i];
					    i++;
					    j++;
				    }
				    temp[j]='\0';
				    strcpy(c,temp);
			    }
		    }
		    else if(c[0]=='_')
		        strcpy(c,ident(c));
		    else if(isdigit(c[0]))
		    {
		    	char num[20],temp1[50];
		    	int j=0,i=0;
		    	while(isdigit(c[i])||c[i]=='.')
		        {
		    	    num[j]=c[i];
			        j++;
			        i++;
		        }
		        num[j]='\0';
		        printf("<constant, %s >  ",num);
		        j=0;
		        while(c[i]!='\0')
             	{
		            temp1[j]=c[i];
		            i++;
	            	j++;
	            }
		            temp1[j]='\0';
		        strcpy(c,temp1); 
		    	
			}
		    else
		    {
		    	int f=0;
		    	switch(c[0])
		    	{
		    		case '+': if(c[1]=='+')
		    		          {
		    		          	    printf("< ++ >  ");
		    		          	    f=1;
							  }
							  else if(c[1]=='=')
							  {
							  	    printf("< += >  ");
							  	    f=1;
							  }
		    		          else
		    		          	    printf("< + >  ");   
		    		          break;
		    		case '-': if(c[1]=='-')
		    	               {
		    	               	    printf("< -- >  ");
		    	               	    f=1;
							   }
							   else if(c[1]=='=')
							  {
							  	    printf("< -= >  ");
							  	    f=1;
							  }
							   else
							        printf("< - >  ");
							   break;
					case '=': if(c[1]=='=')
					          {
					          	    printf("< == >  ");
					          	    f=1;
							  }
							  else
							        printf("< = >  ");
							   break;
					case '*': if(c[1]=='=')
							  {
							  	    printf("< *= >  ");
							  	    f=1;
							  }
							  else
					                printf("< * >  ");
					          break;
					case '/': if(c[1]=='=')
							  {
							  	    printf("< /= >  ");
							  	    f=1;
							  }
							  else
					                printf("< / >  ");
					          break;
					case '%': if(c[1]=='=')
							  {
							  	    printf("< %= >  ");
							  	    f=1;
							  }
							  else
					                printf("< % >  ");
					          break;
				    case '>': if(c[1]=='=')
							  {
							  	    printf("< >= >  ");
							  	    f=1;
							  }
							  else
							        printf("< > >  ");
							  break;
					case '<': if(c[1]=='=')
							  {
							  	    printf("< <= >  ");
							  	    f=1;
							  }
							  else
							        printf("< < >  ");
							  break;
					case '!': if(c[1]=='=')
							  {
							  	    printf("< != >  ");
							  	    f=1;
							  }
							  else
							        printf("< ! >  ");
							  break;
					case '&': if(c[1]=='&')
							  {
							  	    printf("< && >  ");
							  	    f=1;
							  }
							  else
							        printf("< & >  ");
							  break;
					case '|': if(c[1]=='|')
							  {
							  	    printf("< || >  ");
							  	    f=1;
							  }
							  else
							        printf("< | >  ");
							  break;
					case '^': printf("< ^ >  ");
					          break;
				    default : printf("<symbol, %c >  ",c[0]);
				              break;
				}
				int j=0,i;
				if(f==1)
				    i=2;
				else
				    i=1;
				while(c[i]!='\0')
				    {
					    temp[j]=c[i];
					    i++;
					    j++;
				    }
				    temp[j]='\0';
				    strcpy(c,temp);
			}
        }
        printf("\n"); 
	}
	fclose(f);
}

char* ident(char c[50])
{
	int i=1,j=0;
	char key[20],temp[50];
	while(isalnum(c[i])||c[i]=='_')
	    i++;
	memcpy(key,c,i);
    key[i]='\0';
    printf("<identifier, %s >  ",key);
	while(c[i]!='\0')
	{
		temp[j]=c[i];
		i++;
		j++;
	}
		temp[j]='\0';
		return temp;
}
