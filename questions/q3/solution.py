import sys

# R = rock, P = paper, S = scissors
# guide is in the format: ["R", "R", "P", "P", scissors", "R"]
# where if the opponent plays move guide[i], you play the move guide[i + 1]
# if the opponent plays "R", you should play "R"
# if the opponent plays scissors, you should play "R"
# moves is in the format: ["R", "P", "S", "R", "R"]
# score: 1 if you win, 0 if you tie, -1 if you lose
def main(guide, moves):
    # YOUR CODE HERE
    
    m = {}
    for i in range(0, len(guide) - 1, 2):
        m[guide[i]] = guide[i + 1]

    score = 0
    for move in moves:
        if move == "R":
            if m[move] == "P":
                score += 1
            elif m[move] == "S":
                score -= 1
        elif move == "P":
            if m[move] == "S":
                score += 1
            elif m[move] == "R":
                score -= 1
        elif move == "S":
            if m[move] == "R":
                score += 1
            elif m[move] == "P":
                score -= 1

    # PRINT THE RESULT
    print(score)



if __name__ == "__main__":
    data = sys.stdin.read().strip()
    words = data.split()
    guide = words[:6]
    moves = words[6:]
    main(guide, moves)