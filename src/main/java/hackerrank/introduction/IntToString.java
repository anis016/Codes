package hackerrank.introduction;

import java.util.Scanner;

public class IntToString {

    public static void main(String[] args) {

        try {
            Scanner in = new Scanner(System.in);
            int n = in .nextInt();
            in.close();

            String s = String.valueOf(n);
            // String s = Integer.toString(n);

            if (n == Integer.parseInt(s)) {
                System.out.println("Good job");
            } else {
                System.out.println("Wrong answer.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
