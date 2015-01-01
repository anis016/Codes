#include<stdio.h>
#include<string.h>

int main()
{
	char in[1000], xx[1000];
	long i, j, k, l, flag1, flag2, flag3, len, con, kase;
	long x, y, z;

	gets(xx);
	sscanf(xx, "%ld", &kase);

	while(kase--)
	{
		gets(in);	
		len=strlen(in);
		
		flag1=flag2=flag3=k=con=l=x=y=z=0;
		for(i=0; i<len; i++)
		{
			con++;
			if(in[i]=='M')		
			{
				k=i;
				for(j=0; j<k; j++)
				{
					if(in[j]=='?')
					{
						flag1=1;
						x++;
					}
					else
					{	
						flag1=2;
						break;
					}
				}
			}	
			else if(in[i]=='E')
			{
				l=i;
				for(j=k+1; j<l; j++)
				{
					if(in[j]=='?')
					{
						flag2=1;
						y++;
					}
					else
					{
						flag2=2;
						break;
					}
				}
			}
			else if(flag1==1 && flag2==1 && con==len)
			{
				for(j=l+1; j<len; j++)
				{
					if(in[j]=='?')
					{
						flag3=1;
						z++;
					}
					else
					{
						flag3=2;
						break;
					}
				}
			}
		}
	
		if(flag1==1 && flag3==1 && flag3==1 && z==(x+y) && z!=0)
			printf("theorem\n");
		else
			printf("no-theorem\n");
	}
	return 0;
}