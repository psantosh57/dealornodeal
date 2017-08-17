#include "../util/util.h"

class suitcase {

public:

	suitcase(int m = 0) :_money(m) {

		cout << "In suitcase constructor " << endl;
	}

	~suitcase() {

		cout << "In suitcase destructor" << endl;
	}

	suitcase& operator=(suitcase& rhs) {

		cout << "In = operator" << endl;

		this->_money = rhs._money;

		return *this;

	}

	
private:

	int _money;
	
};

class list_of_suitcases {

public:

	list_of_suitcases(suitcase s[]) :_suits{ 0 } {

		cout << "In list_of_suitcases constructor" << endl;

		for (int i = 0; i < 26; i++) {

			_suits[i] = s[i];
		}

		cout << "Filled array" << endl;

	}

	~list_of_suitcases() {

		cout << "In list_of_suitcases destructor" << endl;
	}

private:

	suitcase _suits[26];

};
