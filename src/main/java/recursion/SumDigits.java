package recursion;

public class SumDigits {

    static int sumDigits(int n) {
        int remainder = n % 10;
        if (n == 0) {
            return 0;
        }

        return remainder + sumDigits(n / 10);
    }

    public static void main(String[] args) {
        int n = sumDigits(126);
        System.out.println(n);

    }
}
