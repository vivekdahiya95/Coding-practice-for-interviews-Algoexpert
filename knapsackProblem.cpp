#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getKnapsackValues(vector<vector<int>> knapsackValues,vector<vector<int>> items,int weight);

vector<vector<int>> knapSackProblem(vector<vector<int>> items,int weight)
{
    vector<vector<int>> knapsackValues(items.size(),vector<int>(weight+1,0));
    for(int i=1;i<items.size();i++)
    {
        int currentWeight=items[i-1][0];
        int currentValue=items[i-1][1];
        for (int j=1;j<=weight;++j)
        {
            if(currentWeight>j) knapsackValues[i][j]=knapsackValues[i-1][j];
            else{
                knapsackValues[i][j]=max(knapsackValues[i-1][j],knapsackValues[i-1][j-currentWeight]+currentValue);
            }

        }
    }
    return getKnapsackValues(knapsackValues,items,knapsackValues[items.size()][weight]);
}

vector<vector<int>> getKnapsackValues(vector<vector<int>> knapsackValues,vector<vector<int>> items,int weight)
{
    vector<vector<int>> solution={{},{}};
    int i=knapsackValues.size()-1;
    int c=knapsackValues[0].size()-1;
    while(i>0)
    {
        if(knapsackValues[i][c]==knapsackValues[i-1][c])
        {
            i--;
        }
        else
        {
            solution[1].insert(solution[1].begin(),i-1);
            c-=items[i-1][1];
            i--;
        }
        if(c==0) break;
        
    }
    solution[0].push_back(weight);
    return solution;
}
