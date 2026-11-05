// LC1385. Find the Distance Value Between Two Arrays

/*
   Given two integer arrays `arr1` and `arr2`, and the integer `d`, return the distance value between the two arrays.

   The distance value is defined as the number of elements `arr1[i]` such that there is not any element `arr2[j]` where `|arr1[i] - arr2[j]| <= d`.
*/

/*
   Example1:\
   Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2\
   Output: 2

   Example2:\
   Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3\
   Output: 2

   Example3:\
   Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7]\
   Output: 1
*/

/*
   Constraints:

   - `1 <= arr1.length, arr2.length <= 500`
   - `-1000 <= arr1[i], arr2[j] <= 1000`
   - `0 <= d <= 100`
*/
