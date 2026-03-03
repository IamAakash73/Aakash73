import java.io.*;
import java.util.*;

public class End of file
 {

    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int lineNumber = 1;

        while (sc.hasNext()) {
            String content = sc.nextLine();
            
            System.out.println(lineNumber + " " + content);
            
            lineNumber++;
        }
        
        sc.close();
    }
}
