class Solution {
public:
 void powerset(vector<int> &nums , vector<int> &ans , int i , vector<vector<int>> &allsubsets){
    if( i == nums.size()){
        allsubsets.push_back(ans);
        
        // 
        return ;
    }
 
 ans.push_back(nums[i]);
 powerset(nums, ans , i+1 ,allsubsets);
 ans.pop_back();
 powerset(nums, ans , i+1 , allsubsets);
 }
    vector<vector<int>> subsets(vector<int>& nums){ 
    vector<vector<int>> allsubsets;
    vector<int>ans;
    powerset(nums, ans , 0, allsubsets);

    return allsubsets;

        
    }
};