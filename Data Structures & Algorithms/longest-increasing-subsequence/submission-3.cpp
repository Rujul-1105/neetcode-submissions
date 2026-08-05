class Solution {
   public:
    int lengthOfLIS(vector<int>& vec) {
        int n = vec.size();
        vector<int> temp;
        temp.push_back(vec[0]);

        for (int i = 0; i < n; i++) {
            if (vec[i] > temp.back()) {
                temp.push_back(vec[i]);
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin();
                temp[ind] = vec[i];
            }
        }
        return temp.size();
    }
};
