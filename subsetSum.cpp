#include<iostream>
using namespace std;

bool subsetSum(int arr[],int S,int n){
	
	bool dp[100][100];
	
	for(int i=0;i<=n;i++){
			dp[i][0]=true;
	}
	
	for(int s=1;s<=S;s++){
		dp[0][s]=false;
	}
	
	
	
	for(int i=1;i<=n;i++){
		for(int s=1;s<=S;s++){
			if(arr[i-1]<=s){
				dp[i][s]=dp[i-1][s]||dp[i-1][s-arr[i-1]];
			}
			else{
				dp[i][s]=dp[i-1][s];
			}
		}
	}
	
	cout<<"DP Table"<<" "<<endl;
	
	for(int i=0;i<=n;i++){
		for(int s=0;s<=S;s++){
			cout<<dp[i][s]<<" ";
		}
		cout<<endl;
	}
	
	return dp[n][S];
}

int main(){
	int S=10;
	int n=4;
	int arr[]={2,4,5,6};
	if(subsetSum(arr,S,n)){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
}
