package com.metanit;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.text.DecimalFormat;

public class Interface extends JFrame implements ActionListener{
    private Series series;
    private JButton saveButton;
    private JButton createSeries;
    private JRadioButton linerButton;
    private JRadioButton exponentialButton;
    private ButtonGroup chooseSeriesType;
    private JLabel firstLabel;
    private JLabel coefLabel;
    private JLabel numberLabel;
    private JTextField firstElement;
    private JTextField coefficient;
    private JTextField numberOfElements;
    private JTextField filePathField;
    private JButton printSeriesButton;
    private JLabel stringOfSeries;
    private JTextField jTextField;
    private JButton countJElementButton;
    private JLabel JElement;
    private JButton countSumButton;
    private JLabel JSum;
    public Interface(){
        super("Series");
        GridBagLayout grid = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        setLayout(grid);
        setTitle("GridBagLayout Example");
        GridBagLayout layout = new GridBagLayout();
        this.setLayout(layout);
        setSize(1000, 1000);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        //place radio buttons
        linerButton = new JRadioButton("Liner");
        linerButton.setSelected(true);
        exponentialButton = new JRadioButton("Exponential");
        chooseSeriesType = new ButtonGroup();
        chooseSeriesType.add(linerButton);
        chooseSeriesType.add(exponentialButton);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.weightx = 0.5;
        gbc.ipady = 20;
        gbc.gridx = 0;
        gbc.gridy = 0;
        add(linerButton, gbc);
        gbc.gridy = 1;
        add(exponentialButton, gbc);
        gbc.gridy++;

        //place series parameters
        firstLabel = new JLabel("First element");
        coefLabel = new JLabel("Coefficient");
        numberLabel = new JLabel("N");
        firstElement = new JTextField("Enter the first element");
        coefficient = new JTextField("Enter the coefficient");
        numberOfElements = new JTextField("Enter number of elements");
        gbc.gridx = 0;
        gbc.gridy++;
        add(firstLabel, gbc);
        gbc.gridx = 1;
        add(coefLabel, gbc);
        gbc.gridx = 2;
        add(numberLabel, gbc);
        gbc.gridy++;
        add(numberOfElements, gbc);
        gbc.gridx = 1;
        add(coefficient, gbc);
        gbc.gridx = 0;
        add(firstElement, gbc);

        //place create Button
        createSeries = new JButton("Create series");
        gbc.gridy++;
        add(Box.createVerticalStrut(20), gbc);
        gbc.gridy++;
        createSeries.addActionListener(this);
        gbc.gridx = 1;
        add(createSeries, gbc);

        //place Save
        saveButton = new JButton("Save");
        saveButton.setEnabled(false);
        filePathField = new JTextField("Enter the path to output file");
        saveButton.addActionListener(this);
        gbc.gridy++;
        add(Box.createVerticalStrut(10), gbc);
        gbc.gridy++;
        gbc.gridx = 0;
        add(filePathField, gbc);
        gbc.gridx = 1;
        add(saveButton, gbc);
        gbc.gridy++;
        add(Box.createVerticalStrut(10), gbc);

        //place ToString
        printSeriesButton = new JButton("ToString");
        printSeriesButton.setEnabled(false);
        stringOfSeries = new JLabel("Result of ToString");
        printSeriesButton.addActionListener(this);
        gbc.gridy++;
        gbc.gridx = 0;
        add(printSeriesButton, gbc);
        gbc.gridx++;
        add(stringOfSeries, gbc);

        //place countJElement
        jTextField = new JTextField("J");
        countJElementButton = new JButton("Count J Element");
        countJElementButton.setEnabled(false);
        JElement = new JLabel("JElementResult");
        countJElementButton.addActionListener(this);
        gbc.gridy++;
        gbc.gridx = 0;
        add(countJElementButton, gbc);
        gbc.gridx++;
        add(jTextField, gbc);
        gbc.gridx++;
        add(JElement, gbc);

        //place countSum
        countSumButton = new JButton("Count sum");
        countSumButton.setEnabled(false);
        JSum = new JLabel("Sum");
        countSumButton.addActionListener(this);
        gbc.gridy++;
        gbc.gridx = 0;
        add(countSumButton, gbc);
        gbc.gridx++;
        add(JSum, gbc);
        setVisible(true);
    }


    public void actionPerformed(ActionEvent e) {
        try {
            if (e.getSource() == createSeries)
                createSeries();
            else if (e.getSource() == saveButton)
                save();
            else if (e.getSource() == printSeriesButton)
                convertToString();
            else if (e.getSource() == countJElementButton)
                countJElement();
            else if (e.getSource() == countSumButton)
                countSum();
        }
        catch (NumberFormatException exception){
            JOptionPane.showMessageDialog(this, "Unacceptable input");
        }
        catch (ArithmeticException exception) {
            JOptionPane.showMessageDialog(this, "N < 0!");
        }
    }

    private void createSeries(){
        double first = Double.parseDouble(firstElement.getText());
        double coef = Double.parseDouble(coefficient.getText());
        int n = Integer.parseInt(numberOfElements.getText());
        if (n <= 0)
            throw new ArithmeticException();
        if (linerButton.isSelected())
            series = new Liner(first, coef, n);
        else
            series = new Exponential(first, coef, n);
        saveButton.setEnabled(true);
        printSeriesButton.setEnabled(true);
        countJElementButton.setEnabled(true);
        countSumButton.setEnabled(true);
    }

    private void save(){
        try {
            series.saveToFile(filePathField.getText());
        }
        catch (IOException exception) {
            JOptionPane.showMessageDialog(this, "Unacceptable file path!");
        }
    }

    private void convertToString(){
        stringOfSeries.setText(series.toString());
    }

    private void countJElement(){
        DecimalFormat format = new DecimalFormat("#.######");
        JElement.setText(format.format(series.countJMember(Integer.parseInt(jTextField.getText()))));
    }

    private void countSum(){
        DecimalFormat format = new DecimalFormat("#.######");
        JSum.setText(format.format(series.countSum()));
    }
}
