// Source : https://leetcode.com/problems/subdomain-visit-count/
// Author : https://github.com/xinsheng
// Date   : 2021-12-28

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> cnt;
        for (string cpdomain: cpdomains) {
            int pos = cpdomain.find(" ");
            if (pos != string::npos) {
                int count = stoi(cpdomain.substr(0, pos));
                string domain = cpdomain.substr(pos+1);
                cnt[domain] += count;
                
                pos = domain.find(".");
                while (pos != string::npos) {
                    domain = domain.substr(pos + 1);
                    cnt[domain] += count;
                    pos = domain.find(".");
                }
            }
        }
        vector<string> ans;
        for (auto t: cnt) {
            ans.push_back(to_string(t.second) + " " + t.first);
        }
        return ans;
    }
};

/*
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
*/
	