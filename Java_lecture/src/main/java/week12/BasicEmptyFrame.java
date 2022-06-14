package week12;

import javax.swing.*;

public class BasicEmptyFrame extends JFrame {
    public BasicEmptyFrame(){
        setTitle("첫 번째 프레임");
        setSize(300, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        BasicEmptyFrame bf = new BasicEmptyFrame();
    }
}
