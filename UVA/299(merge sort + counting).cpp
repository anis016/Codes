#include<stdio.h>
#include<stdlib.h>

/*

merge-and-count(A,B)
  ;  A,B two input lists (sorted)
  ;  C  output list
  ;  i,j current pointers to each list, start at beginning
  ;  a_i, b_j elements pointed by i, j
  ;  count number of inversion, initially 0

  while A,B != empty
    copy min(a_i,b_j) to C
    if b_j < a_i 
       count += number of element remaining in A
       j++
    else
       i++
  ; now one list is empty
  copy the remainder of the list to C
  return count, C

*/

long Merge(long *A, long n1, long *B, long n2, long *C)
{
	long i, j, count = 0, k;

	i = j = k = 0;
	while( (i < n1) && (j < n2) )
	{
		if(A[i] <= B[j])
		{
			C[k] = A[i];
			k++;
			i++;
		}
		else
		{
			C[k] = B[j];
			count += (n1 - i);
			j++;
			k++;
		}
	}

	for( ; i<n1; i++)
	{
		C[k] = A[i];
		k++;
	}

	for( ; j<n2; j++)
	{
		C[k] = B[j];
		k++;
	}

	return count;
}

/*

  sort-and-count(L)
  if L become less then 2 return 0
  else
     divide L into A, B 
	 copy first to mid to A copy from mid to last to B
     (rA, A) = sort-and-count(A)
     (rB, B) = sort-and-count(B)
     (r, L) = merge-and-count(A,B)
  return r = rA+rB+r, L

*/

long Merge_Sort(long *A, long L)
{
	long i, *A1, *A2, n1, n2, r1, r2, r;
	
	if(L < 2)
		return 0;
	
	n1 = (L / 2);
	n2 = L - n1;
	
	A1 = (long*)malloc(sizeof(long) * n1);
	A2 = (long*)malloc(sizeof(long) * n2);
	
	for(i=0; i<n1; i++)
		A1[i] = A[i];
	
	for(i=0; i<n2; i++)
		A2[i] = A[n1+i];
	
	r1 = Merge_Sort(A1, n1);
	r2 = Merge_Sort(A2, n2);
	r  = Merge(A1, n1, A2, n2, A);

	return (r1 + r2 + r);
}

int main()
{
	long N, i, num, *A, Case;

	scanf("%ld", &Case);
	while(Case--)
	{
		scanf("%ld", &N);
		A = (long *)malloc(sizeof(long) * N);
		
		for(i=0; i<N; i++)
			scanf("%ld", &A[i]);
		
		num = Merge_Sort(A, N);
		
/*		for(i=0; i<N; i++)
			printf("%ld ", A[i]); */
		
		printf("Optimal train swapping takes %ld swaps.\n", num);
	}
	return 0;
}