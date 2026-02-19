# Question 9: Global Log Merger - 45 Points

Your breach detection system is now helping response teams deploy effectively! But there's another operational challenge: CGI's 400 global locations each produce their own sorted incident logs throughout the day. 

Leadership needs a unified global report to understand the complete timeline of security events across all offices. The problem? Each location has already sorted their logs chronologically, but you need to merge all 400 sorted lists into one master timeline efficiently and in real time.

A slow solution will delay leadership visibility into critical events. Speed matters here. Can you merge these sorted streams without losing efficiency?

## Problem

Given k sorted lists of integers, merge them into a single sorted list.

**Constraints:**
- Each input list is already sorted in ascending order
- Lists may have different lengths
- Lists may be empty

## Input Format

**stdin:** Multiple lines:
1. First line: An integer `k` (number of lists)
2. Next k lines: Each line contains space-separated integers (one sorted list per line)

**Note:** A line may be empty (representing an empty list)

## Output Format

**stdout:** A single line of space-separated integers representing the merged sorted list.

## Examples

**Example 1:**
```
Input:
2
1 3 5
2 4 6

Output:
1 2 3 4 5 6
```
Explanation:
- Merge [1,3,5] and [2,4,6]
- Result: [1,2,3,4,5,6]

**Example 2:**
```
Input:
3
1 4 7
2 5
3 6 8 9

Output:
1 2 3 4 5 6 7 8 9
```
Explanation:
- Merge [1,4,7], [2,5], and [3,6,8,9]
- Result: [1,2,3,4,5,6,7,8,9]

## Function Parameters

Your `main(lines)` function receives:
- `lines`: A Python list of strings where:
  - `lines[0]`: String containing k (number of lists)
  - `lines[1]` to `lines[k]`: Strings containing space-separated integers (or empty strings)
  
Example: `['2', '1 3 5', '2 4 6']`

Your solution should print the result to stdout using `print()`.