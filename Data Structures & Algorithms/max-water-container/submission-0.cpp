class Solution {
   public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int area = INT_MIN;

        int i = 0;
        int j = n - 1;
        while (i < j) {
            int minh = (min(h[i], h[j]));
            int temp = ((j - i) * minh);
            area = max(temp, area);
            if (h[i] > h[j])
                j--;
            else if (h[i] < h[j])
                i++;
            else {
                i++;
                j--;
            }
        }
        return area;
    };
};