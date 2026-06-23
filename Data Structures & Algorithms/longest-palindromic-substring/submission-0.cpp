class Solution {
public:
    pair<int, int> rec(string s, pair<int, int> pr, int l, int r) {

        // CHANGE:
        // Don't stop just because l == 0 or r == n-1.
        // First check if current characters match, then see whether
        // expansion can continue.
        if (l < 0 || r >= s.size()) {
            return pr;
        }

        if (s[l] != s[r]) {
            return pr;
        }

        // CHANGE:
        // Update length and start index after confirming a match.
        int newLen = pr.first + ((l == r) ? 1 : 2);
        int start = l;

        // CHANGE:
        // Continue expanding until boundaries are crossed.
        return rec(s, {newLen, start}, l - 1, r + 1);
    }

    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();

        // CHANGE:
        // Initialize with length 1 because every character
        // is a palindrome of length 1.
        pair<int, int> resp = {1, 0};

        if (n == 0) return "";
        if (n == 1) return s;

        // CHANGE:
        // Iterate over ALL indices as centers.
        for (int i = 0; i < n; i++) {

            // CHANGE:
            // For odd palindrome, start from (i, i)
            // instead of (i-1, i+1).
            auto odd = rec(s, {0, i}, i, i);

            // CHANGE:
            // For even palindrome, start from (i, i+1)
            // only if i+1 exists.
            pair<int, int> eve = {0, i};
            if (i + 1 < n) {
                eve = rec(s, {0, i}, i, i + 1);
            }

            pair<int, int> pr =
                (eve.first > odd.first ? eve : odd);

            if (pr.first > resp.first)
                resp = pr;
        }

        res = s.substr(resp.second, resp.first);
        return res;
    }   
};
