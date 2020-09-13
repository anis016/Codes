package datastructures.array;

import java.util.Iterator;

public class DArrayDemo {

    public static void main(String[] args) {
        DArray<Integer> myDArray = new DArray<>(3);
        myDArray.add(10);
        myDArray.add(12);
        myDArray.add(33);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        myDArray.add(45);
        myDArray.add(57);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        myDArray.set(3, 79);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        // Integer element = myDArray.get(3);
        // System.out.println(element);

        myDArray.removeAt(2);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        myDArray.removeAt(2);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        myDArray.remove(57);
        System.out.println(myDArray.size());
        System.out.println(myDArray);

        System.out.println(myDArray.contains(13));
        System.out.println(myDArray.contains(10));

        // can use the iterator on the object - myDArray because DArray implements Iterable<T> interface
        /*Iterator<Integer> iter = myDArray.iterator();
        while(iter.hasNext()) {
            System.out.println(iter.next());
        }*/
        // can use this enhanced for-loop because DArray implements Iterable<T> interface
        for (Integer elem : myDArray) {
            System.out.println(elem);
        }
    }
}
