package recursion;

import java.io.IOException;

public class MaxInArray {

    static int max1(int[] arr, int step, int temp) {
        int current = arr[step];
        if (current >= temp) {
            temp = current;
        }

        if ((arr.length - 1) == step) {
            return temp;
        }

        return max1(arr, step + 1, temp);
    }

    static int max2(int[] arr, int step) {
        int current = arr[step];
        if ((arr.length - 1) == step) {
            return current;
        }

        int m = max2(arr, step + 1);
        System.out.println("step = " + step + ", current = " + arr[step] + ", max = " + m);
        return Math.max(arr[step], m);
    }

    static int secondLargestRecurse(int[] arr, int step, int largest, int secondLargest) {
        if (arr.length == 1) {
            return arr[0];
        }

        if (arr.length == step) {
            return secondLargest;
        }

        int current = arr[step];
        if (current > largest) {
            secondLargest = largest;
            largest = current;
        } else if (current > secondLargest && current < largest) {
            secondLargest = current;
        }

        return secondLargestRecurse(arr, step + 1, largest, secondLargest);
    }

    static int secondLargestIterative(int[] arr) {
        if (arr.length == 1) {
            return arr[0];
        }

        int max, secondMax;
        max = secondMax = -1;
        for (int current : arr) {
            if (current > max) {
                secondMax = max; // second max will be the earlier max
                max = current;   // current max is largest
            } else if (current > secondMax && current < max) { // get the value in between second max and the max
                secondMax = current;
            }
        }

        return secondMax;
    }

    public static void main(String[] args) throws IOException {

        /*BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] list = reader.readLine().split("\\s+");
        reader.close();
        int[] arr = Arrays.stream(list).mapToInt(Integer::parseInt).toArray();*/

        int[] arr = new int[] {7, 4, 5, 9, 8, 19};
        // System.out.println(max1(arr, 0, arr[0]));
        // System.out.println(max2(arr, 0));

        System.out.println(secondLargestRecurse(arr, 0, arr[0], -1));
        System.out.println(secondLargestIterative(arr));
    }
}
