class Solution {
public:
    int maxLength(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int ans = 2;

        for (int right = 0; right < n; right++) {

            // Check whether nums[right] is coprime
            // with every element in the current window.

            while (true) {

                bool valid = true;

                for (int i = left; i < right; i++) {

                    if (gcd(nums[i], nums[right]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    break;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};