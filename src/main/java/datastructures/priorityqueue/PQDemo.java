package datastructures.priorityqueue;

public class PQDemo {

    public static void main(String[] args) {
        BinaryHeap heap = new BinaryHeap(new Integer[] {4, 10, 3, 5, 1});
        System.out.println(heap);
        System.out.println(heap.isMinHeap(0));
        System.out.println(heap.poll());
        System.out.println(heap.poll());
        System.out.println(heap.poll());
        System.out.println(heap.poll());
        System.out.println(heap.poll());
    }
}
