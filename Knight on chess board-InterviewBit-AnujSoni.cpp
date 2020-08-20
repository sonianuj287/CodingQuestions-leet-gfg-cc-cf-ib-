bool isSafe(int x,int y,int a,int b){
    return !(x<=0 || y<=0 || x>a || y>b);
}

int Solution::knight(int a, int b, int c, int d, int e, int f) {
    if(c == e && d == f)
        return 0;
    int count = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(a+1,vector<bool>(b+1,false));
    vector<int> row = {2,1,-1,-2,-2,-1,1,2};
    vector<int> col = {1,2,2,1,-1,-2,-2,-1};
    vis[c][d] = true;
    q.push({c,d});
    while(!q.empty()){
        int x = q.size();
        while(x--){
            pair p = q.front();q.pop();
            int u = p.first;
            int v = p.second;
            for(int i=0;i<8;i++){
                if(isSafe(u+row[i],v+col[i],a,b) && !vis[u+row[i]][v+col[i]]){
                    if(u+row[i] == e && v+col[i] == f)
                        return count+1;
                    vis[u+row[i]][v+col[i]] = true;
                    q.push({u+row[i],v+col[i]});
                }
            }
        }
        count++;
    }
    return -1;
}
