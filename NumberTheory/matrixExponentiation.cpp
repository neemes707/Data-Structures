#include<iostream>
#include<vector>
using namespace std;
int mod=1e9+7;
void multiply(vector<vector<int> >&A,vector<vector<int> >&B,int n){
    vector<vector<int> >res(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=0;
            for(int k=0;k<n;k++){
                res[i][j]= (res[i][j]+(A[i][j]*B[i][k])%mod)%mod;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=res[i][j];
        }
    }
}
void solve()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int> >nums(m,vector<int>(m));
    vector<vector<int> >I(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
            if(i==j){
                I[i][j]=1;
            }
            else{
                I[i][j]=0;
            }
        }
    }
    while(n){
        if(n%2==0){
            multiply(nums,nums,m);
            n-=1;
        }
        else{
            multiply(I,nums,m);
            n/=2;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<nums[i][j]<<" ";
        cout<<endl;
        }
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
