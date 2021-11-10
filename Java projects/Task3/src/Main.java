package com.metanit;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {
    public static void main(String[] args){
        try {
            Matrix matrix = new Matrix();
            matrix.printTheResult();
        }
        catch (IOException exception){
            System.out.println("File not found or can't read the file!");
        }
        catch (IndexOutOfBoundsException exception){
            System.out.println("Index out of bounds, wrong input!!!");
        }
        catch (InputMismatchException exception){
            if(exception.getMessage()!=null)
                System.out.println(exception.getMessage());
            System.out.println("Wrong Input!");
        }
        catch (NoSuchElementException exception){
            System.out.println("Less elements than needed!");
        }
    }
}
