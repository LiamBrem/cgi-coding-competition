# Question 1: Transaction Verification - 5 Points

You've just been recruited as a Junior Security Analyst at CGI. Your first assignment: a global client experienced a cyber incident that partially corrupted their transaction logs. Before digital transformation can continue, you must verify the total transaction values across all regions to confirm financial integrity.

Your manager needs you to aggregate all reported transaction numbers to ensure nothing was lost in the breach. This is your chance to prove yourself and help restore the client's trust in their systems.

## Problem

Given a list of transaction values (integers), calculate and return the sum of all values.

## Input Format

**stdin:** A single line of space-separated integers representing transaction values.

## Output Format

**stdout:** A single integer representing the sum of all transaction values.

## Examples

**Example 1:**
```
Input:  1 2 3 4 5
Output: 15
```

**Example 2:**
```
Input:  100 -50 25 75
Output: 150
```

## Function Parameters

Your `main(input_list)` function receives:
- `input_list`: A Python list of integers (e.g., `[1, 2, 3, 4, 5]`)

Your solution should print the result to stdout using `print()`.