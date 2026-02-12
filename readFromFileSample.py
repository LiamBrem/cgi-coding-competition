# Reading a file line by line in Python

# Option 1: Read all lines at once
with open("input.txt") as f:
    lines = f.read().splitlines()

# lines[0] is the first line, lines[1] is the second, etc.
# splitlines() removes the newline characters for you

# Option 2: Loop through lines one at a time
with open("input.txt") as f:
    for line in f:
        line = line.strip()  # removes leading/trailing whitespace and newlines
        print(line)

# Common patterns:
# Read a single integer from the first line
n = int(lines[0])

# Read two integers from one line (e.g., "10 20")
a, b = map(int, lines[0].split())

# Read a list of integers, one per line
numbers = [int(line) for line in lines]

# Read a line with two values (e.g., "Alice 42")
name, score = lines[0].split()
score = int(score)
