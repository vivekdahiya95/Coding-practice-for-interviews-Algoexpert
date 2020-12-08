#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
        void insert(vector<int> value,int i=0);//define this youself
};

vector<int> findMaxSum(BinaryTree* tree);

int maxPathSum(BinaryTree tree)
{
    vector<int> maxSumArray=findMaxSum(&tree);
    return maxSumArray[1];
}

vector<int> findMaxSum(BinaryTree* tree)
{
    if (tree->data==NULL) return {0,0};
    vector<int> leftMaxSumArray=findMaxSum(tree->left);
    int leftMaxPathSumAsBranch=leftMaxSumArray[0];
    int leftMaxPathSumAsPath=leftMaxSumArray[1];

    vector<int> righMaxSumArray=findMaxSum(tree->right);
    int righMaxPAthSumAsBranch=righMaxSumArray[0];
    int rightMaxPAthSumAsPath=leftMaxSumArray[1];
    int maxChildSumAsBranch=max(righMaxPAthSumAsBranch,leftMaxPathSumAsBranch);
    int maxSumAsBranch=max(maxChildSumAsBranch+tree->data,tree->data);
    int maxSumAsRootNode=max(leftMaxPathSumAsBranch+tree->data+righMaxPAthSumAsBranch,maxSumAsBranch);
    int maxPathSum=max(leftMaxPathSumAsPath,max(rightMaxPAthSumAsPath,maxSumAsRootNode));

    return vector<int> {maxSumAsBranch,maxPathSum};
}