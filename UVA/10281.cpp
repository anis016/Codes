#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
#define max 100

char sp, in[max], ch;
double speed, dis[max], in_h, in_m, in_s, por, nos;
double sum, hold, hp[max], trim[max], d, sub;
long count, i, g, flag, k;

int main()
{
	while(scanf("%s%c", in, &sp)==2)
	{
		if(sp==' ')
		{
			scanf("%lf", &nos);
			hp[k]=nos;
  		    sscanf(in,"%lf %c %lf %c %lf", &in_h, &ch, &in_m, &ch, &in_s);
			
			hold=in_h+(in_m/60)+(in_s/3600);
			dis[i]=hold;
			
			if(i>0)
			{
				sub=dis[i]-dis[i-1];
				if(flag==1)
				{
					speed=hp[k-1];
				}
				d=d+(sub*speed);
			}
			i++;
			k++;
		}
		else
		{
			sscanf(in,"%lf %c %lf %c %lf", &in_h, &ch, &in_m, &ch, &in_s);
			hold=in_h+(in_m/60)+(in_s/3600);
			dis[i]=hold;
			sub=dis[i]-dis[i-1];
			sum=(sub*hp[k-1])+d;
			printf("%s %.2lf km\n", in, sum);
			i++;
			d=sum;
			flag=1;
		}
	}

	return 0;
}
