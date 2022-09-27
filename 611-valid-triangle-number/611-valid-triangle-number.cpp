class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 0;
        sort(nums.begin() ,nums.end());
        for(int i = 0 ;i < sz-2; i++){
            
            for(int j = i+1 ;j < sz - 1; j++){
                auto it = lower_bound(nums.begin()+(j+1) ,nums.end() ,nums[i] + nums[j]); 
                int idx = sz;
                if(it != nums.end())
                {
                    idx = it - nums.begin();
                }
                cnt += idx - j - 1;
            }
        }
        return cnt;
    }
};