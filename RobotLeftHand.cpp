#include "RobotLeftHand.hpp"
#include <iostream>

RobotLeftHand::RobotLeftHand(int x, int y, Labyrinth* lab) : Robot(x, y, lab)
{
}

RobotLeftHand::~RobotLeftHand()
{
}

int RobotLeftHand::start()
{
	mCount = 0;
	while(!isFinish()){
		turnLeft();
		algo();
		mCount++;
	}
	std::cout << "t1 - Ziel erreicht! Schritte: "<< mCount << std::endl;
	return 1;
}

void RobotLeftHand::algo()
{
	for(int i = 0; i < 4; i++) {
		if(!move(getView())) {
			turnRight();
		} else {
			return;
		}
	}
}
