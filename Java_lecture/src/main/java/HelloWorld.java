
import java.util.ArrayList;
import java.util.Scanner;

public class HelloWorld {


    public static void main(String[] args){
        /*
        System.out.print("달러를 입력하세요 (단위 $) >> ");
        Scanner scanner = new Scanner(System.in);
        int dollar = scanner.nextInt();
        System.out.println(dollar + "달러는 " + dollar*1100 + "원 입니다.");

        System.out.print("곱하고자 하는 두 수 입력 >> ");
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        System.out.println(num1 + " x " + num2 + " = " + num1*num2);
        scanner.close();

         */

        /*
        int price[] = {1800, 2000, 2800, 3000};
        int result = 0;
        System.out.println("메뉴판\n에스프레소 : 1800\n아메리카노 : 2000\n카페라떼 : 2800\n카푸치노 : 3000");
        System.out.print("원하는 메뉴를 입력하세요(띄어쓰기로 메뉴 구분, 마지막에는 '주문' 입력) >> ");

        Scanner scanner = new Scanner(System.in);

        while(true){
            String str = scanner.next();
            if (str.equals("주문")) break;
            if (str.equals("에스프레소")) result += price[0];
            else if (str.equals("아메리카노")) result += price[1];
            else if (str.equals("카페라떼")) result += price[2];
            else if (str.equals("카푸치노")) result += price[3];
        }

        System.out.println("전체 금액은 " + result + "입니다.");
         */

        /*
        Scanner scanner = new Scanner(System.in);
        int arr[] = new int[10];
        for (int i = 0; i < args.length; i++){
            arr[i] = Integer.parseInt(args[i]);
        }

        System.out.print("정수를 입력하세요 >> ");
        int num = scanner.nextInt();
        System.out.print("매개변수 중 " + num + "보다 큰 정수는 ");
        for (int i = 0; i < args.length; i++){
            if (Integer.parseInt(args[i]) > num) System.out.print(args[i] + " ");
        }
        System.out.println("입니다.");
         */


    }
}
