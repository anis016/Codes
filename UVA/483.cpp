#include<stdio.h> 

int main() 
{ 
  char in[100000], out[100000]; 
  long i= 0, j = 0, k = 0, l = 0; 

  while(gets(in)) 
  { 
     k = i; 
  
      while(in[i] != NULL) 
	  { 
           while( ( (in[i] != ' ' || (in[i]>65 && in[i]<90) || (in[i]>97 && in[i]<122) ) && in[i]) ) 
           i++; 

           for(j = i-1; j >= k; j--, l++) 
           out[l] = in[j]; 

           out[l] = ' '; 

           if(in[i]) 
		   { 
               i++; 
               k = i; 
               l++; 
		   } 
	  } 
           out[l] = '\0'; 
          printf("%s\n", out); 

          i = j = k = l = 0; 
   } 
   return 0;
}
    