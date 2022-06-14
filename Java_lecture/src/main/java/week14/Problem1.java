package week14;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Problem1 extends JFrame {
    JLabel text = new JLabel("Problem1");

    public Problem1(){
        setTitle("Problem1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null);

        text.setLocation(0, 0);
        text.setSize(120, 30);
        text.setFont(new Font("Arial", Font.PLAIN, 10));
        text.addKeyListener(new MyKeyListener());
        c.add(text);

        setSize(300,150);
        setVisible(true);
        text.setFocusable(true);
        text.requestFocus();
    }

    class MyKeyListener extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
            if (e.getKeyChar() == '+'){
                Font f = text.getFont();
                int size = f.getSize();
                if (size > 30) {}
                else text.setFont(new Font("Arial", Font.PLAIN, size + 2));
            }
            else if (e.getKeyChar() == '-'){
                Font f = text.getFont();
                int size = f.getSize();
                if (size < 2) {}
                else text.setFont(new Font("Arial", Font.PLAIN, size - 2));
            }
            else if (e.getKeyCode() == KeyEvent.VK_LEFT){
                int x = text.getX();
                int y = text.getY();
                if (x <= 0) {}
                else text.setLocation(x - 5, y);
            }
            else if (e.getKeyCode() == KeyEvent.VK_RIGHT){
                int x = text.getX();
                int y = text.getY();
                if (x > 300) {}
                else text.setLocation(x + 5, y);
            }
            else if (e.getKeyCode() == KeyEvent.VK_UP){
                int x = text.getX();
                int y = text.getY();
                if (y <= 0) {}
                else text.setLocation(x, y - 5);
            }
            else if (e.getKeyCode() == KeyEvent.VK_DOWN){
                int x = text.getX();
                int y = text.getY();
                if (y > 150) {}
                else text.setLocation(x, y + 5);
            }
        }
    }

    public static void main(String[] args) {
        new Problem1();
    }
}
