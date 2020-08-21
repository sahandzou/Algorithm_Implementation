#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    bool *visited;
    vector<vector<int> > *adj;
    stack<int> sort_stack;
 public:
    graph(int v){
        this->V=v;
        this->adj = new vector<vector<int> >(v);
        visited=new bool[v];
        for(int i=0;i<v;i++)visited[i]=false;
    }
    void add_vertex(int n ,int m){
        (*adj)[n].push_back(m);
    }
    void debug(){
        int node=0;
        for(vector<vector<int> >::iterator it=adj->begin();it!=adj->end();it++){

            cout<<"node:"<<node++<<endl;
            for(vector<int>::iterator iti =it->begin();iti!=it->end();iti++){
                cout<<*iti<<", ";
            }
        cout<<endl;
        }
            
    }
    void topological_sort(){
        for(int i=0;i<adj->size();i++){
            if(visited[i]==false){
                visited[i]=true;
                //printf("%d",i);
                recursion(i);
            }
        }
        //recursion(0);
        cout<<"topological sort: ";
        while(sort_stack.size()>1){
            cout<<sort_stack.top()<<" ,";
            sort_stack.pop();
        }
        cout<<sort_stack.top()<<endl;
    }
    void recursion(int n){
        //printf("%d",n);
        for(int i=0;i<(*adj)[n].size();i++){
            if(visited[(*adj)[n][i]]==false){
                visited[(*adj)[n][i]]=true;
                recursion((*adj)[n][i]);
            }

        }
        
        sort_stack.push(n);
        
    }



};
int main()
{
    graph test(5);
    test.add_vertex(0,1);
    test.add_vertex(0,3);
    test.add_vertex(0,2);
    test.add_vertex(1,3);
    test.add_vertex(2,3);
    test.add_vertex(4,2);
    test.add_vertex(4,3);
    test.topological_sort();
    //test.debug();
    return 0;
} 

