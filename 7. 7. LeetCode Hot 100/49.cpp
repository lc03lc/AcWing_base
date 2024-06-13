class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto str: strs)
        {
            auto str_copy = str;
            sort(str.begin(), str.end());
            m[str].push_back(str_copy);
        }
        
        vector<vector<string>> ans;
        for(auto p: m)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};