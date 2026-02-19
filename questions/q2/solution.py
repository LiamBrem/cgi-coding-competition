import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(input_string):
    """
    Count occurrences of "cgi" (case-insensitive) in the input string.
    
    Args:
        input_string: A string to search for "cgi" patterns
    
    Your solution should print the result to stdout using print()
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
    res = 0
    for i in range(len(input_string) - 2):
        if input_string[i: i+3].lower() == "cgi":
            res += 1
    
    print(res)
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    main(input_string)

