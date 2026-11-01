class Solution {
public:
int findays(vector<int>& weights, int capacity ){
    int n = weights.size();
    int days = 1;  
    int load = 0;
    for(int i = 0; i < n; i++ ){
        if( load + weights[i] > capacity ){
            days += 1;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int st = *max_element(weights.begin() , weights.end());
        int end = accumulate(weights.begin() , weights.end() ,0 );
        while( st <= end){
            int mid = st + (end - st)/2;
            int numberofdays = findays(weights , mid); 
            if(numberofdays <= days){
                end = mid -1 ; 

            }else{
                st = mid + 1 ; 
            }
        }
        return st ;
        
    }
};