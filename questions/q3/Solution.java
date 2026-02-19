package q3;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Calculate your total score in Rock-Paper-Scissors based on a strategy guide.
     * 
     * Game Rules:
     * - R (Rock) beats S (Scissors)
     * - S (Scissors) beats P (Paper)
     * - P (Paper) beats R (Rock)
     * 
     * Scoring:
     * - Win: 6 points
     * - Draw: 3 points
     * - Loss: 1 point
     * 
     * @param guide Array of 6 strings representing 3 pairs [opponent_move, your_response]
     * @param moves Array of strings representing the opponent's move sequence
     * 
     * Your solution should print the result to stdout using System.out.println()
     */
    public static void solve(String[] guide, String[] moves) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        // Parse guide
        Map<String, String> guideMap = new HashMap<>();
        for (int i = 0; i < guide.length; i += 2) {
            guideMap.put(guide[i], guide[i + 1]);
        }
        
        // Calculate score
        int score = 0;
        for (String move : moves) {
            String response = guideMap.get(move);
            
            if (move.equals("R")) {
                if (response.equals("P")) score += 1;
                else if (response.equals("S")) score -= 1;
            } else if (move.equals("P")) {
                if (response.equals("S")) score += 1;
                else if (response.equals("R")) score -= 1;
            } else if (move.equals("S")) {
                if (response.equals("R")) score += 1;
                else if (response.equals("P")) score -= 1;
            }
        }
        
        System.out.println(score);
        
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
        String[] words = line.trim().split("\\s+");
        
        String[] guide = Arrays.copyOfRange(words, 0, 6);
        String[] moves = Arrays.copyOfRange(words, 6, words.length);
        
        solve(guide, moves);
        scanner.close();
    }
}