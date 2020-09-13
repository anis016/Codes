package practice;

/**
 * Check whether a positive number is palindrome.
 */
public class PalindromeNumbers {

    public static boolean isNumberPalindrome(int number) {
        int reverseNumber = 0;
        int copy = number;
        while (number != 0) {
            reverseNumber = reverseNumber * 10 + number % 10;
            number /= 10;
        }

        return copy == reverseNumber;
    }

    public static void test() {
        int num1 = 121;
        int num2 = 122;
        int num3 = 123128937;
        int num4 = 656787656;

        boolean flag1 = isNumberPalindrome(num1);
        System.out.println(flag1 + "--- " + num1);

        boolean flag2 = isNumberPalindrome(num2);
        System.out.println(flag2 + "--- " + num2);

        boolean flag3 = isNumberPalindrome(num3);
        System.out.println(flag3 + "--- " + num3);

        boolean flag4 = isNumberPalindrome(num4);
        System.out.println(flag4 + "--- " + num4);
    }

    public static void main(String... args) {

        test();
    }
}
