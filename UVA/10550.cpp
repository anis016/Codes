#include <iostream>          
#include <cstdlib>

using namespace std ;

int main()
{
    int s ;
    int a, b, c ;
    
    while(cin >> s >> a >> b >> c)
    {
        if(!s && !a && !b && !c)
            break ;
        
        int degree = 0 ;
        degree += 720 ;
        int x = s - a ;
        
        if(x < 0)
            x += 40 ;
        
        x *= 9 ;
        degree += x ;
        
        degree += 360 ;
        x = b - a ;
        
        if(x < 0)
            x += 40 ;
        
        x *= 9 ;
        degree += x ;
        x = b - c ;
        
        if(x < 0)
            x += 40 ;
        
        x *= 9 ;
        degree += x ;
        
        cout << degree << endl ;
    }
    
    return(0) ;
} 
