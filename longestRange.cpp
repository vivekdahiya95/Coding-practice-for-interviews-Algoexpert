// find the longest continous range that is availabe in the given sequence
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

vector<int> largestRange(vector<int> array)
{
    vector<int> bestRange={};
    int longestLength=0;
    unordered_map<int,bool> nums={};
    for(int num:array)
    { 
        nums[num]=true;
    }
    for(int num:array)
    {
        if(!nums[num]) continue;
        nums[num]=false;
        int currentLength=1;
        int left=num-1;
        int right=num+1;
        while(nums.find(left)!=nums.end())
        {
            currentLength++;
            nums[num]=false;
            num--;
        }
        while(nums.find(right)!=nums.end())
        {
            currentLength++;
            nums[num]=false;
            num++;
        }
        if(currentLength>longestLength)
        {
            longestLength=currentLength;
            bestRange={left+1,right-1};
        }
    }
    return bestRange;
}