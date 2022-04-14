import java.util.Scanner;

class Menu{
    private String name;
    private int price;
    private int stock;

    public Menu(String name, int price, int stock){
        this.name = name;
        this.price = price;
        this.stock = stock;
    }

    public String getName(){
        return this.name;
    }
    public int getPrice(){
        return this.price;
    }
    public int getStock(){
        return this.stock;
    }
    public void setStock(int stock){
        this.stock = stock;
    }
    public void show(){
        System.out.println(this.name + " : " + this.price + "원 (재고 " + this.stock + ")");
    }
}

public class Kiosk {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("이도원/컴퓨터공학과/12172169");

        System.out.println("[키오스크 초기화]");
        System.out.print("판매하고자 하는 메뉴 종류 수를 입력하세요 >> ");
        int menuNum = scanner.nextInt();

        Menu m[] = new Menu[menuNum];

        for (int i = 0; i < menuNum; i++){
            System.out.print("판매하고자 하는 " + i + "번 메뉴 이름, 가격, 재고를 입력하세요(예: 아메리카노 2000 10) >> ");
            m[i] = new Menu(scanner.next(), scanner.nextInt(), scanner.nextInt());
        }
        System.out.println("[초기화 완료]");

        while(true) {
            System.out.println("\n메뉴판");
            for (int i = 0; i < menuNum; i++) m[i].show();
            System.out.print("원하는 메뉴를 입력하세요(띄어쓰기로 메뉴 구분, 마지막에는 '주문' 입력) >> ");
            String str = scanner.next();

            if (str.equals("종료")) {
                System.out.println("종료되었습니다.");
                break;
            }
            else if (str.equals("재고관리")) {
                System.out.println("[관리자 모드]");
                while (true) {
                    System.out.print("관리자 모드를 나가려면 '종료', 재고 변경을 원하면 메뉴 이름을 입력하세요 >> ");
                    str = scanner.next();
                    if (str.equals("종료")) break;

                    for (int i = 0; i < menuNum; i++) {
                        if (str.equals(m[i].getName())) {
                            System.out.print(m[i].getName() + "의 재고는 현재 " + m[i].getStock() + "입니다." +
                                    "변경을 원하시는 수량을 입력하세요 >> ");
                            m[i].setStock(scanner.nextInt());
                            break;
                        }
                    }
                }
            }
            else {
                int order[] = new int[menuNum];
                boolean flag = true;
                while (!str.equals("주문")) {
                    int idx = 0;
                    for (int i = 0; i < menuNum; i++) {
                        if (str.equals(m[i].getName())) {
                            idx = i;
                            break;
                        }
                    }
                    if (m[idx].getStock() == 0) {
                        System.out.println("재고가 부족한 상품이 있습니다. 다시 주문해주세요.");
                        scanner.nextLine();
                        flag = false;
                        break;
                    }
                    order[idx]++;
                    str = scanner.next();
                }
                if (flag){
                    int sum = 0;
                    for (int i = 0; i < menuNum; i++){
                        sum += (m[i].getPrice() * order[i]);
                        m[i].setStock(m[i].getStock() - order[i]);
                    }
                    System.out.println("전체금액은 " + sum + "원 입니다.");
                }
            }
        }
        scanner.close();
    }
}