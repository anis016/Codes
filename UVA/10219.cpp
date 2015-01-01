#include<stdio.h>
#include<math.h>

int main()
{
    long N, K, i, d, temp, ans;
	double sum, num, den;

	while(scanf("%lld %lld", &N, &K)==2)
	{
		/*
		if(K>(N-K))
			temp=K;
		else
			temp=N-K;
        */
		temp=K>(N-K) ? K : (N-K);

		d=1;
		sum=0.0;
		for(i=temp+1; i<=N; d++, i++)
		{
			num=double(i);
			den=double(d);
			sum+=log10(num/den);
		}
		ans=floor(sum)+1;
		printf("%lld\n", ans);
	}
	return 0;
}