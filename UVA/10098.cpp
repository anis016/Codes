#include <stdio.h>
#include <string.h>
#define MAX 20

void sort(char *v, int n)
{
	int gap,i,j;
	char temp;

	for(gap=n/2; gap ;gap /=2)
		for(i=gap; i<n ;i++)
			for(j=i-gap;v[j]>v[j+gap] && j>=0;j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
	return ;
}

int main()
{
	char s[MAX],t;
	int i,j,len,pos,testCase,dataSet;

	scanf("%d",&dataSet);
	for(testCase=0;testCase<dataSet;testCase++)
	{
		scanf("%s",s);
		len = strlen(s);
		sort(s,len);
		
		while(1)
		{
			puts(s);
			for(i=len-1;i>0;i--)
				if(s[i] > s[i-1])
					break;
			if(!i)
				break;
			else
			{
				pos = i-1;
				while(s[i] > s[pos])
					i++;

				t = s[pos];
				s[pos] = s[i-1];
				s[i-1] = t;

				for(i=pos+1,j=len-1;i<j;i++,j--)
				{
					t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}