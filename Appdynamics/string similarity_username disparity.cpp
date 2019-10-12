/*
For two strings A and B, we define the similarity of the strings to be the length of the longest prefix common to both strings. For example, the similarity of strings "abc" and "abd" is 2, while the similarity of strings "aaa" and "aaab" is 3.

Calculate the sum of similarities of a string S with each of it's suffixes.

Input Format

The first line contains the number of test cases t.
Each of the next t lines contains a string to process, .

Output Format

Output t lines, each containing the answer for the corresponding test case.

Sample Input

2
ababaa  
aa
Sample Output

11  
3

*/
#include <bits/stdc++.h>
using namespace std;
// Complete the stringSimilarity function below.
int stringSimilarity(string s) {
    int n = s.length();
    cout<<n<<endl;
    vector<int> z(n, 0);
    int l = 0, r = 0, k;
    z[0] = n;
    cout<<z[0]<<" ";
    for(int i=1; i<n; i++){
        if(i > r){
            l = i;
            r = i;
            while(r < n && s[r-l] == s[r])
                r++;
            z[i] = r-l;
            r--;
        }
        else{
            k = i - l;
            if(z[k] < r - i + 1){
                z[i] = z[k];
            }
            else{
                l = i;
                while(r < n && s[r-l] == s[r])
                    r++;
                z[i] = r-l;
                r--;
                }
        }
        cout<<z[i]<<" ";
    }
    cout<<endl;
    
    int sum = accumulate(z.begin(), z.end(), 0);
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringSimilarity(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
