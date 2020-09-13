package datastructures.queue;

import java.util.Iterator;

public class FastIntQueue implements Iterable<Integer> {

    int[] data;
    int front, end, size;

    public FastIntQueue(int maxSize) {
        size = front = end = 0;
        data = new int[maxSize];
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() {
        return getSize() == 0;
    }

    public boolean isFull() {
        return getSize() == data.length;
    }

    public boolean contains(Object o) {
        return false;
    }

    @Override
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return false;
            }

            @Override
            public Integer next() {
                return null;
            }
        };
    }

    public void offer(Integer value) {
        if (isFull()) {
            throw new RuntimeException("Queue too small!");
        }
        data[end++] = value;
        size++;
        end = end % data.length;
    }

    public Integer poll() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        size--;
        front = front % data.length;
        return data[front++];
    }

    public Integer peek() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        return data[front];
    }

    /*public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Queue=[");
        if (isEmpty()) {
            return sb.append("]").toString();
        }
        for (int i = front; i < end - 1; i++) {
            sb.append(data[i]).append(", ");
        }
        sb.append(data[end - 1]).append("]");
        return sb.toString();
    }*/
}
