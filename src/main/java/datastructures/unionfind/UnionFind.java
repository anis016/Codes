package datastructures.unionfind;

import java.util.*;

public class UnionFind {

    // number of elements in the list
    int size;

    // number of disjoint components/sets
    int numComponents;

    // size of the components/sets
    int[] componentsSize;

    // id[i] points to parent of i, if id[i] = j, where j is the root node
    int[] id;

    public UnionFind(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("size should be at least 1");
        }
        this.size = size;
        id = new int[size];
        componentsSize = new int[size];

        // in the beginning all the components are singular, they are the set themselves
        this.numComponents = size;

        for (int i = 0; i < size; i++) {
            id[i] = i; // link to itself, each element is root to itself
            componentsSize[i] = 1; // original size is 1
        }
    }

    public int getComponentSize(int p) {
        // for the component size get to the root node and find the number of components
        return componentsSize[find(p)];
    }

    public int getNumComponents() {
        return this.numComponents;
    }

    public int find(int p) {

        // loop until the root of 'p' is found
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }

        // do path compression of all the elements in the set to point to the root node
        while (p != root) {
            int next = id[p]; // get the next element in the path
            id[next] = root; // point the next element directly to the root
            p = next; // go to that next element
        }

        return root;
    }

    public boolean isConnected(int p, int q) {
        // if two nodes are already connected then they should have the same root
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        if (isConnected(p, q)) {
            // the two node p and q are already connected
            return ;
        }

        // connect two nodes if these two are not connected
        int rootp = find(p); // get the root node of p
        int rootq = find(q); // get the root node of q

        // merge smaller components/set to the larger one
        if (componentsSize[rootp] < componentsSize[rootq]) {
            componentsSize[rootq] += componentsSize[rootp]; // merge p into q
            id[rootp] = rootq; // point the root of p to root of q
        } else {
            componentsSize[rootp] += componentsSize[rootq]; // merge q into p
            id[rootq] = rootp; // point the root of q to root of p
        }

        // after merging, reduce the number of components
        numComponents --;
    }

    public String toString() {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < size; i++) {
            int root = find(i);

            // initialize value to ArrayList() if key doesn't exist or get the earlier value
            List<Integer> temp = map.getOrDefault(root, new ArrayList<>());
            temp.add(i);
            map.put(root, temp);
        }
        return map.toString();
    }
}
