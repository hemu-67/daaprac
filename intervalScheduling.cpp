//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//struct Interval{
//	int start,finish;
//};
//
//bool cmp(Interval a,Interval b){
//	return a.finish < b.finish;
//}
//
//void intervalScheduling(vector<Interval> &intervals){
//	
//	sort(intervals.begin(),intervals.end(),cmp);
//	
//	vector<Interval> selected;
//	
//	selected.push_back(intervals[0]);
//	int lastFinish=intervals[0].finish;
//	
//	for(int i=1;i<intervals.size();i++){
//		if(intervals[i].start>=lastFinish){
//			selected.push_back(intervals[i]);
//			lastFinish=intervals[i].finish;
//		}
//	}
//	
//	cout<<"Selected Intervals : ";
//	for(auto i : selected){
//		cout<<"("<<i.start<<","<<i.finish<<")";
//		cout<<endl;
//	}
//		cout<<"Total : "<<selected.size();
//}
//
//int main(){
//	vector<Interval>intervals = {{1,3},{4,4},{2,3}};
//	intervalScheduling(intervals);
//}

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct Interval{
	int start,finish;
};

bool cmp(Interval a,Interval b){
	return a.finish < b.finish;
}

void intervalScheduling(vector<Interval> &intervals){
	
	sort(intervals.begin(),intervals.end(),cmp);
	
	vector<Interval>selected;
	selected.push_back(intervals[0]);
	int lastFinish=intervals[0].finish;
	
	for(int i=1;i<intervals.size();i++){
		if(intervals[i].start>=lastFinish){
			selected.push_back(intervals[i]);
			lastFinish = intervals[i].finish;
		}
	}
	
	cout<<"Selected Intervals : ";
	
	for(auto i : selected){
		cout<<"("<<i.start<<","<<i.finish<<")";
	}
	
	
}
int main(){
	
	vector<Interval> intervals={{0,2},{2,3},{1,3}};
	intervalScheduling(intervals);
	
}
































