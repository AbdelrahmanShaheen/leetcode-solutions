class Solution {
public:
    
    int binary_search(vector<int>& nums, int start ,int val){
        int end = nums.size() - 1;
        int pos = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(val > nums[mid])
            {
                start = mid + 1;
                pos = mid;
            }
            else
                end = mid - 1;
        }
        return pos;
    }
    
    int triangleNumber(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 0;
        sort(nums.begin() ,nums.end());
        for(int i = 0 ;i < sz-2; i++){
            
            for(int j = i+1 ;j < sz - 1; j++){
                int idx = binary_search(nums ,j+1 ,nums[i] + nums[j]);
                if(idx)
                cnt += idx - j;
            }
        }
        return cnt;
    }
};