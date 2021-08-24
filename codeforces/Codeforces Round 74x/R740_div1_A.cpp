#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


void check(int a, int b, vi &v) {
    int n = a + b;
    int A = (n + 1) / 2;
    int B = n / 2;

    int t = ab(A - a);
    v[t] = 1;
    for(int i=0;i<min(a,b);i++) {
        t += 2;
        v[t] = 1;
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    vi v(a + b + 1), r;

    check(a, b, v);
    check(b, a, v);

    for(int i=0;i<v.size();i++)if(v[i])r.pb(i);
    cout<<r.size() <<'\n';
    for(int i=0;i<r.size();i++)cout <<r[i] << " ";
    cout <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
