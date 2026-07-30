#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        vector<long long> storage(26, 0);
        long long remaining = 0;
        string middle = "";

        for (char ch : s) {
            storage[ch - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (storage[i] % 2 != 0) {
                middle = string(1, char(i + 'a'));
            }
            storage[i] /= 2;
            remaining += storage[i];
        }

        auto get_perms = [](const vector<long long>& count, long long k) -> long long {
            __int128 perms = 1;
            long long N = 0;
            
            for (long long c : count) {
                if (c == 0) continue;
                N += c;
                
                long long r = c;
                if (r > N - r) r = N - r;
                
                __int128 combinations = 1;
                for (long long i = 1; i <= r; ++i) {
                    combinations = combinations * (N - i + 1) / i;
                    if (perms * combinations > k) return k + 1;
                }
                
                perms *= combinations;
                if (perms > k) return k + 1;
            }
            return (long long)perms;
        };

        long long total = get_perms(storage, k);
        if (k > total) {
            return "";
        }

        string ans = "";
        
        for (int step = 0; step < remaining; ++step) {
            for (int i = 0; i < 26; ++i) {
                if (storage[i] == 0) {
                    continue;
                }

                storage[i]--;
                long long branch_size = get_perms(storage, k);

                if (k <= branch_size) {
                    ans.push_back(char(i + 'a'));
                    break;
                } else {
                    k -= branch_size;
                    storage[i]++;
                }
            }
        }

        string left = ans;
        string rev_left = left;
        reverse(rev_left.begin(), rev_left.end());

        return left + middle + rev_left;
    }
};