/*
Given a sorted integer array without duplicates, return the summary of its ranges.
Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/

class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string>res;
        int n=nums.size();
        if(n==0)
            return res;
        int s=nums[0],e=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                e++;
            else
            {
                if(s==e)
                    res.push_back(to_string(e));
                else
                    res.push_back(to_string(s)+'-'+'>'+to_string(e));
                s=e=nums[i];
            }
        }
        if(s==e)
            res.push_back(to_string(e));
        else
            res.push_back(to_string(s)+'-'+'>'+to_string(e));
        return res;
    }
};
