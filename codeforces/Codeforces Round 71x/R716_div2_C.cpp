#include <string.h>
#include <stdio.h>
#include <math.h>
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

int ck[200005];
void solve() {
    int n;
    cin >> n;
    vi r = {1}, t = {1};
    ll c = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) for(int j=i;j<n;j+=i)ck[j] = 1;
        if(ck[i])continue;

        t.pb(i);
        c = (c * i) % n;
        if(c == 1)r = t;
    }
    cout << r.size() << endl;
    for(int x:r) cout << x <<" " ;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
