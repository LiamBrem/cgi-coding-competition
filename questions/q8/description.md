# Question 8: Breach Cluster Detection - 40 Points

Your system analysis revealed some concerning patterns. The security operations center has generated a map of the server infrastructure, and multiple servers show signs of compromise. Each "1" on the map represents a compromised server, while "0" represents a clean server.

Here's the critical insight: connected compromised servers (horizontally or vertically adjacent) form a single breach cluster. They're part of the same attack campaign and can be handled by one response team.

You need to count the number of isolated cyber incidents so CGI can deploy response teams effectively. Each cluster needs a dedicated team. Too few teams and the response is inadequate; too many and resources are wasted.

Map the battlefield and count the enemy positions.

## Problem

Given a 2D grid where:
- `1` = compromised server
- `0` = clean server

Count the number of distinct "islands" (clusters) of compromised servers. Servers are connected horizontally or vertically (not diagonally).

## Input Format

**stdin:** A single line containing:
1. First character: width (single digit)
2. Second character: height (single digit)
3. Remaining characters: the grid values concatenated row by row

**Example:** `35101110010` represents:
- Width: 3
- Height: 5
- Grid:
  ```
  1 0 1
  1 1 0
  0 1 0
  ```

## Output Format

**stdout:** A single integer representing the number of distinct breach clusters.

## Examples

**Example 1:**
```
Input:  33110010001
Output: 2
```
Explanation:
- Grid (3x3):
  ```
  1 1 0
  0 1 0
  0 0 1
  ```
- Cluster 1: Connected cells at (0,0), (0,1), (1,1)
- Cluster 2: Single cell at (2,2)
- Total: 2 clusters

**Example 2:**
```
Input:  44101001010010111000
Output: 4
```
Explanation:
- Grid (4x4):
  ```
  1 0 1 0
  0 1 0 1
  0 0 1 0
  1 1 1 0
  ```


## Function Parameters

Your `main(grid)` function receives:
- `grid`: A Python 2D list (list of lists) where each element is a string '0' or '1' (e.g., `[['1','1','0'], ['0','1','0'], ['0','0','1']]`)

Note: Grid elements are strings, not integers!

Your solution should print the result to stdout using `print()`.