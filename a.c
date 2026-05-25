import javax.swing.*;
import java.awt.*;

public class Smiley extends JFrame {

    // Default Constructor
    public Smiley() {

        setTitle("Smiley Face");

        setSize(400, 400);

        setDefaultCloseOperation(
                JFrame.EXIT_ON_CLOSE);

        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {

        super.paint(g);

        // Face
        g.setColor(Color.YELLOW);

        g.fillOval(100, 100,
                200, 200);

        // Eyes
        g.setColor(Color.BLACK);

        g.fillOval(150, 170,
                20, 20);

        g.fillOval(230, 170,
                20, 20);

        // Smile
        g.drawArc(150, 200,
                100, 50,
                180, 180);
    }

    public static void main(String[] args) {

        new Smiley();
    }
}



/-2import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class CircleFrame extends JFrame {

    // Default Constructor
    public CircleFrame() {

        setTitle("Concentric Circles");

        setSize(500, 500);

        setDefaultCloseOperation(
                JFrame.EXIT_ON_CLOSE);

        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {

        super.paint(g);

        Random random =
                new Random();

        int radius = 20;

        for (int i = 0; i < 10; i++) {

            Color color =
                    new Color(
                            random.nextInt(256),
                            random.nextInt(256),
                            random.nextInt(256)
                    );

            g.setColor(color);

            g.drawOval(
                    250 - radius,
                    250 - radius,
                    radius * 2,
                    radius * 2
            );

            radius += 10;
        }
    }

    public static void main(String[] args) {

        new CircleFrame();
    }
}
---3import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator
        extends JFrame
        implements ActionListener {

    private JTextField textField;

    private double number1;
    private double number2;
    private double result;

    private String operator;

    // Default Constructor
    public Calculator() {

        setTitle("Calculator");

        setSize(300, 400);

        setLayout(new BorderLayout());

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textField =
                new JTextField();

        add(textField,
                BorderLayout.NORTH);

        JPanel panel =
                new JPanel();

        panel.setLayout(
                new GridLayout(4, 4));

        String[] buttons = {

                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        for (String text : buttons) {

            JButton button =
                    new JButton(text);

            button.addActionListener(this);

            panel.add(button);
        }

        add(panel,
                BorderLayout.CENTER);

        setVisible(true);
    }

    @Override
    public void actionPerformed(
            ActionEvent e) {

        String value =
                e.getActionCommand();

        if (value.matches("[0-9]")) {

            textField.setText(
                    textField.getText()
                            + value);
        }

        else if (value.equals("C")) {

            textField.setText("");

            number1 = 0;

            number2 = 0;

            result = 0;
        }

        else if (value.equals("+")
                || value.equals("-")
                || value.equals("*")
                || value.equals("/")) {

            number1 =
                    Double.parseDouble(
                            textField.getText());

            operator = value;

            textField.setText("");
        }

        else if (value.equals("=")) {

            number2 =
                    Double.parseDouble(
                            textField.getText());

            switch (operator) {

                case "+":
                    result = number1 + number2;
                    break;

                case "-":
                    result = number1 - number2;
                    break;

                case "*":
                    result = number1 * number2;
                    break;

                case "/":
                    result = number1 / number2;
                    break;
            }

            textField.setText(
                    String.valueOf(result));
        }
    }

    public static void main(String[] args) {

        new Calculator();
    }
}
  
