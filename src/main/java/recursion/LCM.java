package recursion;

public class LCM {

    static int lcm(int a, int b, int step) {
        if(a * step % b == 0) {
            return a * step;
        }
        return lcm(a, b, step + 1);
    }

    public static void main(String[] args) {
        System.out.println(lcm(12, 30, 1));
    }
}
