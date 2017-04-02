# Stima-TSP
TSP solver using branch and bound

Run tsp.exe on command line
1st parameter: input filename containing adjacency matrix
- 1st line: number of nodes
- Rest of file contains the adjacency matrix
  
2nd parameter: TSP solving method
- 0: reduced cost matrix
  * accepts both undirected and directed adjacency matrix
  * produces directed graph  
- 1: complete tour weight
  * accepts only undirected graph adjacency matrix
  * produces undirected graph
