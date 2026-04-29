//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Interval{
//	int start,finish,profit;
//};
//bool cmp(Interval a,Interval b){
//	return a.finish < b.finish;
//}
//
//int findp(vector<Interval> &intervals,int j){
//	for(int i=j-1;i>=0;i--){
//		if(intervals[i].finish<=intervals[j].start){
//			return i;
//	}
//}
//return -1;
//}
//
//int weightedIntervalScheduling(vector<Interval> &interval){
//	sort(interval.begin(),interval.end(),cmp);
//	
//	int n=interval.size();
//	vector<int>M(n);
//	
//	M[0]=interval[0].profit;
//	
//	for(int j=1;j<n;j++){
//		int include=interval[j].profit;
//		
//		int p=findp(interval,j);
//		
//		if(p!=-1){
//			include+=M[p];
//		}
//		
//		int exclude = M[j-1];
//		
//		M[j]=max(include,exclude);
//	}
//	return M[n-1];
//}
//
//int main(){
//	vector<Interval> arr = {
//    {1,3,5}, {2,5,6}, {4,6,5},
//    {6,7,4}, {5,8,11}, {7,9,2}
//};
//    cout<< "Maximum Profit = " << weightedIntervalScheduling(arr);
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval{
    int start,finish,profit;
};

bool cmp(Interval a,Interval b){
    return a.finish < b.finish;
}

// FIXED
int findp(vector<Interval>& intervals,int j){
    for(int i=j-1;i>=0;i--){
        if(intervals[i].finish<=intervals[j].start){
            return i;
        }
    }
    return -1;
}

int weightedIntervalScheduling(vector<Interval> &interval){

    sort(interval.begin(),interval.end(),cmp);
    
    int n=interval.size();
    vector<int>M(n);
    
    M[0]=interval[0].profit;
    
    for(int j=1;j<n;j++){
        
        int include=interval[j].profit;
        
        int p=findp(interval,j);
        
        if(p!=-1){
            include+=M[p];
        }
        
        int exclude = M[j-1];
        
        M[j]=max(include,exclude);
    }
    
    return M[n-1];
}

int main(){
    vector<Interval> arr = {
        {1,3,5}, {2,5,6}, {4,6,5},
        {6,7,4}, {5,8,11}, {7,9,2}
    };

    cout<< "Maximum Profit = " << weightedIntervalScheduling(arr);
}

