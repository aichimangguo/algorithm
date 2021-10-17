class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mapvalue;
        for (int i = 0; i < nums.size(); i++) {
            if (mapvalue.count(nums[i])) {
                mapvalue[nums[i]][0]++;
                mapvalue[nums[i]][2] = i;
            } else {
                mapvalue[nums[i]] = {1, i, i};
            }
        }

        int nMaxValue = 0;
        int nIndex = 0;
        for(auto& value : mapvalue)
        {
            if(nMaxValue < value.second[0])
            {
                nMaxValue = value.second[0];
                nIndex = value.second[2] - value.second[1] + 1;
            }
            else if(nMaxValue == value.second[0])
            {
                nIndex = min(nIndex, value.second[2] - value.second[1] + 1);
            }
        }

        return nIndex;
    }
};
