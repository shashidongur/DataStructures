// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File: 		 floydWarshall.h
//

#ifndef __FLOYDWARSHALL__
#define __FLOYDWARSHALL__

#include <fstream>
#include <iostream>
using namespace std;

class floydWarshall{
	private:
		int** graph;
		int size;
	public:
		floydWarshall(int** graph, int size);
		~floydWarshall();
		int run();
		void print(); 
		void to_file(ofstream* out_file);
};

#endif