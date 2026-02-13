import sys

def main(input_list):
    # YOUR CODE HERE

    print(sum(input_list))

    # PRINT OUTPUT

if __name__ == "__main__":
    data = sys.stdin.read().strip()
    numbers = list(map(int, data.split()))
    main(numbers)
