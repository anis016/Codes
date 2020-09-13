package firecode;

// url: https://www.youtube.com/watch?v=njTh_OwMljA
public class LinkedListOperations {

    static class Node {
        Node next; // to hold the next reference node
        int data;  // to hold the data in current node

        public Node(int data) {
            this.data = data;
        }
    }

    static class LinkedList {
        Node head;

        public void append(int data) {

            if (head == null) {
                // for the first time
                head = new Node(data);
            } else {
                Node current = head;
                while(current.next != null) {
                    current = current.next;
                }
                current.next = new Node(data);
            }
        }

        public void before(int data) {
            Node newHead = new Node(data); // add data in the new head position
            newHead.next = this.head; // link the new head next pointer to the current linked list head
            this.head = newHead; // assign the list head to the new head
        }

        public void delete(int data) {
            // deletes the data in the linked list
            if (head == null) return;
            Node current = head;

            if(current.data == data) {
                // head checking
                head = current.next;
                return;
            }

            while (current.next != null) {
                // while on the current node check the next node's data
                if (current.next.data == data) {
                    // if matches then just point to next to next node.
                    // in this way, next node [which one we need] gets removed.
                    current.next = current.next.next;
                    return;
                }
                current = current.next;
            }
        }

        public void show() {
            LinkedList list = this; // first get the LinkedList object implicitly

            Node current = list.head; // get it's head node
            while(current.next != null) { // iterate through the linked list
                System.out.println(current.data); // print the data

                current = current.next; // get the next reference
            }
            System.out.println(current.data); // print the last data
        }
    }

    public static void main(String... args) {

        LinkedList list = new LinkedList();
        list.append(1);
        list.append(2);
        list.append(5);

        list.before(99);

        list.show();

        list.delete(5);
        System.out.println();
        list.show();
    }
}
