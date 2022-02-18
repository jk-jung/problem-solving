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


string make(int n, int k) {
    string r = "a";
    if(k == 1) {
        while(r.size() < n)r += 'a';
        return r;
    }
    while (true) {
        if (r.size() == n)return r;
        for (int i = 0; i < k - 1; i++) {
            if (i == 0)r += ('a' + i);
            if (r.size() == n)return r;
            for (int j = k - 1; j > i + 1; j--) {
                r += ('a' + j);
                if (r.size() == n)return r;
                if (i == 0)r += ('a' + j);
                if (r.size() == n)return r;
                r += ('a' + i);
                if (r.size() == n)return r;
            }
            r += ('a' + i + 1);
            if (r.size() == n)return r;
            if (i == 0)r += ('a' + i + 1);
            if (r.size() == n)return r;
        }

        for (int i = k - 2; i >= 0; i--) {
            r += ('a' + i);
            if (r.size() == n)return r;
        }
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    cout << make(n, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
