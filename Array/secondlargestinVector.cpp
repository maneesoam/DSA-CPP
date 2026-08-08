#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:

    int secondLargestElement(vector<int> & nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>largest)
           { secondLargest = largest;
            largest = nums[i];
            }else if(nums[i]>secondLargest && nums[i]!=largest){
            secondLargest = nums[i];
            }
        }
            if(secondLargest == INT_MIN){
                cout<<"No second Largest Element is Found";
                return -1;
            }
            else{
                cout<< "second Largest Element is "<<secondLargest<<endl;
                return secondLargest;

            }

        }
      
    
};
int main() {
    vector<int> nums = {10, 5, 20, 8, 20};

    Solution s;
    s.secondLargestElement(nums);

    return 0;
}
