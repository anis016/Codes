#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

int main()
{
	char input[2200][400], ch, other[60000], xx[10000];
	long test, i, j, count;
	
	gets(xx);
	sscanf(xx, "%ld", &test);

	for(i=0; i<test; i++)
	{
		scanf("%s%c", input[i], &ch);
		  gets(other);
	}

	qsort((void *)input, test, sizeof(input[0]), sorting);  ////doing sorting for string type

	count=1;
	for(j=0; j<test; j++)
	{
	   if( strcmp(input[j],input[j+1])==0 )
		  count++;
	   else	  
	   {
		  printf("%s %ld\n", input[j], count);
		  count=1;                              ////////critical part but why???????
	   }
	   
	}
	return 0;

}