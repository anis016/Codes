package datastructures.priorityqueue;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BinaryHeap<T extends Comparable<T>> {

    List<T> heap = null;

    public BinaryHeap() {
        this(1);
    }

    public BinaryHeap(int size) {
        heap = new ArrayList<>(size);
    }

    public BinaryHeap(T[] elements) {
        int heapSize = elements.length;
        heap = new ArrayList<>(heapSize);

        // place all the elements in the heap
        Collections.addAll(heap, elements);

        // build Min heap
        // Optimized Approach - O(n)
        // https://www.geeksforgeeks.org/building-heap-from-array/
        for(int i = Math.max(0, (heapSize / 2) - 1); i >= 0; i--) {
            sink(i);
        }
    }

    public int getSize() {
        return heap.size();
    }

    public boolean isEmpty() {
        return getSize() == 0;
    }

    public void sink(int root) {
        int heapSize = heap.size();

        // We are working with the index position here not the value
        while (true) {
            // get the left child of the node at k
            int left = root * 2 + 1;

            // get the right child of the node at k
            int right = root * 2 + 2;

            // get the smallest child - either left or right child
            // initiate left child as the smallest one
            int smallest = left;
            if (right < heapSize && less(right, left)) {
                smallest = right;
            }

            // if root is already smallest or left is out of bound then stop
            if (left >= heapSize || less(root, smallest)) {
                break;
            }

            // else swap the smallest child with the root and continue
            swap(root, smallest);
            root = smallest;
        }
    }

    public boolean less(int lIndex, int rIndex) {
        T leftValue = heap.get(lIndex);
        T rightValue = heap.get(rIndex);

        // if left is less than right then return -1
        // if left is greater than right then return +1
        // if left is equal to right then return 0
        return leftValue.compareTo(rightValue) <= 0;
    }

    public void swap(int rootIndex, int smallestChildIndex) {
        T rootValue = heap.get(rootIndex);
        T smallestChildValue = heap.get(smallestChildIndex);

        heap.set(rootIndex, smallestChildValue);
        heap.set(smallestChildIndex, rootValue);
    }

    public void add(T element) {
        heap.add(element);

        // get the index of the last element
        int indexOfLastElement = heap.size() - 1;
        swim(indexOfLastElement);
    }

    public void swim(int k) {
        // remember, child = parent * 2 + 1
        // hence, parent = (child - 1) / 2
        int parent = (k - 1) / 2;

        // swim until the added node is in the right position
        // check if the node added is less than the parent
        while (k > 0 && less(k, parent)) {
            swap(k, parent); // swap the parent with the node
            k = parent; // current node becomes the parent

            // grab the next parent with respect to the current node
            parent = (k - 1) / 2;
        }
    }

    public boolean remove(T element) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap.get(i).equals(element)) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    public T removeAt(int index) {
        if (isEmpty()) return null;
        T element = heap.get(index);

        // need to get the index of the last element
        // so that we can swap with the the element in the last index
        int indexOfLastElement = getSize() - 1;

        // if the index that will be removed is already last element then just remove and return
        if (indexOfLastElement == index) {
            heap.remove(index);
            return element;
        }

        // swap it
        swap(indexOfLastElement, index);

        // remove the element
        heap.remove(indexOfLastElement);

        // probably the element went up after swapped, hence sink to correct the structure
        sink(index);

        // probably sinking is not correct because element could be smaller, so nothing happened hence swim up
        if (heap.get(index).equals(element)) {
            // nothing happened after sinking, just check if this is true and then do swimming
            swim(index);
        }

        return element;
    }

    // check if the heap is min heap by starting from root
    public boolean isMinHeap(int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        // if we are outside the bound of the heap then return true
        int heapSize = heap.size();
        if (root >= heapSize)
            return true;

        // if left or right child is within the bound of heap bur root is not less than the child then return false
        if (left < heapSize && !less(root, left)) return false;
        if (right < heapSize && !less(root, right)) return false;

        // recursively call both left and right child of the current root
        return isMinHeap(left) && isMinHeap(right);
    }

    public T getRoot() {
        return heap.get(0);
    }

    public T poll() {
        return removeAt(0);
    }

    public String toString() {
        return heap.toString();
    }
}
