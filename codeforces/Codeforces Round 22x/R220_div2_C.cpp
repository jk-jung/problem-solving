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

int n, m;
char a[1005][1005];
int d[1005][1005];
int vis[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int dfs(int y,int x){
    char t = a[y][x];
    if(t == 'D') t = 'I';
    else if(t == 'I')t = 'M';
    else if(t == 'M')t = 'A';
    else if(t == 'A')t = 'D';

    if(vis[y][x] == 2){
        cout << "Poor Inna!";
        exit(0);
    }
    int &r = d[y][x];
    if(vis[y][x] == 1)return r;
    vis[y][x] = 2;

    r = 1;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != t)continue;
        r = max(r, dfs(ny, nx) + 1);
    }
    vis[y][x] = 1;
    return r;
}

void solve() {
    cin >> n >> m;
    int r =0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 'D')r = max(r, dfs(i, j));
        }
    }
    if(r < 4)cout << "Poor Dima!";
    else
        cout << r / 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
