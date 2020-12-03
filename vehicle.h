
#pragma once
#include <vector>

class vehicle
{
	friend class street;
	int position;
	double Co2Emission;
	double baseEmission;
	bool moved = 0;

public:
	void gasesEmission(int posBefx, int posAftx);
	void changePos(int newPos);

	vehicle(double E_0, int x_) {
		position = x_;
		Co2Emission = E_0;
		baseEmission = E_0;
	}

};

