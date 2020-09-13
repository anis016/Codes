package datastructures.array;

public interface IDArray<T> {

    int size();
    boolean isEmpty();
    T get(int index);
    void set(int index, T element);
    void clear();
    void add(T element);
    T removeAt(int index);
    boolean remove(T element);
    int indexOf(T element);
    boolean contains(T element);
}
