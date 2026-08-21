class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        auto countUniqueMultiples = [&](long long limit) {
            int numCoins = coins.size();
            long long count = 0;
            for (int i = 1; i < (1 << numCoins); ++i) {
                long long multiples = 1;
                int numBits = 0;
                
                for (int j = 0; j < numCoins; ++j) {
                    if (i & (1 << j)) {
                        multiples = std::lcm(multiples, (long long)coins[j]);
                        if (multiples > limit) {
                            multiples = limit + 1;
                            break;
                        }
                        numBits++;
                    }
                }
                
                if (numBits % 2 == 1) {
                    count += limit / multiples;
                } else {
                    count -= limit / multiples;
                }
            }
            return count;
        };
        long long lowerBound = 1;
        long long maxCoin = *std::max_element(coins.begin(), coins.end());
        long long upperBound = (long long)k * maxCoin;

        while (lowerBound < upperBound) {
            long long middle = lowerBound + (upperBound - lowerBound) / 2;
            if (countUniqueMultiples(middle) < k) {
                lowerBound = middle + 1;
            } else {
                upperBound = middle;
            }
        }
        
        return lowerBound;
    }
};