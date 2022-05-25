package week11;

import java.io.*;
import java.util.Scanner;

public class BinaryCopyEx {
    public static void main(String[] args) {
        int c;
        Scanner sc = new Scanner(System.in);
        String path = "C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week11\\resources\\";

        try{
            System.out.print("Source file name: ");
            String source_file = sc.next();
            System.out.print("Dest file name: " );
            String dest_file1 = sc.next();

            FileInputStream fin1 = new FileInputStream(path + source_file);
            FileOutputStream fout1 = new FileOutputStream(path + dest_file1);
            long start1 = System.currentTimeMillis();
            while((c = fin1.read()) != -1){
                fout1.write((byte) c);
            }
            long end1 = System.currentTimeMillis();

            System.out.print("Dest file name: " );
            String dest_file2 = sc.next();

            FileInputStream fin2 = new FileInputStream(path + source_file);
            BufferedInputStream bin2 = new BufferedInputStream(fin2);
            FileOutputStream fout2 = new FileOutputStream(path + dest_file2);
            BufferedOutputStream bout2 = new BufferedOutputStream(fout2);
            long start2 = System.currentTimeMillis();
            while((c = bin2.read()) != -1){
                bout2.write((byte) c);
            }
            long end2 = System.currentTimeMillis();

            System.out.print("Dest file name: " );
            String dest_file3 = sc.next();

            FileInputStream fin3 = new FileInputStream(path + source_file);
            BufferedInputStream bin3 = new BufferedInputStream(fin3);
            FileOutputStream fout3 = new FileOutputStream(path + dest_file3);
            long start3 = System.currentTimeMillis();
            while((c = bin3.read()) != -1){
                fout3.write((byte) c);
            }
            long end3 = System.currentTimeMillis();

            System.out.print("Dest file name: " );
            String dest_file4 = sc.next();

            FileInputStream fin4 = new FileInputStream(path + source_file);
            FileOutputStream fout4 = new FileOutputStream(path + dest_file4);
            BufferedOutputStream bout4 = new BufferedOutputStream(fout4);
            long start4 = System.currentTimeMillis();
            while((c = fin4.read()) != -1){
                bout4.write((byte) c);
            }
            long end4 = System.currentTimeMillis();

            System.out.println("without BufferedStream: " + (end1 - start1) + "ms");
            System.out.println("with BufferedStream: " + (end2 - start2) + "ms");
            System.out.println("with only BufferedInputStream: " + (end3 - start3) + "ms");
            System.out.println("with only BufferedOutputStream: " + (end4 - start4) + "ms");
        }
        catch (IOException e){
            System.out.println("IOException 이 발생했습니다. ");
        }
    }
}
