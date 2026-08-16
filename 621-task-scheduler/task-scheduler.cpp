class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);
        unordered_map<char, int> lastUsed;

        for (char ch : tasks) {
            mpp[ch - 'A']++;
            lastUsed[ch] = 0;
        }

        int interval = 0;

        while (true) {
            int idx = -1;
            int maxi = 0;

            // Find the best available task
            for (int i = 0; i < 26; i++) {
                if (mpp[i] > 0 &&
                    (lastUsed['A' + i] == 0 ||
                     interval + 1 - lastUsed['A' + i] > n)) {

                    if (mpp[i] > maxi) {
                        maxi = mpp[i];
                        idx = i;
                    }
                }
            }

            // Check if all tasks are finished
            bool done = true;
            for (int i = 0; i < 26; i++) {
                if (mpp[i] > 0) {
                    done = false;
                    break;
                }
            }

            if (done)
                return interval;

            interval++;

            // Execute task if one is available
            if (idx != -1) {
                mpp[idx]--;
                lastUsed['A' + idx] = interval;
            }
        }

        return interval;
    }
};