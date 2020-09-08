from typing import List


# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        return self.recursive(root)

    def recursive(self, root: 'Node') -> List[int]:
        result = []
        if root is not None:
            result.append(root.val)
            for c in root.children:
                result.extend(self.recursive(c))

        return result
