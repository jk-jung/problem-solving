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
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.rbegin(), v.rend());
    if(n1 > n2)swap(n1, n2);
    double r = 0;
    for(int i=0;i<n1;i++)r += double(v[i]) / n1;
    for(int i=n1;i<n1+n2;i++)r += double(v[i]) / n2;
    printf("%.10lf\n", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
