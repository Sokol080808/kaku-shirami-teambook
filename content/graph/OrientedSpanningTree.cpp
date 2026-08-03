/**
 * Author: Alexey Vasilyev
 * Date: ?
 * Description: Oriented Spanning Tree
 * Time: O(n log n?)
 */

struct RollbackUF {
    vector <int> p, sz;
    vector <int> changes;
    RollbackUF(int n) {
        p.resize(n);
        changes.reserve(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int time() {
        return changes.size();
    }
    int find(int v) {
        if (v == p[v]) return v;
        return find(p[v]);
    }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        changes.push_back(a);
        sz[b] += sz[a];
        p[a] = b;
        return true;
    }
    void rollback(int t) {
        while (changes.size() > t) {
            int v = changes.back();
            sz[p[v]] -= sz[v];
            p[v] = v;
            changes.pop_back();
        }
    }
};
struct Edge { int a, b; ll w; };
struct Node {
    Edge key;
    Node *l, *r;
    ll delta;
    void prop() {
        key.w += delta;
        if (l) l->delta += delta;
        if (r) r->delta += delta;
        delta = 0;
    }
    Edge top() { prop(); return key; }
};
Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ?: b;
    a->prop(), b->prop();
    if (a->key.w > b->key.w) swap(a, b);
    swap(a->l, (a->r = merge(b, a->r)));
    return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }
pair<ll, vi> dmst(int n, int r, vector<Edge>& g) {
    RollbackUF uf(n);
    vector<Node*> heap(n);
    for (Edge e : g) heap[e.b] = merge(heap[e.b], new Node{e});
    ll res = 0;
    vi seen(n, -1), path(n), par(n);
    seen[r] = r;
    vector<Edge> Q(n), in(n, {-1, -1}), comp;
    deque<tuple<int, int, vector<Edge>>> cycs;
    for (int s = 0; s < n; ++s) {
        int u = s, qi = 0, w;
        while (seen[u] < 0) {
            if (!heap[u]) return {-1, {}};
            Edge e = heap[u]->top();
            heap[u]->delta -= e.w, pop(heap[u]);
            Q[qi] = e, path[qi++] = u, seen[u] = s;
            res += e.w, u = uf.find(e.a);
            if (seen[u] == s) {
                Node* cyc = 0;
                int end = qi, time = uf.time();
                do {
                    cyc = merge(cyc, heap[w = path[--qi]]);
                } while (uf.join(u, w));
                u = uf.find(u), heap[u] = cyc, seen[u] = -1;
                cycs.push_front({u, time, {&Q[qi], &Q[end]}});
            }
        }
        for (int i = 0; i < qi; ++i) {
            in[uf.find(Q[i].b)] = Q[i];
        }
    }
    for (auto& [u, t, comp] : cycs) { // restore so l ( optional )
        uf.rollback(t);
        Edge inEdge = in[u];
        for (auto& e : comp) in[uf.find(e.b)] = e;
        in[uf.find(inEdge.b)] = inEdge;
    }
    for (int i = 0; i < n; ++i) par[i] = in[i].a;
    return {res, par};
}