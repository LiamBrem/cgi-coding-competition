package q5;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Determine if a string is a "triple palindrome".
     * 
     * Requirements:
     * 1. Split the string into three equal parts
     * 2. First + last thirds concatenated must form a palindrome
     * 3. Middle third must also be a palindrome
     * 
     * @param inputString A string with length divisible by 3
     * 
     * Your solution should print 1 if valid, 0 otherwise
     */
    public static void solve(String inputString) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int len = inputString.length();
        int third = len / 3;
        
        String firstThird = inputString.substring(0, third);
        String secondThird = inputString.substring(third, 2 * third);
        String lastThird = inputString.substring(2 * third);
        
        String combined = firstThird + lastThird;
        
        if (isPalindrome(combined) && isPalindrome(secondThird)) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    private static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
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