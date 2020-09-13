#include<stdio.h>
#define MAX 110

int store1[MAX], store2[MAX];
int N;

void process()
{
	int cnt = 0, limit, s1i, s1j, s2i, s2j, inc;
	if(N % 2 == 0)
	{
		int check = (N / 2);

		if(store2[check] == N)
		{
			printf("Sheet 1, front: Blank, %d\n", store1[1]);
			printf("Sheet 1, back : %d, Blank\n", store2[1]);
			
			inc = 2, cnt = 0, limit = ( (N / 2) - 1) / 2;
			s1i = s2i = 2;
			s1j = s2j = (N / 2);
			while(cnt < limit)
			{
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store2[s2j--], store2[s2i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store1[s1i++], store1[s1j--]);
					
					inc++;
					cnt++;
				}
				
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store1[s1j--], store1[s1i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store2[s2i++], store2[s2j--]);
					
					inc++;
					cnt++;
				}
			}
		}

		else
		{
			inc = 1, cnt = 0, limit = ( N / 4);
			s1i = s2i = 1;
			s1j = s2j = (N / 2);
			while(cnt < limit)
			{
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store1[s1j--], store1[s1i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store2[s2i++], store2[s2j--]);
					
					inc++;
					cnt++;
				}
				
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store2[s2j--], store2[s2i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store1[s1i++], store1[s1j--]);
					
					inc++;
					cnt++;
				}
			}
		}
	}
	else
	{
		printf("Sheet 1, front: Blank, %d\n", store1[1]);

		int check = (N + 1) / 2;
		if(store2[check] == 0)
		{
			printf("Sheet 1, back : %d, Blank\n", store2[1]);
			
			printf("Sheet 2, front: Blank, %d\n", store2[2]);
			printf("Sheet 2, back : %d, %d\n", store1[2], store1[(N + 1) / 2]);
			
			inc = 3, cnt = 0, limit = ( (N / 2) - 1) / 2;
			s1i = s2i = 3;
			s1j = s2j = (N / 2);
			while(cnt < limit)
			{
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store1[s1j--], store1[s1i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store2[s2i++], store2[s2j--]);
					
					inc++;
					cnt++;
				}

				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store2[s2j--], store2[s2i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store1[s1i++], store1[s1j--]);
					
					inc++;
					cnt++;			
				}
			}
		}

		else
		{
			printf("Sheet 1, back : %d, %d\n", store2[1], store2[check]);

			inc = 2, cnt = 0, limit = ( (N / 2) - 1) / 2;
			s1i = s2i = 2;
			s1j = s2j = (N / 2);
			while(cnt < limit)
			{
				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store2[s2j--], store2[s2i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store1[s1i++], store1[s1j--]);
					
					inc++;
					cnt++;
				}

				if(cnt < limit)
				{
					printf("Sheet %d, front: %d, %d\n", inc, store1[s1j--], store1[s1i++]);
					printf("Sheet %d, back : %d, %d\n", inc, store2[s2i++], store2[s2j--]);
					
					inc++;
					cnt++;
				}
			}

		}
	}
}

void read_data()
{
	int i, j, cnt;

	cnt = 1;
	store1[1] = cnt++;

	for(i = 2, j = 1; cnt <= N; )
	{
		if(cnt <= N)
			store2[j++] = cnt++;
		if(cnt <= N)
			store2[j++] = cnt++;
		if(cnt <= N)
			store1[i++] = cnt++;
		if(cnt <= N)
			store1[i++] = cnt++;
	}

	return ;
}

int main()
{
	while(scanf("%d", &N), N)
	{
		if(N == 1)
		{
			printf("Printing order for 1 pages:\n");
			printf("Sheet 1, front: Blank, 1\n");

			continue;
		}

		read_data();

		printf("Printing order for %d pages:\n", N);
		process();
	}
	return 0;
}