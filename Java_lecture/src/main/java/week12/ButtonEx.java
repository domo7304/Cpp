package week12;

import javax.swing.*;
import java.awt.*;

public class ButtonEx extends JFrame {
    public ButtonEx(){
        // 기본 상태, 마우스를 버튼에 올렸을 때, 클릭했을 때에 대한 버튼 아이콘의 변화를 보여준다.
        setTitle("이미지 버튼 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        String src = "C:\\Users\\lee\\source\\Lecture\\Java_lecture\\src\\main\\java\\week12\\images\\";
        ImageIcon normalIcon = new ImageIcon(src + "normalIcon.gif");
        ImageIcon rolloverIcon = new ImageIcon(src + "rolloverIcon.gif");
        ImageIcon pressedIcon = new ImageIcon(src + "pressedIcon.gif");

        JButton btn = new JButton("Button", normalIcon);
        btn.setRolloverIcon(rolloverIcon);
        btn.setPressedIcon(pressedIcon);

        c.add(btn);
        setSize(250, 150);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ButtonEx();
    }
}
