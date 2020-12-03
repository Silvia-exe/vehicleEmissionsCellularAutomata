#include "street.h"

void street::initStreet() {

	for (int i = 0; i < lenght; i++) {
		occupied.push_back(0);
		obstacles.push_back(0);
	}

}

void street::fillObstacles(double rho) {

	int obstacleCells = lenght * rho;
	int tempObsX;
	int numbObstCell = 0;

	while (numbObstCell != obstacleCells) {
		
		tempObsX = rand() % lenght;

		std::cout << tempObsX << ":";
		if (obstacles[tempObsX] == 0) {
			obstacles[tempObsX] = 1;
			numbObstCell++;
		}
	}
}

void street::fillOccupied(double rho, double E_0) {

	int occupiedCells = (lenght * 2)*rho;
	int tempOccX;
	int numbOccCell = 0;

	while (numbOccCell != occupiedCells) {
		tempOccX = rand() % lenght;
		if (occupied[tempOccX] == 0) {
			occupied[tempOccX] = 1;
			vehicle temp(E_0, tempOccX);
			vehicles.push_back(temp);
			numbOccCell++;
		}
	}
}

void street::moveVehicles() {
	int tempPos;

	for (int i = 0; i < vehicles.size(); i++) {
		tempPos = vehicles[i].position;
		occupied[tempPos] = 0;
		if (vehicles[i].position != -1) {
			if (tempPos == lenght - 1 || tempPos == lenght - 2) {
				occupied[tempPos] = 0;
				vehicles[i].position = -1;
			}
			else if (occupied[tempPos + 1] == 0) {
				if (obstacles[tempPos + 1] == 0) {
					vehicles[i].position += 1;
					occupied[tempPos + 1] = 1;
				}
			}
		}
	}
}

void street::printObstacles() {
	std::cout << "\n";
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < lenght; x++) {
			std::cout << obstacles[x]<< ":";
		}
		std::cout << "\n";
	}

}
