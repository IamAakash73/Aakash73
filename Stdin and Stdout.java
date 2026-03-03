import java.io.*;
import java.util.*;
import java.math.*;

public class Stdin and Stdout {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        // Read the integer, double, and String in that order.
        int i = scan.nextInt();
        double d = scan.nextDouble();
        
        // Consume the remaining newline character left by nextDouble()
        scan.nextLine(); 
        
        String s = scan.nextLine();

        // Close the scanner when done
        scan.close();

        // Print the values in the required order: String, Double, Int
        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}
