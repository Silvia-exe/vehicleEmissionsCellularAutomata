#pragma once
#include <vector>
#include <iostream>
#include "vehicle.h"


class street
{
	friend class vehicle;
	std::vector<int> occupied;
	std::vector<int> obstacles;
	std::vector<vehicle> vehicles;
	int lenght;

	void initializeStreet(int lenght_, double rhoOb_, double rhoO_, double E_0_) {
		lenght = lenght_;
		initStreet();
		fillObstacles(rhoOb_);
		fillOccupied(rhoO_, E_0_);
	}

public:
	void initStreet();
	void fillObstacles(double rhoOb);
	void fillOccupied(double rho, double E_0);
	void printObstacles();
	void moveVehicles();

	street(int lenght_, double rhoOb_, double rhoO_) {
		initializeStreet(lenght_, rhoOb_, rhoO_);
	}
};

