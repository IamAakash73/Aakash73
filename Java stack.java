import java.util.*;
class Solution{
    
    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            String input=sc.next();
            //Complete the code
            System.out.println(isBalanced(input));
        }
        sc.close();
    }

    public static boolean isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty()) {
                    return false; // Unmatched closing bracket
                }
                char openBracket = stack.pop();
                if ((c == ')' && openBracket != '(') || 
                    (c == '}' && openBracket != '{') || 
                    (c == ']' && openBracket != '[')) {
                    return false; // Mismatched brackets
                }
            }
        }
        return stack.isEmpty(); // True if all brackets were matched
    }
}
