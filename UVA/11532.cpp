#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef long long LL;

char str[MAX];

LL pow(LL base, LL expo)
{
	LL ans = 1;

	for(LL i = 1; i <= expo; i++)
		ans *= base;
	return ans;
}

void init(LL len)
{
	for(LL i = 0; i <= len; i++)
		str[i] = 0;
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	LL P, Q, len, i, sum, Case;

	scanf("%lld", &Case);

	while(Case --)
	{
		scanf("%lld %lld", &P, &Q);
		
		len = 0;
		if(P / 2 < Q) // last 01
		{
			len = P + Q;

			for(i = len; i >= 0 && P; )
			{
				if(i >= 0 && P)
					str[i] = '1', i--, P--;
				if(i >= 0 && Q)
					str[i] = '0', i--, Q--;
				if(i >= 0 && P)
					str[i] = '1', i--, P--;
			}

			while(i >= 0)
				str[i] = '0', i--;

			str[len + 1] = '\0';

			sum = 0;
			LL j = 0;

			for(i = len; i>=0; i--)
			{
				LL ch = str[i] - '0';
				sum += ch * pow(2, j);
				j++;
			}
		}
		else // last 11
		{
			len = P + Q;

			for(i = 0; i <= len && Q; )
			{
				if(i <= len && P)
					str[i] = '1', i++, P--;
				if(i <= len && Q)
					str[i] = '0', i++, Q--;
				if(i <= len && P)
					str[i] = '1', i++, P--;
			}

			while(i < len)
				str[i] = '1', i++;

			str[len + 1] = '\0';

			sum = 0;
			LL j = 0;
			
			for(i = len - 1; i>=0; i--)
			{
				LL ch = str[i] - '0';
				sum += ch * pow(2, j);
				j++;
			}
		}

		printf("%lld\n", sum);
		
		init(len);
	}

	return 0;
}