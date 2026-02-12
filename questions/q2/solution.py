import sys

def main():
    input_string = sys.stdin.read().strip()
    res = 0

    for i in range(0, len(input_string) - 2):
        if input_string[i:i+3].lower() == "cgi":
            res += 1

    print(res)

if __name__ == "__main__":
    main()

