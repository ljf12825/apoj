// LC4100. Minimum Cost Path With Even XOR Parity
// LeetCode Weekly Contest 526 Q4

/*
   You are given a tree with `n` nodes numbered from 0 to `n - 1`, represented by a 2D integer array `edges`. Each `edges[i] = [u_i, v_i, c_i]` represents an edge between nodes `u_i represents an edge between nodes `u_i`` and `v_i` with cost `c_i`.

   You are also given an integer array `values` of length `n`, where `values[i]` is the value of node `i`.

   A path between two distinct nodes is Balanced-XOR if the bitwise XOR of the values of all nodes on the path, including both endpoints, has an even number of set bits.

   The cost of a path is the sum of its edge costs.

   Return the minimum cost of a Balanced-XOR path. If no such path exists, return -1.

   The number 0 has zero set bits.
*/

/*
   Example1:\
   Input: edges = [[0,1,4],[0,2,6],[0,3,3],[3,4,5]], values = [3,1,7,1,3]\
   Output: 7

   Example2:\
   Input: edges = [[0,1,5],[1,2,10]], values = [1,7,3]\
   Output: 5

   Example3:\
   Input: edges = [[0,1,5],[0,2,7],[0,3,9]], values = [1,3,5,9]\
   Output: -1
*/

/*
   Constraints:

   - `2 <= n <= 10^5`
   - `edges.length == n - 1`
   - `edges[i] = [u_i, v_i, c_i]`
     - `0 <= u_i, v_i <= n - 1`
     - `1 <= c_i <= 10^9`
   - `edges` represents a valid tree.
*/
