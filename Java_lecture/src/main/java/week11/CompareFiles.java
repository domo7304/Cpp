package week11;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class CompareFiles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String src = "C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week11\\resources\\";

        System.out.print("File1 name: ");
        String file1 = sc.next();
        System.out.print("File2 name: ");
        String file2 = sc.next();

        try{
            FileInputStream fin1 = new FileInputStream(src + file1);
            FileInputStream fin2 = new FileInputStream(src + file2);
            int c;
            boolean equal = true;
            while ((c = fin1.read()) != -1){
                if (c != fin2.read()) {
                    equal = false;
                    break;
                }
            }
            if (equal && fin2.read() == -1) System.out.println("Equal");
            else System.out.println("Different");
            fin2.close();
            fin1.close();
        } catch (IOException e){
            System.out.println("IOExeption 이 발생했습니다.");
        }
        sc.close();
    }
}
