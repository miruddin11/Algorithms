class Solution {
public:
    unordered_map<long long, int> mp;
    string S;
    int K;
    int solve(long long i, long long uniqueChars, bool canChange) {
        long long key = (i << 27) | (uniqueChars << 1) | (canChange);
        if (mp.count(key)) { 
            return mp[key];
        }
        if (i == S.size()) {
            return 0;
        }
        int characterIndex = S[i] - 'a';
        int uniqueCharsUpdated = uniqueChars | (1 << characterIndex);
        int uniqueCharCount = __builtin_popcount(uniqueCharsUpdated);
        int result;
        if (uniqueCharCount > K) {
            result = 1 + solve(i + 1, 1 << characterIndex, canChange);
        } else {
            result = solve(i + 1, uniqueCharsUpdated, canChange);
        }
        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; ++newCharIndex) {
                int newSet = uniqueChars | (1 << newCharIndex);
                int newUniqueCharCount = __builtin_popcount(newSet);
                if (newUniqueCharCount > K) {
                    result = max(result, 1 + solve(i + 1, 1 << newCharIndex, false));
                } else {
                    result = max(result, solve(i + 1, newSet, false));
                }
            }
        }
        return mp[key] = result;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true) + 1;
    }
};