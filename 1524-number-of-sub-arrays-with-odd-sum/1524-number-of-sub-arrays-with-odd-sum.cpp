class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int mod = 1e9 + 7;

        long long even = 1;
        long long odd = 0;

        long long ans = 0;
        int prefix = 0;

        for(int i = 0; i < arr.size(); i++) {

            prefix += arr[i];

            if(prefix % 2 == 1) {

                ans = (ans + even) % mod;
                odd++;

            }
            else {

                ans = (ans + odd) % mod;
                even++;

            }
        }

        return ans;
    }
};