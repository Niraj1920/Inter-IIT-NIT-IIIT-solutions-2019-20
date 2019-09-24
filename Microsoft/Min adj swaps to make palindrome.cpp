//Minimum adjacent swaps required to make a string palindrome.

#include <bits/stdc++.h>

using namespace std;

string s;
int ns,c[256],d,e,h;

void move(int from, int to) {
	if (from < to) {
		int x = s[from];
		for (int i = from; i < to; i++)
			s[i] = s[i+1];
		s[to] = x;
	}else if (from > to) {
		int x = s[from];
		for (int i = from; i > to; i--)
			s[i] = s[i-1];
		s[to] = x;
	}
	//return abs(from-to);
}

int main(void) {
	while (1) {
		cin>>s;
		if (s[0] == '0')
			break;
		
		memset(c, 0, sizeof c);
		ns = (int) s.length();
		for (int i = 0; i < ns; i++)
			c[(int) s[i]]++;
		d = 0;
		for (int i = 0; i < 256; i++)
			d += c[i]%2;
		if (d > 1) {
			printf("Impossible\n");
			continue;
		}
		
		h = 0;
		for (int i = 0; i < ns/2; i++)
			if (s[i] != s[ns-1-i]) {
				d = 1000;
				e = -1000;
				for (int j = i+1; j < ns-1-i; j++)
					if (s[j] == s[ns-1-i]) {
						d = j;
						break;
					}
				for (int j = ns-2-i; j > i; j--)
					if (s[j] == s[i]) {
						e = j;
						break;
					}
				h += min(d-i, ns-1-i-e);
				if (d-i < ns-1-i-e)
					move(d, i);
				else
					move(e, ns-1-i);
					
				//cout<<i<<" "<<d<<" "<<e<<" "<<s<<" "<<h<<endl;
			}
			
		cout<<h<<endl;
	}
	return 0;
}
