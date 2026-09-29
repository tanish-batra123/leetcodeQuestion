class Solution {
public:
    void sieve(int n, vector<bool>& isPrime) {

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int p = i * i; p <= n; p = p + i) {
                    isPrime[p] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        int maxVal = *max_element(arr.begin(), arr.end());
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = false;
        sieve(maxVal, isPrime);
        vector<int> visited(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = 1;
        if (maxVal >= 1)
            isPrime[1] = false;
        int minimumJumps = INT_MAX;

        map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            int x = arr[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {

                    if (isPrime[p])
                        mpp[p].push_back(i);

                    while (x % p == 0)
                        x /= p;
                }
            }
            if (x > 1 && isPrime[x]) {
                mpp[x].push_back(i);
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            int idx = it.first;
            int jump = it.second;
            int val = arr[idx];
            q.pop();

            if (idx == n - 1) {
                minimumJumps = min(minimumJumps, jump);
            }

            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = 1;
                q.push({idx - 1, jump + 1});
            }

            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = 1;
                q.push({idx + 1, jump + 1});
            }

            if (isPrime[val] && mpp.find(val) != mpp.end()) {
                for (int n : mpp[val]) {

                    if (!visited[n]) {
                        visited[n] = 1;
                        q.push({n, jump + 1});
                    }
                }
                mpp.erase(val);
            }
        }
        return minimumJumps;
    }
};