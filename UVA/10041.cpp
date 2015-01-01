#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int relatives,rood[30002],i,j,mid;
long sum,test;


void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;

  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
	  while ((numbers[right] >= pivot) && (left < right))
		  right--;

	  if(left != right)
	  {
		  numbers[left] = numbers[right];
		  left++;
	  }
	  
	  while ((numbers[left] <= pivot) && (left < right))
		  left++;
	  
	  if (left != right)
	  {
		  numbers[right] = numbers[left];
		  right--;
	  }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  
  if (left < pivot)
	  q_sort(numbers, left, pivot-1);
  if (right > pivot)
	  q_sort(numbers, pivot+1, right);
}


void quickSort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}


int main()
{
    while(scanf("%ld",&test)==1)
    {
          for(i=0;i<test;i++)
          {
           scanf("%d",&relatives);
           
		   for(j=0;j<relatives;j++)
			   scanf("%d",&rood[j]);


           quickSort(rood,relatives);

           mid=ceil(double(relatives/2.0))-1;
           
		   sum=0;           
		   for(j=0;j<relatives;j++)
			   sum+=abs(rood[mid]-rood[j]);
           
		   printf("%ld\n",sum);
          }
    }
	return 0;
}