class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        map<int ,int>start_to_idx; // start,index of interval before sorting.
        
        for(int i= 0 ;i < intervals.size() ;i++){
            start_to_idx[intervals[i][0]] = i;
        }
        vector<int>ans(intervals.size() ,-1); 
        
        //Doing the binary search.
        for(int i= 0 ;i < intervals.size() ;i++){
            auto it = start_to_idx.lower_bound(intervals[i][1]);
            if(it != start_to_idx.end())
            ans[i] =  it->second;
        }
        return ans;
    }
    //nlong(n) --> time complexity.
};