#include <iostream>
#include <ctime>


int main() {
	srand(unsigned(time(0)));
	int n;
	int m;
	std::cout << "Please enter amount of archers: "; std::cin >> n;
	std::cout << "Please enter how much shots you want archers to blow: "; std::cin >> m;
	int** strel = new int* [n];

	for (int i = 0; i < n; i++) {
		strel[i] = new int[m];
	} //archers and their shots

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			strel[i][j] = rand() % 11;
			std::cout << strel[i][j] << "\t";
		}
		std::cout << "\n";
	}


	int max, amount = 1;


	int maxa; //desides whether an archer's result is the best or not

	int* archersbest = new int[n]; //best archers' score

	for (int i = 0; i < n; i++) {
		max = strel[i][0];
		for (int j = 0; j < m; j++) {
			if (max < strel[i][j]) {
				max = strel[i][j];
			}
		}
		archersbest[i] = max; //this writes down best results of every archer

	}

	int thewinner1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			maxa = archersbest[0];
			thewinner1 = 0;
			continue;
		}
		else {
			if (maxa < archersbest[i]) {
				maxa = archersbest[i];
				amount = 1;
				thewinner1 = i;
			}
			else {
				if (maxa > archersbest[i])continue;
				else {
					amount++;
				}
			}
		}
	}
	if (amount == 1 && archersbest[0] == maxa)std::cout << "The winner is archer with number 1 and the best score being " << maxa << "\n";
	if (amount == 1 && archersbest[0] != maxa) {
		std::cout << "There's the one victorious archer with number " << ++thewinner1 << " and the best score being " << maxa << " points\n";
	}

	if (amount != 1) {
		int* archersplacei = new int[amount]; //determines best archers' places;
		int sum, b = 0, r = 0;

		//this block finds places of archers with the best score
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				maxa = archersbest[0];
				archersplacei[0] = i;
				continue;
			}
			else {
				if (maxa < archersbest[i]) {
					maxa = archersbest[i];
					b = 0;
					archersplacei[b] = i;
					b += 1;
				}
				else {
					if (maxa > archersbest[i])continue;
					if (maxa == archersbest[i] && b != amount) {
						archersplacei[b] = i;
						b += 1;
					}
				}
			}
		}

		int z = 0;
		int* temparchersbest = new int[amount];//writes down sum of all shots of every best archer

		//this counts sum of points for every best archer
		for (int i = 0; i < n; i++) {
			if (i == archersplacei[z]) {
				sum = 0;
				for (int j = 0; j < m; j++) {
					sum += strel[i][j];
				}
				temparchersbest[z] = sum;
				z += 1;
			}
		}



		int maxw = temparchersbest[0]; //temparchersbest consists sum of points for every best archer, so maxw finds the highest
		int thewinner = archersplacei[0]; //determines the winner
		int damount = 1; //if this is more than 1 then we will write down every archer that has same highest score

		for (int i = 0; i < amount; i++) {
			if (maxw < temparchersbest[i]) {
				maxw = temparchersbest[i];
				damount = 1;
				thewinner = archersplacei[i];
			}
			else {
				if (i != 0 && maxw == temparchersbest[i]) {
					damount++;
				}
			}
		}


		if (damount == 1 && thewinner == 0 && maxw == temparchersbest[0]) { std::cout << "The winner is archer number 1 with" << maxw << " acquired points"; }

		if (damount == 1 && thewinner != 0) { std::cout << "The winner is archer number " << ++thewinner << " with " << maxw << " acquired points"; }

		if (damount != 1) {
			int* thelastarchersarray = new int[damount];//list of winners if they have same highest sums
			int f = 0;
			maxw = temparchersbest[0];
			for (int i = 0; i < amount; i++) {
				if (maxw < temparchersbest[i]) {
					maxw = temparchersbest[i];
					f = 0;
					thelastarchersarray[f] = archersplacei[i];
					f += 1;
				}
				else if (i != 0 && maxw == temparchersbest[i] && f != amount) {
					thelastarchersarray[f] = archersplacei[i];
					f += 1;
				}
			}

			std::cout << "There claims to be " << damount << " winners and their numbers are\n";
			for (int i = 0; i < damount; i++) {
				std::cout << thelastarchersarray[i] << "\n";
				if (i == damount - 1)break;
				std::cout << "and\n";
			}
			std::cout << "with max result being " << maxw << "\n";
			delete[] thelastarchersarray;
		}
		delete[] temparchersbest;
		delete[] archersplacei;
	}



	//очищение памяти
	for (int i = 0; i < n; i++) {
		delete[] strel[i];
	}
	delete[] strel;

	delete[] archersbest;





	return 0;
}