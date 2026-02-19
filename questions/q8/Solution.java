package q8;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Count the number of islands in a 2D grid.
     * 
     * An island is a group of '1's connected horizontally or vertically.
     * '0' represents water.
     * 
     * @param grid A 2D character array where each cell is either '1' (land) or '0' (water)
     * 
     * Your solution should print the number of islands to stdout
     */
    public static void solve(char[][] grid) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        if (grid == null || grid.length == 0) {
            System.out.println(0);
            return;
        }
        
        Set<String> seen = new HashSet<>();
        int islands = 0;
        
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1' && !seen.contains(i + "," + j)) {
                    dfs(grid, i, j, seen);
                    islands++;
                }
            }
        }
        
        System.out.println(islands);
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    private static void dfs(char[][] grid, int i, int j, Set<String> seen) {
        String key = i + "," + j;
        if (seen.contains(key)) return;
        
        seen.add(key);
        
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int[] dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[ni].length 
                && grid[ni][nj] == '1') {
                dfs(grid, ni, nj, seen);
            }
        }
    }
    
    // ============================================
    // DO NOT MODIFY BELOW THIS LINE
    // ============================================
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String data = scanner.nextLine();
        
        int width = Character.getNumericValue(data.charAt(0));
        int height = Character.getNumericValue(data.charAt(1));
        
        char[][] grid = new char[height][width];
        int idx = 2;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                grid[i][j] = data.charAt(idx++);
            }
        }
        
        solve(grid);
        scanner.close();
    }
}