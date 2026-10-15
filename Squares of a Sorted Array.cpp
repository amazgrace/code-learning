#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A){
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> A = {-4, -1, 0, 3, 10};
    vector<int> result = solution.sortedSquares(A);
    for (int x : result) {
        cout << x << "";
    }
    return 0;
}

