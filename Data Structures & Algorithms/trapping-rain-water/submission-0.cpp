class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size();

        if (!n) return 0;
        int i = 0;
        int j = n - 1;

        int lmax = h[i];
        int rmax = h[j];

        int sum = 0;
        while (i < j) {
            if (lmax < rmax) {
                i++;
                lmax = max(lmax, h[i]);
                sum += lmax - h[i];
            } else {
                j--;
                rmax = max(rmax, h[j]);
                sum += rmax - h[j];
            }
        }

        return sum;
    }
};
