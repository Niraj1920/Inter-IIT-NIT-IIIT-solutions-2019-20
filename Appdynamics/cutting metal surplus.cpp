/*
Mr. Octopus has recently shut down his factory and want to sell off his metal rods to a local businessman.

In order to maximize profit, he should sell the metal of same size and shape. If he sells  metal rods of length , he receives N x L x metal_price. The remaining smaller metal rods will be thrown away. To cut the metal rods, he needs to pay cost_per_cut for every cut.

What is the maximum amount of money Mr. Octopus can make?

Input Format
First line of input contains cost_per_cut
Second line of input contains metal_price
Third line contains L, the number of rods Mr. Octopus has, followed by L integers in each line representing length of each rod.

Output Format
Print the result corresponding to the testcase.

Constraints
1 <= metal_price, cost_per_cut <= 1000
1 <= L <= 50
Each element of lenghts will lie in range [1, 10000].

Sample Input#00

1
10
3
26
103
59
Sample Output#00

1770
Explanation Here cuts are pretty cheap. So we can make large number of cuts to reduce the amount of wood wasted. Most optimal lengths of rods will be . So we will cut  pieces of length  from  rod, and throw peice of length  from it. Similarly we will cut  pieces of length  from  rod and throw away a piece of length . From  rod, we will cut  pieces of length  and throw a piece of length . So in total we have  pieces of length  and we have made  cuts also. So total profit is 

Sample Input#01

100
10
3
26
103
59
Sample Output#01

1230
*/
#include <bits/stdc++.h>
using namespace std;

int get_profit(vector<int> &rods, int size, int cpc, int mp){
    int profit = 0;
    for(int r : rods){
        int rodProf = 0;
        if(r%size == 0){
            rodProf += ((r/size) * size * mp) - (r/size - 1) * cpc;
        }
        else{
            rodProf += ((r/size) * size * mp) - (r/size) * cpc;
        }
        if(rodProf > 0)
            profit += rodProf;
    }
    return profit;
}

int main(){
    int n;
    int cpc , mp;
    cin >> cpc >> mp;
    cin >> n;
    vector<int> v(n);
    int maxlen = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        maxlen = max(maxlen, v[i]);
    }

    int ret = 0;
    for(int size=1; size<=maxlen; size++){
        int prof = get_profit(v, size, cpc, mp);
        ret = max(prof, ret);
    }
    cout <<ret << endl;
    return 0;
}
