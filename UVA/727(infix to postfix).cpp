#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
#define MAX 100

char infix[MAX], postfix[MAX];
stack<char>stk;

void read_input()
{
	char ch[10];

	stk = std::stack<char>();

	stk.push('(');
	while(gets(ch))
	{
		if(strlen(ch) == 0)
			break;
		strcat(infix, ch);
	}
	return ;
}

bool check_prcedence(char a, char b)
{
	return (a=='*' || a=='/') >= (b=='*' || b=='/');
}

bool operand(char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	return false;
}

void postfix_conversion()
{
	int len = strlen(infix);
	int i, k = 0;

	for(i = 0; i < len; i++)
	{
		if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			while(!stk.empty() && stk.top() != '(')
			{
				char Top = stk.top();
				
				bool flag = check_prcedence(stk.top(), infix[i]);
				if(flag == true)
				{
					char ch = stk.top();
					stk.pop();
					postfix[k++] = ch;
				}
				else
					break;
			}
			stk.push(infix[i]);
		}

		else if(infix[i] == '(')
			stk.push('(');

		else if(infix[i] == ')')
		{
			while( !stk.empty() && stk.top() != '(')
			{
				char ch = stk.top();
				stk.pop();
				postfix[k++] = ch;
			}
			if(!stk.empty()) 
				stk.pop();
		}

		else if(operand(infix[i]) == true)
			postfix[k++] = infix[i];
	}

	while(!stk.empty() && stk.top()!= '(')
	{
		char ch = stk.top();
		stk.pop();
		postfix[k++] = ch;
	}
	postfix[k] = '\0';
		
	return ;
}

void init()
{
	int len = strlen(infix);
	int i;

	for(i = 0; i <= len; i++)
		infix[i] = 0;
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	char xx[MAX];
	int Case;

	gets(xx);
	sscanf(xx, "%d", &Case);
	gets(xx);
	while(Case--)
	{
		read_input();
		
		postfix_conversion();
		printf("%s\n", postfix);
		init();

		if(Case)
			printf("\n");
	}
	return 0;
}