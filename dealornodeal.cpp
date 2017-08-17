#include "dealornodeal.h"

bool game::ifInteractive = true;

void game::shuffleArray() {

	srand(time(NULL));

	for (int i = 0; i < 20; i++) {

		int p1 = rand() % 26;
		int p2 = rand() % 26;
		
		while (p1 == p2) {

			p2 = rand() % 26;
		}

		//cout << "Swapping elements at " << p1 << " and " << p2 << endl;
		int temp = this->_s[p1];
		this->_s[p1] = this->_s[p2];
		this->_s[p2] = temp;
	}

}

void game::revealCases(int num, int myCase, int round) {

	//cout << "My case is " << myCase << endl;
	cout << "Round " << round << "!" << endl;
	cout << "Open " << num << " suitcases!" << endl;

	int ind = -1;

	for (int i = 0; i < num; i++) {

		if (game::ifInteractive) {

			cout << "Pick a suitcase!" << endl;
			cin >> ind;

			while (this->_s[ind] == -1 || ind == myCase) {

				cout << "You already chose that! Pick another suitcase" << endl;
				cin >> ind;

			}
		
		}
		else {

			ind = rand() % 26;

			while (ind == myCase || this->_s[ind] == -1) {

				ind = rand() % 26;

			}

		}
		
		cout << "You chose case " << ind << endl;
		cout << "It had $" << this->_s[ind] << endl;
		this->_s[ind] = -1;

	}	

}

void game::showRemainingCases(int myCase) {

	cout << "Remaining cases are " << endl;

	for (int j = 0; j < 26; j++) {

		if (this->_s[j] != -1 && j != myCase) {

			cout << "Case " << j << endl;
		}

	}
}

bool game::generateOffer(int myCase) {

	int sum = 0;
	int count = 0;
	bool ifAccepted = false;

	for (int i = 0; i < 26; i++) {

		if (this->_s[i] != -1) {

			//cout << "Adding to sum, index "<< i << " element " << this->_s[i] << endl;
			sum = this->_s[i] + sum;
			//cout << "Sum now is " << sum << endl;
		}
		else {

			count++;
		}
	}

	sum = sum / (26 - count);
	sum = sum / 3;

	//cout << "Current suitcase status - " << endl;

	this->showRemainingCases(myCase);

	//cout << *this << endl;

	cout << "The bank is offering you $" << sum << "!" << endl;

	if (game::ifInteractive) {

		cout << "Do you accept this offer?" << endl;
		cin >> ifAccepted;
		if (ifAccepted) {

			cout << "Congratulations! You have won $" << sum << "!" << endl;
		}

	}
	
	return ifAccepted;

}

bool game::playRounds(int myCase, bool isInteractive) {

	int cases = 6;
	int round = 1;
	bool gameOver = false;

	for (int i = cases; i > 1; i--) {
		cout << "Round #" << round << endl;
		this->revealCases(i, myCase, round);
		if (this->generateOffer(myCase)) {

			cout << "Your case had $" << this->_s[myCase] << "!" << endl;
			gameOver = true;
			return true;
		}
		else {

			round++;
			
		}

		
		
	}

	for (int j = 1; j < 5; j++) {
		cout << "Round of 1s #" << round << endl;
		this->revealCases(1, myCase, round);
		if (this->generateOffer(myCase)) {

			cout << "Your case had $" << this->_s[myCase] << "!" << endl;
			gameOver = true;
			return true;
		}
		else {

			round++;

		}

	}

	return gameOver;

}

void game::playGame(bool isInteractive) {

	int numIter = 0;

	suitcase suitArr[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };

	game a(suitArr);

	srand(time(NULL));
	int mySuitcase = -1;

	//do {

		numIter++;

		//suitcase suitArr[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };

		//game a(suitArr);

		a.shuffleArray();

		if (game::ifInteractive) {

			cout << "Pick a suitcase!" << endl;
			cin >> mySuitcase;
			cout << "Your suitcase is number " << mySuitcase << "!" << endl;

		}
		else {

			srand(time(NULL));
			mySuitcase = rand() % 26;

		}

		bool theEnd = a.playRounds(mySuitcase);

		if (game::ifInteractive) {

			if (theEnd) {

				cout << "Your case had $" << a._s[mySuitcase] << endl;
				cout << "Thanks for playing!" << endl;

			}
			else {

				cout << "Let's see what's in your case!" << endl;
				cout << "Your case had $" << a._s[mySuitcase] << "!!" << endl;
			}


		}
		else if (!theEnd && !game::ifInteractive) {

			cout << "FINAL ROUND" << endl;
			cout << "My case is " << mySuitcase << endl;

			if (a._s[mySuitcase] == 0) {

				cout << "YOU ARE BANKRUPT !!!!" << endl;
				//break;
			}
			else if (a._s[mySuitcase] == 1000000) {

				cout << "YOU ARE A MILLIONAIRE !!!!" << endl;
				//break;
			}

			cout << a;

		}




	//} while (a._s[mySuitcase] != 0 || a._s[mySuitcase] != 1000000);


	cout << "Number of rounds needed to become bankrupt/a millionaire are " << numIter << endl;

}