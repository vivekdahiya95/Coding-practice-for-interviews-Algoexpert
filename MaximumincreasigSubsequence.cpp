#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> builSequence(vector<int> array,vector<int> sequences,int currentIdx,int sum)
{
    vector<vector<int>> sequence={{},{}};
    sequence[0].push_back(sum);
    while(currentIdx!=INT_MIN)
    {
        sequence[1].insert(sequence[1].begin(),array[currentIdx]);
        currentIdx=sequences[currentIdx];
    }
    return sequence;
}

vector<vector<int>> maxIncreasingSubsequence(vector<int> array)
{
    vector<int> sequences(array.size(),INT_MIN);
    vector<int> sums=array;
    int maxSumIdx=0;
    for(int i=0;i<array.size();i++)
    {
        int currentNum=array[i];
        for(int j=0;j<i;j++)
        {
            int otherNum=array[j];
            if(otherNum<currentNum && sums[j]+currentNum>sums[i])
                {
                    sums[i]=sums[i]+currentNum;
                    sequences[i]=j;
                }
        }
        if(sums[i]>=sums[maxSumIdx])
            maxSumIdx=i;
    }
    return builSequence(array,sequences,maxSumIdx,sums[maxSumIdx]);
}