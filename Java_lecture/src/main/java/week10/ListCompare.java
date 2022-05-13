package week10;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

public class ListCompare {
    static long add(List<Integer> list) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) list.add(i);
        long end = System.currentTimeMillis();
        return end - start;
    }
    static long add2(List<Integer> list) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) list.add(500, i);
        long end = System.currentTimeMillis();
        return end - start;
    }
    static long remove(List<Integer> list) {
        long start = System.currentTimeMillis();
        for (int i = list.size() - 1; i >= 0; i--) list.remove(i);
        long end = System.currentTimeMillis();
        return end - start;
    }
    static long remove2(List<Integer> list) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) list.remove(500);
        long end = System.currentTimeMillis();
        return end - start;
    }
    static long access(List<Integer> list) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < list.size(); i++) list.get(i);
        long end = System.currentTimeMillis();
        return end - start;
    }

    public static void main(String[] args) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        Vector<Integer> v = new Vector<Integer>();
        LinkedList<Integer> ll = new LinkedList<Integer>();
        System.out.println("Insert in the end");
        System.out.println("ArrayList: " + add(al) + "ms");
        System.out.println("Vector: " + add(v) + "ms");
        System.out.println("LinkedList: " + add(ll) + "ms");
        System.out.println("");
        System.out.println("Insert in the middle");
        System.out.println("ArrayList: " + add2(al) + "ms");
        System.out.println("Vector: " + add2(v) + "ms");
        System.out.println("LinkedList: " + add2(ll) + "ms");
        System.out.println("");
        System.out.println("Sequential access");
        System.out.println("ArrayList: " + access(al) + "ms");
        System.out.println("Vector: " + access(v) + "ms");
        System.out.println("LinkedList: " + access(ll) + "ms");
        System.out.println("");
        System.out.println("Remove from the middle");
        System.out.println("ArrayList: " + remove2(al) + "ms");
        System.out.println("Vector: " + remove2(v) + "ms");
        System.out.println("LinkedList: " + remove2(ll) + "ms");
        System.out.println("");
        System.out.println("Remove from the end");
        System.out.println("ArrayList: " + remove(al) + "ms");
        System.out.println("Vector: " + remove(v) + "ms");
        System.out.println("LinkedList: " + remove(ll) + "ms");
    }
}
