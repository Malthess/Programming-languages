#include <iostream>
#include <cstdlib>
#include <ctime>
#include <type_traits>
const int gridsize = 50; //Making this a global constant to avoid array issues.

void Display(bool grid[gridsize + 1][gridsize + 1]);

//This copy's the grid for comparision purposes.
void CopyGrid(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1]);
//Calculates Life or Death
void liveOrDie(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int& alive, int& dead, int rows, int cols);

void alivedead(int& alive, int& dead, bool grid[gridsize + 1][gridsize + 1]);

void somestuff(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int a, int b, int& life, int rows, int cols);

void checking(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int life, int a, int b);

int main() {
	srand(unsigned(time(0)));
	//const int gridsize = 50;
	bool grid[gridsize + 1][gridsize + 1] = {}, grid2[gridsize + 1][gridsize + 1] = {}, pravda = true;

	//just checking how much rows and columns we have
	int rows = std::extent<decltype(grid), 0>::value;
	int cols = std::extent<decltype(grid), 1>::value;
	int alive = 0, dead = 0;

	//there we will determine how much cycles we do want to see
	unsigned int stepsss;
	int stepss = 0;
	std::cout << "Please tell us how much cycles you'd like this program to do: "; std::cin >> stepsss;
	while (stepsss < 0) {
		std::cout << "Please enter values from 0 to eternity: "; std::cin >> stepsss;
	}
	//randomly designates alive cells at the start
	int howmuch = (rand() % ((gridsize + 1) * (gridsize + 1))); //defines amount of cells being alive at the start
	int xarray, yarray, xtemp = NULL, ytemp = NULL; //this line defines default variables of i and j for arrays and two temporary variables for them as well.
	while (howmuch) //this randomly assigns default alive cells without them repeating places
	{
		xarray = rand() % gridsize; yarray = rand() % gridsize;
		if (xtemp != xarray && ytemp != yarray)
		{
			grid[xarray][yarray] = true;
			howmuch--;
			xtemp = xarray;
			ytemp = yarray;
		}
	}

	do {


		Display(grid);     //This is our display.
		liveOrDie(grid, grid2, alive, dead, rows, cols); //calculate if it lives or dies.

		std::cout << "alive " << alive << "/ "; std::cout << "dead " << dead << "\n";
		system("CLS");
		stepss = stepss + 1;
	} while (stepss != stepsss);
}

void Display(bool grid[gridsize + 1][gridsize + 1]) {
	for (int a = 0; a <= gridsize; a++) {
		for (int b = 0; b <= gridsize; b++) {
			if (grid[a][b] == true) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
			if (b == gridsize) {
				std::cout << std::endl;
			}
		}
	}
}

void liveOrDie(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int& alive, int& dead, int rows, int cols) {
	CopyGrid(grid, grid2);
	alivedead(alive, dead, grid);
	for (int a = 0; a <= gridsize; a++) {
		for (int b = 0; b <= gridsize; b++) {
			int life = 0;
			somestuff(grid, grid2, a, b, life, rows, cols);
			checking(grid, grid2, life, a, b);
		}
	}
}

void CopyGrid(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1]) {
	for (int a = 0; a <= gridsize; a++) {
		for (int b = 0; b <= gridsize; b++) { grid2[a][b] = grid[a][b]; }
	}
}

void alivedead(int& alive, int& dead, bool grid[gridsize + 1][gridsize + 1]) {
	alive = 0; dead = 0;
	for (int i = 0; i <= gridsize; i++) {
		for (int j = 0; j <= gridsize; j++) {
			if (grid[i][j] == true)alive++;
			else {
				dead++;
			}
		}
	}
}

void somestuff(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int a, int b, int& life, int rows, int cols) {
	if (a == 0) {
		//highest left
		if (b == 0) {
			if (grid2[a][b + 1] == true) ++life;//Право
			if (grid2[a + 1][b] == true) ++life;//Низ
			if (grid2[a + 1][b + 1] == true) ++life;//Нижний правый угол

		}
		//highest right
		if (b == cols) {
			if (grid2[a][b - 1] == true) ++life;//Лево
			if (grid2[a + 1][b] == true) ++life;//Низ
			if (grid2[a + 1][b - 1] == true) ++life;//Нижний левый угол

		}
		//highest line
		if (b != cols && b != 0) {
			if (grid2[a][b - 1] == true) ++life;//Лево
			if (grid2[a][b + 1] == true) ++life;//Право
			if (grid2[a + 1][b] == true) ++life;//Низ
			if (grid2[a + 1][b - 1] == true) ++life;//Нижний левый угол
			if (grid2[a + 1][b + 1] == true) ++life;//Нижний правый угол


		}
	}
	else if (b == 0) {
		//lowest left
		if (a == rows) {
			if (grid2[a - 1][b] == true) ++life;//Верх
			if (grid2[a][b + 1] == true) ++life;//Право
			if (grid2[a - 1][b + 1] == true) ++life;//Верхний правый угол

		}
		//leftest line
		else if (a != 0) {
			if (grid2[a - 1][b] == true) ++life;//Верх
			if (grid2[a][b + 1] == true) ++life;//Право
			if (grid2[a + 1][b] == true) ++life;//Низ
			if (grid2[a + 1][b + 1] == true) ++life;//Нижний правый угол
			if (grid2[a - 1][b + 1] == true) ++life;//Верхний правый угол

		}
	}
	if (a == rows) {
		//lowest line
		if (b != 0 && b != cols) {
			if (grid2[a][b - 1] == true) ++life;//Лево
			if (grid2[a - 1][b] == true) ++life;//Верх
			if (grid2[a][b + 1] == true) ++life;//Право
			if (grid2[a - 1][b - 1] == true) ++life;//Верхний левый угол
			if (grid2[a - 1][b + 1] == true) ++life;//Верхний правый угол

		}
		//lowest right
		else if (b == cols) {
			if (grid2[a][b - 1] == true) ++life;//Лево
			if (grid2[a - 1][b] == true) ++life;//Верх
			if (grid2[a - 1][b - 1] == true) ++life;//Верхний левый угол

		}
	}
	else if (a != 0) {
		//righteous line
		if (a != rows && b == cols) {
			if (grid2[a - 1][b] == true) ++life;//Верх
			if (grid2[a][b - 1] == true) ++life;//Лево
			if (grid2[a + 1][b] == true) ++life;//Низ
			if (grid2[a - 1][b - 1] == true) ++life;//Верхний левый угол
			if (grid2[a + 1][b - 1] == true) ++life;//Нижний левый угол

		}
	}
	//center
	if (a != 0 && a != rows && b != 0 && b != cols) {
		if (grid2[a - 1][b] == true) ++life;//Верх
		if (grid2[a][b - 1] == true) ++life;//Лево
		if (grid2[a][b + 1] == true) ++life;//Право
		if (grid2[a + 1][b] == true) ++life;//Низ
		if (grid2[a - 1][b - 1] == true) ++life;//Верхний левый угол
		if (grid2[a + 1][b - 1] == true) ++life;//Нижний левый угол
		if (grid2[a - 1][b + 1] == true) ++life;//Верхний правый угол
		if (grid2[a + 1][b + 1] == true) ++life;//Нижний правый угол



	}
}

void checking(bool grid[gridsize + 1][gridsize + 1], bool grid2[gridsize + 1][gridsize + 1], int life, int a, int b) {
	if (grid2[a][b]) {
		if (life < 2) { grid[a][b] = false; }
		else if (life > 3) { grid[a][b] = false; }
	}
	else
	{
		if (life == 3)grid[a][b] = true;
	}
}