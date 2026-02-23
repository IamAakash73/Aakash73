import java.util.*;
import java.io.*;

class Solution{
    
    private static boolean isBalanced(String expression) {
               Deque<Character> stack = new ArrayDeque<Character>();

        for (char bracket : expression.toCharArray()) {
            if (bracket == '(' || bracket == '{' || bracket == '[') {
                stack.push(bracket);
            } else if (bracket == ')' || bracket == '}' || bracket == ']') {
 
                if (stack.isEmpty()) {
                    return false;
                }
                char lastOpen = stack.pop();
                if (!isMatchingPair(lastOpen, bracket)) {
                    return false;                 }
            }
        }
       
        return stack.isEmpty();
    }


    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
    
    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            String input=sc.next();
            // Complete the code
            System.out.println(isBalanced(input));
        }
        sc.close();     }
}
