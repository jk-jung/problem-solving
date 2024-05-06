#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin>>n;
    vi v(n);
    for(int &x:v)cin>>x;
    sort(v.begin(), v.end());

    if(n == 1) {
        cout << -1 << endl;
    }else if(n == 2) {
        int d = v[1] - v[0];
        if(d == 0) {
            cout << 1 << endl;
            cout << v[0] << endl;
        }else if(d % 2 == 0) {
            cout << 3 << endl;
            cout << v[0] - d << " " << v[0] + d / 2 << " " << v[1] + d << endl;
        }else {
            cout << 2 << endl;
            cout << v[0] - d << " " << v[1] + d << endl;
        }
    }else {
        set<int> s;
        for(int i=1;i<n;i++) {
            s.insert(v[i] - v[i - 1]);
        }
        if(s.size() > 2) {
            cout << 0 << endl;
        }else if(s.size() == 1) {
            int d = *s.begin();
            if(d == 0) {
                cout << 1 << endl;
                cout << v[0] << endl;
            }else {
                cout << 2 << endl;
                cout << v[0] - d << " " << v[n - 1] + d << endl;
            }
        }else {
            vi d(s.begin(), s.end());
            if(d[0] * 2 == d[1]) {
                vi r;
                for(int i=1;i<n;i++){
                    if(v[i] - v[i - 1] == d[1]) {
                        r.pb(v[i - 1] + d[0]);
                    }
                }
                if(r.size() == 1) {
                    cout << 1 << endl;
                    cout << r[0] << endl;
                }else {
                    cout << 0 << endl;
                }
            }else {
                cout << 0 << endl;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
