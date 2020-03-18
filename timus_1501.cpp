#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first
#define S second
         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 

int n;
string s1,s2;

int dp[1005][1005];

int solve(int i, int j, int st1, int st2){
	
	if(dp[i][j] != -1)
		return dp[i][j];
	
	if(st1 + st2 == 2*n)
		return 0;
	
	if(abs(st1 - st2) > 1 || (j>=n && i>=n)){
		dp[i][j] = -1;
		return -1;
	}
	
		
	int res1,res2;
	
	if(i < n){
		if(s1[i] == '0'){ res1 = st1+1; res2 = st2; }
		else { res1 = st1; res2 = st2 + 1; }
	
		if(solve(i+1, j, res1, res2) == 0) {dp[i][j]  = 1; return 0;}
	}
	
	if(j < n){
		if(s2[j] == '0'){ res1 = st1+1; res2 = st2; }
		else { res1 = st1; res2 = st2 + 1; }

		if(solve(i, j+1, res1, res2) == 0) {dp[i][j] = 2; return 0;}
	}
	
	dp[i][j] = -2;
	
	return -2;
}


int main(){
	fasterInOut;
	
	cin >> n >> s1 >> s2;
	
	mem(dp, -1);
	
	int cnt = 0,i=0, j=0;
	vector <int> ans;
	
	solve(0,0,0,0);
	
	while(cnt != 2*n && dp[i][j] != -1){
		if(dp[i][j] == -2)
			break;
		ans.pb(dp[i][j]);
		cnt++;
		if(dp[i][j] == 1)
			i++;
		else
			j++;
	}
	
	if(cnt == 2*n){
		for(i=0; i<2*n; i++)
			cout << ans[i];
		cout << endl;
	}
	else
		cout << "Impossible" << endl;
	
	return 0;
}
