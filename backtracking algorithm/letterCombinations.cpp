class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int Index) {
        if (Index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[Index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, Index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        result.clear();
        s.clear();
        if (digits.empty()) return result;
        backtracking(digits, 0);
        return result;
    }
};