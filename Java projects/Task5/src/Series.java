package com.metanit;

import java.io.FileOutputStream;
import java.io.IOException;
import java.text.DecimalFormat;


public abstract class Series {
    double firstElement;
    double coefficient;
    int currentNumberOfElements;

    Series(double first, double coef, int n){
        firstElement = first;
        coefficient = coef;
        currentNumberOfElements = n;
    }

    public Double countSum(){
        double result = 0;
        for (int i = 0; i<currentNumberOfElements; i++){
            result+=countJMember(i+1);
        }
        return result;
    }

    public abstract Double countJMember(int j);

    public String toString(){
        StringBuilder result = new StringBuilder();
        for(int i = 0; i<currentNumberOfElements; i++){
            DecimalFormat format = new DecimalFormat("#.######");
            result.append(format.format(countJMember(i+1))+" ");
        }
        return result.toString();
    }

    public void saveToFile(String filePath) throws IOException{
            FileOutputStream out = new FileOutputStream(filePath);
            out.write(toString().getBytes());
    }

}
