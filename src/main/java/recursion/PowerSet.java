package recursion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
* Power Set
* The set of all subsets of a particular set S, including the empty set [] and the set S itself.
* set = [1, 2, 3]
* Power sets = [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]
*
* */

public class PowerSet {

    static void combination_list(List<Integer> elements, int current, List<List<Integer>> results, List<Integer> path) {

        if (current == elements.size()) {
            results.add(path);
            return ;
        }

        List<Integer> pathListWithCurrentElement = new ArrayList<>(path);
        int currentElement = elements.get(current);
        pathListWithCurrentElement.add(currentElement);

        // including the current element
        combination_list(elements, current + 1, results, pathListWithCurrentElement);

        // excluding the current element
        combination_list(elements, current + 1, results, path);
    }

    public static void main(String[] args) {
        List<Integer> sets = Arrays.asList(1, 2, 3);
        List<List<Integer>> results = new ArrayList<>();
        combination_list(sets, 0, results, new ArrayList<>());
        System.out.println(results);
    }
}
