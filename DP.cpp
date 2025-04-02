#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string, std::vector, std::unordered_map, std::min, std::max;


/**
 * Min Cost Climbing Stairs
 *
 * Given an array cost that represents the cost of step on a staircase,
 * find the minimum cost to reach the top of the staircase.  
 * You can start from either the 0th or 1st step and can climb one or two steps at a time.  
 * 
 * @note Time complexity: O(n)
 */
 int minCost(vector<int> cost) {
    int n = cost.size();

    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[n];
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
 * A subsequence appears in the same relative order but not necessarily contiguous.
 * 
 * @note Time complexity: O(m * n)
 */
int longestCommonSubseq(string s, string t) {
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
 * Longest Palindromic Subsequence
 * 
 * Given a string s, find the length of the longest palindromic subsequence. 
 * 
 * @note Time complexity: O(n^2)
 */
int longestPalindromeSubseq(string s) {
    int n = s.length(); 

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // we start at the last row
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[1][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}


/**
 * Longest Increasing Subsequence
 * 
 * Given an array of integers, find the length of the longest increasing subsequence.
 * 
 * @note Time complexity: O(n^2)
 */
int longestIncreaseSubseq(vector<int> v) {
    int n = v.size();
    int result = 0;

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    
    return result;
}


/**
 * Knapsack Problem 
 * 
 * Given n items, where each item has a weight and a value, and a bag with capacity w, 
 * determine the maximum total value by selecting items without exceeding the capacity.
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