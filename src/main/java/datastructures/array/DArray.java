package datastructures.array;

import java.util.Iterator;

public class DArray<T> implements IDArray<T>, Iterable<T> {

    T[] array;
    int length;   // current length of the array
    int capacity; // initial capacity of the array

    {
        length = 0;
        capacity = 0;
    }

    public DArray() {
        this(16); // if user gives nothing then assume the initial array capacity is 16
    }

    public DArray(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("capacity should be greater than 0");
        }

        this.capacity = capacity;
        array = (T[]) new Object[capacity];
    }

    @Override
    public int size() {
        return length;
    }

    @Override
    public boolean isEmpty() {
        return (this.length == 0);
    }

    @Override
    public T get(int index) {
        return array[index];
    }

    @Override
    public void set(int index, T element) {
        if (index > this.length) {
            throw new IndexOutOfBoundsException("index - " + index + " greater than array length");
        }
        array[index] = element;
    }

    @Override
    public void add(T element) {
        if (length >= capacity) {
            // time to resize
            capacity = capacity * 2; // double the capacity
            T[] temp = (T[]) new Object[capacity];

            // copy the element of the earlier array
            for(int i = 0; i < length; i++) {
                temp[i] = array[i];
            }
            temp[length] = element;
            length += 1;

            array = temp;
        } else {
            array[length] = element;
            length += 1;
        }
    }

    @Override
    public void clear() {
        for (int i = 0; i < length; i++) {
            array[i] = null;
        }
        length = 0;
    }

    @Override
    public T removeAt(int index) {
        if (index < 0 || index >= length) { // remember, starts from 0 hence index >= length
            throw new IndexOutOfBoundsException("index given is out of bound");
        }

        T element = get(index);
        for (int i = 0, j = 0; i < length; i++) {
            if (i == index) {
                continue;        // remove this element and don't include in updated set
            }
            array[j] = array[i]; // update the array
            j++;
        }
        array[length] = null;
        length = length - 1; // removed an element and hence reduce length by 1
        return element;
    }

    @Override
    public boolean remove(T element) {
        for (int i = 0; i < length; i++) {
            if (array[i].equals(element)) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    @Override
    public int indexOf(T element) {
        for (int i = 0; i < length; i++) {
            if (array[i].equals(element)) {
                return i;
            }
        }
        return -1;
    }

    @Override
    public boolean contains(T element) {
        int index = indexOf(element);
        return index != -1;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            int index = 0;
            @Override
            public boolean hasNext() {
                return index < length;
            }

            @Override
            public T next() {
                return get(index++);
            }
        };
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("array=[");
        for (int i = 0; i < length; i++) {
            sb.append(array[i]);
            if (i+1 < length) sb.append(", ");
        }
        sb.append("]");
        return sb.toString();
    }
}
