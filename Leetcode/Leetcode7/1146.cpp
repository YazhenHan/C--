#include <vector>

using namespace std;

class SnapshotArray {
private:
    int snap2;
    vector<vector<int>> vv;
    vector<vector<int>> vv2;
public:
    SnapshotArray(int length) {
        snap2 = 0;
        vv = vector<vector<int>>(length);
        for (auto & v : vv)
            v.push_back(0);
    }
    
    void set(int index, int val) {
        vv[index].push_back(val);
    }
    
    int snap() {
        vector<int> temp;
        for (int i = 0; i < vv.size(); i++) {
            temp.push_back(vv[i].back());
        }
        vv2.push_back(temp);
        snap2++;
        return snap2 - 1;
    }
    
    int get(int index, int snap_id) {
        return vv2[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */