import sys

def main(input_string):
    # YOUR CODE HERE

    res = 0
    for i in range(len(input_string) - 2):
        if input_string[i: i+3].lower() == "cgi":
            res += 1
    
    print(res)

    # PRINT THE RESULT


if __name__ == "__main__":
    input_string = sys.stdin.read().strip()
    main(input_string)

