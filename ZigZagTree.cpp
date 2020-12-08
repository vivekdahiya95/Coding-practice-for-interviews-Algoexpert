#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
};

void zigzagTraversal(node* root)
{
    if(!root) return;

    stack<struct node*> s1current;
    stack<struct node*> s2next;

    s1current.push(root);

    bool leftToRight=true;

    while(!s1current.empty())
    {
        struct node* top=s1current.top();
        s1current.pop();
        
    }
}
