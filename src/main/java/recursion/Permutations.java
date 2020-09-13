package recursion;

import java.util.ArrayList;
import java.util.List;

public class Permutations {

    // https://www.redgreencode.com/recursion-see-recursion/
    static void permute(String prefix, String str, List<String> output) {
        int strLength = str.length();
        // base case: when the current string length is empty
        if (strLength == 0) {
            output.add(prefix);
            // System.out.println(prefix);
        } else {
            for (int i = 0; i < strLength; i++) {
                // take a character from the current string
                String characterFromStr = String.valueOf(str.charAt(i));
                // add this character at the end of the prefix
                String newPrefix = prefix + characterFromStr;
                // form a new string by removing this character
                String newStr = str.substring(0, i) + str.substring(i + 1, strLength);
                // recurse
                permute(newPrefix, newStr, output);
            }
        }
    }

    public static void main(String[] args) {
        String str = "abc";
        List<String> output = new ArrayList<>();
        permute("", str, output);
        System.out.println(output);
    }
}
