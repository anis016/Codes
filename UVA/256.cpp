#include<stdio.h>
#include<string.h>

int main()
{
	
	long	arr[10][10];

			arr[2][0]=0,arr[2][1]=1,arr[2][2]=81;
			arr[4][0]=0,arr[4][1]=1,arr[4][2]=2025,arr[4][3]=3025,arr[4][4]=9801;
			arr[6][0]=0,arr[6][1]=1,arr[6][2]=88209,arr[6][3]=494209,arr[6][4]=998001;
			arr[8][0]=0,arr[8][1]=1,arr[8][2]=4941729,arr[8][3]=7441984,arr[8][4]=24502500;arr[8][5]=25502500,arr[8][6]=52881984,arr[8][7]=60481729,arr[8][8]=99980001;

	long n,i;
	while(scanf("%ld",&n)==1)
	{
		if(n==2)
			for(i=0;i<3;i++)
				printf("%02ld\n",arr[n][i]);
		else if(n==4)
			for(i=0;i<5;i++)
				printf("%04ld\n",arr[n][i]);
		else if(n==6)
			for(i=0;i<5;i++)
				printf("%06ld\n",arr[n][i]);
		else
			for(i=0;i<9;i++)
				printf("%08ld\n",arr[n][i]);

	}
	
	return 0;
}


/*#include<stdio.h>

int  main()
{
	__int64 j, in4, in2, in6, in8, mod, div, hold, array2[10000], array4[10000], i, array6[10000], array8[10000];

/////////////////////////////////////////////////////////////////////////////
////////////////////////    PRECALCULATION    ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

	printf("FOR ====... 2... \n\n");
	
	hold=mod=div=i=j=0;
	for(in2=0; in2<=99; in2++)
	{
		mod=in2%10;
		div=in2/10;

		hold=(mod+div)*(mod+div);
		if(hold==in2)
		{
			array2[i]=in2;
			i++;
		}

	}

	for(j=0; j<i; j++)
	printf("%I64d\n", array2[j]);


	printf("\n\n\n");

/////////////////////////////////////////////////////////////////////////////

	printf("FOR ====... 4... \n\n");
	
	hold=mod=div=i=j=0;
	for(in4=0; in4<=9999; in4++)
	{
		mod=in4%100;
		div=in4/100;

		hold=(mod+div)*(mod+div);
		if(hold==in4)
		{
			array4[i]=in4;
			i++;
		}

	}

	for(j=0; j<i; j++)
	printf("%I64d\n", array4[j]);

	printf("\n\n\n");

/////////////////////////////////////////////////////////////////////////////

	printf("FOR ====... 6... \n\n");
	
	hold=mod=div=i=j=0;
	for(in6=0; in6<=999999; in6++)
	{
		mod=in6%1000;
		div=in6/1000;

		hold=(mod+div)*(mod+div);
		if(hold==in6)
		{
			array6[i]=in6;
			i++;
		}

	}

	for(j=0; j<i; j++)
	printf("%I64d\n", array6[j]);

	printf("\n\n\n");

/////////////////////////////////////////////////////////////////////////////

	printf("FOR ====... 8... \n\n");
	
	hold=mod=div=i=j=0;
	for(in8=0; in8<=99999999; in8++)
	{
		mod=in8%10000;
		div=in8/10000;

		hold=(mod+div)*(mod+div);
		if(hold==in8)
		{
			array8[i]=in8;
			i++;
		}

	}

	for(j=0; j<i; j++)
	printf("%I64d\n", array8[j]);

	printf("\n\n\n");

/////////////////////////////////////////////////////////////////////////////
//////////////***********************************************////////////////
/////////////////////////////////////////////////////////////////////////////	
	
//	return 0;
//}

