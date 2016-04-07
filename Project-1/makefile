project: main.cpp dijkstra.cpp floydWarshall.cpp 
	g++ dijkstra.cpp floydWarshall.cpp main.cpp -lrt -o graphSolver
	./graphSolver graphsMatrices.txt

customProject: main.cpp dijkstra.cpp floydWarshall.cpp 
	g++ dijkstra.cpp floydWarshall.cpp main.cpp -lrt -o customGraphSolver

generator: graphGenerator.cpp graphGenerator.h
	g++ graphGenerator.cpp -o generator
	./generator
