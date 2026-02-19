import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(nums):
    """
    Find the maximum score by selecting non-adjacent elements.
    
    You cannot select two adjacent tasks/elements.
    Return the maximum total score possible.
    
    Args:
        nums: A list of integers representing task values
    
    Your solution should print the maximum score to stdout
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
    n = len(nums)

    if n == 0:
        print("0")
        return
    
    if n == 1:
        print(nums[0])
        return

    prev2 = nums[0]
    prev1 = max(nums[0], nums[1])

    for i in range(2, n):
        current = max(prev1, prev2 + nums[i])
        prev2 = prev1
        prev1 = current

    print(prev1)
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    nums = list(map(int, input_string.split()))
    main(nums)