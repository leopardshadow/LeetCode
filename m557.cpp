
# 2022.9.22

class Solution:
    def reverseWords(self, s: str) -> str:
        xs = s.split(' ')
        ans = ''
        for x in xs:
            ans += x[::-1] + ' '
        return ans[:-1]

    """
Runtime: 58 ms, faster than 66.20% of Python3 online submissions for Reverse Words in a String III.
Memory Usage: 14.6 MB, less than 46.10% of Python3 online submissions for Reverse Words in a String III.
"""
