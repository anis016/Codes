#include<stdio.h>
#include<string.h>
#define MAX 10010

char in1[MAX], in2[MAX];
char out1[MAX], out2[MAX], hold3[MAX], z, temp[MAX], temp_hold[MAX];
long hold1[MAX], hold2[MAX], out_1[MAX], out_2[MAX], temp_lon[MAX];

int main()
{
	long len1, len2, i, j, k, l, t, temp_min, temp_max, y, w, zz, tt, flag;
	
	while(gets(in1))
	{
		gets(in2);

		len1=strlen(in1);
		len2=strlen(in2);

		if(len1<len2)
		{
			strcpy(temp, in1);
			tt=len1;

			strcpy(in1, in2);
			len1=len2;

			strcpy(in2, temp);
			len2=tt;
		}

		for(i=0; i<MAX; i++)
			hold1[i]=hold2[i]=0;

		for(i=0; i<len1; i++)
			hold1[in1[i]]++;

		for(i=0; i<len2; i++)
			hold2[in2[i]]++;

		k=l=flag=0;
		for(i=96; i<123; i++)
		{
			if(hold1[i]!=0)
			{
				out1[k]=char(i);
				out_1[k]=hold1[i];
				k++;
			}

			if(hold2[i]!=0)
			{
				out2[l]=char(i);
				out_2[l]=hold2[i];
				l++;
			}

		}

		z='0';
		t=0;
		
		if(k<l)
		{
			strcpy(temp_hold, out1);
			strcpy(out1, out2);
			strcpy(out2, temp_hold);

			temp_min=k;
			temp_max=l;
			for(i=0; i<temp_max; i++)
			{
				flag=0;
				for(j=0; j<temp_min; j++)     
				{
					if(flag==1)
						break;
					if(out1[i]==out2[j])
					{
						flag=1;
					   z=out1[i];
					    if(out_1[j]>out_2[i])
						{
						  for(y=0; y<out_2[i]; y++)
						  {
							hold3[t]=z;
							t++;
						  }
						}
					    else if(out_1[j]<out_2[i])
						{
						  for(w=0; w<out_1[j]; w++)
						  { 
							hold3[t]=z;
							t++;
						  }
						}
					    else if(out_1[j]==out_2[i])
						{
						  for(zz=0; zz<out_1[j]; zz++)
						  {
							hold3[t]=z;
							t++;
						  }
						}
					}
				}
			}
			hold3[t]='\0';
		    printf("%s\n", hold3);
		}
		
		else if( (k>l) || (k==l) )
		{
			temp_min=l;
			temp_max=k;

			for(i=0; i<temp_max; i++)
			{
				flag=0;
				for(j=0; j<temp_min; j++)     
				{
					if(flag==1)
						break;
					if(out1[i]==out2[j])
					{
						flag=1;
					   z=out1[i];
					    if(out_1[i]>out_2[j])
						{
						  for(y=0; y<out_2[j]; y++)
						  {
							hold3[t]=z;
							t++;
						  }
						}
					    else if(out_1[i]<out_2[j])
						{
						  for(w=0; w<out_1[i]; w++)
						  { 
							hold3[t]=z;
							t++;
						  }
						}
					    else if(out_1[i]==out_2[j])
						{
						  for(zz=0; zz<out_1[i]; zz++)
						  {
							hold3[t]=z;
							t++;
						  }
						}
					}
				}
			}
			hold3[t]='\0';
		    printf("%s\n", hold3);

		}
	
	}	
	return 0;
}
