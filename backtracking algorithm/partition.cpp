class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(const string& s, int startIndex) {
        // 如果startIndex大于等于s的大小，说明已经遍历完了s，找到了一组方案
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            // 是回文子串
            if (isPalindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();   
        }
            
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};