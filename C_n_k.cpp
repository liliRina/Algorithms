vector <vector<int>> C;
int c (int n, int k)
{  
    if (C[n][k]==0 && n!=0)
    {
        C[n][k]=c(n-1, k-1)+c(n-1, k);
    }
    return C[n][k];
}
int climbStairs(int n) 
{
    int res = 0;
    vector <int> f(n+1, 0);
    for (int i=0; i<n+1; i++)
    {
        C.push_back(f);
    }
    C[0][0]=1;
    for (int i=1; i<C.size(); i++)
    {
        C[i][0]=1;
        C[i][1]=i;
    }
    for (int i = n; i >=0 ; i-=2)
    {
        res+=c(n-(n-i)/2, i);
    }
    cout<<res<<endl;
    return res;
}
