#include "dealornodeal.h"

bool game::ifInteractive = false;

void game::shuffleArray() {

	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {

		int p1 = rand() % 26;
		int p2 = rand() % 26;
		
		while (p1 == p2) {

			p2 = rand() % 26;
		}

		int temp = this->_s[p1];
		this->_s[p1] = this->_s[p2];
		this->_s[p2] = temp;
	}

}

void game::revealCases(int num, int myCase, int round) {

	cout << "Round " << round << "!" << endl;
	cout << "Open " << num << " suitcases!" << endl;

	int ind = -1;

	for (int i = 0; i < num; i++) {

		if (game::ifInteractive) {

			this->showRemainingCases(myCase);
			this->showRemainingValues(myCase);

			cout << "Pick a suitcase between 1 to 26!" << endl;
			cin >> ind;

			while (ind < 1 || ind > 26) {

				cout << "Please select a suitcase between 1 and 26" << endl;
				cin >> ind;

			}

			while (this->_s[ind - 1] == -1 || ind == myCase) {

				cout << "You already chose that! Pick another suitcase" << endl;
				cin >> ind;

			}
		
		}
		else {

			ind = (rand() % 26) + 1;

			while (ind == myCase || this->_s[ind - 1] == -1) {

				ind = (rand() % 26) + 1;

			}

		}
		
		cout << "You chose case " << ind << endl << endl;
		cout << "It had $" << this->_s[ind - 1] << endl << endl;
		this->_s[ind - 1] = -1;

	}	

}

void game::showRemainingCases(int myCase) {

	cout << "Remaining cases are - ";

	for (int j = 0; j < 26; j++) {

		if (this->_s[j] != -1 && j != (myCase - 1)) {

			cout << (j + 1) << " ";
		}

	}

	cout << endl << endl;
}


void game::showRemainingValues(int myCase) {

	game t = *this;

	t.shuffleArray();

	cout << "Remaining values are - ";

	for (int i = 0; i < 26; i++) {

		if (t._s[i] != -1) {

			cout << t._s[i] <<" ";

		}
	}

	cout << endl << endl;

}


bool game::generateOffer(int myCase) {

	int sum = 0;
	int count = 0;
	double factor = 0;
	int ifAccepted = 0;

	for (int i = 0; i < 26; i++) {

		if (this->_s[i] == -1) {

			count++;
		}
	}

	count = (26 - count);

	factor = (double) 1 / count;

	for (int j = 0; j < 26; j++) {

		if (this->_s[j] != -1) {

			sum = sum + (this->_s[j] * factor);
		}

	}

	cout << "The bank is offering you $" << sum << " !" << endl << endl;

	showRemainingValues(myCase);

	if (game::ifInteractive) {

		cout << "Do you accept this offer? Yes = 1, No = 0 " << endl << endl;
		cin >> ifAccepted;

		while (ifAccepted != 1 && ifAccepted != 0) {

			cout << "Please input 1 for Yes or 0 for No" << endl << endl;
			cin >> ifAccepted;
		}

		if (ifAccepted) {

			cout << "Congratulations! You have won $" << sum << " !" << endl << endl;
		}

	}
	
	return ifAccepted;

}

bool game::playRounds( int myCase, bool isInteractive) {

	int cases = 6;
	int round = 1;
	bool gameOver = false;

	for (int i = cases; i > 1; i--) {
		this->revealCases(i, myCase, round);
		if (this->generateOffer(myCase)) {

			cout << "Your case had $" << this->_s[myCase - 1] << " !" << endl << endl;
			gameOver = true;
			return true;
		}
		else {

			round++;
			
		}
				
	}

	for (int j = 1; j < 5; j++) {
		cout << "Round of 1s #" << round << endl << endl;
		this->revealCases(1, myCase, round);
		if (this->generateOffer(myCase)) {

			cout << "Your case had $" << this->_s[myCase - 1] << " !" << endl << endl;
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

	srand(time(NULL));
	int mySuitcase = -1;

	if (ifInteractive) {

		shuffleArray();

		cout << "Pick a suitcase between 1-26!" << endl << endl;
		cin >> mySuitcase;

		while (mySuitcase < 1 || mySuitcase > 26) {

			cout << "Please select a suitcase between 1 and 26" << endl << endl;
			cin >> mySuitcase;

		}

		cout << "Your suitcase is number " << mySuitcase << " !" << endl << endl;

		bool theEnd = playRounds(mySuitcase);

		if (theEnd) {
			
			cout << "Thanks for playing!" << endl << endl;

		}
		else {

			cout << "Let's see what's in your case!" << endl << endl;
			cout << "Your case had $" << _s[mySuitcase - 1] << " !!" << endl << endl;
			cout << "Thanks for playing!" << endl;
		}

	}
	else {

		suitcase suitArr[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };

		game a(suitArr);

		do {

			numIter++;

			*this = a;

			shuffleArray();

			srand(time(NULL));
			mySuitcase = (rand() % 26) + 1; //Gives me a random variable between 1-26

			cout << "My suitcase is " << mySuitcase << endl;

			bool theEnd = playRounds(mySuitcase);

			cout << "My case is " << (mySuitcase - 1) << " and it had $" << _s[mySuitcase - 1] << endl << endl;

			if (_s[mySuitcase - 1] == 0) {

				cout << "YOU ARE BANKRUPT !!!!" << endl << endl;
				break;
			}
			else if (_s[mySuitcase - 1] == 1000000) {

				cout << "YOU ARE A MILLIONAIRE !!!!" << endl << endl;
				break;
			}

			cout << *this;

		} while (_s[mySuitcase - 1] != 0 || _s[mySuitcase - 1] != 1000000);


		cout << "Number of rounds needed to become bankrupt/a millionaire are " << numIter;

	}
}