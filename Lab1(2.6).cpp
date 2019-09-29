//#include "pch.h" // если не будет запускаться
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
	setlocale(0, "");
	int countDices = 0;
	int countOfEdge[7] = { 2, 4, 6, 8, 10, 12, 20 };
	int sumOfAllEdges = 0;
	int sumOfAllDices = 0;
	cout << "Enter the count of dices: " << endl;
	cin >> countDices;

	int *arr = new int[countDices];

	for (int i = 0; i < countDices; i++) {
		//srand(time(0));
		int numberOfDice = rand() % 7 + 1;
		int R = 0;
		arr[i] = countOfEdge[numberOfDice - 1];
		cout << "Dice number " << i+1 << " | " << arr[i] << " | " << endl;

		for (int j = 0; j < arr[i]; j++) {
			R = rand() % 2 + 1;
			if (R == 2) {
				R = 0;
			}
			cout << "Edge " << j + 1 <<" = " << R << endl;
			sumOfAllEdges += R;
			if (j == 0) {
				sumOfAllDices += R;
			}
		}
	}

	cout << endl << "Sum of All Dices = " << sumOfAllDices << endl;
	cout << "Sum of All Edges = " << sumOfAllEdges << endl;

	system("pause");
	return 0;
}
