import sys

def main():
    data = sys.stdin.read().strip()
    numbers = list(map(int, data.split()))
    print(sum(numbers))

if __name__ == "__main__":
    main()
