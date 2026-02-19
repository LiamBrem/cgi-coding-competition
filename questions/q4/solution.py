import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(input_string):
    """
    Find the first character that appears in both halves of a string.
    
    Args:
        input_string: A string with even length
    
    Your solution should print the result to stdout using print()
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================

    firstHalf = input_string[:len(input_string) // 2]
    secondHalf = input_string[len(input_string) // 2:]

    s = set(firstHalf)
    for c in secondHalf:
        if c in s:
            print(c)
            return
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    data = sys.stdin.read().strip()
    main(data)