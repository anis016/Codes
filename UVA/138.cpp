#include<stdio.h>

int main()
{
	printf("         6         8\n");
	printf("        35        49\n");
	printf("       204       288\n");
	printf("      1189      1681\n");
	printf("      6930      9800\n");
	printf("     40391     57121\n");
	printf("    235416    332928\n");
	printf("   1372105   1940449\n");
	printf("   7997214  11309768\n");
	printf("  46611179  65918161\n");

	return 0;
}

/*
#define MAX 20
__int64 storel[MAX], storer[MAX], j, N;
void make_number()
{
	__int64 i, n, a, b, c, n1;
	__int64 sum, root, d;

	j = 0;
	for(i = 6; ; i++)
	{
		if(j == 10)
			break;

		n = i - 1;
		sum = ( n * (1 + n) ) / 2;

		a = 1;
		b = (i + 1) * 2 - 1;
		c = - 2 * sum;

		d = (b * b) - 4 * a * c;
		root = (__int64)sqrt(d);

		if(root * root != d)
			continue;
		else
			n1 = (-b + root) / 2;

		storel[j] = i;
		storer[j++] = i + n1;
	}
	return ;
}

void generate()
{
	make_number();
	__int64 i;
	for(i = 0; i < j; i++)
		printf("%10I64d%10I64d\n", storel[i], storer[i]);
}
*/