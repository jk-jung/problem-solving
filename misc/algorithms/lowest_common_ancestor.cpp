class LowestCommonAncestor {
public:
    int n, log_n;
    vector<int> depth, *tree;
    vector<vector<int>> parent;

    void init(int _n, vector<int> *_tree) {
        n = _n;
        log_n = 32 - __builtin_clz(n);
        tree = _tree;
        depth.clear(), depth.resize(n + 1);
        parent.clear(), parent.resize(n + 1);
        for (int i = 0; i < n; i++)parent[i].resize(log_n + 1, -1);

        for (int i = 0; i < n; i++) {
            if (parent[i][0] == -1) dfs(i, -1);
        }
    }

    int lca(int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        for (int i = log_n; i >= 0; i--) {
            if (depth[y] - depth[x] >= (1 << i)) {
                y = parent[y][i];
            }
        }
        if (x == y) return x;
        for (int i = log_n; i >= 0; i--) {
            if (parent[x][i] != parent[y][i]) {
                x = parent[x][i], y = parent[y][i];
            }
        }
        return parent[x][0];
    }

    int up_to(int x, int dep) {
        for (int i = log_n; i >= 0; i--) {
            if (depth[x] - dep >= (1 << i)) {
                x = parent[x][i];
            }
        }
        return x;
    }

    void dfs(int x, int y) {
        depth[x] = (y == -1 ? 0 : depth[y] + 1);
        build(x, y);
        for (int z : tree[x]) {
            if (z != y) dfs(z, x);
        }
    }

    void build(int x, int y) {
        parent[x][0] = y;
        for (int i = 1; i <= log_n; i++) {
            int z = parent[x][i - 1];
            if (z == -1)break;
            parent[x][i] = parent[z][i - 1];
        }
    }
};