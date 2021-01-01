#include <vector>
#include <iostream>
#include <stack>
#include <queue>

class Graph
{
private:
    const int V;      // vertex num
    int E = 0;        // edge num
    std::vector<std::vector<int>> adj;
public:
    Graph(int V) : V(V) { adj.resize(V); }
    int getV() { return V; }
    int getE() { return E; }
    void addEdge(int v, int w) { adj[v].push_back(w); adj[w].push_back(v); E++;}
    std::vector<int> getAdj(int v) { return adj[v]; }
    auto getAdjs() { return adj; }
};

class DepthFirstSearch
{
private:
    std::vector<bool> marked = { false };
    int count = 0;
    void dfs(Graph G, int v) {
        marked[v] = true;
        count++;
        for (auto w : G.getAdj(v))
            if (!marked[w])
                dfs(G, w);
    }
public:
    DepthFirstSearch(Graph G, int s) { marked.resize(G.getV()); dfs(G, s); }
    bool getMarked(int w) { return marked[w]; }
    int getCount() { return count; }
};

class DepthFirstPaths
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> edgeTo;
    int s;
    void dfs(Graph G, int v) {
        marked[v] = true;
        for (auto w : G.getAdj(v))
            if (!marked[w])
            {
                edgeTo[w] = v;
                dfs(G, w);
            }
    }
public:
    DepthFirstPaths(Graph G, int s) : s(s) { marked.resize(G.getV()); edgeTo.resize(G.getV()); dfs(G, s); }
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

class BreadthFirstPaths
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> edgeTo;
    int s;
    void bfs(Graph G, int s) {
        std::queue<int> q;
        marked[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto w : G.getAdj(v))
                if(!marked[w])
                {
                    edgeTo[w] = v;
                    marked[w] = true;
                    q.push(w);
                }
        }
    }
public:
    BreadthFirstPaths(Graph G, int s) : s(s) { marked.resize(G.getV()); edgeTo.resize(G.getV()); bfs(G, s); }
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

class CC
{
private:
    std::vector<bool> marked = { false };
    std::vector<int> id;
    int count = 0;
    void dfs(Graph G, int v) {
        marked[v] = true;
        id[v] = count;
        for (auto w : G.getAdj(v))
            if(!marked[w])
                dfs(G, w);
    }
public:
    CC(Graph G) {
        marked.resize(G.getV());
        id.resize(G.getV());
        for (int s = 0; s < G.getV(); s++)
            if (!marked[s])
            {
                dfs(G, s);
                count++;
            }
    }
    bool connected(int v, int w) { return id[v] == id[w]; }
    int getId(int v) { return id[v]; }
    int getCount() { return count; }
};

int main() {
    Graph g(5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    // g.addEdge(2, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    CC c(g);
    std::cout << c.connected(0, 1) << std::endl;
    std::cout << c.connected(0, 2) << std::endl;
    std::cout << c.getCount() << std::endl;
    std::cout << c.getId(1) << " " << c.getId(2) << std::endl;
    return 0;
}