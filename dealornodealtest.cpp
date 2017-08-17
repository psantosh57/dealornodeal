#include "dealornodeal.h"
#include "vld.h"


int main() {

	suitcase suitArr[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};

	game g(suitArr);

	g.playGame();

	cout << game::ifInteractive << endl;


#if 0
	g.shuffleArray();

	srand(time(NULL));
	int mySuitcase = rand() % 26;

	g.playRounds(mySuitcase);
#endif // 0


#if 0
	//Round #1 - 6 cases
	g.revealCases(6, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #2 - 5 cases
	g.revealCases(5, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #3 - 4 cases
	g.revealCases(4, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #4 - 3 cases
	g.revealCases(3, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #5 - 2 cases
	g.revealCases(2, mySuitcase);
	cout << g;
	g.generateOffer();

	//20 cases opened

	//Round #6 - 1 case
	g.revealCases(1, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #7 - 1 case
	g.revealCases(1, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #8 - 1 case
	g.revealCases(1, mySuitcase);
	cout << g;
	g.generateOffer();

	//Round #9 - 1 case
	g.revealCases(1, mySuitcase);
	cout << g;
	g.generateOffer();
#endif // 0
#if 0

	cout << "FINAL ROUND" << endl;
	cout << "My case is " << mySuitcase << endl;

	cout << g;

#endif // 0


	//Round #10 - 1 case
	//g.revealCases(1, mySuitcase);
	//cout << g;
	//g.generateOffer();

	//cout << g;



	return 0;
}