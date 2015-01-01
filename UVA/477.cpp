#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100

double RC[MAX][100];
long store[MAX];

int main()
{
	double x, y ;
	char in;
	long i, r, count;
	
	i=r=0;
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
		}
		r++;
	}

	count=0;
	while(1)
    {
        cin >> x >> y ;
        
        if((x == 9999.9)&&(y == 9999.9))
            break ;
        
        bool k = true ;
        count++ ;
        
        for(i = 0; i < r; i++)
        {
            if(store[i]==1 && (x > RC[i][0])&&(x < RC[i][2])&&(y < RC[i][1])&&(y > RC[i][3]))
            {               
                cout << "Point " << count << " is contained in figure " << i+1 << endl ;
				k = false ;
            }
            
            if(store[i]==0 && (sqrt(pow(x-RC[i][0], 2) + pow(y-RC[i][1], 2)) < RC[i][2]))
            {
                cout << "Point " << count << " is contained in figure " << i+1 << endl ;
				k = false ;
            }
        }
        
        if(k==true)
            cout << "Point " << count << " is not contained in any figure\n" ;
    }
    
    return(0) ;
}
