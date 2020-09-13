#include<stdio.h>
#include<string.h>

int main()
{
	long n,i,arr[111],l,j,count,temp,flag;

	while(scanf("%ld",&n)==1,n!=0)
	{
		l=1;
		while(1)
		{	
			memset(arr,0,sizeof(arr));
			
			arr[1]=1;
			count=flag=temp=0;
			for(i=1;i<=n;i++)
			{
				if(arr[i]==0)
				{
					count++;
					if(count==l)
					{
						arr[i]=1;
						if(i==13)
						{
							for(j=1;j<=n;j++)
							{
								if(arr[j]==0)
								{
									flag=1;
									break;
								}
							}
							if(flag==1)
								break;
							else
							{
								printf("%ld\n",l);
								temp=1;
								break;
							}
						}
						count=0;
					}
					//continue;
				}
				if(i==n)
					i=0;
			}
			if(temp==1)
				break;
			l++;
		}
	}

	return 0;
}
