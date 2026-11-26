#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, bagweight;
    cin >> n >> bagweight;
    vector<int> weight(n, 0), value(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> value[j];
    }
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
    for (int j = weight[0]; j <= bagweight; ++j) {
        dp[0][j] = value[0];
    }
    for (int i = 1; i < weight.size(); ++i) {
        for (int j = 0; j <= bagweight; ++j) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[n - 1][bagweight] << endl;
    return 0;
}


// 一维dp数组实现
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 读取 M 和 N
    int M, N;
    cin >> M >> N;

    vector<int> costs(M);
    vector<int> values(M);

    for (int i = 0; i < M; i++) {
        cin >> costs[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> values[j];
    }

    // 创建一个动态规划数组dp，初始值为0
    vector<int> dp(N + 1, 0);

    // 外层循环遍历每个类型的研究材料
    for (int i = 0; i < M; ++i) {
        // 内层循环从 N 空间逐渐减少到当前研究材料所占空间
        for (int j = N; j >= costs[i]; --j) {
            // 考虑当前研究材料选择和不选择的情况，选择最大值
            dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
        }
    }

    // 输出dp[N]，即在给定 N 行李空间可以携带的研究材料最大价值
    cout << dp[N] << endl;

    return 0;
}