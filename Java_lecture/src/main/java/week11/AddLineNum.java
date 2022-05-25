package week11;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class AddLineNum {
    public static void main(String[] args) {
        try{
            FileReader fileReader = new FileReader("C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week11\\test_long.txt");
            // Scanner 에 file 을 넣어줌으로써 한 줄 씩 편하게 읽어올 수 있다
            Scanner scanner = new Scanner(fileReader);
            FileWriter fileWriter = new FileWriter("C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week11\\AddLineNumEx.txt");

            int lineNum = 1;
            while (scanner.hasNext()){
                String s = Integer.toString(lineNum) + '\t' + scanner.nextLine() + '\n';
                fileWriter.write(s);
                lineNum++;
            }
            fileWriter.close();
            scanner.close();
            fileReader.close();
        }
        catch(IOException e){
            System.out.println("IOException");
        }
    }
}