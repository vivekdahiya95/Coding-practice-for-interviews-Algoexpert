#include<bits/stdc++.h>
using namespace std;

int getMinimumSpaces(string pi,set<string> numbersTable,unordered_map<int,int> *cache,int i)
{
    int idx=i;
    if(i==pi.length()) return -1;
    if(cache->find(idx)!=cache->end()) return cache->at(idx);
    int minSpaces=INT_MAX;
    for(int i=idx;i<pi.length();i++)
    {
        string prefix=pi.substr(idx,i+1-idx);
        if(numbersTable.find(prefix)!=numbersTable.end())
        {
            int minSpacesInSuffix=getMinimumSpaces(pi,numbersTable,cache,i+1);
            if(minSpacesInSuffix==INT_MAX)
            {
                minSpacesInSuffix=min(minSpacesInSuffix,minSpaces);
            }
            else{
                minSpaces=min(minSpaces,minSpacesInSuffix+1);
            }
            
        }

    }
    cache->insert({idx,minSpaces});
    return cache->at(idx);
}

int numberinPI(string pi, vector<string> numbers)
{
    set<string> numberTable;
    for(string number:numbers)
        numberTable.insert(number);
    
    unordered_map<int,int> cache;
    for(int i=pi.length()-1;i>=0;i--)
    {
        getMinimumSpaces(pi,numberTable,&cache,i);
    }
    return cache[0]==INT_MAX?-1:cache[0];
}