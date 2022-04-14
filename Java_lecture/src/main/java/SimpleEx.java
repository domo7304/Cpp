class Pen{
    private int amount;

    public Pen(int amount){
        setAmount(amount);
    }
    public int getAmount(){ return amount; }
    public void setAmount(int amount){ this.amount = amount; }
}

class SharpPencil extends Pen{
    private int width;

    public SharpPencil(int amount, int width){
        super(amount);
        this.width = width;
    }
    public int getWidth(){ return this.width; }
}

class ColorPen extends Pen{
    private String color;

    public ColorPen(int amount, String color){
        super(amount);
        this.color = color;
    }
    public String getColor() { return color; }
}

class BallPen extends ColorPen{
    public BallPen(int amount, String color){
        super(amount, color);
    }
}

class FountainPen extends ColorPen {
    public FountainPen(int amount, String color){
        super(amount, color);
    }
    public void refill(int n) {
         setAmount(n);
    }
}

public class SimpleEx {
    static void print(Pen p){
        if (p instanceof SharpPencil) {
            SharpPencil sp = (SharpPencil) p;
            System.out.println("샤프의 수는 " + sp.getAmount() + " 굵기는 " + sp.getWidth());
        }
        if (p instanceof BallPen) {
            BallPen bp = (BallPen) p;
            System.out.println("볼펜의 수는 " + bp.getAmount() + " 색깔은 " + bp.getColor());
        }
        if (p instanceof FountainPen) {
            FountainPen fp = (FountainPen) p;
            System.out.println("만년필의 수는 " + fp.getAmount() + " 색깔은 " + fp.getColor());
        }
    }

    public static void main(String [] args) {
        /*
        SharpPencil sp = new SharpPencil();
        BallPen bp = new BallPen();
        FountainPen fp = new FountainPen();
        sp.setAmount(10);
        bp.setAmount(5);
        fp.setAmount(2);
        System.out.println("샤프의 수는 " + sp.getAmount());
        System.out.println("볼펜의 수는 " + bp.getAmount());
        System.out.println("만년필의 수는 " + fp.getAmount());

        SharpPencil sp = new SharpPencil(10, 5);
        BallPen bp = new BallPen(5, "빨간색");
        FountainPen fp = new FountainPen(2, "검은색");
        System.out.println("샤프의 수는 " + sp.getAmount() + " 굵기는 " +
                sp.getWidth());
        System.out.println("볼펜의 수는 " + bp.getAmount() + " 색깔은 " +
                bp.getColor());
        System.out.println("만년필의 수는 " + fp.getAmount() + " 색깔은 " +
                bp.getColor());
        */
        Pen[] p = new Pen[3];
        p[0] = new SharpPencil(10, 5);
        p[1] = new BallPen(5, "빨간색");
        p[2] = new FountainPen(2, "검은색");
        for (int i = 0; i < 3; i++) print(p[i]);
    }
}
