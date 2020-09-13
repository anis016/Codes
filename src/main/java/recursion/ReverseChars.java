package recursion;

public class ReverseChars {

    static void reverse(char[] str, int l, int r) {
        if (l > r) {
            System.out.println(str);
            return ;
        }

        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;

        reverse(str, l + 1, r - 1);
    }

    public static void main(String[] args) {
        char[] str = {'a', 'b', 'c'};
        // char[] s = new char[] {'1', '2', '3'};
        reverse(str, 0, str.length - 1);
    }
}
