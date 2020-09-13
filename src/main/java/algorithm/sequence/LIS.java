package algorithm.sequence;

/**
 * Longest Increasing Subsequence
 * LIS - O(MxN) solution
 * Idea: https://www.youtube.com/watch?v=4fQJGoeW5VE
 *
 * Problem: For a vector D of size n, find its LIS.
 *
 * Define Vector L or 2D array L[][]:
 * 		 L[i] == A vector, LIS of D that ends with D[i].
 * 		 L[0] == {D[0]}
 * Example:
 * input: {3, 2, 6, 4, 5, 1}  ... index {0, 1, 2, 3, 4, 5}
 * L[0]: 3
 * L[1]: 2
 * L[2]: 2, 6
 * L[3]: 2, 4
 * L[4]: 2, 4, 5 --> this is the LIS (output)
 * L[5]: 1
 */

public class LIS {

	// initialize array with random value that will not appear in the input array
	static int[][] init_array(int len) {
		
		int[][] L = new int[len][len];
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++)
				L[i][j] = -Integer.MIN_VALUE;
	    return L;
	}

	// get the maximum length of the current array
	static int getMaxLen_L(int[] L) {
		int i;
		for(i = 0; i < L.length; i++) {
			if(L[i] == -Integer.MIN_VALUE)
				break;
		}
		return i;
	}

	static void LIS(int[] D) {
		int maxLengthIndex = -Integer.MIN_VALUE;

		int len = D.length;
		int i, j, k;
		int[][] L = init_array(len);

		L[0][0] = D[0];
		for(i = 1; i < len; i++) {

			int max = -1;
			int index = -1;
			for(j = 0; j < i; j++) {         // look for every tail of L which is less than current D[i]
				int lj_length = getMaxLen_L(L[j]); // get the current L max length
				int dj = L[j][lj_length-1];  // tail of L
				int di = D[i];               // tail of D (current one)

				if(dj < di) {                // if tail of L is smaller than current value D[i] then consider it
					if(lj_length >= max) {   // check for the max of the L's length and equal means, work with the latest L index
						max = lj_length;
						index = j;
						maxLengthIndex = i;
					}
				}
			}
			if(max == -1) {
				L[i][0] = D[i]; // if nothing is found, only append the current one
			} else {
				for(k = 0; k < getMaxLen_L(L[index]); k++) { // copy that index which is of max length found
					L[i][k] = L[index][k];
				}
				L[i][k] = D[i];  // append the current one at the end
			}
		}

		printLIS(L[maxLengthIndex]);
	}

	static void printLIS(int[] L) {
		int counter = 0;
		for(int i = 0; i < L.length; i++) {
			if(L[i] == -Integer.MIN_VALUE)
				break;
			counter++;
			System.out.print(L[i] + ", ");
		}
		System.out.println("\nHighest Length: " + counter);
	}
	
	public static void main(String[] args) {
		
		int[] data = {3, 2, 6, 4, 5, 1};
		LIS(data);
	}
}
