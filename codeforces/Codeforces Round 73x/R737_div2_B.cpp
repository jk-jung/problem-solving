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

bool sf(pi &a, pi &b){
    return a.S < b.S;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i].F = a;
        v[i].S = i;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++)v[i].F = i;
    sort(v.begin(), v.end(), sf);

    int r = 1;
    for(int i=1;i<n;i++){
        if(v[i-1].F + 1 != v[i].F) r++;
    }

    cout << (r <= k ? "Yes" : "No") << endl;

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
