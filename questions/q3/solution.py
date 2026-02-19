import sys

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(guide, moves):
    """
    Calculate your total score in Rock-Paper-Scissors based on a strategy guide.
    
    Game Rules:
    - R (Rock) beats S (Scissors)
    - S (Scissors) beats P (Paper)
    - P (Paper) beats R (Rock)
    
    Scoring:
    - Win: 6 points
    - Draw: 3 points
    - Loss: 1 point
    
    Args:
        guide: List of 6 strings representing 3 pairs [opponent_move, your_response]
               e.g., ["R", "P", "P", "S", "S", "R"]
        moves: List of strings representing opponent's move sequence
               e.g., ["R", "P", "S"]
    
    Your solution should print the result to stdout using print()
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
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

    print(score)
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    data = sys.stdin.read().strip()
    words = data.split()
    guide = words[:6]
    moves = words[6:]
    main(guide, moves)