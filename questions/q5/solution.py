import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(input_string):
    """
    Determine if a string is a "triple palindrome".
    
    Requirements:
    1. Split the string into three equal parts
    2. First + last thirds concatenated must form a palindrome
    3. Middle third must also be a palindrome
    
    Args:
        input_string: A string with length divisible by 3
    
    Your solution should print 1 if valid, 0 otherwise
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================

    firstThird = input_string[:len(input_string) // 3]
    secondThird = input_string[len(input_string) // 3: 2 * len(input_string) // 3]
    lastThird = input_string[2 * len(input_string) // 3:]

    def isPalindrome(s):
        return s == s[::-1]

    if isPalindrome(firstThird + lastThird) and isPalindrome(secondThird):
        print("1")
    else:
        print("0")
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    main(input_string)