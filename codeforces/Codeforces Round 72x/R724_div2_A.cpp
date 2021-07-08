#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))


void solve(vector<int> &v) {
    sort(v.begin(), v.end());
    if (v[0] < 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << v.back() + 1 << endl;
    for (int i = 0; i <= v.back(); i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        solve(v);
    }
}
