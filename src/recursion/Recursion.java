package recursion;

/**
 * Unwind until I get something to stop the computations.
 */
public class Recursion {

    /**
     * a x b = a(1) + a(2) + a(3) + .... + a(b)
     * mult(a, b) = a + mult(a, (b-1))
     *              returns a if b == 1 (base case)
     *
     * example:
     * 3 x 5 = 3 + mult(3, 5)
     *       =     3 + mult(3, 4)
     *       =         3 + mult(3, 3)
     *       =             3 + mult(3, 2)
     *       =                 3 + mult(3, 1) => mult(3, 1) returns 3, as b == 1
     *       =                 3 => returns 3
     *       =             6 => returns 3 + 3 = 6
     *       =         9 => returns 3 + 6 = 9
     *       =     12 => returns 3 + 9 = 12
     *       = 15 => returns 3 + 12 = 15
     */
    static int multiplication(int a, int b) {

        if (b == 1) {
            return a;
        }

        return a + multiplication(a, b-1);
    }

    /**
     * a! = a x (a - 1) X (a - 2) X .... X 1
     * fact(a) = a x fact(a - 1)
     *           returns 1 if a == 1 (base case)
     *
     * example:
     * 5! = 5 x fact(4)
     *    =     4 x fact(3)
     *    =         3 x fact(2)
     *    =             2 x fact(1) => fact(1) returns 1, as a == 1
     *    =             2 => returns 2 X 1 = 2
     *    =         6 => returns 3 X 2 = 6
     *    =     24 => returns 4 X 6 = 24
     *    = 120 => returns 5 X 24 = 120
     */
    static int factorial(int a) {

        if (a == 1) {
            return 1;
        }

        return a * factorial(a - 1);
    }

    /**
     * fibonacci series = 0, 1, 1, 2, 3, 5, 8, 13 ...
     * nth term = (n-1)th term + (n-2)th term
     *
     * fibo(a) = fibo(a - 1) + fibo(a - 2)
     *           returns 1 if fibo(1) or 0 if fibo(0) (base case)
     *
     * example:
     * fibo(4) = fibo(3) + 'fibo(2)'
     * fibo(3) = fibo(2) + 'fibo(1)'
     * fibo(2) = fibo(1) + 'fibo(0)'
     *           fibo(1) = 1 ==> fibo(1) returns 1
     * fibo(2) = 1 + fibo(0)
     *               fibo(0) = 0 ==> fibo(0) returns 0
     * fibo(2) = 1 + 0 = 1; returns 1
     * fibo(3) = 1 + fibo(1)
     *         =     fibo(1) = 1 ==> fibo(1) returns 1
     * fibo(3) = 1 + 1 = 2; returns 2
     * fibo(4) = 2 + fibo(2)
     *         =     fibo(1) + 'fibo(0)'
     *         =     fibo(1) = 1 ==> fibo(1) returns 1
     *         =     1 + fibo(0)
     *         =     1 + fibo(0) = 0 ==> fibo(0) returns 0
     *         =     1 + 0 = 1; returns 1
     *         = 2 + 1
     *         = 3
     */
    static int fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    /**
     * "ababa"
     */
    static boolean palindrome(String text, int start, int end) {

        if (start > text.length() / 2) {
            return true;
        }

        if (text.charAt(start) == text.charAt(end)) {
           return palindrome(text, start + 1, end - 1);
        } else {
            return false;
        }
    }

    public static void main(String... args) {

        int mul = multiplication(3, 5);
        print("Multiplication: " + mul);

        int fact = factorial(5);
        print("Factorial: " + fact);

        int fibo = fibonacci(4);
        print("Fibonacci: " + fibo);

        String text = "abaaba";
        boolean palin = palindrome(text, 0, text.length() - 1);
        print("Palindrome: " + palin);
    }

    static void print(Object ob) {
        System.out.println(ob);
    }

}
