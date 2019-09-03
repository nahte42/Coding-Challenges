class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){ return {}; }
        std::sort(nums.begin(), nums.end());
        int len = nums.size();

        std::vector<std::vector<int>> result;        

        for(int i = 0; i < len - 3; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            //if all smallest value > target, return empty
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){
                break;
            }
            //if left is lager negative than right 3 sum, left++
            if(nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target){
                continue;
            }
            
            for(int j = i + 1; j < len - 2; ++j){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                //if left 4 sum is larger than target, return result
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target){
                    break;
                }
                //if nums[i] + nums[j] + right 2 sum < target, find 2 value in j and len - 1 index
                if(nums[i] + nums[j] + nums[len-2] + nums[len-1] < target){
                    continue;
                }
                int nextJ = j + 1;
                int k = len - 1;
                while(nextJ < k){
                    if(nums[i] + nums[j] + nums[nextJ] + nums[k] == target){  
                        // Do not need have to do this step, because we checked nums[j] == num[j-1](avoid duplicate) and have increased the next nextJ's index before were increasing the nextJ's index value
                        // while(nextJ < k && nums[nextJ] == nums[nextJ + 1]){
                        //     nextJ++;
                        // }
                        while(nextJ < k && (nums[k] == nums[k - 1])){
                            k--;
                        }
                    std::vector<int> temp = {nums[i], nums[j], nums[nextJ], nums[k]}; 
                    result.push_back(temp);
                    ++nextJ;
                    --k;
                    }
                    else if(nums[i] + nums[j] + nums[nextJ] + nums[k] < target){
                        ++nextJ;
                    }
                    else{
                        --k;
                    }
                }
            }
        }
		
        return result;
    }
};