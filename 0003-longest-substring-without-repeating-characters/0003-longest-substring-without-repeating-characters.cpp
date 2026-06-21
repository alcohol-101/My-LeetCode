// 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // 如果字符重复，移动 left 直到重复字符被移除
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            // 加入当前字符
            window.insert(s[right]);
            // 更新最大长度
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};