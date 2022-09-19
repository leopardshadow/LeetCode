
# 2022.9.19

"""
parsing
---
desired onboard date QQ
"""

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        m = { }
        
        for path in paths:
            ps = path.split(" ")
            d = ps[0]
            for f in ps[1:]:
                found = re.search('(.*)\((.*)\)', f)
                fullpath = d + '/' + found[1]
                if found[2] in m:
                    m[found[2]].append(fullpath)
                else:
                    m[found[2]] = [fullpath]
        
        ans = []
        
        for key, value in m.items():
            if len(value) > 1:
                ans.append(value)
                
        return ans
    
"""
Runtime: 120 ms, faster than 74.41% of Python3 online submissions for Find Duplicate File in System.
Memory Usage: 23.7 MB, less than 73.05% of Python3 online submissions for Find Duplicate File in System.
"""
