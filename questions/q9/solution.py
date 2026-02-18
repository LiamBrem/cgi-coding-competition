import sys
import heapq

def main(lines):
    k = int(lines[0])
    
    lists = []
    for i in range(1, k + 1):
        if lines[i].strip():
            lists.append(list(map(int, lines[i].split())))
        else:
            lists.append([])

    heap = []
    
    for i in range(k):
        if lists[i]:
            heapq.heappush(heap, (lists[i][0], i, 0))
    
    result = []
    
    while heap:
        value, list_index, element_index = heapq.heappop(heap)
        result.append(value)
        
        next_index = element_index + 1
        if next_index < len(lists[list_index]):
            heapq.heappush(heap, 
                (lists[list_index][next_index], list_index, next_index))

    print(" ".join(map(str, result)))

if __name__ == "__main__":
    input_string = sys.stdin.read()
    lines = input_string.strip().split("\n")
    main(lines)