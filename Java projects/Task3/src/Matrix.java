package com.metanit;

import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Vector;

public class Matrix {
    double[][] matrix;
    int size;

    public void fillTheMatrix() throws IOException, NumberFormatException {
        String fileAdress = "C:/2courseProgramming/Java/Task3/data.txt";
        Path path = Paths.get(fileAdress);
        Scanner fileReader = new Scanner(path);
        //int i = 0;
        size = fileReader.nextInt();
        matrix = new double[size][size];
        /*while (fileReader.hasNext()) {
            StringTokenizer row = new StringTokenizer(fileReader.nextLine());
            int j = 0;
            while (row.hasMoreTokens()) {
                tempMatrix[i][j] = Double.parseDouble(row.nextToken());
                j++;
            }
            i++;
        }*/
        for(int i = 0; i< size; i++){
            for (int j = 0; j< size; j++){
                //if(fileReader.hasNext())
                    matrix[i][j] = fileReader.nextInt();
                /*else{
                    throw new InputMismatchException("Less elements than needed!");
                }*/
            }
        }
        if(fileReader.hasNextInt()){
            throw new InputMismatchException("More elements than needed!");
        }
    }

    public double scaliarMultiplication(int column, int row) {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += matrix[row][i] * matrix[i][column];
        }
        return result;
    }

    public Vector<Vector<Integer>> findMinRowAndMaxColumn() {
        double min = matrix[0][0];
        double max = matrix[0][0];
        Vector<Vector<Integer>> result = new Vector<Vector<Integer>>();
        result.add(new Vector<Integer>());
        result.add(new Vector<Integer>());
        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                if (matrix[n][m] >= max) {
                    if (matrix[n][m] > max) {
                        result.elementAt(0).clear();
                        max = matrix[n][m];
                    }
                    if(!result.elementAt(0).contains(m))
                        result.elementAt(0).add(m);
                }
                if (matrix[n][m] <= min) {
                    if (matrix[n][m] < min) {
                        result.elementAt(1).clear();
                        min = matrix[n][m];
                    }
                    if(!result.elementAt(1).contains(n))
                        result.elementAt(1).add(n);
                }
            }
        }
        return result;
    }

    public void printTheResult() throws IOException{
        fillTheMatrix();
        Vector<Vector<Integer>> rowsAndColumns = findMinRowAndMaxColumn();
        System.out.println("Scaliar multiplications of columns with max element and rows with min elements");
        for (int i = 0; i < rowsAndColumns.elementAt(0).size(); i++) {
            for (int j = 0; j < rowsAndColumns.elementAt(1).size(); j++) {
                System.out.println("Scalar multiplication of column number " + rowsAndColumns.elementAt(0).elementAt(i) + " and row number " + rowsAndColumns.elementAt(1).elementAt(j) + ": ");
                System.out.println(scaliarMultiplication(rowsAndColumns.elementAt(0).elementAt(i), rowsAndColumns.elementAt(1).elementAt(j)));
            }
        }
    }

}