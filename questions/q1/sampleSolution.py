total = 0

with open ("input.txt", "r") as f:
    for line in f:
        total += int(line.strip())

print(total)