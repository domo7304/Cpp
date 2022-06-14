package week11.HW3;

import java.io.*;
import java.util.*;

public class WordCount {
    public static void main(String[] args) {
        System.out.println("이도원 / 컴퓨터공학과 / 12172169");
        Scanner sc = new Scanner(System.in);
        String src = "C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week11\\resources\\";
        HashMap<String, Integer> wordsCount = new HashMap<>();

        try{
            System.out.print("Input file name: ");
            String input_name = sc.next();
            System.out.print("Output file name: ");
            String output_name = sc.next();

            FileReader fr = new FileReader(src + input_name);
            BufferedReader br = new BufferedReader(fr);
            FileWriter fw = new FileWriter(src + output_name);
            BufferedWriter bw = new BufferedWriter(fw);

            // 스트림에서 데이터를 읽어와 String 에 저장 및 split 진행
            String str = "", line;
            while ((line = br.readLine()) != null){
                str += line;
            }
            String[] words = str.split(" |\n|,|\\.|:|;|\\?|!|\\[|]|\\(|\\)|'");

            // 문자열 배열을 순회하며, 단어의 개수 count
            for (int i = 0; i < words.length; i++){
                words[i] = words[i].toLowerCase();

                // 현재 words[i] 가 "" 가 아니며(문자열에서 구분자 두 개가 연속으로 올 경우 "" 가 저장됨),
                // HashMap 에 있는 경우와 없는 경우에 따라 나누어 저장
                if (!words[i].equals("")){
                    if (wordsCount.containsKey(words[i])) wordsCount.put(words[i], wordsCount.get(words[i]) + 1);
                    else wordsCount.put(words[i], 1);
                }
            }

            // HashMap 에 저장한 단어들을 파일에 write
            for (String key : wordsCount.keySet()){
                Integer value = wordsCount.get(key);
                String tmp = key + " " + Integer.toString(value) + '\n';
                bw.write(tmp);
            }

            System.out.println("Word count finished");

            bw.close();
            fw.close();
            br.close();
            fr.close();
        }
        catch (IOException e){
            System.out.println("IOException 이 발생했습니다.");
        }
    }
}