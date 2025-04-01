#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string, std::vector, std::unordered_map, std::min, std::max;


/**
 * Coin Change
 *
 * Given an array of coin denominations and an integer amount n representing a total amount of money,
 * find the minimum number of coins that is needed to make up that amount.
 * 
 * @note Time complexity: O(m * n)
 */
 int minCoin(vector<int>& coins, int n) {
    vector<int> dp (n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int coin : coins) {
            if (coin <= i and dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}


/**
 * Unique Path
 * 
 * Count all unique paths from the top-left to the bottom-right of an m x n grid.
 * 
 * @note Time complexity: O(m * n)
 */
int uniquePath(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) { 
        for (int j = 1; j < n; j++) {
            dp[j] += dp[i - 1];
        }
    }

    return dp[n - 1];
}


/**
 * Longest Common Subsequence
 * 
 * Given two strings s and t, find the length of their longest common subsequence.
 * A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.
 * 
 * @note Time complexity: O(m * n)
 */
int lcs(const string& s, const string& t) {
    int m = s.length();
    int n = t.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}


/**
 * Knapsack Problem 
 * 
 * Given n items, where each item has a weight and a value, and a bag with capacity w, 
 * find the maximum total value by selecting items without exceeding the capacity.
 * 
 * @note Time complexity: O(n * w)
 */
int knapsack(vector<int> weight, vector<int> value, int w) {
    int n = weight.size(); 

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}