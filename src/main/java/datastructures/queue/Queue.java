package datastructures.queue;

import java.util.Iterator;
import java.util.LinkedList;

public class Queue<T> implements Iterable<T> {

    LinkedList<T> queue;

    public Queue() {
        queue = new LinkedList<>();
    }

    public int getSize() {
        return queue.size();
    }

    public boolean isEmpty() {
        return getSize() == 0;
    }

    public void enqueue(T data) {
        queue.addLast(data);
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        return queue.removeFirst();
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        return queue.getFirst();
    }

    @Override
    public Iterator<T> iterator() {
        return queue.iterator();
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Queue=[");
        if (isEmpty()) {
            return sb.append("]").toString();
        }
        for (int i = 0; i < getSize() - 1; i++) {
            sb.append(queue.get(i)).append(", ");
        }
        sb.append(queue.get(getSize() - 1)).append("]");
        return sb.toString();
    }
}
