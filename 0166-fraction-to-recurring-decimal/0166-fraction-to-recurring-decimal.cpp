class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        string result;
        if((long long)numerator * (long long)denominator < 0) {
            result += "-";
        }
        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);
        long long integerDiv = absNumerator / absDenominator;
        result += to_string(integerDiv);
        long long remain = absNumerator % absDenominator;
        if(remain == 0) {
            return result;
        }
        result += '.';
        unordered_map<int, int> mp;
        while(remain != 0) {
            if(mp.count(remain)) {
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }
            mp[remain] = result.length();
            remain *= 10;
            int digit = remain / absDenominator;
            result += to_string(digit);
            remain = remain % absDenominator;
        }
        return result;
    }
};