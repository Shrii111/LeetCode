class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
         int n = operations.size();
    vector<long long> lengths(n + 1);
    lengths[0] = 1; // word = "a"

    // Precompute lengths[i] = length after i operations
    for (int i = 0; i < n; ++i) {
        if (operations[i] == 0) {
            lengths[i + 1] = lengths[i] * 2;
        } else {
            lengths[i + 1] = lengths[i] * 2;
        }
        if (lengths[i + 1] > k) lengths[i + 1] = k; // Prevent overflow
    }

    function<char(int, long long)> dfs = [&](int idx, long long pos) -> char {
        if (idx == 0) return 'a'; // Base case

        long long prevLen = lengths[idx - 1];

        if (operations[idx - 1] == 0) {
            if (pos <= prevLen) {
                return dfs(idx - 1, pos);
            } else {
                return dfs(idx - 1, pos - prevLen);
            }
        } else {
            if (pos <= prevLen) {
                return dfs(idx - 1, pos);
            } else {
                char ch = dfs(idx - 1, pos - prevLen);
                return (ch == 'z') ? 'a' : ch + 1;
            }
        }
    };

    return dfs(n, k);
    }
};