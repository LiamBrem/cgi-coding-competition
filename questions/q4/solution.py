import sys


def main(input_string):
    # YOUR CODE HERE

    firstHalf = input_string[:len(input_string) // 2]
    secondHalf = input_string[len(input_string) // 2:]

    s = set(firstHalf)
    for c in secondHalf:
        if c in s:
            print(c)
            return

    # PRINT OUTPUT



if __name__ == "__main__":
    data = sys.stdin.read().strip()
    main(data)