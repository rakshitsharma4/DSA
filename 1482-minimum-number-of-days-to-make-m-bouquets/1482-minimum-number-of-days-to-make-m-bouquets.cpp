class Solution {
public:
bool possible(vector<int>& bloomDay, int day, int m, int k){
    int nofb = 0;
    int n = bloomDay.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        if(bloomDay[i] <= day){
            count ++ ;
        } else{
            nofb += count/k ;
            count = 0;
        }
         
    }
     nofb += count/k ;
    return nofb >= m ;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = 1 ; 
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        while(st <= end){
            int mid = st + ( end - st )/2;
            if((long long) bloomDay.size() < (long long) m*k){
                return - 1;
            }
            if(possible(bloomDay, mid,  m, k)){
                end = mid -1;
            }else{
                st = mid +1;
            }
        }
        return st ;
        
    }
};