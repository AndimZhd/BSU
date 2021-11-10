package com.company;

public class Main {

    public static void main(String[] args) {
        try {
            if(args.length != 2){
                throw new ArithmeticException("The number of parametres is not 2");
            }
        }
        catch (ArithmeticException exception){
            System.out.println(exception.getMessage());
            return;
        }
        try {
            double x = Double.parseDouble(args[0]);
            double precision = Double.parseDouble(args[1]);
            double currentMember = (x*x*x*-1)/2/6;
            double currentSum = 0;
            int k = 2;
            while(Math.abs(currentMember) >= precision){
                currentSum+=currentMember;
                currentMember = currentMember*-1*x/(k+1)/(k+2)*k;
                k++;
            }
            System.out.println(currentSum);
        }
        catch (NumberFormatException exception) {
            System.out.println("An exception during converatation occured");
            System.out.println(exception.getMessage());
        }
    }
}
