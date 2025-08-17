#include<bits/stdc++.h>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(string s) {    
    unordered_map<char, int> charIndexMap; // Map to store the last index of each character
    int maxLength = 0; // Variable to store the maximum length of substring found
    int start = 0; // Start index of the current substring

    for (int i = 0; i < s.length(); i++) {
        // If the character is already in the map and its index is greater than or equal to start
        if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start) {
            start = charIndexMap[s[i]] + 1; // Move start to the next index after the last occurrence
        }
        charIndexMap[s[i]] = i; // Update the last index of the character
        maxLength = max(maxLength, i - start + 1); // Calculate the length of current substring
    }

    return maxLength; // Return the maximum length found
}  




