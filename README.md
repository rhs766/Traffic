# Traffic
Simulation of cars using a four-way intersection.

Parent process determines order of cars, creates child processes using  
	fork() per car and prints the current direction per direction change.  
Child processes represent each car and print their info when using the intersection.  

Program reads an input file from stdin using redirection.

Compile: g++ -std=c++11 -o traffic traffic.cpp  
Run: ./traffic < input.txt

Example input file (without comments):  
E 			// Initial direction  
1 			// Max number of cars per direction  
ABC N 2 	// Car info (license plate, direction, time)  
BCD N 2  
CDE S 3  
DEF E 2  
EFG S 1  
FGH W 1  

Example output:  
Current direction: Eastbound  
Car DEF is using the intersection for 2 sec(s).  
Current direction: Southbound  
Car CDE is using the intersection for 3 sec(s).  
Current direction: Westbound  
Car FGH is using the intersection for 1 sec(s).  
Current direction: Northbound  
Car ABC is using the intersection for 2 sec(s).  
Current direction: Southbound  
Car EFG is using the intersection for 1 sec(s).  
Current direction: Northbound  
Car BCD is using the intersection for 2 sec(s).  
