#include <time.h>						//time
#include <stdlib.h> 					//srand, rand
#include <iostream>
#include "Randomizer.h"

using namespace std;

int iRandom(int a, int b){				// целое из [a, b] 
	return rand()%(b-a+1) + a;
}

double dRandom(int a, int b){			// вещественное из [a, b]
	return a + (b - a) * rand() / (double)RAND_MAX;
}

void Randomize() {						//	начальное число - время
	srand((unsigned int)time(NULL));
	rand();
}