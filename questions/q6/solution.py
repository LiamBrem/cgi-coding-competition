import sys
sys.setrecursionlimit(10**7)

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(nums):
    """
    Determine if Player 1 can win or tie in the optimal number picking game.
    
    Two players alternate picking from either end of a list.
    Both play optimally to maximize their score.
    
    Args:
        nums: A list of integers representing project values
    
    Your solution should print 1 if Player 1 wins/ties, 0 otherwise
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
    n = len(nums)

    from functools import lru_cache

    @lru_cache(None)
    def dfs(l, r):
        if l == r:
            return nums[l]
        
        pick_left = nums[l] - dfs(l + 1, r)
        pick_right = nums[r] - dfs(l, r - 1)
        
        return max(pick_left, pick_right)

    result = dfs(0, n - 1)

    if result >= 0:
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
    nums = list(map(int, input_string.split()))
    main(nums)
