#include<bits/stdc++.h>
using namespace std;

int getIdxOfFirstSmaller(vector<int> array,int startingIdx,int minVal)
{
  //find the index of first smaller element which is greater than the minVal
  for(int i=startingIdx;i<array.size();i++)
  {
      if(array[i]<array[startingIdx] && array[i]>minVal)
      {
           return i;
      }
  }
  return -1;
}

int getIdxOfFirstGreaterOrEqual(vector<int> array,int startingIdx,int maxVal)
{
    for(int i=startingIdx+1;i<array.size();i++)
    {
        if(array[i]>array[startingIdx] && array[i]<maxVal) return i;
    }
    return -1;
}

bool areSameBsts(vector<int> arrayOne,vector<int> arrayTwo,int rootIdxOne,int rootIdxTwo,int minVal,int maxVal)
{
    if(rootIdxOne==-1 || rootIdxTwo==-1) return rootIdxOne==rootIdxTwo;
    if(arrayOne[rootIdxOne]!=arrayTwo[rootIdxTwo]) return false;
    int leftRootIdxOne=getIdxOfFirstSmaller(arrayOne,rootIdxOne,minVal);
    int leftRootIdxTwo=getIdxOfFirstSmaller(arrayTwo,rootIdxTwo,minVal);
    int rightRootIdxOne=getIdxOfFirstGreaterOrEqual(arrayOne,rootIdxOne,maxVal);
    int rightRootIdxTwo=getIdxOfFirstGreaterOrEqual(arrayTwo,rootIdxTwo,maxVal);

    int currentVal=arrayOne[rootIdxOne];
    bool leftAreSame=areSameBsts(arrayOne,arrayTwo,leftRootIdxOne,leftRootIdxTwo,minVal,currentVal);
    bool rightAreSame=areSameBsts(arrayOne,arrayTwo,rightRootIdxOne,rightRootIdxTwo,currentVal,maxVal);
    return leftAreSame && rightAreSame;
}

bool sameBSTs(vector<int> arrayOne,vector<int> arrayTwo)
{
    return areSameBsts(arrayOne,arrayTwo,0,0,INT_MIN,INT_MAX);
}