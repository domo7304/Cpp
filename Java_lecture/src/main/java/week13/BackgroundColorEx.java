package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BackgroundColorEx extends JFrame {
    // 버튼 컴포넌트를 멤버 변수로 빼준 것
    JButton red = new JButton("red");
    JButton blue = new JButton("blue");
    JButton green = new JButton("green");

    public BackgroundColorEx(){
        setTitle("EX1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();

        // JFrame default layout 은 BorderLayout
        // North 에 한 개의 컴포넌트밖에 들어가지 못한다.
        // 때문에 Panel 을 하나 더 두어 그곳에 버튼을 위치시키기.
        // Panel 의 default layout 은 FlowLayout
        JPanel p = new JPanel();
        ButtonAction ba = new ButtonAction();
        red.addActionListener(ba);
        blue.addActionListener(ba);
        green.addActionListener(ba);
        p.add(red);
        p.add(blue);
        p.add(green);
        p.setBackground(Color.GRAY);

        c.add(p, BorderLayout.NORTH);
        c.setBackground(Color.CYAN);

        setSize(500, 500);
        setVisible(true);
    }

    private class ButtonAction implements ActionListener{
        public void actionPerformed(ActionEvent e){
            Container c = getContentPane();
            if (e.getActionCommand().equals("red")){
                c.setBackground(Color.RED);
            }
            else if (e.getActionCommand().equals("blue")){
                c.setBackground(Color.BLUE);
            }
            else {
                c.setBackground(Color.GREEN);
            }
        }
    }

    public static void main(String[] args) {
        new BackgroundColorEx();
    }
}
