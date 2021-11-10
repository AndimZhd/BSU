package com.metanit;

public class Liner extends Series{
    public Liner(double first, double coef, int n){
        super(first, coef, n);
    }
    @Override
    public Double countJMember(int j) {
        return firstElement+coefficient*(j-1);
    }

    @Override
    public Double countSum() {
        return (firstElement+countJMember(currentNumberOfElements-1))/2*currentNumberOfElements;
    }
}
