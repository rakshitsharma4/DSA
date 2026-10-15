
class Solution {
public:
    long long calculatetotalhours(vector<int>& piles, int h) {
        long long totalh = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalh += ceil((double)piles[i] / (double)h);
        }

        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = *max_element(piles.begin(), piles.end());

        while (st <= end) {
            int mid = st + (end - st) / 2;
            long long totalh = calculatetotalhours(piles, mid);

            if (totalh <= h) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return st;
    }
};
