# -*- coding:utf-8 -*-
from queue import LifoQueue


class Solution:
    stack = LifoQueue()
    minStack = LifoQueue()
    def push(self, node):
        # write code here
        if self.stack.empty():
            self.stack.put(node)
            self.minStack.put(node)
        else:
            self.stack.put(node)
            lastMin = self.minStack.get()
            self.minStack.put(lastMin)
            self.minStack.put( min(node, lastMin ))
    def pop(self):
        # write code here
        if self.stack.empty():
            return None
        else:
            self.minStack.get()
            return self.stack.get()
    def top(self):
        # write code here
        if self.stack.empty():
            return None
        else:
            t = self.stack.get()
            self.stack.put(t)
            return t

    def min(self):
        # write code here
        if self.minStack.empty():
            return None
        else:
            t = self.minStack.get()
            self.minStack.put(t)
            return t
