#include<string.h>
#include<stdlib.h>
#include<stdio.h>
static int count=0;
char operator[]={'*','/','+','-','%','%','='};

int rightlimit(char* ,int);
int leftlimit(char* ,int);
char* makestring(char*,int ,int);
char* replacestring(char* ,char*,int ,int);

void main(){
	char c[60],*temp,*ch;
	printf("Enter input string: ");
	scanf("%s",c);
	ch=c;
	int k,j;
	for(j=0;j<6;j=j+2)
		for(k=0;k<strlen(ch);k++){
			if(ch[k]==operator[j]||ch[k]==operator[j+1]){
				int start=leftlimit(ch,k);
				int end=rightlimit(ch,k);
				temp=makestring(ch,start,end);				
				ch=replacestring(ch,temp,start,end);
				k=0;
				continue;
			}
	    }
		printf("\n%s",ch);	
}

int leftlimit(char *ch,int point){
	int flag=0;
	int i,j;
	for(i=point-1;i>=0;i--){
		for(j=0;j<strlen(operator);j++){
			if(ch[i]==operator[j]){
				flag=1;
				return i+1;
			}
		}
	}
	if(flag==0)
		return 0;
}

int rightlimit(char *ch,int point){
	int flag=0;
	int i,j;
	for(i=point+1;i<=strlen(ch);i++){
		for(j=0;j<strlen(operator);j++){
			if(ch[i]==operator[j]){
				flag=1;
				return i-1;
			}
		}
	}
	if(flag==0)
		return strlen(ch);
}

char* replacestring(char *ch,char *subch,int pos,int end){
	int i,j;
	char *res=(char*)malloc(sizeof(char)*strlen(ch));
	for(i=0;i<pos;i++)
	   res[i]=ch[i];
	for(j=0;j<strlen(subch);j++,i++){
			res[i]=subch[j];
	}	
	for(j=end+1;j<strlen(ch);j++,i++){
			res[i]=ch[j];
	}
	res[i]='\0';
	return res;
}

char* makestring(char *ch,int start,int end){
	int ki=start;
	char *t=(char*)malloc(sizeof(char)*5);
	char *tem=(char*)malloc(sizeof(char)*5);
    t[0]='t';
    t[1]='\0';
    tem=itoa(++count,tem,10);
    t=strcat(t,tem); 
	printf("\nt%d=",count);
	//printf("start: %d\n End: %d\n",start,end);
	while(ki<=end)
	{
		printf("%c",ch[ki]);
		ki++;
	}	
	return t;
	
}
