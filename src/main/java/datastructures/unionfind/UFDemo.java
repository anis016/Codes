package datastructures.unionfind;

public class UFDemo {

    public static void main(String[] args) {
        UnionFind uf = new UnionFind(11);
        uf.union(4, 9);
        uf.union(1, 0);
        uf.union(5, 6);
        uf.union(5, 10);
        uf.union(5, 1);
        uf.union(7, 8);
        System.out.println(uf);
        System.out.println("number of components: " + uf.getNumComponents());
    }
}
