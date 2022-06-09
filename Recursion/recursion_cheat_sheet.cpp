#include "bits/stdc++.h"
// #include <boost/math/common_factor.hpp>
// #include <algorithm>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

vector<string> powerSet(string& s){
    int n = s.size();
    vector<string> ans;
    for(int num =0;num< (1<<n);num++){
        string sub = "";
        for(int i =0;i<n;i++)
            if(num&(1<<i)) sub += s[i];
        if(sub.size()>0) ans.pb(sub);
    }
    sort(all(ans));
    return ans;
}

// Recursion Start here

void reverseArr(vector<int>& v,int i){
    if(i>= v.size() / 2) return;
    swap(v[i],v[v.size() - i -1]);
    reverseArr(v,i+1);
}

bool isPalindrome(string& s,int i){
    if(i >= s.size() / 2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    isPalindrome(s,i+1);
}

void rSubset(int index,vector<int>& ds,vector<vector<int>>& ans,vector<int>& nums,int n){
    if(index == n){
        ans.pb(ds);
        return;
    }
    ds.pb(nums[index]);
    rSubset(index+1,ds,ans,nums,n);
    ds.ppb();
    rSubset(index+1,ds,ans,nums,n);
}

void rSubsetS(int index,vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,int n,int sum,int target){
    if(index == n){
        if(sum == target)
            ans.pb(ds);
        return;
    }
    ds.pb(nums[index]);
    sum += nums[index];
    rSubsetS(index+1,ans,ds,nums,nums.size(),sum,target);
    sum -= nums[index];
    ds.ppb();
    rSubsetS(index+1,ans,ds,nums,nums.size(),sum,target);
}

bool rSubsetSa(int index,vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,int n,int sum,int target){
    if(index == n){
        if(sum == target){
            ans.pb(ds);
            return true;
        }
        return false;
    }
    ds.pb(nums[index]);
    sum += nums[index];
    if(rSubsetSa(index+1,ans,ds,nums,nums.size(),sum,target) == true)
        return true;
    sum -= nums[index];
    ds.ppb();
    if(rSubsetSa(index+1,ans,ds,nums,nums.size(),sum,target) == true)
        return true;
    return false;
}

int rSubsetC(int index,vector<int>& ds,vector<vector<int>>& ans,int sum,int target,vector<int>& nums,int n){
    if(index == n){
        if(sum == target) return 1;
        else return 0;
    }
    ds.pb(nums[index]);
    sum += nums[index];
    int l = rSubsetC(index+1,ds,ans,sum,target,nums,n);
    ds.ppb();
    sum -= nums[index];
    int r = rSubsetC(index+1,ds,ans,sum,target,nums,n);
    return l + r;
}

void rCombSumUb(int index,vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,int target,int n){
    if(index == n){
        if(target == 0) ans.pb(ds);
        return;
    }
    if(nums[index] <= target){
        ds.pb(nums[index]);
        rCombSumUb(index,ans,ds,nums,target-nums[index],n);
        ds.ppb();
    }
    rCombSumUb(index+1,ans,ds,nums,target,n);
}

void rCombSumB(int index,vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,int target){
    // sort nums vector before executing bounded combination sum
    // if(index == n){
    if(target == 0) {
        ans.pb(ds);
        return;
    }
    // }
    for(int i=index;i<nums.size();i++){
        if(i>index and nums[i] == nums[i-1]) continue;
        if(nums[i] > target) break;
        ds.pb(nums[i]);
        rCombSumB(i+1, ans, ds, nums, target-nums[i]);
        ds.ppb();
    }
}

void rSubsetSum(int index,int sum,int n,vector<int>& nums,vector<int>& ds){
    if(index == n){
        ds.pb(sum);
        return;
    }
    rSubsetSum(index+1,sum+nums[index],n,nums,ds);
    rSubsetSum(index+1,sum,n,nums,ds);
}

void rSubsetSum2(int index,vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums){
    // sort nums array before using
    ans.pb(ds);
    for(int i =index;i<nums.size();i++){
        if(i!=index and nums[i] == nums[i-1]) continue;
        ds.pb(nums[i]);
        rSubsetSum2(i+1,ans,ds,nums);
        ds.ppb();
    }
}

void rPermutationSwap(int index,vector<int>& nums,vector<vector<int>>& ans){
    if(index == nums.size()){
        ans.pb(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        rPermutationSwap(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}

bool isSafeNQ(int row,int col,vector<string> board,int n){ // N-Queen
    int dr = row;
    int dc = col;
    while(row>=0 and col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row = dr;
    col = dc;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    row = dr;
    col = dc;
    while(row<n and col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}

void rNQueen(int col,vector<string>& board,vector<vector<string>>& ans,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafeNQ(row,col,board,n)){
            board[row][col] = 'Q';
            rNQueen(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

bool isValid(vector<vector<char>>& board,int row,int col,char c){
    for(int i =0;i<9;i++){
        if(board[i][col] == c) return false;
        if(board[row][i] == c) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){ // sudoko - solver
    for(int i =0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == '.'){
                for(char c ='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                        board[i][j] = c;
                        if(solve(board) == true) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isSafeMC(int node,int color[],bool graph[101][101],int n,int col){ // M-color
    for(int k=0;k<n;k++){
        if(k!=node and graph[k][node]==1 and color[k]==col){
            return false;
        }
    }
    return true;
}
bool rMColoring(int node,int color[],int m,int N,bool graph[101][101]){
    if(node == N) return true;
    for(int i=1;i<=m;i++){
        if(isSafeMC(node,color,graph,N,i)){
            color[node]=i;
            if(rMColoring(node+1,color,m,N,graph)) return true;
            color[node]=0;
        }
    }
    return false;
}

void rRatInMaze(int i,int j,vector<vector<int>>& a,int n,vector<string>& ans,string move,vector<vector<int>>& vis){
    if(i==n-1 and j==n-1){
        ans.push_back(move);
        return;
    }
    if(i+1<n and !vis[i+1][j] and a[i+1][j] == 1){
        vis[i][j] =1;
        rRatInMaze(i+1,j,a,n,ans,move+'D',vis);
        vis[i][j] =0;
    }
    if(j-1>=0 and !vis[i][j-1] and a[i][j-1] == 1){
        vis[i][j] =1;
        rRatInMaze(i,j-1,a,n,ans,move+'L',vis);
        vis[i][j] =0;
    }
    if(j+1<n and !vis[i][j+1] and a[i][j+1] == 1){
        vis[i][j] =1;
        rRatInMaze(i,j+1,a,n,ans,move+'R',vis);
        vis[i][j] =0;
    }
    if(i-1>=0 and !vis[i-1][j] and a[i-1][j] == 1){
        vis[i][j] =1;
        rRatInMaze(i-1,j,a,n,ans,move+'U',vis);
        vis[i][j] =0;
    }
}

bool isValidPP(string s,int start,int end){
    while(start<= end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}

void rPalindromePartion(int index,string s,vector<string>& path,vector<vector<string>>& ans){
    if(index == s.size()){
        ans.pb(path);
        return;
    }
    for(int i =index;i<s.size();i++){
        if(isValidPP(s,index,i)){
            path.pb(s.substr(index,i-index+1));
            rPalindromePartion(i+1,s,path,ans);
            path.ppb();
        }
    }
}

string rPermuattionSequence(int n,int k){
    int fact =1;
    vector<int> numbers;
    for(int i =1;i<n;i++){
        fact = fact*i;
        numbers.pb(i);
    }
    numbers.pb(n);
    string ans ="";
    k = k -1;
    while(true){
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0) break;
        k = k %fact;
        fact = fact / numbers.size();
    }
    return ans;
}

void solve(){}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif
    int t=1;
    cin>>t;
    while(t--){
        solve();
    } 
    return 0;
}