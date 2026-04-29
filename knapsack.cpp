#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &wt,vector<int> &val,int n,int W){
	
	vector<vector<int>> dp(n+1,vector<int>(W+1,0));
	
	for(int i=1;i<=n;i++){
		for(int w=1;w<=W;w++){
			if(wt[i-1]<=w){
				dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
			}
			else{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	
	cout<<"DP TABLE : ";
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			cout<<dp[i][w]<<" ";
		}
		cout<<endl;
	}
	
	return dp[n][W];
	
}

int main(){
	
	int n=4;
	int W=8;
	
	vector<int>wt={1,3,4,5};
	vector<int>value={10,40,50,70};
	
	int maxprofit=knapsack(wt,value,n,W);
	cout<<"Maximum profit is : "<<maxprofit;
}
