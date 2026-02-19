import sys
import heapq

# ============================================
# IMPLEMENT YOUR SOLUTION IN THE main() FUNCTION
# ============================================

def main(lines):
    """
    Merge k sorted lists into a single sorted list.
    
    Args:
        lines: A list of strings where:
               - lines[0]: String containing k (number of lists)
               - lines[1] to lines[k]: Strings with space-separated integers
                 (or empty strings for empty lists)
    
    Your solution should print the merged sorted list to stdout
    """
    # ============================================
    # YOUR CODE HERE
    # ============================================
    
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
    
    # ============================================
    # END YOUR CODE
    # ============================================


# ============================================
# DO NOT MODIFY BELOW THIS LINE
# ============================================
if __name__ == "__main__":
    input_string = sys.stdin.read()
    lines = input_string.strip().split("\n")
    main(lines)