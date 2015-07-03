// 15 Three Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution
{
public:
	 vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int st = i+1;
            int ed = nums.size()-1;
            int target = -nums[i];
            while(st<ed)
            {
            	if((nums[st]+nums[ed]) < target)
            	{
            		st++;
            	}
            	else if((nums[st]+nums[ed]) > target)
            	{
            		ed--;
            	}
            	else
            	{
            		vector<int> vec{nums[i], nums[st], nums[ed]};
            		res.push_back(vec);
                    int k = st+1;
                    while(nums[k] == nums[k-1] && k < ed) k++;
                    st = k;
                    k = ed -1;
                    while(nums[k] == nums[k+1] && k > st) k--;
                    ed = k;
            	}
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	int A[] = {-1, 0, 1, 2, -1, -4};
	int n = 6;
	vector<int> nums(A, A+n);
	Solution mySolution;
	vector<vector<int> > res = mySolution.threeSum(nums);
	for(int i = 0; i < res.size(); ++i)
	{
		for(int j = 0; j < res[i].size(); ++j)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}