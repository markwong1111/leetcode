#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string, std::vector, std::unordered_map, std::min, std::max;


/**
 * Kadane's Algorithm
 * 
 * Given an array of integers, find the subarray with the maxium sum
 * 
 * @note Time complexity: O(n)
 */
int kadane(vector<int>& v) {
    int sum = 0;
    int result = INT_MIN;
   

    for (int num : v) {
        sum += num;
        result = max(result, sum);

        if (sum < 0) { 
            sum = 0;
        }
    }

    return result;
}


/**
 * Sliding Window - Maximum Window Sum
 * 
 * Given an array of integers, find the subarray with the maximum sum of size k.
 * 
 * @note Time complexity: O(n)
 */
int maxWindow(vector<int>& v, int k) {
    int left = 0;
    int sum = 0; 
    int result = INT_MIN;

    for (int right = 0; right < v.size(); right++) {
        sum += v[right];

        if (right >= k - 1) {
            result = max(result, sum);
            sum -= v[left];
            left++;
        }
    }

    return result;
}


 /**
 * Sliding Window - Minimum Window Substring
 * 
 * Find the shortest substring of s that contains all characters of t including duplicates.
 * If no such substring exists, return an empty string.
 * 
 * @note Time complexity: O(m + n)
 */
string minWindow(string s, string t) {
    if (s.length() < t.length()) return "";

    int left = 0;
    int min = INT_MAX;
    int index = 0;
    int count = t.length();

    unordered_map<char, int> map;

    for (const char& c : t) {
        map[c]++;
    }

    for (int right = 0; right < s.length(); right++) {
        if (map[s[right]] > 0) {
            count--;
        }

        map[s[right]]--;

        while (count == 0) {
            if (right - left + 1 < min) {
                min = right - left + 1;
                index = left;
            }
      
            if (map[s[left]] == 0) {
                count++;
            }

            map[s[left]]++;
            left++;
        }
    }

    return min == INT_MAX ? "" : s.substr(index, min);
}


/**
 * Two Pointer
 * 
 * Given a sorted array of integers, find two numbers that add up to a target number.
 * 
 * @note Time complexity: O(n)
 */
vector<int> twoSum(vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        int sum = v[left] + v[right];

        if (sum < target) {
            left++; 
        }
        else if (sum > target) {
            right--;
        }
        else {
            return {v[left], v[right]};
        }
    }

    return {};
}


/**
 * Prefix Sum
 * 
 * Given an array of integers, find the total number of subarrays whose sum equals to k.
 * 
 * @note Time complexity: O(n)
 */
int subarraySum(vector<int>& v, int k) {
    int result = 0;
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = 1;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        result += map[sum - k];
        map[sum]++;
    }

    return result;
}