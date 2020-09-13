package datastructures.stack;

import java.util.Iterator;
import java.util.LinkedList;

public class Stack<T> implements Iterable<T> {
    LinkedList<T> stack;

    public Stack() {
        stack = new LinkedList<>();
    }

    public int getSize() {
        return stack.size();
    }

    public boolean isEmpty() {
        return getSize() == 0;
    }

    public void push(T data) {
        stack.addLast(data);
    }

    public T get(int index) {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        return stack.get(index);
    }

    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        return stack.removeLast();
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        return stack.peekLast();
    }

    public int indexOf(T data) {
        for (int i = 0; i < getSize(); i++) {
            if (data.equals(stack.get(i))) {
                return i;
            }
        }
        return -1;
    }

    public boolean contains(T data) {
        int index = indexOf(data);
        return index != -1;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            int index;

            @Override
            public boolean hasNext() {
                return index < getSize();
            }

            @Override
            public T next() {
                T data = stack.get(index);
                index ++;
                return data;
            }
        };
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Stack=[");
        if (isEmpty()) {
            return sb.append("]").toString();
        }
        for (int i = 0; i < getSize() - 1; i++) {
            sb.append(stack.get(i)).append(", ");
        }
        sb.append(stack.get(getSize() - 1)).append("]");
        return sb.toString();
    }
}
