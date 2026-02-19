# Question 2: Signature Detection

Good work on the transaction verification! Your manager is impressed. Now there's a more urgent issue: suspicious log files are showing up across multiple systems with mixed-case messages. The security team suspects attackers are embedding a signature pattern to communicate between compromised servers.

You've been tasked with analyzing these logs. Intelligence suggests the adversary's signature is the string "cgi,"  but they're trying to hide it by varying the case (CGI, Cgi, cGi, etc.). You need to detect how many times this pattern appears in the massive unstructured logs, regardless of case.

## Problem

Count how many times the substring "cgi" appears in the input string, case-insensitive. Note that overlapping occurrences should NOT be counted separately.

## Input Format

**stdin:** A single line containing a string (may contain letters, numbers, and special characters).

## Output Format

**stdout:** A single integer representing the count of "cgi" occurrences (case-insensitive).

## Examples

**Example 1:**
```
Input:  cgiCGIcgi
Output: 3
```
Explanation: Found "cgi" (lowercase), "CGI" (uppercase), and "cgi" (lowercase) = 3 occurrences.

**Example 2:**
```
Input:  TheCgiCompanyIsAwesome
Output: 1
```
Explanation: Found "Cgi" = 1 occurrence.

## Function Parameters

Your `main(input_string)` function receives:
- `input_string`: A Python string containing the log data (e.g., `"cgiCGIcgi"`)

Your solution should print the result to stdout using `print()`.