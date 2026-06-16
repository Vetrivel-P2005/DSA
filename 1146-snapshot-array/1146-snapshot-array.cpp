class SnapshotArray {
private:
    vector<vector<pair<int, int>>> history;
    int current_snap_id;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0});
        }
        current_snap_id = 0;
    }
    
    void set(int index, int val) {
        if (!history[index].empty() && history[index].back().first == current_snap_id) {
            history[index].back().second = val;
        } else {
            history[index].push_back({current_snap_id, val});
        }
    }
    
    int snap() {
        return current_snap_id++;
    }
    
    int get(int index, int snap_id) {
        const auto& target_history = history[index];
        
        auto it = upper_bound(target_history.begin(), target_history.end(), 
                                   make_pair(snap_id, numeric_limits<int>::max()),
                                   [](const pair<int, int>& a, const pair<int, int>& b) {
                                       return a.first < b.first;
                                   });
        
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */