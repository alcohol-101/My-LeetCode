class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        int result=qsxz(nums,0 ,nums.size()-1,nums.size()-k);
        return result;
    }

    int qsxz(vector<int>& nums, int left, int right, int target) {
        if (left == right) return nums[left];
        
        int ran_index = left + rand() % (right - left + 1);
        int now = nums[ran_index];
        
        // 1. 将 pivot 移到最右边
        swap(nums[ran_index], nums[right]);
        
        // 2. 分区：j 指向第一个大于 now 的位置（即小于区的边界）
        int j = left;  // ✅ 正确：从 left 开始
        for (int i = left; i < right; i++) {  // 遍历 [left, right-1]
            if (nums[i] < now) {
                swap(nums[j], nums[i]);
                j++;
            }
        }
        
        // 3. 将 pivot 放到正确位置
        swap(nums[j], nums[right]);
        
        // 4. 递归选择
        if (j == target) {
            return nums[j];
        } else if (j < target) {
            return qsxz(nums, j + 1, right, target);
        } else {
            return qsxz(nums, left, j - 1, target);
        }
    }


    
};