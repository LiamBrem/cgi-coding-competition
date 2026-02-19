package q9;

import java.util.*;

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Merge k sorted lists into a single sorted list.
     * 
     * @param lists A list of sorted integer lists
     * 
     * Your solution should print the merged sorted list to stdout
     */
    public static void solve(List<List<Integer>> lists) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        int k = lists.size();
        
        // Min heap: [value, list_index, element_index]
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        for (int i = 0; i < k; i++) {
            if (!lists.get(i).isEmpty()) {
                heap.offer(new int[]{lists.get(i).get(0), i, 0});
            }
        }
        
        List<Integer> result = new ArrayList<>();
        
        while (!heap.isEmpty()) {
            int[] entry = heap.poll();
            int value = entry[0];
            int listIndex = entry[1];
            int elemIndex = entry[2];
            
            result.add(value);
            
            int nextIndex = elemIndex + 1;
            if (nextIndex < lists.get(listIndex).size()) {
                heap.offer(new int[]{
                    lists.get(listIndex).get(nextIndex),
                    listIndex,
                    nextIndex
                });
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) sb.append(" ");
            sb.append(result.get(i));
        }
        System.out.println(sb.toString());
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    // ============================================
    // DO NOT MODIFY BELOW THIS LINE
    // ============================================
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = Integer.parseInt(scanner.nextLine());
        
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            String line = scanner.nextLine();
            List<Integer> list = new ArrayList<>();
            if (!line.trim().isEmpty()) {
                String[] parts = line.trim().split("\\s+");
                for (String part : parts) {
                    list.add(Integer.parseInt(part));
                }
            }
            lists.add(list);
        }
        
        solve(lists);
        scanner.close();
    }
}