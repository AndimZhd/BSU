package com.metanit;

import java.util.StringTokenizer;

public class Main {

    static boolean isANumber(String symbol){
        return !(symbol.equals("+") || symbol.equals("-") || symbol.equals("x"));
    }

    static int countTheProblem(String problem, int x){
        StringTokenizer problemTokenizer;
        StringBuilder currentNumber = new StringBuilder("");
        boolean sign = true;
        int currentResult = 0;
        problemTokenizer = new StringTokenizer(problem);

        while (problemTokenizer.hasMoreTokens()) {
            String temp = problemTokenizer.nextToken();
            if (isANumber(temp)) {
                currentNumber.append(temp);
            } else if (temp.equals("+")) {
                if(sign)
                    currentResult += Integer.parseInt(currentNumber.toString());
                else
                    currentResult -= Integer.parseInt(currentNumber.toString());
                currentNumber.delete(0, currentNumber.length());
                sign = true;
            } else if (temp.equals("-")) {
                if(sign)
                    currentResult += Integer.parseInt(currentNumber.toString());
                else
                    currentResult -= Integer.parseInt(currentNumber.toString());
                currentNumber.delete(0, currentNumber.length());
                sign = false;
            } else if (temp.equals("x")) {
                currentNumber.append(x);
            }
        }
        if(sign)
            currentResult += Integer.parseInt(currentNumber.toString());
        else
            currentResult -= Integer.parseInt(currentNumber.toString());
        currentNumber.delete(0, currentNumber.length());

        return currentResult;
    }

    public static void main(String[] args) {
        String problem = args[0];
        int x = Integer.parseInt(args[1]);
        try {
            System.out.println(countTheProblem(problem, x));
        }
        catch (NumberFormatException exception){
            System.out.println(exception.getMessage());
            System.out.println("An exception during converatation occured");
        }
    }
}
