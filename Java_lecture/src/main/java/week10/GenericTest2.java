package week10;

class Rect<T extends Number>{
    private T width;
    private T height;

    public Rect(T width, T height){
        this.width = width;
        this.height = height;
    }
    public T getWidth(){
        return this.width;
    }
    public T getHeight(){
        return this.height;
    }
    public void setWidth(T width){
        this.width = width;
    }
    public void setHeight(T height){
        this.height = height;
    }
    public String toString(){
        return "week10.Rect [width=" + this.width + ", height=" + this.height + "]";
    }
}

public class GenericTest2 {
    public static void main(String[] args){
        Rect<Integer> r1 = new Rect<>(1, 2);
        System.out.println(r1);
        Rect<Double> r2 = new Rect<>(1.1, 2.2);
        System.out.println(r2);
    }
}
