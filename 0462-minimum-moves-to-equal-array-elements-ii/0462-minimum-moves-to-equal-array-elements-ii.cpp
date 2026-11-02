class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Find median
        int n = nums.size();
        int median = nums[n / 2];

        // Step 3: Calculate total moves
        int moves = 0;

        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};