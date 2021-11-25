// Source : https://leetcode.com/problems/first-bad-version/
// Author : https://github.com/xinsheng
// Date   : 2021-11-25

/*
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, 
 * the latest version of your product fails the quality check. 
 * Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * For minimize the call number of `isBadVersion`, I check the middle place each time, and find out the solution.
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1,  end = n;
        int mid = 1;
        while (start < end) {
            int tmid = (end - start) / 2;
            if (tmid == 0) {
                break;
            }
            mid = start + tmid;

            if (isBadVersion(mid)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        return (isBadVersion(start)) ? start : end;
    }
};
