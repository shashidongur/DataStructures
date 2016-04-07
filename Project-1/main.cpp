// 
// Author:       Shashi Bushan Dongur
// Class:        CSCE 4110
// Date:         April 2016
// Proejct:      Term Project - 1
// File: 		 main.cpp
//


#include "dijkstra.h"
#include "floydWarshall.h"
#include <string>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int runAlgorithms(char*);
int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		cout<<"Please pass input file.\n";
		return 1;
	}
	return runAlgorithms(argv[1]);
}

int runAlgorithms(char* fileName)
{
	ifstream inputFile;
	ofstream dijkastraResult;
	ofstream floydWarshallResult;
	ofstream timeResults;

	inputFile.open(fileName);
	if (inputFile.is_open())
	{
		string line;
		timeResults.open("timeResults.txt");
		dijkastraResult.open("djkastraResult.txt");
		floydWarshallResult.open("floydWarshallResult.txt");

		timeResults<<"Matrix Size\t\tDijkstra\t\tFloyd-Warshall\n";
		while (getline(inputFile,line))
		{
			int size = atoi(line.c_str());
			int** matrix = new int*[size];
			for (int i = 0; i<size; i++)
				matrix[i] = new int[size];
			for (int i=0; i<size; i++)
			{
				int j=0;
				string element;
				getline(inputFile,line);
				for (int k=0; k<line.size(); k++)
				{
					if (line[k] == ' ')
					{
						matrix[i][j] = atoi(element.c_str());
						element.clear();
						j++;
					}
					else
						element.push_back(line[k]);
				}
			}

			struct timespec start_time, stop_time;
			double elapse_time;
			class dijkstra* dij = new dijkstra(size);
			if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time) == 0)
			{	
				for (int i=0; i<size; i++)
				{
					dij->run(i,matrix);
				}
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_time);
				elapse_time = stop_time.tv_sec - start_time.tv_sec;
				elapse_time += ((stop_time.tv_nsec/1E9) - (start_time.tv_nsec/1E9));
				dij->to_file(&dijkastraResult); 
				timeResults<<size<<"\t\t\t"<<setprecision(10)<<elapse_time<<"\t\t";
				dij->~dijkstra();
			}
			else
			{
				cout<<"ERROR: Clock failed. Fatal error at matrix size="<<size<<"\n";
				return 1;
			}

			class floydWarshall* fl_w = new floydWarshall(matrix, size);
			if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time) == 0)
			{
				fl_w->run();
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_time);
				elapse_time = stop_time.tv_sec - start_time.tv_sec;
				elapse_time += ((stop_time.tv_nsec/1E9) - (start_time.tv_nsec/1E9));
				fl_w->to_file(&floydWarshallResult);
				timeResults<<setprecision(10)<<elapse_time<<"\n";
				fl_w->~floydWarshall();
			}
			else
			{
				cout<<"ERROR: Clock failed. Fatal error at matrix size="<<size<<"\n";
				return 1;
			}
		}
		timeResults.close();
		dijkastraResult.close();
		floydWarshallResult.close();
	}
	return 0;
}