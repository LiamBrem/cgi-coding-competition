# Question 3: Rock, Paper, Scissors - 15 Points

Excellent detective work on the signature detection! The attack patterns are becoming clearer. Analysis shows the cyber adversary uses a predictable response strategy when engaging with defensive systems...almost like a game of Rock-Paper-Scissors.

You've been given a counter-strategy guide that tells you exactly how to respond to each of their moves. Your task is to calculate the total defensive effectiveness score based on historical engagement data. Each engagement outcome has a different point value:

- **Win** -> Major mitigation (+1 points)
- **Draw** -> Partial containment (0 points)  
- **Loss** -> Minor fallback (-1 point)

This score will help leadership understand how effective your defensive posture has been.

## Problem

You're playing Rock-Paper-Scissors with a strategy guide. The guide tells you how to respond to each opponent move. Calculate your total score based on a series of moves.

**Rules:**
- Rock (R) beats Scissors (S)
- Scissors (S) beats Paper (P)
- Paper (P) beats Rock (R)

**Scoring:**
- Win: 6 points
- Draw: 3 points
- Loss: 1 point

## Input Format

**stdin:** A single line containing:
1. First 6 values: The strategy guide as 3 pairs (opponent move, your response)
2. Remaining values: The sequence of opponent moves to score

All values are space-separated. Moves are represented as: R (Rock), P (Paper), S (Scissors)

## Output Format

**stdout:** A single integer representing your total score.

## Examples

**Example 1:**
\`\`\`
Input:  R R P P S S R S P
Output: 7
\`\`\`
Explanation:
- Guide: {R→R, P→P, S→S} (all draws)
- Moves: [R, S, P]
- R: Play R → Draw (3 pts)
- S: Play S → Draw (3 pts)
- P: Play P → Draw (3 pts)
- **Total: 9 points**

**Example 2:**
\`\`\`
Input:  R P P S S R R P S
Output: 13
\`\`\`
Explanation:
- Guide: {R→P, P→S, S→R}
- Moves: [R, P, S]
- R: Play P → Win (6 pts)
- P: Play S → Win (6 pts)  
- S: Play R → Loss (1 pt)
- **Total: 13 points**

## Function Parameters

**Python:** Your `main(guide, moves)` function receives:
- `guide`: A list of 6 strings representing 3 pairs of [opponent_move, your_response] (e.g., `["R", "P", "P", "S", "S", "R"]`)
- `moves`: A list of strings representing the opponent's move sequence (e.g., `["R", "P", "S"]`)
- Print using: `print()`

**Java:** Your `solve(guide, moves)` method receives:
- `guide`: A `String[]` array of 6 strings representing 3 pairs
- `moves`: A `String[]` array representing the opponent's move sequence
- Print using: `System.out.println()`