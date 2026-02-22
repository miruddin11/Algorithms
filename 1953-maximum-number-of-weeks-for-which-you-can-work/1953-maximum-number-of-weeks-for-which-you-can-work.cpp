class Solution {
public:
    typedef long long ll;
    long long numberOfWeeks(vector<int>& milestones) {
        ll sum = 0;
        ll maxElement = *max_element(begin(milestones) , end(milestones));
        for(auto &m : milestones) {
            sum += m;
        }
        ll remaining = sum - maxElement;

        return min(sum , 2 * remaining + 1);
    }
};