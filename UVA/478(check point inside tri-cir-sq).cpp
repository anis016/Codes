#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100

double RC[MAX][100];
long store[MAX];

int triangle(double px, double py, long tt)
{
	double area1, area2, area3, area4, sum;
	area1=area2=area3=area4=sum=0.0;
	
	area1 = (.5)*fabs((RC[tt][0]*(RC[tt][3] - RC[tt][5]) - RC[tt][1]*(RC[tt][2] - RC[tt][4]) + (RC[tt][2]*RC[tt][5] - RC[tt][4]*RC[tt][3])));
	
	area2 = (.5)*fabs((px*(RC[tt][1] - RC[tt][5]) - py*(RC[tt][0] - RC[tt][4]) + (RC[tt][0]*RC[tt][5] - RC[tt][4]*RC[tt][1])));
	area3 = (.5)*fabs((px*(RC[tt][1] - RC[tt][3]) - py*(RC[tt][0] - RC[tt][2]) + (RC[tt][0]*RC[tt][3] - RC[tt][2]*RC[tt][1])));
	area4 = (.5)*fabs((px*(RC[tt][3] - RC[tt][5]) - py*(RC[tt][2] - RC[tt][4]) + (RC[tt][2]*RC[tt][5] - RC[tt][4]*RC[tt][3])));
	
	sum=area2+area3+area4;
	if(fabs(sum - area1)<=.000001) 
		return 1;
	else
		return 0;
}

int main()
{
	double x, y ;
	char in;
	long i, r, count;
	
	r=0;
	while(1)
	{
		cin>>in;

		if(in=='*')
			break;
		else
		{			
			if(in=='c')
			{
				cin>>RC[r][0]>>RC[r][1]>>RC[r][2];
				store[r]=0;
			}
			else if(in=='r')
			{
				cin>>RC[r][0]>>RC[r][1]>>RC[r][2]>>RC[r][3];
				store[r]=1;
			}
			else if(in=='t')
			{
				cin>>RC[r][0]>>RC[r][1]>>RC[r][2]>>RC[r][3]>>RC[r][4]>>RC[r][5];
				store[r]=2;
			}
		}
		r++;
	}

	count=0;
	while(1)
    {
        cin>>x>>y ;
        
        if((x == 9999.9)&&(y == 9999.9))
            break ;
        
        bool k = true ;
        count++ ;
        
        for(i=0; i<r; i++)
        {
            if(store[i]==1 && (x > RC[i][0])&&(x < RC[i][2])&&(y < RC[i][1])&&(y > RC[i][3]))
            {               
                cout << "Point " << count << " is contained in figure " << i+1 << endl ;
				k=false ;
            }
            
            if(store[i]==0 && (sqrt(pow(x-RC[i][0], 2) + pow(y-RC[i][1], 2)) < RC[i][2]))
            {
                cout << "Point " << count << " is contained in figure " << i+1 << endl ;
				k=false ;
            }

			if((store[i]==2) && triangle(x, y, i)==1)
			{
				cout << "Point " << count << " is contained in figure " << i+1 << endl ;
				k=false;
			}
        }
        
        if(k==true)
            cout << "Point " << count << " is not contained in any figure\n" ;
    }
    
    return 0;
}
