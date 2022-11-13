
# 2022.11.13

"""
偷懶用 python
---
看 C++ 比較好的做法是用 stack 來處理這種把東西倒過來的操作
"""

class Solution:
    def reverseWords(self, s: str) -> str:
        xs = s.split(' ')
        xs = filter(lambda x: len(x) > 0, xs)
        return reduce(lambda x, y: y + ' ' + x, xs)
"""
Runtime: 71 ms, faster than 29.64% of Python3 online submissions for Reverse Words in a String.
Memory Usage: 14.2 MB, less than 16.15% of Python3 online submissions for Reverse Words in a String.
"""
