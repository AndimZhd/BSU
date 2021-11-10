package com.metanit;

public class Exponential extends Series{
    public Exponential(double first, double coef, int n){
        super(first, coef, n);
    }
    @Override
    public Double countSum() {
        return firstElement*(1-Math.pow(coefficient, currentNumberOfElements))/(1-coefficient);
    }

    @Override
    public Double countJMember(int j) {
        return firstElement*Math.pow(coefficient, j-1);
    }
}
