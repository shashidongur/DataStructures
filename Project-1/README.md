# Dijkstra's and Floyd-Warshall Algorithms 
For All Pair Shortest Path Problem with Complete Directed Graphs

## Graph Generator

To run the generator input the command:
make generator

## Run Dijkastra and FloydWarshall on generated or custom Graphs

__To run the algorithms with generated graph file, input the command:__

make project

__To run the algorithm with custom graph file, input the command:__

make customeProject
./customGraphSolver <custom file name>

__The program will generate three text files:__

"dijkstraResult.txt" 		- Result of running dijkastra algorithm on graph

"floydWarshallResult.txt" 		- Result of running floyd warshall algorithm on graph

"timeResults.txt"			- Result of time comparision for both 
