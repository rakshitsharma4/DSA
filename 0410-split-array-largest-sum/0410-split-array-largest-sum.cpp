class Solution {
public:
bool ISpossible(vector<int>& nums, int k , int maxvalue){
    int n = nums.size();
    int crrsum = 0;
    int maxsplit = 1;
    for(int i = 0; i < n; i++){
        if( crrsum + nums[i] <= maxvalue){
            crrsum += nums[i];

        }else{
            maxsplit ++ ;
            crrsum = nums[i];
        }
        
    }
    return maxsplit <= k ;
}
    int splitArray(vector<int>& nums, int k) {
        int st  = *max_element(nums.begin() , nums.end());
        int end = accumulate(nums.begin() , nums.end() ,0);
        while(st <= end){
            int mid = st + (end - st)/2;
            if(ISpossible(nums, k ,mid )){
                end  = mid -1;

            }else{
                st = mid +1;
            }
        }
        return st ;
        
    }
};