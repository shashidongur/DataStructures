// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File:         graphGenerator.cpp
//


#include "graphGenerator.h"
#define MAX 1000    // maximum vertices
#define MIN 50      // minimun vertices
#define COUNT 30    // number of graphs being generated
using namespace std;

int main()
{
   // Make sure this is only called once throughout the program
   srand(time(NULL));

   int numberOfVertices;

   // Initialize output File
   ofstream outputFile;
   outputFile.open("graphsMatrices.txt");

   for(int i = 0; i < COUNT; i++)
   {
      numberOfVertices = ((i * (int)(MAX / COUNT)) + MIN);
      generator* gen;
      gen = new generator(numberOfVertices);
      gen->to_file(&outputFile);

      gen->~generator();
   }
   outputFile.close();
}

generator::generator(int size_in)
{
    size=size_in; 
    graph = new int* [size];  
    for (int i=0; i<size; i++) 
        graph[i] = new int[size]; 

    populate(size);
}

generator::~generator()
{
    for (int i=0; i<size; i++) 
        delete graph[i];
    delete graph;
}

void generator::populate(int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (i==j)
                graph[i][j] = 0;
            else 
                graph[i][j] = (rand() % 100) + 1;
        }
    }
}

void generator::print()
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
            cout<<graph[i][j]<<"\t";
        cout<<"\n";
    }

}

void generator::to_file(ofstream* out_file)
{
    *out_file << size<<"\n"; 
    for (int i=0; i<size; i++) 
    {
        for (int j=0; j<size; j++)
            *out_file << graph[i][j]<<" "; 
        *out_file << "\n";
    }
}