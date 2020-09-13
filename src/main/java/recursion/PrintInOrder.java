package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.stream.Stream;

public class PrintInOrder {

    static int[][] print(int[] arr, int[][] temp, int step, int start, int end) {
        if (start > end) {
            return temp;
        }

        // step is un-necessary, not needed. could be also start
        temp[step][0] = arr[start];
        temp[step][1] = arr[end];
        return print(arr, temp, step + 1, start + 1, end - 1);
    }

    public static void main(String[] args) throws IOException {
        int[] arr;
        int[][] temp;

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] list = reader.readLine().split("\\s+");
        arr = Stream.of(list).mapToInt(Integer::parseInt).toArray();
        // System.out.println(Arrays.toString(arr));

        int step = (int) Math.ceil(n / 2.0);
        temp = new int[step][2];

        for (int[] i : print(arr, temp, 0, 0, arr.length - 1)) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
