// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively



bool isSafe(int i,int j, int R, int C)
{
    return i>=0 && i<R && j>=0 && j<C;
}

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(matrix[i][j]==2)
                q.push(make_pair(make_pair(i,j),0));
        
    int time=0;
   while(!q.empty())
    {
        pair<pair<int,int>,int> curr=q.front();
        q.pop();
        
        int x=curr.first.first;
        int y=curr.first.second;
        time= curr.second;
        
                int row[]={-1,0,0,1};
                int col[]={0,-1,1,0};
            
            for(int i=0;i<4;i++)        
                if(isSafe(x+row[i],y+col[i],R,C) && matrix[x+row[i]][y+col[i]]==1)
                {
                    q.push(make_pair(make_pair(x+row[i],y+col[i]),time+1));
                    matrix[x+row[i]][y+col[i]]=2;
                }
    }
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(matrix[i][j]==1)
                return -1;
    
    return time;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
