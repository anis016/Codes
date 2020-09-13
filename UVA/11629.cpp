#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10001

long guess, expres;
struct List
{
	char str[50];
	long num;
}list[51];

int sort_string(const void *op, const void *b)
{
	List *p = (List *)op;
	List *q = (List *)b;

	return ( strcmp( p->str, q->str ) );
}

void read_input()
{
	long i, op, b;
	char ch;
	for(i=0; i<guess; i++)
	{
		scanf("%s %ld%c%ld", list[i].str, &b, &ch, &op);
		list[i].num = op + b * 10;
	}

	getchar();
	qsort((void *)list, guess, sizeof(list[0]), sort_string);

	return ;
}

long Bsearch(char *s)
{
	long low, high, mid, f;

	low = 0;
	high = guess - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		f = strcmp(s, list[mid].str);

		if(f > 0)
			low = mid + 1;
		else if(f < 0)
			high = mid - 1;
		else if(f == 0)
			return list[mid].num;
	}
}

bool find_guess()
{
	bool flag;
	char temp[MAX], op[4], digit[MAX], *pch;
	long comp, sum;

	gets(temp);

	pch = strtok (temp, " ");
	sum = 0;

	while(pch != NULL) 
	{
		if( isalnum (pch [0]) ) 
			sum += Bsearch(pch);
		else if ( pch [0] != '+' ) 
		{
			strcpy(op, pch);
			pch = strtok (NULL, " ");
			strcpy(digit, pch);

            break;
		}
		pch = strtok (NULL, " ");
	}
	
	comp = atol(digit) * 10;

	flag = false;
	if ( !strcmp (op, "<") )
		flag = (sum < comp) ? true : false;
	
	else if ( !strcmp (op,  ">") )
		flag = (sum > comp) ? true : false;
	
	else if ( !strcmp (op, "<=") )
		flag = (sum <= comp) ? true : false;
	
    else if ( !strcmp (op, ">=") )
        flag = (sum >= comp) ? true : false;
	
    else if ( !strcmp (op, "=") )
       flag = (sum == comp) ? true : false;

	return flag;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long i;
	bool flag;

	while(scanf("%ld %ld", &guess, &expres)==2)
	{
		read_input();
		
		for(i=1; i<=expres; i++)
		{
			flag = false;
			flag = find_guess();
			
			if(flag == true)
				printf("Guess #%ld was correct.\n", i);
			else
				printf("Guess #%ld was incorrect.\n", i);
		}
	}

	return 0;
}
