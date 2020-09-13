#include<stdio.h>
#include<string.h>
#define MAX 310

long J, num_node[MAX], P[MAX], count[MAX];

long parent(long x)
{
	if(P[x]==-1)
		return x;
	
	P[x] = parent(P[x]);
	
	return P[x];
}

int main()
{
	char ch, xx[MAX];
	long i, t1, t2, cnt, Case;
	
	scanf("%ld", &Case);
	getchar();
	getchar();
	while(Case--)
	{
		scanf("%c", &ch);
		for(i=65, J=1; i<=long(ch); i++)
		{
			num_node[char(i)] = J;

			P[J+1] = -1;
			P[J] = -1;

			count[J+1]=0;
			count[J]=0;
			J++;
		}
		
		getchar();
		while(gets(xx))
		{
			if(!strlen(xx)) 
                   break;

			t1 = parent(num_node[xx[0]]);
			t2 = parent(num_node[xx[1]]);

			if(t1!=t2)
				P[t1] = t2;
		}

		for(i=1;i<=J;i++)
			count[parent(i)]++;
		
		cnt = 0;
		for(i=1;i<J;i++)
			if(count[i]!=0)
				cnt++;

			
		printf("%ld\n", cnt);
		
		if(Case > 0)
			printf("\n");
	}	

	return 0;
}
