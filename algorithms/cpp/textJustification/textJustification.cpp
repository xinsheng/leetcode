// Source : https://leetcode.com/problems/text-justification/
// Author : https://github.com/xinsheng
// Date   : 2021-12-27

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string justifyLine(vector<string>& words, int maxWidth) {
        string tmp = "";
        for (int i = 0; i < words.size(); i++) {
            maxWidth -= words[i].length();
        }

        int i = 0; 
        while (maxWidth > 0) {
            if (i >= words.size() - 1)
                i = 0;
            words[i++] += " ";

            maxWidth--;
        }
        for (string t : words) {
            tmp += t;
        }
        return tmp;
    }

    string leftJustify(vector<string>& words, int maxWidth) {
        string tmp = "";
        for (int i = 0; i < words.size(); i++) {
            maxWidth -= words[i].length();
            if (i != words.size() - 1) {
                maxWidth -= 1;
                words[i] += " ";
            }
            tmp += words[i];
        }

        for (int i = 0; i < maxWidth; i++) {
            tmp += " ";
        }
        return tmp;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int start = 0;
        int end = 0;

        int pad = maxWidth;

        vector<string> currentWords;
        int currentLen = 0;
        for (int i = 0; i < n; i++) {
            int wlen = words[i].length();
            int spaceCount = currentWords.size() - 1;

            int nextLen = words[i].length();

            if (currentLen + spaceCount == maxWidth || (currentLen + spaceCount + nextLen + 1 > maxWidth)) {
                ans.push_back(justifyLine(currentWords, maxWidth));
                currentWords.clear();
                currentLen = 0;
                currentLen += wlen;
                currentWords.push_back(words[i]);
            }
            else {
                currentLen += wlen;
                currentWords.push_back(words[i]);
            }
        }

        ans.push_back(leftJustify(currentWords, maxWidth));
        return ans;
    }
};

/*
Test Case:
["This", "is", "an", "example", "of", "text", "justification."]
16
["What", "must", "be", "acknowledgment", "shall", "be"]
16
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
20
["ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"]
16
["Listen","to","many,","speak","to","a","few."]
6
*/
	