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



void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<n;i++){
        if(a[i] != b[i] && a[i] + 1 != b[i]) {
            cout <<"NO" << endl;
            return;
        }
    }
    cout <<"YES" << endl;
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
