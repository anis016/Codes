package recursion;

public class ReverseInteger {

    static int[] reverse1(int[] orig, int[] rev, int start, int end) {
        if (start == orig.length) {
            return rev;
        }

        rev[start] = orig[end];
        return reverse1(orig, rev, start + 1, end - 1);
    }

    static int[] reverse2(int[] orig, int start, int end) {
        if (start < end) {
            int val1 = orig[start];
            int val2 = orig[end];

            // swap values
            orig[start] = val2;
            orig[end] = val1;

            reverse2(orig, start + 1, end - 1);
        }
        return orig;
    }

    static int[] reverse3(int[] orig, int start, int end) {
        if (start < end) {
            reverse3(orig, start + 1, end - 1);
        }
        int val1 = orig[start];
        int val2 = orig[end];

        // swap values
        orig[start] = val2;
        orig[end] = val1;
        return orig;
    }

    public static void main(String[] args) {
        int[] arr  = new int[] {69, 87, 45, 21, 47};
        /*for (int elem: reverse1(arr, new int[arr.length], 0, arr.length - 1)) {
            System.out.println(elem);
        }
        System.out.println();

        for (int elem: reverse2(arr, 0, arr.length - 1)) {
            System.out.println(elem);
        }
        System.out.println();*/

        for (int elem: reverse3(arr, 0, arr.length - 1)) {
            System.out.println(elem);
        }
    }
}
