#include<bits/stdc++.h>
#include<numeric>
using namespace std;

#define mod 1000000007
//given a series of students and their scores
//distributre the minimum rewards among them such that a higher score gets a better rewards than his successor 
//or predecessor

vector<int> getLocalMins(vector<int> array);
void expandFromLocalMinIdx(int localMinIdx,vector<int> scores,vector<int>& rewards);

int getMinRewards(vector<int> array)
{
    vector<int> rewards(array.size(),1);
    vector<int> localmins=getLocalMins(array);
    for(auto idx:localmins)
    {
        expandFromLocalMinIdx(idx,array,rewards);
    }
    return accumulate(rewards.begin(),rewards.end(),0);
}

vector<int> getLocalMins(vector<int> array)
{
    if(array.size()==1) return vector<int>{array[0]};
    vector<int> localmins{};
    for(int i=0;i<array.size();i++)
    {
        if(i==0 && array[i+1]>array[i])
            localmins.push_back(i);
        if(i==array.size()-1 && array[i-1]>array[i])
            localmins.push_back(i);
        if(i=array.size()-1 || i==0)
            continue;
        if(array[i]<array[i+1] && array[i]<array[i-1])
        localmins.push_back(i);
    }
    return localmins;
}
void expandFromLocalMinIdx(int localMinIdx,vector<int> array,vector<int>& rewards)
{
    int leftIdx=localMinIdx-1;
    int rightIdx=localMinIdx+1;
    while(leftIdx>=0 && array[leftIdx]>array[leftIdx+1])
    {
        rewards[leftIdx]=max(rewards[leftIdx],rewards[leftIdx+1]+1);
        leftIdx--;
    }
    while(rightIdx<array.size() && array[rightIdx]>array[rightIdx-1])
    {
        rewards[rightIdx]=rewards[rightIdx-1]+1;
        rightIdx++;    
    }
}