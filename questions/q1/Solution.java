package q1;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Calculate the sum of all transaction values.
     * 
     * @param inputList An array of integers representing transaction values
     * 
     * Your solution should print the result to stdout using System.out.println()
     */
    public static void solve(int[] inputList) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int sum = 0;
        for (int num : inputList) {
            sum += num;
        }
        
        System.out.println(sum);
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    // ============================================
    // DO NOT MODIFY BELOW THIS LINE
    // ============================================
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        String[] parts = line.trim().split("\\s+");
        
        int[] numbers = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            numbers[i] = Integer.parseInt(parts[i]);
        }
        
        solve(numbers);
        scanner.close();
    }
}
