# Question 6: Predict the Winner

The encryption keys have been validated and your security contributions are being noticed across CGI. Now leadership needs your strategic expertise during the crisis.

CGI leadership must allocate resources across competing initiatives. Two strategic teams (Team A and Team B) alternate claiming projects to maximize total ROI. Both teams play optimally to maximize their score.

Your task: determine whether Team A (Player 1) can secure at least a tie given the list of project values.

## Problem

Two players are playing a game with a list of integers representing project values. They take turns picking a number from either the leftmost or rightmost end of the list.

Each player plays optimally to maximize their total score (i.e. picks the largest number they can).

Determine whether Player 1 can win or tie.

## Input Format

**stdin:** A single line of space-separated integers.

## Output Format

**stdout:** Print `1` if Player 1 can win or tie, `0` otherwise.

## Examples

**Example 1:**
```
Input:  1 5 2 1
Output: 1
```
__Option A__:
- Player 1 picks right (1): Remaining [1, 5, 2]
- Player 2 optimally picks 1 (left): Remaining [5, 2]
- Player 1 picks 5: Remaining [2]
- Player 2 gets 2
Scores: P1 = 1 + 5 = 6, P2 = 1 + 2 = 3 ✓

__Option B__:
- Player 1 picks left (1): Remaining [5, 2, 1]
- Player 2 optimally picks 5: Remaining [2, 1]
- Player 1 picks 2: Remaining [1]
- Player 2 gets 1
Scores: P1 = 1 + 2 = 3, P2 = 5 + 1 = 6 ✗

Output: 1

**Example 2:**
```
Input:  1 5 233 7
Output: 0
```

- P1 picks 7: [1, 5, 233] remains -> P2 can pick 233
- P2 picks 233: P2 clearly wins here

Output: 0


## Function Parameters

Your `main(nums)` function receives:
- `nums`: A Python list of integers representing the project values (e.g., `[1, 5, 2]`)

Your solution should print the result to stdout using `print()`.
