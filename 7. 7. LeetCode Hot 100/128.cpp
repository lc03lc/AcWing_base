class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        set<int> s(nums.begin(), nums.end());
        set<int>::iterator index = s.begin();
        set<int>::iterator end = s.end();
        end--;
        int max_val = 1;
        int cur = 1;
        while (index != end) {
            set<int>::iterator tmp = index;
            index++;
            if ((*index) - (*tmp) == 1) {
                cur++;
                if (cur > max_val) {
                    max_val = cur;
                }
            } else {
                cur = 1;
            }
        }
        return max_val;
    }
};