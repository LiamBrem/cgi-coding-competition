package q7;

import java.util.*;

// ============================================
// DO NOT MODIFY: TreeNode class and parsing helpers
// These are provided for you to use
// ============================================

class TreeNode {
    List<Integer> val;
    List<TreeNode> children;
    
    TreeNode() {
        this.val = new ArrayList<>();
        this.children = new ArrayList<>();
    }
    
    int evaluate() {
        if (children.isEmpty()) {
            return val.get(0);
        } else {
            int childSum = 0;
            for (TreeNode child : children) {
                childSum += child.evaluate();
            }
            return val.indexOf(childSum);
        }
    }
}

// ============================================
// IMPLEMENT YOUR SOLUTION IN THE solve() METHOD
// ============================================

public class Solution {
    /**
     * Evaluate the root node of a tree structure.
     * 
     * Tree Node Structure:
     * - Leaf nodes: Return the first (and only) element in their val array
     * - Internal nodes: Sum all children's return values, then return the INDEX
     *                  of that sum in the node's val array
     * 
     * @param root A TreeNode object with val (List<Integer>) and children (List<TreeNode>)
     * 
     * Your solution should print the result to stdout
     */
    public static void solve(TreeNode root) {
        // ============================================
        // YOUR CODE HERE
        // ============================================
        
        System.out.println(dfs(root));
        
        // ============================================
        // END YOUR CODE
        // ============================================
    }
    
    private static int dfs(TreeNode node) {
        if (node.children.isEmpty()) {
            return node.val.get(0);
        } else {
            int childSum = 0;
            for (TreeNode child : node.children) {
                childSum += dfs(child);
            }
            return node.val.indexOf(childSum);
        }
    }
    
    // ============================================
    // DO NOT MODIFY BELOW THIS LINE: Parsing helpers
    // ============================================
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        TreeNode root = parseTree(input);
        solve(root);
        scanner.close();
    }
    
    private static TreeNode parseTree(String s) {
        TreeNode node = new TreeNode();
        
        if (s.startsWith("L")) {
            // Leaf node: L[1,2,3]
            String arrayPart = s.substring(1);
            node.val = parseArray(arrayPart);
            node.children = new ArrayList<>();
        } else if (s.startsWith("N")) {
            // Internal node: N[1,2,3](child1)(child2)...
            int bracketEnd = s.indexOf(']');
            String arrayPart = s.substring(1, bracketEnd + 1);
            node.val = parseArray(arrayPart);
            
            String childrenStr = s.substring(bracketEnd + 1);
            node.children = parseChildren(childrenStr);
        }
        
        return node;
    }
    
    private static List<Integer> parseArray(String s) {
        s = s.trim();
        if (s.startsWith("[") && s.endsWith("]")) {
            s = s.substring(1, s.length() - 1);
        }
        
        List<Integer> result = new ArrayList<>();
        if (s.isEmpty()) {
            return result;
        }
        
        String[] parts = s.split(",");
        for (String part : parts) {
            result.add(Integer.parseInt(part.trim()));
        }
        return result;
    }
    
    private static List<TreeNode> parseChildren(String s) {
        List<TreeNode> children = new ArrayList<>();
        int i = 0;
        
        while (i < s.length()) {
            if (s.charAt(i) == '(') {
                int depth = 1;
                int j = i + 1;
                while (j < s.length() && depth > 0) {
                    if (s.charAt(j) == '(') depth++;
                    else if (s.charAt(j) == ')') depth--;
                    j++;
                }
                String childStr = s.substring(i + 1, j - 1);
                children.add(parseTree(childStr));
                i = j;
            } else {
                i++;
            }
        }
        
        return children;
    }
}