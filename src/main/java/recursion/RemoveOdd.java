package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.stream.Stream;

public class RemoveOdd {
    // move -> moves all the time
    // pos -> moves only when there is an odd number
    static int[] removeOdd(int[] arr, int pos, int move) {
        if (move == arr.length - 1) {
            return arr;
        }

        if (arr[move] % 2 == 0) {
            arr[pos] = arr[move];
            arr[move] = -1;
            pos = pos + 1;
        }
        return removeOdd(arr, pos, move + 1);
    }

    public static void main(String[] args) throws IOException {
        int[] arr;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] list = reader.readLine().split("\\s+");
        arr = Stream.of(list).mapToInt(Integer::parseInt).toArray();
        // System.out.println(Arrays.toString(arr));

        for (int i : removeOdd(arr, 0, 0)) {
            if (i == -1)
                break;
            System.out.println(i);
        }
    }
}
