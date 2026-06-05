class Solution {
public:
    void merge (vector<int>&nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right - mid;
        vector<int>left_arr(n1);
        vector<int>right_arr(n2);
        for (int index = 0; index < n1; index++){
            left_arr[index] = nums[left+index];
        }
        for (int index = 0; index < n2; index++){
            right_arr[index] = nums[mid+1+index];
        }
        int k = 0, l = 0, m = left;
        while (k < n1 && l < n2){
            if (left_arr[k] < right_arr[l]){
                nums[m++] = left_arr[k++];
            }else{
                nums[m++] = right_arr[l++];
            }
        }
        while (k < n1){
            nums[m++] = left_arr[k++];
        }
        while (l < n2){
            nums[m++] = right_arr[l++];
        }

    }
    void sort (vector<int>&nums, int left , int right){
        if (left < right){
            int mid = left + (right - left)/2;
            sort(nums, left, mid);
            sort(nums, mid + 1, right);
            merge (nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};