import java.util.Scanner;
import java.util.StringTokenizer;

public class StringTokenizerEx {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("더하기 수식 입력 >> ");
        String str = scanner.nextLine();

        StringTokenizer st = new StringTokenizer(str, "+");
        int sum = 0;

        // st.nextToken() 할 때마다 원소를 하나씩 빼기 때문에 for문으로
        // for (int i = 0; i < st.countTokens(); i++)
        // 해버리면, sum 에 하나 더해질 때마다 (st.nextToken()때마다)
        // st.countTokens() 가 하나 줄어들어서 제대로 동작을 안한다.
        while(st.hasMoreTokens()){
            sum += Integer.parseInt(st.nextToken());
        }

        System.out.println("Sum = " + sum);
        scanner.close();
    }
}
