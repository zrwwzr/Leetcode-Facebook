class Solution {
public:
    int partition(vector<int> &nums, int begin, int end){
        int pivot = nums[end], i = 0, j = end - 1;
        while(i <= j){
            if(nums[i] >= pivot) i++;
            else swap(nums[i], nums[j--]);
        }
        swap(nums[i], nums[end]);
        return i;
    }
    int quickSelect(vector<int> &nums, int begin, int end, const int &k){
        if(begin > end) return INT_MAX;
        int idx = partition(nums, begin, end);
        if(idx - begin + 1 == k) return nums[idx];
        else if(idx - begin + 1 < k) return quickSelect(nums, idx + 1, end, k - idx + begin - 1);
        return quickSelect(nums, begin, idx - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
