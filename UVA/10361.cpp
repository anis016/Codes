#include<stdio.h>
#include<string.h>
#define MAX 500

char in1[MAX], in2[MAX], s2[MAX], s3[MAX], s4[MAX],s5[MAX],out[MAX], hold1[MAX], hold2[MAX];
long ss, qq, i, ii, j, k, l, m, n, o, len1, len2,flag, tt, uu,ll;
char final2[MAX], final1[MAX], xx[100];
long test, ttt, d, v, z, o1, o2;

int main()
{
	gets(xx);
	sscanf(xx, "%ld", &test);
	for(ttt=0; ttt<test; ttt++)
	{
	  gets(in1);
	  gets(in2);
		
	  len1=strlen(in1);
	  len2=strlen(in2);

	  flag=j=ss=qq=0;
	 for(i=0; i<len1; i++)
	 {
		if(in1[i]=='<')
		{
			k=l=m=n=0;
			for(j=i; j<len1; j++)
			{
				if( (in1[j]>='A' && in1[j]<='Z') || (in1[j]>='a' && in1[j]<='z') || in1[j]==' ' || in1[j]=='.')
				{
					s2[k]=in1[j];
					k++;
				}
				if(in1[j]=='>')
				{
					s2[k]='\0';
					
					l=0;
					for(tt=j; tt<len1; tt++)
					{
						if( (in1[tt]>='A' && in1[tt]<='Z') || (in1[tt]>='a' && in1[tt]<='z') || in1[tt]==' ' || in1[j]=='.')
						{
							s3[l]=in1[tt];
							l++;
						}
						if(in1[tt]=='<')
						{
							s3[l]='\0';

							m=0;
							for(uu=tt; uu<len1; uu++)
							{
								if( (in1[uu]>='A' && in1[uu]<='Z') || (in1[uu]>='a' && in1[uu]<='z') || in1[j]==' ' || in1[j]=='.')
								{
									s4[m]=in1[uu];
									m++;
								}
								if(in1[uu]=='>')
								{
									s4[m]='\0';

									o=0;
									for(ll=uu; ll<=len1; ll++)
									{
										if( (in1[ll]>='A' && in1[ll]<='Z') || (in1[ll]>='a' && in1[ll]<='z') || in1[j]==' ' || in1[j]=='.')
										{
											s5[o]=in1[ll];
											o++;
										}
										if(ll==len1)
										{
											s5[o]='\0';
											flag=1;
											break;
										}
										
									}

								}
								if(flag==1)
									break;

							}
						}
						if(flag==1)
							break;
					}
				}
				if(flag==1)
					break;

			}
		}
		if(flag==1)
		{
			break;
		}
	 }

	qq=0;
 
	for(ii=0; ii<len2-3; ii++)
	{
		hold2[qq]=in2[ii];
		qq++;
	}
	hold2[qq]='\0';

	strcat(s4, s3);
	strcat(s2, s5);

	o1=strlen(s4);
	o2=strlen(s2);
	
	for(d=0,z=0; d<qq;z++, d++)
		final1[z]=hold2[d];
	
	for(d=0; d<o1; z++,d++)
		final1[z]=s4[d];

	for(d=0; d<o2; z++,d++)
		final1[z]=s2[d];

	final1[z]='\0';

	for(ll=0, d=0; ll<len1; ll++)
	{
		if(in1[ll]=='>' || in1[ll]=='<')
			continue;
		else
		{
			final2[d]=in1[ll];
			d++;
		}
	}
	final2[d]='\0';

	printf("%s\n",final2);
	printf("%s\n",final1);
	 
    }
	return 0;
}
