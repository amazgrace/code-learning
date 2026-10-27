#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int startx = 0, starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i,j;
        while (loop--) {
            i = startx;
            j = starty;
            for (j; j < n - offset; j++){
                res[i][j] = count++;
            }

            for (i; i< n - offset; i++){
                res[i][j] = count++;
            }

            for (j; j > starty; j--){
                res[i][j] = count++;
            }

            for (i; i > startx; i--){
                res[i][j] = count++;
            }

            startx++;
            starty++;

            offset += 1;
        } 
        if (n % 2 == 1) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<vector<int>> result = solution.generateMatrix(n);
    
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}