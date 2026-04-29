#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int start, finish, weight;
};

bool jobComparator(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

int binarySearch(vector<Job>& jobs, int index) {
    int lo = 0, hi = index - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int findMaxProfit(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), jobComparator);

    vector<int> table(n);
    table[0] = jobs[0].weight;

    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].weight;
        int l = binarySearch(jobs, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i - 1]);
    }

    return table[n - 1];
}

int main() {
    vector<Job> jobs = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}};
    cout << findMaxProfit(jobs) << endl;
    return 0;
}
