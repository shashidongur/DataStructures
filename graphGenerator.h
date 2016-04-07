// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File: 		 graphGenerator.h
//


#ifndef __GRAPH_GEN__
#define __GRAPH_GEN__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class generator{
    private:
        int** graph;
        int size; 

    public:
        generator(int);
        ~generator();
        void populate(int);
        void to_file(ofstream*);
        void print();
};
#endif