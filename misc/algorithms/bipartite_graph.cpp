
class BipartiteGraph {
public:
    int n, m, vis_cnt;
    vi L, R, vis;
    vector <vi> v;


    BipartiteGraph(int _n, int _m) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n, m = _m, vis_cnt = 0;
        L.clear(), L.resize(n, -1);
        R.clear(), R.resize(m, -1);
        vis.clear(), vis.resize(n, -1);
        v.clear(), v.resize(n);
    }

    void add(int s, int e) { v[s].pb(e); }

    int compute_max_matching() {
        int r = 0;
        for (int i = 0; i < n; i++, vis_cnt++) {
            if (dfs(i)) r++;
        }
        return r;
    }

private:
    bool dfs(int x) {
        if (vis[x] == vis_cnt) return false;
        vis[x] = vis_cnt;

        for (int y: v[x]) {
            if (R[y] < 0 || dfs(R[y])) {
                R[y] = x, L[x] = y;
                return true;
            }
        }
        return false;
    }
};