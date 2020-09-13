package datastructures.queue;

import java.util.Arrays;

public class DemoFastQueue {

    public static void main(String[] args) {
        FastIntQueue q = new FastIntQueue(5);

        q.offer(1);
        q.offer(2);
        q.offer(3);
        q.offer(4);
        q.offer(5);

        System.out.println(q.poll()); // 1
        System.out.println(q.poll()); // 2
        System.out.println(q.poll()); // 3
        System.out.println(q.poll()); // 4

        System.out.println(q.isEmpty()); // false

        q.offer(7);
        q.offer(8);
        q.offer(9);

        System.out.println(q.poll()); // 5
        System.out.println(q.poll()); // 7
        System.out.println(q.poll()); // 8
        System.out.println(q.poll()); // 9

        System.out.println(q.isEmpty()); // true
    }
}
