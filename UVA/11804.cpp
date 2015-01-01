#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11

struct List
{
	char name[21];
	int attack;
	int defence;
}player[MAX];

void read_input()
{
	for(int i = 0; i < 10; i++)
		scanf("%s %d %d", player[i].name, &player[i].attack, &player[i].defence);
	return ;
}

int sort_attack(const void *a, const void *b)
{
	List *p = (List *)a;
	List *q = (List *)b;

	if( p->attack != q->attack )
		return q->attack - p->attack;   // increasing order
	else if( (p->attack == q->attack) && (p->defence != q->defence) )
		return p->defence - q->defence;  // decreasing order
	else if( (p->attack == q->attack ) && (p->defence == q->defence) )
		return strcmp(p->name, q->name);  // increasing order
}

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

void print_a()
{
	char attacker[MAX][21];
	int i;

	for(i = 0; i < 5; i++)
		strcpy(attacker[i], player[i].name);

	qsort( (void *)attacker, 5, sizeof(attacker[0]), sorting);

	printf("(%s, ", attacker[0]);
	for(i = 1; i <= 3; i++)
		printf("%s, ", attacker[i]);
	printf("%s)", attacker[4]);
}

void print_d()
{
	char defence[MAX][21];

	int i;
	int j = 0;

	for(i = 5; i < 10; i++)
		strcpy(defence[j++], player[i].name);

	qsort( (void *)defence, 5, sizeof(defence[0]), sorting);

	printf("(%s, ", defence[0]);
	for(i = 1; i <= 3; i++)
		printf("%s, ", defence[i]);
	printf("%s)", defence[4]);
}


int main()
{
	int cnt = 1;
	int Case;
	char buf[MAX];

	gets(buf);
	sscanf(buf, "%d", &Case);

	while(Case--)
	{
		read_input();
		qsort( (void *)player, 10, sizeof(player[0]), sort_attack);

		printf("Case %d:\n", cnt++);
		print_a();
		printf("\n");
		print_d();
		printf("\n");
	}
	return 0;
}
