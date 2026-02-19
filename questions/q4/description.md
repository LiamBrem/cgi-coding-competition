# Question 4: Encryption Key Recovery - 20 Points

Your defensive strategies are working well! However, a new challenge has emerged. During the chaos of the cyber incident, two departments independently submitted halves of a critical encryption key needed to secure the client's most sensitive data.

The problem? The key was split between them, and only one character appears in both halves. That shared character is the validation code needed to proceed with the encryption process. You need to find it quickly! Brute force approaches will delay the response time and leave systems vulnerable.

Time is of the essence. Find the shared character efficiently.

## Problem

Given a string, split it exactly in half and find the one character that appears in both halves.

**Constraints:**
- The string length is always even
- Exactly one character appears in both halves
- Case-sensitive (e.g., 'A' and 'a' are different)

## Input Format

**stdin:** A single line containing a string of even length.

## Output Format

**stdout:** A single character that appears in both halves.

## Examples

**Example 1:**
```
Input:  abcdcefg
Output: c
```
Explanation:
- First half: "abcd"
- Second half: "cefg"
- Shared character: 'c'

**Example 2:**
```
Input:  xyzqzabc
Output: z
```
Explanation:
- First half: "xyzq"
- Second half: "zabc"
- Shared character: 'z'

> You can assume that the length of the given input string will be even.

## Function Parameters

**Python:** Your `main(input_string)` function receives:
- `input_string`: A string with even length (e.g., `"abcdcefg"`)
- Print using: `print()`

**Java:** Your `solve(inputString)` method receives:
- `inputString`: A `String` with even length
- Print using: `System.out.println()`