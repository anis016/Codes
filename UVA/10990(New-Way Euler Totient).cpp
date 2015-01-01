#include<stdio.h>
#include<math.h>
#define MAXN 2000001

struct List
{
	long sum;
	long depth;
	long num;
	long phi_val;
}list[MAXN];

long prime[MAXN];
long Fact[MAXN];
long fgE[MAXN];

void generate()
{
   prime[0] = 0;
   prime[1] = 1;

   long i, j;

   for(i=2; i<=sqrt(MAXN); i++) 
   {
	   if(prime[i]==0) 
	   { 
		   for(j=i*i; j<=MAXN; j=j+i) 
		   { 
			   prime[j] = 1;
			   Fact[j] = i;
		   }
	   } 
   }
}

long find_euler_totient(long n)
{
	long k, f, m;
	if(!Fact[n]) 
		return n-1;
	if(fgE[n]) 
		return list[n].phi_val;

	fgE[n] = 1;
	f = Fact[n];
	m = n/f;
	
	if(m % f == 0)
		k = f * find_euler_totient(m);
	else
		k = (f - 1) * find_euler_totient(m);
	
	list[n].phi_val = k;

	return k;
}


void generate_depth()
{
	long I;

	list[1].depth = 0;
	list[1].phi_val = 1;
	list[1].num = 1;
	list[1].sum = 0;

	for(I = 2; I <= MAXN; I++)
	{
		list[I].num = I;
		list[I].phi_val = find_euler_totient(I);
		list[I].depth = list[list[I].phi_val].depth + 1;
		list[I].sum = list[I - 1].sum + list[I].depth;
	}
	return ;
}

int main()
{
	long st, end, Case;

	generate();
	generate_depth();

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld %ld", &st, &end);
		
		long result = list[end].sum - list[st - 1].sum;
		printf("%ld\n", result);
	}
	return 0;
}