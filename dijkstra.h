// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File: 		 djkastra.h
//

#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <fstream>
#include <cstdlib>

#define GRAPH_MAX 101 // maximum value in graph + 1
using namespace std;

/* id value pair for queue */
class vertexValue{
	public:
		int id;
		int value;
		vertexValue(int, int);
};
struct compare_val{
	bool operator()(vertexValue const &v1, vertexValue const &v2)
	{
		return v1.value > v2.value;
	}
};
class dijkstra{
	private:
		int** graph;
		int** prev;
		int size;
		priority_queue<vertexValue, vector<vertexValue>, compare_val >q;
	public:
		dijkstra(int size);
		~dijkstra();
		void run(int start, int** matrix);
		void print(); //testing
		void to_file(ofstream* out_file);
};

#endif