package datastructures.linkedlist;

public class DemoSL {

    public static void main(String[] args) {
        SingleLinkedList<Integer> llist = new SingleLinkedList<>();
        llist.insertAtHead(6);
        llist.insertAtHead(5);
        llist.insert(8);
        llist.insertAt(2, 4);
        llist.insertAt(3, 30);
        llist.insertAt(1, 99);
        llist.insertAt(6, 897);
        llist.insert(88);

        System.out.println(llist);

        llist.removeHead();
        System.out.println(llist);
        System.out.println("head -> " + llist.peekHead());

        llist.removeTail();
        System.out.println(llist);
        System.out.println("tail -> " + llist.peekTail());

        llist.removeAt(6);
        System.out.println(llist);

        llist.remove(30);
        System.out.println(llist);

        llist.remove(31);
        System.out.println(llist);

        for (Integer elem : llist) {
            System.out.println(elem);
        }
    }
}
