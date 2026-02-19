package q10;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Find the maximum score by selecting non-adjacent elements.
     * 
     * You cannot select two adjacent tasks/elements.
     * Return the maximum total score possible.
     * 
     * @param nums An array of integers representing task values
     * 
     * Your solution should print the maximum score to stdout
     */
    public static void solve(int[] nums) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int n = nums.length;
        
        if (n == 0) {
            System.out.println("0");
            return;
        }
        
        if (n == 1) {
            System.out.println(nums[0]);
            return;
        }
        
        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int current = Math.max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        System.out.println(prev1);
        
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
        
        int[] nums = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            nums[i] = Integer.parseInt(parts[i]);
        }
        
        solve(nums);
        scanner.close();
    }
}