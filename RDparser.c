#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int top=0;
char str[20];

E()
{
	printf("\nE->TE\'");
	T();
	Edash();
}

T()
{
	printf("\nT->FT\'");
	F();
	Tdash();
}

F()
{
	if(str[top]=='(') 
	{
		printf("\nF->(id)");
		advance();
		E();
		if(str[top]!=')')
	    {
	    	printf("\nString NOT accepted by the grammar");
	    	exit(0);
		}
    }
    else if(isalpha(str[top])||isdigit(str[top]))
    {
    	printf("\nF->id");
    	advance();
	}
	else
	{
		printf("\nString NOT accepted by the grammar");
		exit(0);
	}
}

Edash()
{
	if(str[top]=='+') 
	{
		printf("\nE\'->+TE\'");
		advance();
		T();
		Edash();
    }
    else 
    {
        printf("\nE\'->Epsilon");
	}
}

Tdash()
{
	if(str[top]=='*') 
	{
		printf("\nT\'->*FT\'");
		advance();
		F();
		Tdash();
    }
    else 
    {
        printf("\nT\'->Epsilon");
	}
}

advance()
{
	top++;
}

void main()
{
	
	printf("Enter input string: ");
	scanf("%s", str);
	int end=strlen(str);
	E();
	if(top==end)
	   printf("\nString is accepted by the grammar");
	else
	   printf("\nString is NOT accepted by the grammar");
}
