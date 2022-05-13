package week10;

// concat 아이디어 생각 못했음. 눈여겨보기
class Item<T>{
    private T data;

    public T get(){ return this.data; }
    public void set (T data) { this.data = data; }
}

public class WildcardTest {

    // static 꼭 써주기!!!!!!!
    public static String concat(Item<?> i1, Item<?> i2){
        return i1.get().toString().concat(i2.get().toString());
    }

    public static void main(String[] args){
        Item<Integer> i1 = new Item<>();
        Item<Double> d1 = new Item<>();
        Item<String> s1 = new Item<>();

        i1.set(10);
        d1.set(10.1);
        s1.set("Hello");

        String s = concat(i1, s1);
        System.out.println(s);
    }
}
