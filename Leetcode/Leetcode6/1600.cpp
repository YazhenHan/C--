#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class ThroneInheritance {
private:
    struct node
    {
        string name;
        vector<node*> children;
    }* root;
    unordered_map<string, node*> sn;
    unordered_set<string> us;
public:
    ThroneInheritance(string kingName) {
        root = new node();
        root->name = kingName;
        sn[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        node* temp = new node();
        temp->name = childName;
        sn[childName] = temp;
        sn[parentName]->children.push_back(temp);
    }
    
    void death(string name) {
        us.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(node* root, vector<string>& ans) {
        if (!us.count(root->name)) 
            ans.push_back(root->name);
        for (auto t : root->children) {
            dfs(t, ans);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */