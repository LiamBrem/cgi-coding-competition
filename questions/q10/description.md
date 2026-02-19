# Question 10: Maximum Score With No Adjacent Picks - 50 Points

Congratulations! You've made it to the final challenge. All your work has led to this moment.

CGI is allocating innovation funding across initiatives. However, adjacent projects compete for the same talent pool. They cannot both be funded. Your task is to select the optimal subset of non-adjacent initiatives to maximize long-term impact.

If all systems are stabilized, the Shadow ROI incident will be contained, CGI's global infrastructure will be secure, and trusted outcomes will be restored.

Complete this final challenge, and leadership will welcome you as a full CGI Partner.

## Problem

You are given a list of integers representing the value of tasks arranged in a line.

You may select tasks to maximize your total score, but you **cannot select two adjacent tasks**. You may choose any subset that respects this rule.

Return the maximum total score possible.

## Input Format

**stdin:** A single line of space-separated integers.

## Output Format

**stdout:** A single integer representing the maximum total score possible.

## Examples

**Example 1:**
```
Input:  3 2 5 10 7
Output: 15
```
Explanation:
- Select indices 0, 2, 4: 3 + 5 + 7 = 15
- Or select indices 1, 3: 2 + 10 = 12 (less optimal)
- Or select indices 0, 3: 3 + 10 = 13 (less optimal)
- Maximum: 15

**Example 2:**
```
Input:  5 1 3 8
Output: 13
```
Explanation:
- Select indices 0, 3: 5 + 8 = 13
- Maximum: 13

## Function Parameters

Your `main(nums)` function receives:
- `nums`: A Python list of integers representing task values (e.g., `[3, 2, 5, 10, 7]`)

Your solution should print the result to stdout using `print()`.
