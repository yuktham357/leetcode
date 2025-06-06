class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        stack<char> t;
        string p;
        int i = 0;
        for (char c : s) {
            t.push(c);
            freq[c - 'a']--;
            char smallest = 'a';
            while (smallest <= 'z' && freq[smallest - 'a'] == 0)
                smallest++;
            while (!t.empty() && (smallest > 'z' || t.top() <= smallest)) {
                p += t.top();
                t.pop();
            }
        }
        while (!t.empty()) {
            p += t.top();
            t.pop();
        }

        return p;
        
        }
};