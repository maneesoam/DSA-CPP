#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        for( int i=0; i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
                }
                return count<=1;
        
    }
};
int main(){
    Solution obj;
    vector<int>nums ={3,4,5,1,2};
    if(obj.check(nums))
    cout<<"true";
    else
    cout<<"false";
    return 0;
}