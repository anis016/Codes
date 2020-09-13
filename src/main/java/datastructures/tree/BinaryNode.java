package datastructures.tree;

/**
 * hackerrank:
 *  https://www.youtube.com/watch?v=oSWTXtMglKE
 * mycodeschool:
 *  https://www.youtube.com/watch?v=qH6yxkw0u78&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=25
 * leetcode:
 *  https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/
 */

public class BinaryNode {
    int value;
    BinaryNode left;
    BinaryNode right;

    public BinaryNode() {
    }

    public BinaryNode(int value) {
        this.value = value;
    }

    public BinaryNode(int value, BinaryNode left, BinaryNode right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public BinaryNode getLeft() {
        return left;
    }

    public void setLeft(BinaryNode left) {
        this.left = left;
    }

    public BinaryNode getRight() {
        return right;
    }

    public void setRight(BinaryNode right) {
        this.right = right;
    }
}
