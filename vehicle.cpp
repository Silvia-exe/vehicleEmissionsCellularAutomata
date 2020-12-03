
#include "vehicle.h"

void vehicle::gasesEmission(int posBefx, int posAftx) {
	int dist = posAftx - posBefx;
	switch (dist)
	{
	case 0:
		Co2Emission = baseEmission;
		break;
	case 1:
		Co2Emission = baseEmission * 1.02;
		break;
	}
}

void vehicle::changePos(int newPos) {
	position = newPos;
}

