#include<stdio.h>
#include<string.h>
int main()
{
	char lin[100];
	int i;
	while(gets(lin))
	{
	   for(i=0;lin[i]!='\0';i++)
	   {
	    
                 if(lin[i]=='W')         printf("Q");
	        else if(lin[i]=='E')         printf("W");
	        else if(lin[i]=='R')         printf("E");
	        else if(lin[i]=='T')         printf("R");
            else if(lin[i]=='Y')         printf("T");
            else if(lin[i]=='U')         printf("Y");
            else if(lin[i]=='I')         printf("U");
            else if(lin[i]=='O')         printf("I");
            else if(lin[i]=='P')         printf("O");


            else if(lin[i]=='S')         printf("A");
            else if(lin[i]=='D')         printf("S");
            else if(lin[i]=='F')         printf("D");
            else if(lin[i]=='G')         printf("F");
            else if(lin[i]=='H')         printf("G");
            else if(lin[i]=='J')         printf("H");
            else if(lin[i]=='K')         printf("J");
            else if(lin[i]=='L')         printf("K");


            else if(lin[i]=='X')         printf("Z");
            else if(lin[i]=='C')         printf("X");
            else if(lin[i]=='V')         printf("C");
            else if(lin[i]=='B')         printf("V");
            else if(lin[i]=='N')         printf("B");
            else if(lin[i]=='M')         printf("N");


            else if(lin[i]=='[')         printf("P");
            else if(lin[i]==']')         printf("[");
            else if(lin[i]=='\\')        printf("]");
            else if(lin[i]==';')         printf("L");
            else if(lin[i]=='\'')        printf(";");
            else if(lin[i]==',')         printf("M");
            else if(lin[i]=='.')         printf(",");
            else if(lin[i]=='/')         printf(".");


           else if(lin[i]=='2')          printf("1");
           else if(lin[i]=='3')          printf("2");
           else if(lin[i]=='4')          printf("3");
           else if(lin[i]=='5')          printf("4");
           else if(lin[i]=='6')          printf("5");
           else if(lin[i]=='7')          printf("6");
           else if(lin[i]=='8')          printf("7");
           else if(lin[i]=='9')          printf("8");
           else if(lin[i]=='0')          printf("9");
           else if(lin[i]=='-')          printf("0");
           else if(lin[i]=='=')          printf("-");
           else if(lin[i]==96)           printf("=");
           else if(lin[i]==' ')          printf(" ");

	   }
	   printf("\n");
	}
	return 0;
}

/*
#include <iostream>            
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <string>
#include <ctype.h>

using namespace std ;

int main(int argc, char *argv[])
{
    string str ;
    char LINE[47] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 91, 93, 92,
                     'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 59, 39,
                     'Z', 'X', 'C', 'V', 'B', 'N', 'M', 44, 46, 47,
                     '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61} ;
    
    while(getline(cin, str, '\n'))
    {
        for(int i = 0; str[i] != '\0'; i++)
        {
            str[i] = toupper(str[i]) ;
            
            if((str[i] == ' ')||(str[i] == '\n'))
                cout << str[i] ;
            else
            {
                for(int j = 1; j < 47; j++)
                {
                    if(str[i] == LINE[j])
                    {
                        cout << LINE[j-1] ;
                        break ;
                    }
                }
            }
        }
        
        cout << endl ;
    }
    
    return(0) ;
} 
*/