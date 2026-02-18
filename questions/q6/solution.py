import sys
sys.setrecursionlimit(10**7)

def main(nums):
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

if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    nums = list(map(int, input_string.split()))
    main(nums)
