#pragma once
#include "AutosO.h"
#include "CarProp.h"
#include "Functions.h"
#include <math.h>
#include <iostream>
#include <time.h>


class SimulationKreis
{
public:
	SimulationKreis();
	~SimulationKreis();

	void run();

	std::vector <AutosO*> autosO;//Vektor für Autos, die vor dem Kreisverkehr sind
	std::vector <AutosO*> autosOInKV;
	std::vector <AutosO*> autosOOutKv;


	void spawnAutosNord();
	void spawnAutosWest();
	void spawnAutosOst();
	void spawnAutosSued();

	void spawnAutos();

	void moveAutosInKV();
	void moveAutosbeforeKV();
	void moveAutosOutKV();
	void moveAutos();

	void checkDestination();

	void deleteAutosO();

	void renderAutosO(sf::RenderTarget& target);

	int rndValueSpawn;
	int rndValueDirection;
	int rndValueType;

	int endCounterNorthKV;
	int endCounterEastKV;
	int endCounterSouthKV;
	int endCounterWestKV;

	int startCounterNorthKV;
	int startCounterEastKV;
	int startCounterSouthKV;
	int startCounterWestKV;
	
};


/*void Simulation::deleteAutosO()
{
	
}


for (auto* i : this->autoso)
	{
		delete i;
	}
*/