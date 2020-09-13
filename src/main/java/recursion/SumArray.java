package recursion;

public class SumArray {

    static int sumArray(int[] array, int length) {
        if (length == 0) {
            return 0;
        }

        return array[length - 1] + sumArray(array, length - 1);
    }

    public static void main(String[] args) {
        int[] array = new int[] {1, 2, 3, 4};
        System.out.println(sumArray(array, array.length));
    }

}
