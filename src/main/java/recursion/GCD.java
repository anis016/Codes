package recursion;

public class GCD {

    static int gcd(int a, int b) {
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        } else {
            int r = a % b;
            return gcd (b, r);
        }
    }

    public static void main(String[] args) {
        System.out.println(gcd(270, 192));
        System.out.println(gcd(25, 8895));
        System.out.println(gcd(8895, 25));
    }
}
