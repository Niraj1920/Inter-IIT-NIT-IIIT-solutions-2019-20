/*
You are given  an array. You are allowed to square exactly 1 element of array. Find max subarray sum after you square an element.
Approach : 
For every index find max subarray sum with subarray starting at that index. Call this array start
For every index find max subarray sum with subarray ending at that index. Call this array end
Note: if element is negative,set start[i]=0;end[i]=0;
Compute start and end using start[i]=max(0,arr[i]+start[i+1);
end[i]=max(0,arr[i]+end[i-1);

for(all i){
	val=A[i]*A[i];
	ans=max(ans, val + start[i+1] + end[i-1]);
}
	
This approach can be optimized to O(1) space complexity. However the above solution has no issue.

*/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int len = sizeof(ar)/sizeof(ar[0]);
    int ans[n] = {0};
    ans[0] = ar[0]*ar[0];
    int max_so_far = ar[0];
    int max_end=ans[0];
    for(int i=1; i<n; i++){
        //cout<<ans[i-1]+ar[i]<<" "<<ans[i-1] - max_so_far*max_so_far + max_so_far + ar[i]*ar[i]<<" "<<ar[i]*ar[i]<<endl;
        ans[i] = max({ans[i-1]+ar[i], ans[i-1] - max_so_far*max_so_far + max_so_far + ar[i]*ar[i], ar[i]*ar[i]});
        if(ans[i-1] - max_so_far*max_so_far + max_so_far + ar[i]*ar[i] > ans[i-1] || ar[i]*ar[i] > ans[i-1])
            max_so_far = ar[i];
        max_end=max(max_end,ans[i]);
    }
    cout<<max_end<<endl;
    return 0;
}
