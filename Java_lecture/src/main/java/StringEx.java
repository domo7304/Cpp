import java.util.Scanner;
import java.util.StringTokenizer;

public class StringEx {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        while(true){
            System.out.print(">> ");
            String str = scanner.nextLine();
            if (str.equals("그만")){
                System.out.println("종료합니다...");
                break;
            }
            // String words[] = str.split(" ");
            // System.out.println("어절 개수는 " + words.length);
            // 위처럼 하면 " " 말고 두 칸 씩 띄어 쓸 경우 의도한대로 동작 x
            // 아래처럼 StringTokenizer 을 사용하면 공백을 모두 지워줌
            StringTokenizer st = new StringTokenizer(str, " ");
            System.out.println("어절 개수는 " + st.countTokens());
        }
        scanner.close();
    }
}