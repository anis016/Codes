package datastructures.stack;

public class DemoStack {

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(4);
        stack.push(2);
        stack.push(5);
        stack.push(13);
        System.out.println(stack);

        stack.pop();
        System.out.println(stack);

        System.out.println(stack.contains(5));
        System.out.println(stack.contains(13));

        for (Integer data : stack) {
            System.out.println(data);
        }
    }
}
