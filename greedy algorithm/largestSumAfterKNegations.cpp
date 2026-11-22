class Solution {
private:
    static bool cmp(int a, int b) {
    return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size() && k > 0; i++) {
            if (A[i] < 0) {
                A[i] = -A[i];
                k--;
            }
        }
        if (k % 2 == 1) {
            A[A.size() - 1] *= -1; 
        }
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};