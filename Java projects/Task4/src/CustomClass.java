package com.metanit;

public class CustomClass implements Comparable<CustomClass>{
    private final Double number;
    CustomClass(double n){
        number = n;
    }
    public int compareTo(CustomClass customClass) {
        return number.compareTo(customClass.number);
    }

    public String toString() {
        return String.valueOf(number);
    }
}