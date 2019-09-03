class Solution {
public:
 vector<vector<int>> threeSum(vector<int>& nums) {
       if (nums.size() < 3)
       {
           return {};
       }
       std::sort(nums.begin(), nums.end());
       
       std::vector< std::vector< int > > result;
       for (int ii = 0; ii < nums.size() - 2; ++ii)
       {
           const int a = nums[ii];
           
           if (ii > 0 && a == nums[ii-1])
           {
               // Skip, since we have processed "a" before.
               continue;
           }
           
           // All numbers after a are positive. Consequently sum will always be greater than 0.
           if (a > 0)
           {
               return result;
           }
           
           int jj = ii + 1;             // front index increments towards the back
           int kk = nums.size() - 1;    // back index decrements towards the front
           
           // ... as long as they do not cross...
           while (jj < kk)
           {
               const int b = nums[jj];
               const int c = nums[kk];
               const int sum = a + b + c;
               
               // ... their sum is zero, store the result.
               if (sum == 0)
               {
                   // Skipped all values at the front identical to "b" since we have solved for "b".
                   while(jj < kk && nums[jj] == b)
                   {
                       jj += 1;
                   }
                   // Skip identical values at the back as well.
                   while (jj < kk && nums[kk] == c)
                   {
                       kk -= 1;
                   }
                   result.push_back({a, b, c});
               }
               else if (sum < 0)
               {
                   // sum is too small. Increment the front index to yield a bigger sum.
                   jj += 1;
               }
               else if (sum > 0)
               {
                   // sum is too big. Decrement the front index to yield a smaller sum.
                   kk -= 1;
               }
               // try again with new triplet {a,b,c}.
           }
       }
       return result;
   }
};