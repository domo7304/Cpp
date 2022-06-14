package week14;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Problem4 extends JFrame {
    private JTextArea ta = new JTextArea(4, 7);
    private String [] subjects = {"Java", "Data Structure", "OS"};
    private String [] description = {"Java is a 2-1 class.", "Data Structure is a 2-1 class.", "OS is a 3-1 class,"};
    private JComboBox<String> combo = new JComboBox<>(subjects);

    public Problem4(){
        setTitle("EX4");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();

        combo.addActionListener(new ComboActionListener());
        ta.setText(description[0]);

        c.add(combo, BorderLayout.NORTH);
        c.add(ta);

        setSize(300, 300);
        setVisible(true);
    }

    class ComboActionListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e) {
            int idx = combo.getSelectedIndex();
            ta.setText(description[idx]);
        }
    }

    public static void main(String[] args) {
        new Problem4();
    }
}
