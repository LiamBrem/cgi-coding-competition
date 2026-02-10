import random

with open("input.txt", "w") as f:
    for i in range(10000):
            f.write(str(random.randint(1, 1000)) + "\n")