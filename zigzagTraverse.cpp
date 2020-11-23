#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

bool isOutOfBounds(int row,int col,int height,int width)
{
    return row<0 || row>height ||col<0 ||col>width;
}

vector<int> zigzagTraverse(vector<vector<int>> array)
{
    int height=array.size();
    int width=array[0].size();
    vector<int> result{};

    int row=0;
    int col=0;

    bool goingDown=true;

    while(!isOutOfBounds(row,col,height,width))
    {
        result.push_back(array[row][col]);
        if(goingDown)
        {
            if(row==height || col==0)
            {
                goingDown=false;
                if(row==height) col++;
                else row++;
            }
            else{
                row++;
                col--;
            }
        }
        else{
            if(row==0 || col==width)
            {
                goingDown=true;
                if(col=width) row++;
                else col++;
            }
            else row--,col++;
            }
    }
    return result;

}