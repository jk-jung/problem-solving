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
    int n, m;
    cin >> n >> m;
    vi b(m), f(n);
    map<int,int> t, idx;
    for (int &x: f)cin >> x, t[x]++;
    for(int i=0;i<n;i++)idx[f[i]] = i;
    for (int &x: b)cin >> x;
    for(int x: b)if(!t.count(x)){
        cout << "Impossible\n";
        return;
    }
    for(int x:b) {
        if(t[x] >= 2){
            cout << "Ambiguity\n";
            return;
        }
    }

    cout << "Possible\n";
    for(int x:b)cout << idx[x] + 1 << " ";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
