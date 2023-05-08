#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    vector< vector<int> > graph = {
        { 0, 5, 0, 0, 0, 4, 6, 0, 0, 0 },
        { 5, 0,10, 2, 0, 0, 0, 0, 0, 0 },
        { 0,10, 0, 0,12, 0, 0, 0, 0, 0 },
        { 0, 2, 0, 0, 9,11, 0, 0, 4, 0 },
        { 0, 0,12, 9, 0, 0, 0, 0, 5, 0 },
        { 4, 0, 0,11, 0, 0, 0,15,13, 0 },
        { 6, 0, 0, 0, 0, 0, 0,16, 0, 9 },
        { 0, 0, 0, 0, 0,15,16, 0,10, 5 },
        { 0, 0, 0, 4, 5,13, 0,10, 0,11 },
        { 0, 0, 0, 0, 0, 0, 9, 5,11, 0 }
    };
    set<int> SP = {}, SM = {0,1,2,3,4,5,6,7,8,9};
 
    int min = numeric_limits<int>::max();
    int l, t;
    
    for (auto i = 0; i < graph.size(); ++i)
        for (auto j = i; j < graph.size(); ++j)
            if (graph[i][j] < min && graph[i][j]!=0)
            {
                min = graph[i][j];
                l = i;
                t = j;
            }
    cout << "[" << l + 1 << ", " << t + 1 << " ];  ";
    SP.insert(l);   SM.erase(l);
    SP.insert(t);   SM.erase(t); 
    while (!SM.empty()) 
    {
        min = numeric_limits<int>::max();
        l = t = 0;
        for (auto i:SM)
            for(auto j: SP)
                if (graph[i][j]<min && graph[i][j] != 0)
                    {
                        min = graph[i][j];
                        l = i;
                        t = j;
                    }
        SP.insert(l);   SM.erase(l);
        cout << "[" << l+1 << ", " << t+1 << " ];  ";
    }
    system("pause");
    return 0;
}