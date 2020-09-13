package recursion.dc;

import java.util.Arrays;

public class MSort {

    static void mSort(int[] arr) {
        int len = arr.length;
        if (len < 2) {
            return ;
        }

        int mid = len / 2; // partition the array in the middle
        int[] left = new int[mid]; // left -> left of the array till mid from 0
        int[] right = new int[len - mid]; // right -> right of the array till the end from mid

        // copy left side
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }

        // copy right side
        for (int i = 0; i < (len - mid); i++) {
            right[i] = arr[mid + i];
        }

        mSort(left); // divide left
        mSort(right); // divide right
        merge(left, right, arr); // combine left and right
    }

    static void merge(int[] left, int[] right, int[] combine) {
        int lLen = left.length;
        int rLen = right.length;
        int l = 0;
        int r = 0;
        int c = 0;

        while (l < lLen && r < rLen) {
            if (left[l] <= right[r]) {
                combine[c] = left[l];
                l++;
            } else {
                combine[c] = right[r];
                r++;
            }
            c++;
        }

        while (l < lLen) {
            combine[c] = left[l];
            l++;
            c++;
        }

        while (r < rLen) {
            combine[c] = right[r];
            r++;
            c++;
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 6, 8, 0, 99, 8, 9, 5, 3, 7, 7};
        mSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
