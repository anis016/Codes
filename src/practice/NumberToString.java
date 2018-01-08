package practice;

/**
 * Convert a Number to String.
 */
public class NumberToString {

    public static String numberToString(int number) {
        StringBuilder sb = new StringBuilder();
        boolean isNeg = number < 0;
        boolean isZero = number == 0;

        if (isNeg) {
            number *= -1;
        }

        if (isZero) {
            sb.append("0");
        }

        while (number != 0) {
            sb.append(number % 10);
            number /= 10;
        }

        return isNeg ? "-" + sb.reverse().toString() : sb.reverse().toString();
    }

    public static void main(String... args) {

        String res;

        res = numberToString(1234134);
        System.out.println(res);

        res = numberToString(-6672834);
        System.out.println(res);

        res = numberToString(0);
        System.out.println(res);
    }
}
