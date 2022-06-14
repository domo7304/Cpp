package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LabelMoveEx extends JFrame {
    JButton left = new JButton("left");
    JButton right = new JButton("right");
    JButton up = new JButton("up");
    JButton down = new JButton("down");
    JLabel label = new JLabel("Java");

    public LabelMoveEx(){
        setTitle("EX2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();

        JPanel p_north = new JPanel();
        JPanel p_center = new JPanel();

        left.addActionListener(new ButtonAction());
        right.addActionListener(new ButtonAction());
        up.addActionListener(new ButtonAction());
        down.addActionListener(new ButtonAction());

        p_north.add(left);
        p_north.add(right);
        p_north.add(up);
        p_north.add(down);
        p_north.setBackground(Color.YELLOW);

        label.setSize(50, 20);
        label.setLocation(0, 0);
        p_center.setLayout(null);
        p_center.add(label);

        c.add(p_north, BorderLayout.NORTH);
        c.add(p_center, BorderLayout.CENTER);
        setSize(500, 500);
        setVisible(true);
    }

    private class ButtonAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            if (e.getActionCommand().equals("left")){
                label.setLocation(label.getX() - 10, label.getY());
            }
            else if (e.getActionCommand().equals("right")){
                label.setLocation(label.getX() + 10, label.getY());
            }
            else if (e.getActionCommand().equals("up")){
                label.setLocation(label.getX(), label.getY() - 10);
            }
            else {
                label.setLocation(label.getX(), label.getY() + 10);
            }
        }
    }

    public static void main(String[] args) {
        new LabelMoveEx();
    }
}
