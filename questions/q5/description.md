# Question 5: Triple Palindrome Validator - 25 Points

Fantastic work recovering that encryption key! The security team now needs your help with another encryption challenge. The system has an encryption validator that flags symmetrical keys as authentic based on a specific structural pattern.

You must verify whether incoming authentication tokens meet strict structural integrity requirements. The validator checks for a "triple palindrome" pattern - a unique signature that legitimate keys possess. Invalid tokens could indicate forged credentials or compromised systems.

This is a critical security checkpoint. Get it right.

## Problem

Determine if a string is a "triple palindrome" by checking:
1. Split the string into three equal parts (first third, middle third, last third)
2. The first and last thirds combined (concatenated) must form a palindrome
3. The middle third must also be a palindrome on its own


## Input Format

**stdin:** A single line containing a string (length divisible by 3).

## Output Format

**stdout:** Print `1` if it's a valid triple palindrome, `0` otherwise.

## Examples

**Example 1:**
```
Input:  abccba
Output: 1
```
Explanation:
- First third: "ab"
- Middle third: "cc"
- Last third: "ba"
- "ab" + "ba" = "abba" (palindrome ✓)
- "cc" (palindrome ✓)
- Result: 1

**Example 2:**
```
Input:  abcdef
Output: 0
```
Explanation:
- First third: "ab"
- Middle third: "cd"
- Last third: "ef"
- "ab" + "ef" = "abef" (not a palindrome ✗)
- Result: 0

> You can assume that the length of the given string mod 3 will be 0 (evenly divisible by 3).

## Function Parameters

**Python:** Your `main(input_string)` function receives:
- `input_string`: A string with length divisible by 3 (e.g., `"abccba"`)
- Print using: `print()`

**Java:** Your `solve(inputString)` method receives:
- `inputString`: A `String` with length divisible by 3
- Print using: `System.out.println()`