package datastructures.queue;

import datastructures.stack.Stack;

public class DemoQueue {

    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(4);
        queue.enqueue(2);
        queue.enqueue(5);
        queue.enqueue(13);
        System.out.println(queue);

        System.out.println("dequeued " + queue.dequeue());
        System.out.println(queue);
    }
}
