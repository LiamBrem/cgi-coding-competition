def main(grid):
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

    



# DO NOT MODIFY
if __name__ == "__main__":
    import sys
    data = sys.stdin.read().strip()
    width = data[0]
    height = data[1]
    grid = []
    for i in range(2, len(data), int(width)):
        grid.append(list(data[i:i+int(width)]))
    main(grid)
    