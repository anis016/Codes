package datastructures.linkedlist;

import java.util.Iterator;

class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this(data, null);
    }

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return String.format("Node{data=%s, next=%s}", data, next);
    }
}

public class SingleLinkedList<T> implements Iterable<T> {

    private int size;
    private Node<T> head;
    private Node<T> tail;

    public SingleLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public int getSize(){
        return size;
    }

    public boolean isEmpty() {
        return getSize() == 0;
    }

    // inserting at the head
    public void insertAtHead(T data) {

        // for the first time head=tail=null, i.e size = 0
        if (isEmpty()) {
            head = tail = new Node<T>(data);
        } else {
            Node<T> temp = head;
            head = new Node<>(data);
            head.next = temp;
        }
        this.size++;
    }

    // inserting at a particular position
    public void insertAt(int index, T data) {
        if (isEmpty()) {
            insertAtHead(data);
        } else {
            if (index <= 1) {
                insertAtHead(data);
            } else if (index > size) {
                throw new IndexOutOfBoundsException("index position " + index + " given is greater than the size " + size);
            } else if (index == size) {
                insertAtLast(data);
            } else {
                Node<T> temp = new Node<T>(data);
                Node<T> current_first = head;
                Node<T> current_second = head.next;

                int counter = 0;
                while (current_first != null) {
                    counter ++;
                    if (index == (counter + 1))
                        break;
                    current_first = current_first.next;
                    current_second = current_second.next;
                }
                assert current_first != null;
                temp.next = current_second;
                current_first.next = temp;
                size++;
            }
        }
    }

    // inserting in the tail position, i.e. appending only when there's at least 1 data
    public void insert(T data) {
        if (isEmpty()) {
            insertAtHead(data);
        } else {
            insertAtLast(data);
        }
    }

    public void insertAtLast(T data) {
        if (isEmpty()) {
            insertAtHead(data);
        } else {
            tail.next = new Node<>(data);
            tail = tail.next; // tail is always pointing to the end of only
            size ++;
        }
    }

    public T peekHead() {
        if (isEmpty()) {
          throw new RuntimeException("list is empty");
        }
        return head.data;
    }

    public T peekTail() {
        if (isEmpty()) {
            throw new RuntimeException("list is empty");
        }
        return tail.data;
    }

    public T removeHead() {
        T value = peekHead();
        head = head.next;
        size --;
        return value;
    }

    public T removeTail() {
        T value = peekTail();
        Node<T> current = head;
        while (current != null) {
            if (current.next.next == null)
                break;
            current = current.next;
        }
        assert current != null;
        tail = current;
        tail.next = null;
        size --;
        return value;
    }

    public T removeAt(int index) {
        T value;
        if (index < 1) {
            value = removeHead();
        } else if (index > size) {
            throw new IndexOutOfBoundsException("index position " + index + " given is greater than the size " + size);
        } else if (index == size) {
            value = removeTail();
        } else {
            int counter = 0;
            Node<T> current = head;
            while (current != null) {
                counter ++;
                if (counter >= (index - 1)) {
                    break;
                }
                current = current.next;
            }
            assert current != null;
            value = current.next.data;
            current.next = current.next.next;
            size --;
        }
        return value;
    }

    public boolean remove(T value) {
        boolean success = false;
        Node<T> current = head;
        if (current.data.equals(value)) {
            removeHead();
            return true;
        } else {
            while (current != null) {
                if (current.next != null) {
                    T nextValue = current.next.data;
                    if (value.equals(nextValue)) {
                        success = true;
                        break;
                    }
                }
                current = current.next;
            }

            if (success) {
                current.next = current.next.next;
                size --;
            }
        }

        return success;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            Node<T> current = head;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public T next() {
                T value = current.data;
                current = current.next;
                return value;
            }
        };
    }

    // int indexOf(T value)
    // boolean contains(T value)

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node<T> current = head;
        sb.append("SingleLinkedList[");
        while(current != null) {
            // iterate except the last element
            if (current.next == null) {
                break;
            }
            sb.append(current.data).append(" -> "); // insert (, ) after all the element except last
            current = current.next;
        }

        assert current != null;
        sb.append(current.data); // append only the last element
        sb.append("]");
        return sb.toString();
    }
}
