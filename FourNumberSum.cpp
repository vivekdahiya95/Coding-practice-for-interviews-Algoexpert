#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

vector<vector<int>> fourNumberSum(vector<int> array,int targetSum)
{
    vector<vector<int>> quadruplets{};
    unordered_map<int,vector<vector<int>>> mp;
    for(int i=1;i<array.size();i++)
    {
        for(int j=i+1;j<array.size();j++)
        {
            int currentSum=array[i]+array[j];
            int difference=targetSum-currentSum;
            if(mp.find(difference)!=mp.end())
            {
                for(auto pair:mp[difference])
                {
                    pair.push_back(array[j]);
                    pair.push_back(array[i]);
                    quadruplets.push_back(pair);
                }
            }
        }
        for(int j=0;j<i;j++)
        {
            int currentSum=array[i]+array[j];
            if(mp.find(currentSum)!=mp.end())
            {
                mp[currentSum].push_back(vector<int>{array[i],array[j]});
            }
            else
            {
                mp[currentSum]=vector<vector<int>>{{array[i],array[j]}};
            }
        }
    }
    return quadruplets;
}
