package hackerrank.introduction;

import java.util.Scanner;

public class StaticInitializerBlock {
    static int B;
    static int H;
    static boolean flag;

    static {
        Scanner input = new Scanner(System.in);
        B = input.nextInt();
        H = input.nextInt();
        input.close();

        flag = false;
        try {
            if (B > 0 && H > 0) {
                flag = true;
            } else {
                throw new Exception("java.lang.Exception: Breadth and height must be positive");
            }
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        if(flag) {
            int area=B * H;
            System.out.print(area);
        }
    }
}
