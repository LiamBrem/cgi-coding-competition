import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(input_list):
    """
    Calculate the sum of all transaction values.
    
    Args:
        input_list: A list of integers representing transaction values
    
    Your solution should print the result to stdout using print()
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
    print(sum(input_list))
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    data = sys.stdin.read().strip()
    numbers = list(map(int, data.split()))
    main(numbers)
