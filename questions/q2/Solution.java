package q2;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Count occurrences of "cgi" (case-insensitive) in the input string.
     * 
     * @param inputString A string to search for "cgi" patterns
     * 
     * Your solution should print the result to stdout using System.out.println()
     */
    public static void solve(String inputString) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int count = 0;
        for (int i = 0; i <= inputString.length() - 3; i++) {
            String substring = inputString.substring(i, i + 3);
            if (substring.equalsIgnoreCase("cgi")) {
                count++;
            }
        }
        
        System.out.println(count);
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    // ============================================
    // DO NOT MODIFY BELOW THIS LINE
    // ============================================
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        solve(inputString);
        scanner.close();
    }
}
