package q4;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Find the first character that appears in both halves of a string.
     * 
     * @param inputString A string with even length
     * 
     * Your solution should print the result to stdout using System.out.println()
     */
    public static void solve(String inputString) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int mid = inputString.length() / 2;
        String firstHalf = inputString.substring(0, mid);
        String secondHalf = inputString.substring(mid);
        
        Set<Character> firstSet = new HashSet<>();
        for (char c : firstHalf.toCharArray()) {
            firstSet.add(c);
        }
        
        for (char c : secondHalf.toCharArray()) {
            if (firstSet.contains(c)) {
                System.out.println(c);
                return;
            }
        }
        
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