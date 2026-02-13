import sys

def main(input_string):
    # YOUR CODE HERE

    firstThird = input_string[:len(input_string) // 3]
    secondThird = input_string[len(input_string) // 3: 2 * len(input_string) // 3]
    lastThird = input_string[2 * len(input_string) // 3:]

    def isPalindrome(s):
        return s == s[::-1]

    if isPalindrome(firstThird + lastThird) and isPalindrome(secondThird):
        print("1")
    else:
        print("0")

    # PRINT OUTPUT

if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    main(input_string)