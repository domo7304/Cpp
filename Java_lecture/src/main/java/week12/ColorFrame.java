package week12;

import javax.swing.*;
import java.awt.*;

public class ColorFrame extends JFrame {
    public ColorFrame(){
        setTitle("ContentPane 과 JFrame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // 프레임 위로 무언가를 배치시키기 위해서는 ContentPane 을 우선 받아와야 함.\
        Container c = getContentPane();
        c.setBackground(Color.ORANGE);
        c.setLayout(new FlowLayout());

        c.add(new JButton("OK"));
        c.add(new JButton("Cancel"));
        c.add(new JButton("Ignore"));

        setSize(300, 150);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ColorFrame();
    }
}
