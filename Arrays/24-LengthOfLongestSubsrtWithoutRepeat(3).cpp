class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> mp;
      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mp.find(s[right]) != mp.end())
          left = max(mp[s[right]] + 1, left);

        mp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
