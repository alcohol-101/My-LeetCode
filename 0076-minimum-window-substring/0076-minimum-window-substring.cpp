class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for (char c : t) need[c]++;

        unordered_map<char,int> win;
        int left = 0, matched = 0;
        int minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (need.count(c)) {
                win[c]++;
                if (win[c] == need[c]) matched++;
            }

            while (matched == (int)need.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                if (need.count(d)) {
                    if (win[d] == need[d]) matched--;
                    win[d]--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};