#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

struct car {		// Each car has:
	string name;	// name = license plate
	char dir;		// dir = direction
	int time;		// time = time using intersection
};

int main()
{
	vector<car> cars;	// holds all cars in order
	vector<car> north;	// holds northbound cars in order
	vector<car> east;	// holds eastbound cars in order
	vector<car> south;	// holds southbound cars in order
	vector<car> west;	// holds westbound cars in order
	pid_t pid;
	char start;			// initial direction
	cin >> start;
	char order[4];		// holds directional order
	if (start == 'N')	// determines directional order
	{
		order[0] = 'N';
		order[1] = 'E';
		order[2] = 'S';
		order[3] = 'W';
	}
	else if (start == 'E')
	{
		order[0] = 'E';
		order[1] = 'S';
		order[2] = 'W';
		order[3] = 'N';
	}
	else if (start == 'S')
	{
		order[0] = 'S';
		order[1] = 'W';
		order[2] = 'N';
		order[3] = 'E';
	}
	else if (start == 'W')
	{
		order[0] = 'W';
		order[1] = 'N';
		order[2] = 'E';
		order[3] = 'S';
	}
	else
	{
		cout << "Initial Direction is invalid. " << endl;
	}
	int max;			// max number of cars per direction
	cin >> max;
	string tempName;	// read and store name of a car from cin
	char tempDir;		// read and store dir of a car from cin
	int tempTime;		// read and store time of a car from cin
	int c = 0;			// index of cars in cars vector
	int n = 0;			// index of cars in northbound vector
	int e = 0;			// index of cars in eastbound vector
	int s = 0;			// index of cars in southbound vector
	int w = 0;			// index of cars in westbound vector
	int sizeC;			// number of cars in cars vector
	int sizeN;			// number of cars in northbound vector
	int sizeE;			// number of cars in eastbound vector
	int sizeS;			// number of cars in southbound vector
	int sizeW;			// number of cars in westbound vector

	while (cin >> tempName >> tempDir >> tempTime)  // determines order of cars per direction
	{
		if (tempDir == 'N')
		{
			north.push_back(car());
			north[n].name = tempName;
			north[n].dir = tempDir;
			north[n].time = tempTime;
			n++;
		}
		else if (tempDir == 'E')
		{
			east.push_back(car());
			east[e].name = tempName;
			east[e].dir = tempDir;
			east[e].time = tempTime;
			e++;
		}
		else if (tempDir == 'S')
		{
			south.push_back(car());
			south[s].name = tempName;
			south[s].dir = tempDir;
			south[s].time = tempTime;
			s++;
		}
		else if (tempDir == 'W')
		{
			west.push_back(car());
			west[w].name = tempName;
			west[w].dir = tempDir;
			west[w].time = tempTime;
			w++;
		}
		else
		{
			cout << "Input direction is invalid. " << endl;
		}
		c++;
	}
	sizeC = c;
	sizeN = n;
	sizeE = e;
	sizeS = s;
	sizeW = w;
	c = 0;
	n = 0;
	e = 0;
	s = 0;
	w = 0;
	while(c < sizeC)	// determines order for all cars
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < max; k++)
			{
				if (order[j] == 'N')
				{
					if (n < sizeN)
					{
						cars.push_back(north[n]);
						n++;
						c++;
					}
				}
				else if (order[j] == 'E')
				{
					if (e < sizeE)
					{
						cars.push_back(east[e]);
						e++;
						c++;
					}
				}
				else if (order[j] == 'S')
				{
					if (s < sizeS)
					{
						cars.push_back(south[s]);
						s++;
						c++;
					}
				}
				else if (order[j] == 'W')
				{
					if (w < sizeW)
					{
						cars.push_back(west[w]);
						w++;
						c++;
					}
				}
				else
				{
					cout << "Invalid format." << endl;
				}
			}
		}
	}
	char prev = 'A';
	for(int i = 0; i < sizeC; i++)	// print statements
	{
		if (pid=fork()!=0)
		{
			if(cars[i].dir != prev)
			{
				if (cars[i].dir == 'N')
				{
					cout << "Current direction: Northbound" << endl;
				}
				else if (cars[i].dir == 'E')
				{
					cout << "Current direction: Eastbound" << endl;
				}
				else if (cars[i].dir == 'S')
				{
					cout << "Current direction: Southbound" << endl;
				}
				else if (cars[i].dir == 'W')
				{
					cout << "Current direction: Westbound" << endl;
				}
				else
				{
					cout << "Direction format is invalid." << endl;
				}
			}
			wait(NULL);
		}
		else
		{
			cout << "Car " << cars[i].name << " is using the intersection for " << cars[i].time << " sec(s)." << endl;
			sleep(cars[i].time);
			exit(0);
		}
		prev = cars[i].dir;
	}
	return 0;
}
