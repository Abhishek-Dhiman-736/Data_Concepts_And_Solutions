/*
 * Problem: Group Anagrams
 * Topic: Arrays and Hashing
 * Approach: Iterate through the array, sort each string to use as a canonical key, 
 * and store the original strings in a hash map using that sorted key.
 * Time Complexity: O(N * K log K) where N is the number of strings, and K is the maximum length of a string.
 * Space Complexity: O(N * K) to store the hash map and resulting arrays.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for(int i = 0; i < strs.size(); i++){
            string original = strs[i];
            string sortedWord = original;
            sort(sortedWord.begin(), sortedWord.end());
            
            m[sortedWord].push_back(original);
        }
        
        vector<vector<string>> ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};