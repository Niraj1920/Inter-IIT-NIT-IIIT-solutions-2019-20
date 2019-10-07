/*
***changed scenario a bit..code below is as per asked question in test.. 

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i]
is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room.
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct meet{
    int a,d;
};

bool compare(struct meet m1, struct meet m2){
    return m1.a < m2.a;
}

int maxMeetings(vector<int> &arrival, vector<int> &depart){
    int n = arrival.size();
    vector<int> meetings(n, 0);
    struct meet m[n];
    for(int i=0; i<n; i++){
        m[i].a = arrival[i];
        m[i].d = depart[i];
    }
    sort(m, m+n, compare);
    
    for(int i=0; i<n; i++){
        int temp = 1;
        for(int j=i+1; j<n; j++){
            if(m[i+temp-1].d <= m[j].a)    temp++;
            else    continue;
        }
        //cout<<temp<<endl;
        meetings.push_back(temp);
    }
    auto maxM = max_element(meetings.begin(), meetings.end());
    return *maxM;   
}
int main() {
	int n;
	cin>>n;
	vector<int> arrival(n, 0), depart(n, 0);
	for(int i=0; i<n; i++){
	    cin>>arrival[i];
	}
	for(int i=0; i<n; i++){
	    cin>>depart[i];
	}
	int maxM = 0;
	maxM = maxMeetings(arrival, depart);
	cout<<maxM<<endl;
	return 0;
}
