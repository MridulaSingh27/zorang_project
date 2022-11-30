double Max = 10000000000

int fun(int i, int n, int mask)
{
    int dp[n + 1][1 << (n + 1)];
    if (mask == ((1 << i) | 3))
        return dist[1][i];
    if (dp[i][mask] != 0)
        return dp[i][mask];
  
    int res = MAX;
    for (int j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = min(res, fun(j, mask & (~(1 << i)))
                                    + dist[j][i]);
    return dp[i][mask] = res;
}



int tsp(vector<vector<double>> location){
    int n = location.size();
    vector <vector<int>> dist(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
 double la1=location[i][1],la2=location[j][1];
            double lo1=location[i][2],lo2=location[j][2];
            double distance = sqrt((la1-la2)*(la1-la2) + (lo1-lo2)*(lo1-lo2))
            dist[i][j]= distance;
        }
    }


    int ans = MAX;
    int y=-1;
    for (int i = 1; i <= n; i++)
        int x = fun(i, (1 << (n + 1)) - 1) + dist[i][1];
        if(x<ans){
            ans=x;y=i;
        }
}
