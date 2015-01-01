#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100

int s[MAX];

int main()
{
//	freopen("in.txt", "r", stdin);

	int n, i, flag;

	while(scanf("%d", &n), n)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]);

		sort(s, s + n);

		flag = 0;
		for(i = 1; i < n; i++)
		{
			int m = s[i] - s[i - 1];			
			if( m > 200)
				flag = 1;
		}
		
		if ( 2 * (1422 - s[n - 1]) > 200 ) 
			flag = 1;

		if(flag == 0)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}