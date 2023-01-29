// Distinct Echo Substrings


class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> result;
        for (int i = 0; i < n; i++) {
            for (int j = i, k = i, s1 = 0, s2 = 0; k + 1 < n; j++, k += 2) {
                s1 += text[j] - 'a';
                s2 += text[k] - 'a' + text[k + 1] - 'a';
                if (s1 * 2 != s2) {
                    continue;
                }
                if (text.substr(i, j - i + 1) != text.substr(j + 1, (k + 1) - (j + 1) + 1)) {
                    continue;
                }
                result.insert(text.substr(i, k + 1 - i + 1));
            }
        }
        return result.size();
    }
};