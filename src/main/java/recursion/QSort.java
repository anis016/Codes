package recursion;

import java.util.Arrays;

public class QSort {


    static int[] qSort(int[] arr, int start, int end) {
        if (start < end) {
            int pivotIndex = partition(arr, start, end); // get the pivot index
            qSort(arr, start, pivotIndex - 1); // sort 1st half excluding the pivot
            qSort(arr, pivotIndex + 1, end); // sort 2nd half excluding the pivot
        }
        return arr;
    }

    static int partition(int[] arr, int start, int end) {
        int pivot = arr[end]; // consider initial pivot position is at the end
        int pivotIndex = start; // pivot index is the start index. Scan the pivot from start
        for (int i = start; i < end; i++) { // till the end
            if (arr[i] <= pivot) { // left side should be smaller than the pivot and right side should be greater than the pivot
                swap(arr, i, pivotIndex); // swap the pivot index'ed element and current element
                pivotIndex++; // increment pivot index
            }
        }
        swap(arr, end, pivotIndex); // at the end swap the pivotIndex with initial pivot position
        return pivotIndex; // return the pivot index
    }

    static void swap(int[] arr, int a, int b) {
        int temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }


    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 6, 8, 0, 99, 8, 9, 5, 3, 7};
        System.out.println(Arrays.toString(qSort(arr, 0, arr.length - 1)));
    }
}
