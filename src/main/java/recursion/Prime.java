package recursion;

public class Prime {

    static boolean isPrime1(int n, int step) {
        if (n == 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n == 3) {
            return true;
        } else {
            if (step < n) {
                int reminder = n % step;
                if (reminder == 0) {
                    return false; // step is less than n and divisor found
                } else {
                    return isPrime1(n, step + 1); // step is less than n and divisor not found
                }
            } else {
                return true; // step exceeded n and no divisor found
            }
        }
    }

    static boolean isPrime2(int n, int step) {
        if (n < 2) {
            return false;
        } else if (n == step) {
            return true;
        } else if (n % step == 0) {
            return false;
        }  else {
            return isPrime2(n, step + 1);
        }
    }

    static boolean isPrime3(int n, int step, int limit) {
        if (n < 2) {
            return false;
        } else if (step > limit) {
            return true; // found prime
        }
        else if (n % step == 0) {
            return false; // not prime
        } else {
            return isPrime3(n, step + 1, limit); // recurse
        }
    }

    public static void main(String[] args) {

        for (int i = 1; i <= 100; i++) {
            boolean prime = isPrime1(i, 2);
            if (prime) {
                System.out.print(i + ", ");
            }
        }
        System.out.println();

        for (int i = 1; i <= 100; i++) {
            boolean prime = isPrime2(i, 2);
            if (prime) {
                System.out.print(i + ", ");
            }
        }
        System.out.println();

        for (int i = 1; i <= 100; i++) {
            boolean prime = isPrime3(i, 2, (int) Math.sqrt(i));
            if (prime) {
                System.out.print(i + ", ");
            }
        }
    }
}
