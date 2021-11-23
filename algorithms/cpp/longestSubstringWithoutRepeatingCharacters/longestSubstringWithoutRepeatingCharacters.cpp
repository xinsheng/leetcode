// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : https://github.com/xinsheng
// Date   : 2021-11-23

/*
* Given a string s, find the length of the longest substring without repeating characters.
*/

#include <string.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
 * Idea:
 * Iterate each char in the string, and store the substring without repeating characters in `tmpStr`,
 * and keep the `finalStr` is the longest.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string finalStr = "";
        string tmpStr = "";
        for (size_t i = 0; i < s.length(); i++) {
            size_t pos = tmpStr.find(s[i]);
            if (pos != string::npos) {
                //found repeat, store the longest substring currently.
                finalStr = (tmpStr.length() > finalStr.length()) ? tmpStr : finalStr;
				//keep the substring that not contains repeat char
                tmpStr = tmpStr.substr(pos+1);
            }
            tmpStr += s[i];
        }
        finalStr = (tmpStr.length() > finalStr.length()) ? tmpStr : finalStr;
        return finalStr.length();
    }
};

/*
#include "gtest/gtest.h"
TEST(longestSubstringWithoutRepeatingCharacters, Test) {
	Solution s;
	EXPECT_EQ(s.lengthOfLongestSubstring(""), 0);
	EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
	EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
	EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
	EXPECT_EQ(s.lengthOfLongestSubstring("dvdf"), 3);
}
*/