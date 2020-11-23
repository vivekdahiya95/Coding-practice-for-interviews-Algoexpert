#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define int long long int

//given a array of numbers find the subarray that need to be sorted in order to get the final array sorted
//give the smallest subarry that need to be sorted
bool isOutOfOrder(int i,int num,vector<int> array);
vector<int> subarraySort(vector<int> array)
{
    int left_number=INT_MAX;
    int right_number=INT_MIN;

    for(int i=0;i<array.size();i++)
    {
        int num=array[i];
        if(isOutOfOrder(i,num,array))
        {
            left_number=min(num,left_number);
            right_number=max(num,right_number);
        }
    }
    if(left_number==INT_MAX)
        return vector<int>{-1,-1};
    
    int leftIdx=0;
    while(left_number>=array[leftIdx])
    {
        leftIdx++;
    }
    int rightIdx=array.size()-1;
    while(right_number<=array[rightIdx])
    {
        rightIdx--;
    }
    return vector<int> {leftIdx,rightIdx};
}


bool isOutOfOrder(int i,int num,vector<int> array)
{
    if(i==0)
    {
        return array[i+1]>num;
    }
    if(i==array.size()-1)
    {
        return num>array[i-1];
    }
    return array[i+1]> num && array[i-1]<num;
}