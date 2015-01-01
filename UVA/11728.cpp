#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
#define MAXIM 1001

vector<int>factor[MAXIM + 100];
int a[MAXIM + 100], prime[MAXIM + 100];
bool fact[MAXIM + 100];

void initp()
{
	int i, j, t, k;
	int M = (int)sqrt(MAXIM);

	for(i = 3; i <= M; i+=2)
		if(a[i] == 0)
		{
			for(j = i * i; j <= MAXIM; j += 2 * i)
				a[j] = 1;
		}

	for(k = 3, t = 1; k <= MAXIM; k += 2)
		if(a[k] == 0)
		{
			fact[k] = true;
			prime[t++] = k;
		}
	fact[2] = true;
	prime[0] = 2;
}

void initf()
{
	int i;
	for(i = 0; i <= MAXIM; i++)
		factor[i].clear();
}

void init_factor()
{
	int i, j, c;
	
	factor[1].push_back(1);
	for(i = 2; i <= MAXIM; i++)
	{
       c = 0;
       for(j = 1; j * j <= i; j++)
       {
             if(j * j == i)
                  factor[i].push_back(j);
             else if(i % j == 0)
             {
                  factor[i].push_back(j);
                  factor[i].push_back(i / j);
             }                  
       }
    }	
	return ;
}

int main()
{
	int Case = 1, s, n, m, i, flag;

	initp();
	initf();
    init_factor();
    	
	while(scanf("%d", &m) == 1)
	{
        flag = 0;
        s = m;
        s--;
        
        if(m == 1)
        {
           printf("Case %d: %d\n", Case++, 1);
           continue;
        }
           
		if(!m)
			break;
		
		while(1)
		{
      		int sum = 0;
    
            for(i = 0; i < factor[s].size(); i++)
                    sum += factor[s][i];
            
            if(sum == m)
               break;
            
            s--;
            if(s < 1)
            {
                flag =1;
                break;
            }
        }
        
        if(flag == 0)
             printf("Case %d: %d\n", Case++, s);
        else
             printf("Case %d: %d\n", Case++, -1);
	}

//    getch();
	return 0;
}
