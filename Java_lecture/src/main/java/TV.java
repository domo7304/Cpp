public class TV {

    private String name;
    private int size;
    private int year;

    public TV (String name, int size, int year){
        this.name = name;
        this.size = size;
        this.year = year;
    }

    public TV(String name, int size){
        this.name = name;
        this.size = size;
        this.year = -1;
    }

    public void show(){
        if (this.year == -1) System.out.println("생산년도가 불분명한 " + name + "에서 만든 " + size + "인치 TV");
        else System.out.println(year + "년도 " + name + "에서 만든 " + size + "인치 TV");
    }

    public static void main(String[] args){
        TV myTV = new TV("LG", 32, 2021);
        TV mySecondTV = new TV("Samsung", 27);
        myTV.show();
        mySecondTV.show();
    }
}
