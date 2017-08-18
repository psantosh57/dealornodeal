#include "dealornodeal.h"
#include "vld.h"


int main() {

	suitcase suitArr[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};

	game g(suitArr);

	g.playGame();

	return 0;
}