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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    map<int,int> c;
    for(int i=0;i<n;i++){
        int a = 0, b = 0;
        for(int j=0;j<m;j++){
            if(v[i][j] == 'G')a = j;
            if(v[i][j] == 'S')b = j;
        }
        if(a > b){
            cout << -1 << endl;
            return;
        }
        c[b-a]++;
    }
    cout << c.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
