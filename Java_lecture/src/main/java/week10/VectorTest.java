package week10;

import java.util.Scanner;
import java.util.Vector;

public class VectorTest {

    public static Double mean(Vector<? extends Number> v){
        Double sum = 0.0;
        for (int i = 0; i < v.size(); i++) sum += v.get(i).doubleValue();
        return sum / v.size();
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Vector<Integer> v = new Vector<>();

        while(true){
            System.out.print("숫자를 입력하세요 >> ");
            Integer num = s.nextInt();
            if (num == 0) {
                System.out.println("종료합니다.");
                break;
            }
            v.add(num);
            System.out.println("누적 평균은 " + mean(v));
        }
        s.close();
    }
}
