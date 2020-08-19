// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * g[]: graph representation
 */


void dfs(int V, vector<int> g[], vector<bool> &v,int src)
{
    v[src]=true;
    
    for(int i:g[src])
    {
        if(v[i]==false)
        {
            dfs(V,g,v,i);
        }
    }
}


int findMother(int V, vector<int> g[]) 
{ 

  vector<bool> v(V,false);
  
  int mother=0;
  for(int i=0;i<V;i++)
  {
    
      if(v[i]==false)
      {
          mother=i;
          dfs(V,g,v,i);
      }
  }
  
  vector<bool> vis(V,false);
  dfs(V,g,vis,mother);
  
  for(bool b:vis)
  {
      if(b==false)
      return -1;
  }
  
  return mother; 
  
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
