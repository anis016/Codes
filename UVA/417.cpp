#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAXI 83682

long J = 1, jj = 1;

struct List
{
	char str[50];
	long count;
}list[MAXI];

void gen1()
{
	long i;
	for(i='a'; i<='z'; i++)
	{
		list[jj].str[0] = char(i);
		list[jj].str[1] = '\0';
		list[jj].count = J++;
		jj++;
	}
}

void gen2()
{
	long i, j;
	for(i='a'; i<='z'; i++)
		for(j= i + 1; j<='z'; j++)		
		{
			list[jj].str[0] = char(i);
			list[jj].str[1] = char(j);
			list[jj].str[2] = '\0';
			list[jj].count = J++;
			jj++;
		}
}

void gen3()
{
	long i, j, k;
	for(i='a'; i<='z'; i++)
		for(j= i + 1; j<='z'; j++)		
			for(k= j + 1; k<='z'; k++)
			{
				list[jj].str[0] = char(i);
				list[jj].str[1] = char(j);
				list[jj].str[2] = char(k);
				list[jj].str[3] = '\0';				
				list[jj].count = J++;
				jj++;
			}
	
}

void gen4()
{
	long i, j, k, l;
	for(i='a'; i<='z'; i++)
		for(j= i + 1; j<='z'; j++)		
			for(k= j + 1; k<='z'; k++)
				for(l= k + 1; l<='z'; l++)
				{
					list[jj].str[0] = char(i);
					list[jj].str[1] = char(j);
					list[jj].str[2] = char(k);
					list[jj].str[3] = char(l);
					list[jj].str[4] = '\0';				
					list[jj].count = J++;
					jj++;
				}
}

void gen5()
{
	long i, j, k, l, m;
	for(i='a'; i<='z'; i++)
		for(j= i + 1; j<='z'; j++)		
			for(k= j + 1; k<='z'; k++)
				for(l= k + 1; l<='z'; l++)
					for(m= l + 1; m<='z'; m++)
					{
						list[jj].str[0] = char(i);
						list[jj].str[1] = char(j);
						list[jj].str[2] = char(k);
						list[jj].str[3] = char(l);
						list[jj].str[4] = char(m);
						list[jj].str[5] = '\0';				
						list[jj].count = J++;
						jj++;
					}
}

void generate()
{
	gen1();
	gen2();
	gen3();
	gen4();
	gen5();
	
	return ;
}

int sort_function( const void *a, const void *b)
{
	char *s,*t;

	s = ((struct List*)a)->str;
	t = ((struct List*)b)->str;
	return strcmp(s,t);
}

long Bsearch(char *s)
{
	long low, high, mid, f;

	low = 0;
	high = MAXI - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		f = strcmp(s, list[mid].str);

		if(f == 0)
			return list[mid].count;
		else if(f < 0)
			high = mid - 1;
		else if(f > 0)
			low = mid + 1;
	}
}

int main()
{
	char buf[MAXI], tempo[MAXI];
	long flag;

	generate();
	qsort((void *)list, 83682, sizeof(list[0]), sort_function);

	while(scanf("%s", buf)==1)
	{
		strcpy(tempo, buf);
		sort( tempo, tempo + strlen(tempo) );

		if(strcmp(buf, tempo)==0)
		{
			flag = Bsearch(buf);
			printf("%ld\n", flag);
		}
		else
			printf("0\n");
	}	
	return 0;
}