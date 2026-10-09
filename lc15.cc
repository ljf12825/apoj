// LC15. 3Sum

/*
   Given an integer array nums. return all the triplets `nums[i], nums[j], nums[k]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`

   Notice that the solution set must not contain duplicate triplets.
*/

/*
   Example1:\
   Input: nums = [-1, 0 ,1, 2, -1, -4]\
   Output: [[-1, -1, 2], [-1, 0, 1]]\
   Explanation:\
   nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.\
   nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.\
   nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0\
   The distinct triplets are [-1, 0, 1] and [-1, -1 ,2]\

   Example2:\
   Input: nums = [0,1,1]\
   Output: []\

   Example3:\
   Input: nums = [0,0,0]\
   Output: [[0,0,0]]
*/
