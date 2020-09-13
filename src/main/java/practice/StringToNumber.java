package practice;

/**
 * Convert a String to Number.
 */
public class StringToNumber {

    // 12345 = 5 x 1 + 4 x 10 + 3 x 100 + 2 x 1000 + 1 x 10000
    public static int stringToNumber1(String string) {
        int res = 0;
        int n = 1;
        int neg = 1;

        // check for null
        if (string == null) {
            throw new NullPointerException("Null Pointer !");
        }

        // check negative
        if (string.startsWith("-")) {
            neg = -1;
            string = string.substring(1, string.length());
        }

        int stringLength = string.length() - 1;
        for(int i = stringLength; i >= 0; i--) {
            res += (string.charAt(i) - '0') * n;
            n *= 10;
        }

        return res * neg;
    }

    // Better Solution
    // 367 =
    //  0 x 10 + 3 = 3
    //  3 x 10 + 6 = 36
    // 36 x 10 + 7 = 367
    public static int stringToNumber2(String string) {
        int res = 0;
        int neg = 1;

        // check for null
        if (string == null) {
            throw new NullPointerException();
        }

        // check for negative
        if (string.startsWith("-")) {
            neg = -1;
            string = string.substring(1, string.length());
        }

        int stringLength = string.length();
        for (int  i = 0; i < stringLength; i++) {
            res = res * 10 + (string.charAt(i) - '0');
        }

        return res * neg;
    }

    public static void main(String... args) {

        int res1;

        res1 = stringToNumber1(null);
        System.out.println(res1);

        res1 = stringToNumber2("887685657");
        System.out.println(res1);

        res1 = stringToNumber2("");
        System.out.println(res1);

        res1 = stringToNumber2("-11323");
        System.out.println(res1);

        /*int res2 = stringToNumber2("3129837");
        System.out.println(res2);*/
    }
}
