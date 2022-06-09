#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int graph_size = 1000;

struct Node
{
    int id,length=0;
};
vector <Node> graph[graph_size],heap;
bool fff(Node a, Node b)
{
    if(a.length > b.length) return 1;
    return 0;
}

bool visited[ graph_size ];

int main()
{
    Node vr; // beginning node
    int i,nodes,edges,a,b,s;
    cin>>nodes>>edges;
    for(i=1; i<=edges; i++)
    {
        cin>>a>>b>>s;
        vr.id=b;
        vr.length=s;
        graph[a].push_back(vr);
        vr.id=a;
        graph[b].push_back(vr);
    }
    vr.id=1;
    vr.length=0;
    heap.push_back(vr);
    make_heap(heap.begin(),heap.end(),fff);

    Node top,neighbour,curr;

    while(heap.size()!=0)
    {
        top=heap.front();
        pop_heap(heap.begin(),heap.end(),fff);
        heap.pop_back();
        if(visited[top.id]) continue;

        cout<<"marked "<<top.id<< endl;

        if(top.id==nodes)
        {
            cout<<top.length<< endl;
            return 0;
        }
        visited[top.id]=1;

        for(i=0; i < graph[top.id].size(); i++)
        {
            neighbour = graph[top.id][i];
            if(visited[neighbour.id] == 0)
            {
                curr = neighbour;
                curr.length += top.length;
                cout<<"pushed "<<curr.id<<" into the heap with length "<<curr.length<< endl;
                heap.push_back(curr);
                push_heap(heap.begin(),heap.end(),fff);
            }
        }
    }
    cout<<"Node "<<nodes<<" is unreachable"<< endl;
    return 0;
}
/*
7 9
1 2 18
1 4 5
2 4 6
4 5 4
2 5 3
2 3 2
3 6 3
3 7 5
6 7 1
*/
