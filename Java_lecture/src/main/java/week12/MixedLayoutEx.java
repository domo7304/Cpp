package week12;

import javax.swing.*;
import java.awt.*;

public class MixedLayoutEx extends JFrame {
    public MixedLayoutEx(){
        setTitle("MixedLayout Sample");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();

        JLabel label = new JLabel("Text example", SwingConstants.CENTER);
        label.setForeground(Color.RED);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2, 20, 20));
        panel.add(new JButton("Button 1"));
        panel.add(new JButton("Button 2"));
        panel.add(new JButton("Button 3"));
        panel.add(new JButton("Button 4"));

        /*
        이렇게 넣으면 안된다. Default Layout 은 BorderLayout 이기 때문에, 모두 Center 로 들어가서
        마지막에 add() 한 것만 보이게 된다.
        c.add(label);
        c.add(panel);
        */

        c.add(label, BorderLayout.NORTH);
        c.add(panel, BorderLayout.CENTER);

        setSize(300, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MixedLayoutEx();
    }
}
