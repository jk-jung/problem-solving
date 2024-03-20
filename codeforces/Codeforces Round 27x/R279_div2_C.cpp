#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    vi A(s.size()), B(s.size());
    for(int i=0, t = 0;i<s.size();i++) {
        t = (t * 10 + s[i] - '0') % a;
        A[i] = t;
    }
    for(int i=s.size()-1, t = 0, p=1;i>=0;i--, p = p * 10 % b) {
        t = (t + (s[i] - '0') * p) % b;
        B[i] = t;
    }
    for(int i=0;i<s.size()-1;i++) {
        if(A[i] == 0 && B[i+1] == 0 && s[i+1] != '0') {
            cout << "YES\n";
            cout << s.substr(0, i+1) << '\n';
            cout << s.substr(i+1) << '\n';
            return;
        }
    }
    cout <<"NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
