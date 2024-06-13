class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            m[tmp] = i;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.find(nums[i])!=m.end() && i!=m[nums[i]])
            {
                ans.push_back(i);
                ans.push_back(m[nums[i]]);
                break;
            }
        }
        return ans;
    }
};