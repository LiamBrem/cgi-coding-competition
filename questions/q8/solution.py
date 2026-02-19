# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(grid):
    """
    Count the number of islands in a 2D grid.
    
    An island is a group of '1's connected horizontally or vertically.
    '0' represents water.
    
    Args:
        grid: A 2D list where each cell is either '1' (land) or '0' (water)
    
    Your solution should print the number of islands to stdout
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
    if not grid or not grid[0]:
        print(0)
        return
    
    seen = set()
    
    def dfs(i, j):
        if (i, j) in seen:
            return
        seen.add((i, j))
        for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < len(grid) and 0 <= nj < len(grid[ni]) and grid[ni][nj] == '1':
                dfs(ni, nj)
    
    islands = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == '1' and (i, j) not in seen:
                dfs(i, j)
                islands += 1
    
    print(islands)
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    import sys
    data = sys.stdin.read().strip()
    width = data[0]
    height = data[1]
    grid = []
    for i in range(2, len(data), int(width)):
        grid.append(list(data[i:i+int(width)]))
    main(grid)
    