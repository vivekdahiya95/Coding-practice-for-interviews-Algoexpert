#include<bits/stdc++.h>
using namespace std;

class JobGraph
{
    JobGraph();
    void addDep(JobGraph a,JobGraph b);


};

JobGraph* createJobGraph(vector<int> jobs,vector<vector<int>> deps)
{
    JobGraph* graph=new JobGraph(jobs);
    for(vector<int> dep:deps)
        graph->addDep(dep[0],dep[1]);

    return graph;

}

void removeDeps(JobGraph* node,vector<JobNode*> *nodeWithNoPrereq)
{
    while(node->deps.size())
    {
        JobNode* dep=node->deps.back();
        node->deps.pop_back();
        dep->numOfPrereq--;
        if(!dep->numOfPrereqs)
            nodeeswithNoPrereqs->push_back(dep);
    }
}

vector<int> TopologicalSort(vector<int> jobs,vector<vector<int>> deps)
{
    JobGraph* jobgraph= createJobGraph(jobs,deps);
    return getOrderedjobs(jobgraph);

}