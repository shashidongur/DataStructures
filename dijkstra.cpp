// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File: 		 dijkastra.cpp
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "dijkstra.h"
#include <unistd.h>
using namespace std;

vertexValue::vertexValue(int id_init, int val_init)
{
	id = id_init;
	value = val_init;
}

dijkstra::dijkstra(int size_init)
{
	size = size_init;
	graph = new int*[size];
	for (int i=0; i<size; i++)
		graph[i] = new int[size];
	prev = new int*[size];
	for (int i=0; i<size; i++)
		prev[i] = new int[size];
	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			graph[i][j] = GRAPH_MAX;
	for (int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			prev[i][j] = -1;
}

dijkstra::~dijkstra()
{
	for (int i=0; i<size; i++)
		delete graph[i];
	delete graph;
}

void dijkstra::run(int start, int** matrix)
{
	class vertexValue* v;
	for (int i=0; i<size; i++)
	{	
		v= new vertexValue(i,matrix[start][i]);
		q.push(*v);
		delete v;
	}
	while (!q.empty())
	{
		class vertexValue u = q.top();
		q.pop(); // yoooooo
        
		for (int i=0; i<size; i++)
		{
			if (matrix[start][u.id] + matrix[u.id][i] < graph[start][i])
			{
				graph[start][i] = matrix[start][u.id] + matrix[u.id][i];
				prev[start][i] = u.id;
			}

		}
	}
}

void dijkstra::print()
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			cout<<graph[i][j]<<"\t";
		cout<<"\n";
	}
}

void dijkstra::to_file(ofstream* out_file)
{
	*out_file<<size<<"\n";
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			*out_file<<graph[i][j]<<" ";
		*out_file<<"\n";
	}
}