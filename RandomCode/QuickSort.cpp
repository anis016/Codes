/*
ID: anis.cu1
LANG: C++
PROB:
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning (disable : 4789)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<ctime>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))
#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)
#define MAX 10

void Swap(int *Array, int &a, int &b) {
	int temp;
	temp = Array[a];
	Array[a] = Array[b];
	Array[b] = temp;
}
 
void print(int *Array, int start, int last) {
	for(int i = start; i < last; i++) {
		printf("%d ", Array[i]);
	}
	printf("\n");
}

// Given an array, the quicksort will partition the array such that all the elements before the piviot will be les then or equals to the pivot
// and all the elements after the pivot will be greater then or equal to the pivot
// Array[] => holder of the integer items, p => 1st position of the array to be partitioned, r => last position of the array to be partitioned
// Runtime for the partition is O(n) since the j is scanning all the elements from the the 1st position to r - 1 position
int partitionList(int *Array, int p, int r) {

	int lastElement = Array[r]; // Consider the pivot as the last element
	int j, i = p - 1; // i -> 1st pointer before which all the elements are less then the pivot. Initially it points to -1 since no scanning is done.
					  // j -> between i and j all the elements are greater then the pivot
	for(j = p; j < r; j++) { // j -> starts scanning from the 1st element till the last element before the pivot to find a element less then the pivot
		if(Array[j] <= lastElement) { // if such element is found
			i++; // increment the ith value so that to show a element is found
			Swap(Array, j, i); // swap that particular element with the current jth element
		}
	}
	i = i + 1; // last value greater then pivot
	r = r; // last element
	Swap(Array, i, r); // the pivoted element is swaped with the last greatest value and the pivot is now in its confirmed position
	print(Array, p, i+1);
	return i; // returning the array position of which left to be sorted and the right to be sorted again.
}
// if pivot is p then below recursion tree is created.
/*
							partition(Array, 0, r) // suppose there are r elements
									|
									|
					  -------------------------------
					  |		   	    |				|
					  |			    |				|
		partition(Array, 0, p-1)    p	  partition(Array, p+1, r) // at the end of the partition function call p is in its correct postion.
																   // now recursively we need to sort out the  0 -> p-1 and p+1 -> r elements.
*/

void quickSort(int *Array, int p, int r) {

	if(p < r) {
		int pivot = partitionList(Array, p, r);
		quickSort(Array, p, pivot - 1);
		quickSort(Array, pivot + 1, r);
	}
}

int main() {

	int Array[] = {13,19,9,5,12,8,7,4,21,2,6,11};
	int length = 12;

	quickSort(Array, 0, length-1);
	print(Array, 0, length);
}