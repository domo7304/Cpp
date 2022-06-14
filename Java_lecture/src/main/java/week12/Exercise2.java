package week12;

import javax.swing.*;
import java.awt.*;

public class Exercise2 extends JFrame {
    public Exercise2(){
        setTitle("JLabel 이용하여 레이블 만들기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        String src = "C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week12\\images\\";
        ImageIcon icon1 = new ImageIcon(src + "beauty.jpg");
        ImageIcon icon2 = new ImageIcon(src + "normalIcon.gif");

        JLabel label1 = new JLabel("사랑합니다");
        JLabel label2 = new JLabel(icon1);
        JLabel label3 = new JLabel("전화하세요", icon2, SwingConstants.CENTER);

        c.add(label1);
        c.add(label2);
        c.add(label3);

        setSize(400, 600);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Exercise2();
    }
}
