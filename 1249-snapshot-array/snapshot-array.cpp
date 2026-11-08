class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;

    int cnt = 0;

    SnapshotArray(int length) {
        arr.assign(length, vector<pair<int, int>>({{0, 0}}));
    }

    void set(int index, int val) {
        if (arr[index].back().first == cnt) {
            arr[index].back().second = val;
        } 
        else{
            arr[index].push_back({cnt,val});
        }
    }

    int snap() {
        cnt++;
        return cnt - 1;
    }

    int get(int index, int snap_id) {

        int low = 0;
        int high = arr[index].size()-1;
        int ans=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[index][mid].first<=snap_id){
                ans= arr[index][mid].second;
                 low=mid+1;
            }else{
                high=mid-1;
            }
               
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */