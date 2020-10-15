#pragma once
#include <iostream>
#include "player.h"

using namespace std;

class Casino
{
	Player top100[100] = {Player("0",0)};
	string top100NameFile;
	void loadTop100();

	public:
		Casino(string top100Name = "top100.txt") {
			top100NameFile = top100Name;

			loadTop100();
		}

	void printMenu(string,int);
	void updateTop100(Player);
	void printTop100();
	void saveTop100();
};

