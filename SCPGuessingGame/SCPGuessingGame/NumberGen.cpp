#include <stdlib.h>
#include <time.h>
#include "NumberGen.h"

using namespace std;

int RandomizeNumber(int* ppRN, int maxNumber) {
	srand(time(0));
	int RandomNumb = rand() % maxNumber;
	return RandomNumb;
}