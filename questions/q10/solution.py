import sys

def main(nums):
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

if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    nums = list(map(int, input_string.split()))
    main(nums)