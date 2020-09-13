package hackerrank.problem;


import common.Commons;

import java.io.IOException;
import java.util.List;
import java.util.stream.Stream;

public class SimpleArraySum {

    static int simpleArraySum(int[] ar) {
        int sum = 0;
        for (int elem : ar) {
            sum += elem;
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {

        List<String> text = Commons.getFilePath("sas.txt");
        int sizeOfArray = Integer.parseInt(text.get(0));
        String elements = text.get(1);

        int[] ar = Stream.of(elements.split("\\s+")).mapToInt(Integer::parseInt).toArray();
        System.out.println(simpleArraySum(ar));

        /*Integer[] arr = Stream.of(elements.split("\\s+")).map(Integer::parseInt).toArray(Integer[]::new);
        for (Integer elem : arr) {
            System.out.println(elem);
        }*/
    }
}
