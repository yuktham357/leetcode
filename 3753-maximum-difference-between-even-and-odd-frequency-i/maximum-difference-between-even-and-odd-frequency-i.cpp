class Solution {
public:
    int maxDifference(string s) {
            unordered_map<char, int> freq;
            for (char ch : s) {
                freq[ch]++;
            }
            int maxOdd = INT_MIN;
            int minEven = INT_MAX;
            for (auto& p : freq) {
                int f = p.second;
                if (f % 2 == 1) {  
                    maxOdd = max(maxOdd, f);
                } else {           
                    minEven = min(minEven, f);
                }
            }
            return maxOdd - minEven;
    }
};