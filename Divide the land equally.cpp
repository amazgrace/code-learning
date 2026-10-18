#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    } 

    // 统计横向
    vector<int> rowSum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rowSum[i] += vec[i][j];
        }
    }

    // 统计纵向
    vector<int> colSum(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            colSum[j] += vec[i][j];
        }
    }

    int result = INT_MAX;
    int rowcut = 0;
    for (int i = 0; i < n - 1; i++) {
        rowcut += rowSum[i];
        result  = min(result, abs(sum - 2 * rowcut));
    }

    int colcut = 0;
    for (int j = 0; j < m - 1; j++) {
        colcut += colSum[j];
        result = min(result, abs(sum - 2 * colcut));
    }
    cout << result << endl;
}