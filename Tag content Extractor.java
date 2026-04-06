import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());
        while (testCases > 0) {
            String line = in.nextLine();
            
            // Regex explanation:
            // <(.+)> : Start tag capture group 1 (tag name)
            // ([^<>]+) : Content capture group 2 (one or more non '<' or '>')
            // </\\1> : End tag with backreference to the tag name in group 1
            boolean matchFound = false;
            Pattern p = Pattern.compile("<(.+)>([^<>]+)</\\1>");
            Matcher m = p.matcher(line);

            while (m.find()) {
                System.out.println(m.group(2));
                matchFound = true;
            }

            if (!matchFound) {
                System.out.println("None");
            }

            testCases--;
        }
        in.close();
    }
}
