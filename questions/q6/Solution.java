package q6;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Determine if Player 1 can win or tie in the optimal number picking game.
     * 
     * Two players alternate picking from either end of a list.
     * Both play optimally to maximize their score.
     * 
     * @param nums An array of integers representing project values
     * 
     * Your solution should print 1 if Player 1 wins/ties, 0 otherwise
     */
    public static void solve(int[] nums) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int result = dfs(nums, 0, nums.length - 1, new HashMap<>());
        
        if (result >= 0) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    private static int dfs(int[] nums, int l, int r, Map<String, Integer> memo) {
        if (l == r) {
            return nums[l];
        }
        
        String key = l + "," + r;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        
        int pickLeft = nums[l] - dfs(nums, l + 1, r, memo);
        int pickRight = nums[r] - dfs(nums, l, r - 1, memo);
        
        int result = Math.max(pickLeft, pickRight);
        memo.put(key, result);
        return result;
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