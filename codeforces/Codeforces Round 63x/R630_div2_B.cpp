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

vi p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    int n;
    cin >> n;
    vi v(n), r(n);
    for(int &x:v)cin>>x;
    map<int, int> used;
    for (int k = 0; k < p.size(); k++) {
        for (int i = 0; i < n; i++) {
            if (!r[i] && v[i] % p[k] == 0){
                if(!used.count(k)){
                    int sz = used.size();
                    used[k] = sz + 1;
                }
                r[i] = used[k];
            }
        }
    }
    cout << used.size() << endl;
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
