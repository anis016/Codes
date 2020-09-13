#include<stdio.h>

int main()
{
 char *letter;
 int count=0, i;

 while(gets(letter))
 {
  for(i=0;letter[i]!='\0'; i++)
  printf("%c", (letter[i]==' ')? letter[i]: letter[i]-7);
  printf("\n");
 }
  return 0;
}

