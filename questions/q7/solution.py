### ------------------------------- ###
### ----- YOUR CODE AT BOTTOM ----- ###
### ------------------------------- ###

class TreeNode:
    """
    A tree node with:
    - val: array of integers
    - children: list of TreeNode children
    """
    
    def __init__(self):
        self.val = []
        self.children = []
    
    def evaluate(self) -> int:
        """
        Evaluate the node:
        - If leaf (no children), return val[0] (the single element)
        - If internal, sum children's returns and return the INDEX of that sum in val
        
        Example:
        val = [1, 2, 3, 4, 5]
        child1.evaluate() = 3
        child2.evaluate() = 2
        sum = 5
        Find index of 5 in [1,2,3,4,5] = 4
        Return 4
        """
        if not self.children:
            # Leaf node - return the single element
            return self.val[0]
        else:
            # Internal node - sum children's returns
            child_sum = sum(child.evaluate() for child in self.children)
            # Find the index of child_sum in val array
            try:
                return self.val.index(child_sum)
            except ValueError:
                raise ValueError(f"Value {child_sum} not found in array {self.val}")


def _parse_array(s: str) -> list:
    """Parse '[1,2,3]' or '1,2,3' to [1,2,3]."""
    s = s.strip()
    if s.startswith('[') and s.endswith(']'):
        s = s[1:-1]
    if not s:
        return []
    return [int(x.strip()) for x in s.split(',')]


def _parse_children(s: str) -> list:
    """Parse '(child1)(child2)...' to list of TreeNode children."""
    children = []
    i = 0
    while i < len(s):
        if s[i] == '(':
            # Find matching closing paren
            depth = 1
            j = i + 1
            while j < len(s) and depth > 0:
                if s[j] == '(':
                    depth += 1
                elif s[j] == ')':
                    depth -= 1
                j += 1
            # s[i+1:j-1] is the child string
            child_str = s[i + 1:j - 1]
            children.append(_parse_tree(child_str))
            i = j
        else:
            i += 1
    return children


def _parse_tree(s: str) -> TreeNode:
    """Recursively parse the serialized string into TreeNode."""
    node = TreeNode()
    
    if s.startswith('L'):
        # Leaf node: L[1,2,3]
        array_part = s[1:]  # Remove 'L'
        node.val = _parse_array(array_part)
        node.children = []
    
    elif s.startswith('N'):
        # Internal node: N[1,2,3](child1)(child2)...
        # Find the array part and children parts
        bracket_end = s.find(']')
        array_part = s[1:bracket_end + 1]  # Include the brackets
        node.val = _parse_array(array_part)
        
        # Parse children from the remaining string
        children_str = s[bracket_end + 1:]
        node.children = _parse_children(children_str)
    
    return node



### ========== YOUR CODE BELOW ========== ###
"""
N[3,7,11](N[1,2](L[1])(L[1]))(L[2])
"""

def main(root):
    # YOUR CODE HERE

    def dfs(node):
        if not node.children:
            return node.val[0]
        else:
            child_sum = sum(dfs(child) for child in node.children)
            try:
                return node.val.index(child_sum)
            except ValueError:
                raise ValueError(f"Value {child_sum} not found in array {node.val}")


    print(dfs(root))


    # PRINT OUTPUT


if __name__ == "__main__":
    import sys
    data = sys.stdin.read().strip()
    root = _parse_tree(data)
    main(root)
    
