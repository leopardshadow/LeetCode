
// 2022.3.14

/*
像這種字串處理的題目好考細心程度，一急就很容易漏掉一些 case QQ
像是 string find 時就常常忘記最後一個可能會出問題，要一開始加上 dummy 的 character 或另外處理
---
另外除非非常確定一定有東西，不然容器的 pop 都要檢查一下會不會爆掉
*/

class Solution {
public:
    string simplifyPath(string path) {
        
        // since it start with a single slash
        path = path.substr(1);
        path += "/";
        
        vector<string> st;
        
        int begin = 0, end = path.find("/");
        while(end != string::npos) {
                        
            string curr = path.substr(begin, end - begin);
            if(curr == "" || curr == ".")
                ;
            else if(curr == ".." && st.size() >= 1)
                st.pop_back();
            else if(curr == "..")
                ;   // cases like "../.."
            else
                st.push_back(curr);
            
            begin = end + 1;
            end = path.find("/", begin);
        }
         
        string ans = "";
        for(const string &s : st)
            ans = ans + "/" + s;
        
        if(ans == "")
            ans = "/";
        
        return ans;
    }
};

/*
Runtime: 12 ms, faster than 31.79% of C++ online submissions for Simplify Path.
Memory Usage: 11.9 MB, less than 5.44% of C++ online submissions for Simplify Path.
*/
