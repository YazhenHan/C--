#include <vector>
#include <iostream>
#include <queue>
#include <stack>

class Digraph
{
private:
    int V;
    int E = 0;
    std::vector<std::vector<int>> adj;
public:
    Digraph(int V) : V(V) { adj.resize(V); }
    int getV() { return V; }
    int getE() { return E; }
    void addEdge(int v, int w) { adj[v].push_back(w); E++; }
    auto getAdj(int v) { return adj[v]; }
    auto getAdjs() { return adj; }
    Digraph reverse() {
        Digraph R(V);
        for (int v = 0; v < V; v++)
            for (int w : getAdj(v))
                R.addEdge(w, v);
        return R;
    }
};

class DirectedDFS
{
private:
    std::vector<bool> marked = { false };
    void dfs(Digraph G, int v) {
        marked[v] = true;
        for (auto w : G.getAdj(v))
            if (!marked[w])
                dfs(G, w);
    }
public:
    DirectedDFS(Digraph G, int s) { marked.resize(G.getV()); dfs(G, s); }
    bool getMarked(int v) { return marked[v]; }
};

class DirectedBFS
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> edgeTo;
    int s;
    void bfs(Digraph G, int s) {
        std::queue<int> q;
        q.push(s);
        marked[s] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto w : G.getAdj(v))
                if (!marked[w])
                {
                    edgeTo[w] = v;
                    marked[w] = true;
                    q.push(w);
                }
        }
    }
public:
    DirectedBFS(Digraph G, int s) : s(s) { marked.resize(G.getV()); edgeTo.resize(G.getV()); bfs(G, s); }
    bool hasPathTo(int v) { return marked[v]; }
    std::stack<int> pathTo(int v) {
        if (!hasPathTo(v))
            return {};
        std::stack<int> path;
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
};

class DirectedCycle
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> edgeTo;
    std::stack<int> cycle;
    std::vector<bool> onStack = { false };
    void dfs(Digraph G, int v) {
        onStack[v] = true;
        marked[v] = true;
        for (auto w : G.getAdj(v))
            if (hasCycle())
                return;
            else if (!marked[w])
            {
                edgeTo[w] = v;
                dfs(G, w);
            }
            else if (onStack[w])
            {
                for (int x = v; x != w; x = edgeTo[x])
                    cycle.push(x);
                cycle.push(w);
                cycle.push(v);
            }
        onStack[v] = false;
    }
public:
    DirectedCycle(Digraph G) {
        onStack.resize(G.getV());
        edgeTo.resize(G.getV());
        marked.resize(G.getV());
        for (int v = 0; v < G.getV(); v++)
            if (!marked[v])
                dfs(G, v);
    }
    bool hasCycle() { return !cycle.empty(); }
    auto getCycle() { return cycle; }
};

class DepthFirstOrder
{
private:
    std::vector<bool> marked = { false };
    std::queue<int> pre;
    std::queue<int> post;
    std::stack<int> reversePost;
    void dfs(Digraph G, int v) {
        pre.push(v);
        marked[v] = true;
        for (int w : G.getAdj(v))
            if (!marked[w])
                dfs(G, w);
        post.push(v);
        reversePost.push(v);
    }
public:
    DepthFirstOrder(Digraph G) {
        marked.resize(G.getV());
        for (int v = 0; v < G.getV(); v++)
            if (!marked[v])
                dfs(G, v);
    }
    auto getPre() { return pre; }
    auto getPost() { return post; }
    auto getReversePost() { return reversePost; }
};

class Topological
{
private:
    std::stack<int> order;
public:
    Topological(Digraph G) {
        DirectedCycle cy(G);
        if (!cy.hasCycle())
        {
            DepthFirstOrder dfo(G);
            order = dfo.getReversePost();
        }
    }
    auto getOrder() { return order; }
    bool isDAG() { return !order.empty(); }
};

class KosarajuSCC
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> id;
    int count = 0;
    void dfs(Digraph G, int v) {
        marked[v] = true;
        id[v] = count;
        for (auto w : G.getAdj(v))
            if (!marked[w])
                dfs(G, w);
    }
public:
    KosarajuSCC(Digraph G) {
        marked.resize(G.getV());
        id.resize(G.getV());
        DepthFirstOrder dfo(G.reverse());
        auto order = dfo.getReversePost();
        while (!order.empty())
        {
            auto t = order.top();
            if (!marked[t])
            {
                dfs(G, t);
                count++;
            }
            order.pop();
        }
    }
    bool isStronglyConnected(int v, int w) { return id[v] == id[w]; }
    int getId(int v) { return id[v]; }
    int getCount() { return count; }
};

int main() {
    Digraph g(5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(1, 3);
    KosarajuSCC ko(g);
    std::cout << ko.isStronglyConnected(1, 4) << std::endl;
    std::cout << ko.getCount() << std::endl;
    return 0;
}