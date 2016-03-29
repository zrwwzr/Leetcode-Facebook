class Solution {
public:
    void merge(vector<int> &nums, int begin, int end){
        int mid = (begin + end) / 2;
        vector<int> temp;
        int i =  begin, j = mid + 1;
        while(i <= mid && j <= end)
            temp.push_back(nums[i] >= nums[j] ? nums[i++] : nums[j++]);
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= end) temp.push_back(nums[j++]);
        for(int i = 0; i < temp.size(); ++i)
            nums[begin + i] = temp[i];
    }
    void mergeSort(vector<int> &nums, int begin, int end){
        if(begin >= end) return;
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, begin, end);
    }
    int findKthLargest(vector<int>& nums, int k) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
};
