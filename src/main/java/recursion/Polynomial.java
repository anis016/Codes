package recursion;

public class Polynomial {

    static void generatePoly(int x, int n, int step) {
        if (n == step) {
            return ;
        }

        if (step == 0) {
            System.out.print(step + 1);
        } else {
            System.out.printf(" + %d^%d", x, step);
        }
        generatePoly(x, n, step + 1);
    }

    static int evalPoly(int x, int n) {
        if ( n == 0) {
            return (int) Math.pow(x, n);
        }

        return (int) Math.pow(x, n) + evalPoly(x, n - 1);
    }


    public static void main(String[] args) {
        int x, n;

        x = 5;
        n = 5;
        generatePoly(x, n, 0);
        System.out.print(" = ");
        System.out.println(evalPoly(x, n - 1));

        x = 2;
        n = 5;
        generatePoly(x, n, 0);
        System.out.print(" = ");
        System.out.println(evalPoly(x, n - 1));
    }
}
