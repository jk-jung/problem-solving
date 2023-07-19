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

struct Data {
    int x, y, z, r;
};

bool sf(Data &a, Data &b) {
    if (a.x == b.x) {
        if (a.y == b.y) {
            if (a.y == 1) {
                if(a.r != b.r) return a.r > b.r;
                return a.z < b.z;
            }
            if(a.r != b.r) return a.r < b.r;
            return a.z > b.z;
        }
        return a.y > b.y;
    }
    return a.x < b.x;
}

void solve() {
    int n;
    vector<Data> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.pb({x, 1, i + 1, y - x});
        v.pb({y, -1, i + 1, y - x});
    }
    sort(v.begin(), v.end(), sf);

    queue<int> q;
    for (int i = 0; i < v.size();) {
        int pos = v[i].x;
        while (i < v.size() && v[i].x == pos && v[i].y == 1) {
            q.push(v[i++].z);
        }
        while (i < v.size() && v[i].x == pos) {
            if (!q.empty() && q.front() != v[i].z) {
                cout << v[i].z << " " << q.front() << endl;
                return;
            }else if(!q.empty()) q.pop();
            i++;
        }
    }
    cout << "-1 -1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
