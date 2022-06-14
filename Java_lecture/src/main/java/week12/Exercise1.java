package week12;

import javax.swing.*;
import java.awt.*;

public class Exercise1 extends JFrame {
    public Exercise1(){
        setTitle("JButton 색깔, 글자 변경");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JButton b1 = new JButton("Blue/Yellow Button");
        JButton b2 = new JButton("Disabled Button");
        JButton b3= new JButton("Italic Button");

        b1.setBackground(Color.yellow);
        b1.setForeground(Color.blue);
        b2.setEnabled(false);
        b3.setFont(new Font("Arial", Font.ITALIC, 20));

        c.add(b1);
        c.add(b2);
        c.add(b3);
        setSize(300, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Exercise1();
    }
}
