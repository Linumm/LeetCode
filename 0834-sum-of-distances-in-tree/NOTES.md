By trying DFS twice
The point is that to easily solve, it must be separated by two subtree (parent-side, child-side)
1) In first dfs, get each node's distance value of its subtree(childs), counting the number of nodes it has
2) then, in second dfs, calculate (things like merge..?) two subtrees' value to one.
3) Dist[child] = Dist[parent] + the num of parent-side subtree's nodes.
