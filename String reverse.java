import java.io.*;
import java.util.*;

// 1. Corrected class name (removed space)
public class String reverse {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        // Ensure input exists
        if (!sc.hasNext()) return;
        String A=sc.next();
        
        // Reverse the string A using StringBuilder
        String reverse = new StringBuilder(A).reverse().toString();
        
        // Compare original string with reversed string
        if (A.equals(reverse)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
