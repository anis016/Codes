#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1010
#define MAXN 1000000

long mat[MAX][MAX];

long top_place;
long order[MAXN], v[MAXN], A[MAXN];
long comp[MAXN]; // component id
long curr_comp;

long vertex, edge;
struct List
{
	char str[20];
	long order;
}list[MAX];
char temp[100];

void insert(char *s, char *f, long i)
{
	strcat(s, f);
	strcpy(list[i].str, s);
}

int sort_string(const void *a, const void *b)
{
	List *p = (List *)a;
	List *q = (List *)b;

	return strcmp( p->str , q->str );
}

void clear_temp()
{
	long len = strlen(temp);
	long i;

	for(i=0; i<len; i++)
		temp[i] = 0;
	return ;
}


long Bsearch(char *s)
{
	long low, high, mid, f;

	high = vertex - 1;
	low = 0;

	while(low <= high)
	{
		mid = (low + high) / 2;
		f = strcmp(s, list[mid].str);

		if(f == 0)
			return list[mid].order;
		else if(f > 0)
			low = mid + 1;
		else if(f < 0)
			high = mid - 1;
	}
	return -1;
}

void read_input()
{
	long x, y, i, len;
	char sur_name[20], first_name[20], sp;
	char sur_name1[20], first_name1[20];
	char sur_name2[20], first_name2[20];

	for(i=1; i<=vertex; i++)
	{
		scanf("%s%c%s", sur_name, &sp, first_name);
		len = strlen(sur_name);
		sur_name[len - 1] = '\0';
		insert(sur_name, first_name, i - 1);
		list[i-1].order = i;

		A[i] = 0;
	}
	
	qsort((void *)list, vertex, sizeof(list[0]), sort_string);

	for(i=0; i<edge; i++)
	{
		scanf("%s%c%s", sur_name1, &sp, first_name1);

		len = strlen(sur_name1);
		sur_name1[len - 1] = '\0';
		
		strcpy(temp, sur_name1);
		strcat(temp, first_name1);
		x = Bsearch(temp);
	//	clear_temp();
		
		scanf("%s%c%s", sur_name2, &sp, first_name2);

		len = strlen(sur_name2);
		sur_name2[len - 1] = '\0';

		strcpy(temp, sur_name2);
		strcat(temp, first_name2);
		y = Bsearch(temp);
	//	clear_temp();

		if(x != -1 && y != -1)
			mat[x][y] = 1;
	}
	return ;
}

void dfs(long a)
{
	long i;

	if(v[a] == 1)
		return ;
	v[a] = 1;
	for(i=1; i<=vertex; i++)
		if(mat[a][i] == 1)
			dfs(i);

	top_place--;
	order[top_place] = a;
}

void dfs_rev(long a) 
{
	long i;

	if(v[a] == 1) 
		return;

	v[a] = 1;
	comp[a] = curr_comp;
	for(i=1; i<=vertex; i++) 
		if(mat[i][a] == 1) 
			dfs_rev(i); 
}

void top()
{
	long i;

	top_place = vertex;

	for(i=1; i<=vertex; i++)
		v[i] = 0;

	for(i=1; i<=vertex; i++)
		if(v[i] == 0)
			dfs(i);
}

void scc() 
{
	long i, j;
	
	top();
	
	for(i=1; i<=vertex; i++) 
		v[i]=0;
	
	for(i=0; i<=vertex; i++)
	{
		j = order[i];
		if (v[j] == 0) 
		{
			curr_comp = j;
			dfs_rev(j);
		}
	}
	return ;
}

long FIND_SET(long x)
{
	if(x != comp[x])
		comp[x] = FIND_SET(comp[x]);
	return comp[x];
}

void init_mat()
{
	long i, j;
	for(i=1; i<=vertex; i++)
		for(j=1; j<=vertex; j++)
			mat[i][j] = 0;
	return ;
}

int main()
{
	long i, cnt;

	while(scanf("%ld %ld", &vertex, &edge)==2)
	{
		if(!vertex && !edge)
			break;

		read_input();
		scc();
		for(i=1; i<=vertex; i++)
			A[FIND_SET(comp[i])]++;
		
		cnt = 0;
		for(i=1; i<=vertex; i++)
			if(A[i])
				cnt++;

		printf("%ld\n", cnt);
		init_mat();
	}
	return 0;
}