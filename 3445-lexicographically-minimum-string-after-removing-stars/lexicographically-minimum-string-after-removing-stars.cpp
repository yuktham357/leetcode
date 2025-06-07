class Solution {
public:
    string clearStars(string s) {
        string p;
        multiset<char> ms;
        for (char c : s) {
            if (c != '*') {
                p.push_back(c);  
                ms.insert(c);    
            } else {
                if (!ms.empty()) {
                    char smallest = *ms.begin();  
                    ms.erase(ms.begin());       
                    for (int j = p.size() - 1; j >= 0; j--) {
                        if (p[j] == smallest) {
                            p.erase(j, 1);
                            break;
                        }
                    }
                }
            }
        }
        return p;
    }
};