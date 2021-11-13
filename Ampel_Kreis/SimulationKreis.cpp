#include "SimulationKreis.h"

SimulationKreis::SimulationKreis()
{

}

SimulationKreis::~SimulationKreis()
{

}

void SimulationKreis::run()
{
	//this->spawnAutos();
	//this->updateAutos();
	this->moveAutos();
}

void SimulationKreis::moveAutosInKVEast()
{
	if (!autosOInKVEast.empty()) {
		for (int i = 0; i < autosOInKVEast.size(); i++)
		{
			autosOInKVEast[i]->checkDestination();
			autosOInKVEast[i]->checkChangeEast(); 
			std::cout << autosOInKVEast[i]->leave << std::endl;
			std::cout << autosOInKVEast[i]->change << std::endl;


			if (autosOInKVEast[i]->leave == false && autosOInKVEast[i]->change == false)
			{
				autosOInKVEast[i]->beschleunigeInKV();
				autosOInKVEast[i]->Kreisbewegung(autosOInKVEast[i]->spawn);
				autosOInKVEast[i]->moveInKV();
				
			}

			else if (autosOInKVEast[i]->change == true && autosOInKVEast[i]->leave == false)
			{
				autosOInKVNorth.push_back(autosOInKVEast[i]);
				autosOInKVEast.erase(autosOInKVEast.begin() + i);

			}
			else if (autosOInKVEast[i]->leave == true)
			{
				autosOOutKv.push_back(autosOInKVEast[i]);
				autosOInKVEast.erase(autosOInKVEast.begin() + i);
				std::cout << autosOOutKv.size() << std::endl;
			}
		}
	}
}


void SimulationKreis::moveAutosInKVWest()
{
	if (!autosOInKVWest.empty()) {
		for (int i = 0; i < autosOInKVWest.size(); i++)
		{
			autosOInKVWest[i]->checkDestination();
			autosOInKVWest[i]->checkChangeWest();

			if (autosOInKVWest[i]->leave == false && autosOInKVWest[i]->change == false)
			{
				autosOInKVWest[i]->beschleunigeInKV();
				autosOInKVWest[i]->Kreisbewegung(autosOInKVWest[i]->spawn);
				autosOInKVWest[i]->moveInKV();
			}

			else if (autosOInKVWest[i]->change == true && autosOInKVWest[i]->leave == false)
			{
				autosOInKVSouth.push_back(autosOInKVWest[i]);
				autosOInKVWest.erase(autosOInKVWest.begin() + i);
			}
			else if (autosOInKVWest[i]->leave == true)
			{
				autosOOutKv.push_back(autosOInKVWest[i]);
				autosOInKVWest.erase(autosOInKVWest.begin() + i);
				std::cout << autosOOutKv.size() << std::endl;
			}
		}
	}
}

void SimulationKreis::moveAutosInKVNorth()
{
	if (autosOInKVNorth.empty()) {
		for (int i = 0; i < autosOInKVNorth.size(); i++)
		{
			autosOInKVNorth[i]->checkDestination();
			autosOInKVNorth[i]->checkChangeNorth();

			if (autosOInKVNorth[i]->leave == false && autosOInKVNorth[i]->change == false)
			{
				autosOInKVNorth[i]->beschleunigeInKV();
				autosOInKVNorth[i]->Kreisbewegung(autosOInKVNorth[i]->spawn);
				autosOInKVNorth[i]->moveInKV();
			}

			else if (autosOInKVNorth[i]->change == true && autosOInKVNorth[i]->leave == false)
			{
				autosOInKVWest.push_back(autosOInKVNorth[i]);
				autosOInKVNorth.erase(autosOInKVNorth.begin() + i);
			}
			else if (autosOInKVNorth[i]->leave == true)
			{
				autosOOutKv.push_back(autosOInKVNorth[i]);
				autosOInKVNorth.erase(autosOInKVNorth.begin() + i);
				std::cout << autosOOutKv.size() << std::endl;
			}
		}
	}
}

void SimulationKreis::moveAutosInKVSouth()
{
	if (!autosOInKVSouth.empty())
	{
		for (int i = 0; i < autosOInKVSouth.size(); i++)
		{
			autosOInKVSouth[i]->checkDestination();
			autosOInKVSouth[i]->checkChangeSouth();

			if (autosOInKVSouth[i]->leave == false && autosOInKVSouth[i]->change == false)
			{
				autosOInKVSouth[i]->beschleunigeInKV();
				autosOInKVSouth[i]->Kreisbewegung(autosOInKVSouth[i]->spawn);
				autosOInKVSouth[i]->moveInKV();
			
			}

			else if (autosOInKVSouth[i]->change == true && autosOInKVSouth[i]->leave == false)
			{
				autosOInKVEast.push_back(autosOInKVSouth[i]);
				autosOInKVSouth.erase(autosOInKVSouth.begin() + i);
			}
			else if (autosOInKVSouth[i]->leave == true)
			{
				autosOOutKv.push_back(autosOInKVSouth[i]);
				autosOInKVSouth.erase(autosOInKVSouth.begin() + i);
				std::cout << autosOOutKv.size() << std::endl;
			}
		}
	}
}

void SimulationKreis::moveAutosInKV()
{
	moveAutosInKVSouth();
	moveAutosInKVEast();
	moveAutosInKVWest();
	moveAutosInKVNorth();
	
}

void SimulationKreis::moveAutosbeforeKV()
{
	for (int i = 0 ; i < autosO.size(); i++)
	{
		if (pow(autosO[i]->getPos().x - 500, 2) + pow(autosO[i]->getPos().y - 500, 2) > pow(300, 2))
		{
			autosO[i]->beschleunige();
			autosO[i]->moveBeforeKV(autosO[i]->spawn, autosO[i]->weg);
		}
		else if( autosOInKVEast.size() <= 2 && autosOInKVSouth.empty() && autosO[i]->spawn == Direction::EAST)
		{
			autosOInKVEast.push_back(autosO[i]); std::cout <<"AutosEast: " << autosOInKVEast.size() << std::endl;
			autosO.erase(autosO.begin() + i); 
		}
		else if (autosOInKVNorth.size() <= 2 && autosOInKVEast.empty() && autosO[i]->spawn == Direction::NORTH)
		{
			autosOInKVNorth.push_back(autosO[i]); std::cout <<"AutosNorth: " << autosOInKVNorth.size() << std::endl;
			autosO.erase(autosO.begin() + i);
		}
		else if (autosOInKVWest.size() <= 2 && autosOInKVNorth.empty() && autosO[i]->spawn == Direction::WEST)
		{
			autosOInKVWest.push_back(autosO[i]); std::cout <<"AutosWest: " << autosOInKVWest.size() << std::endl;
			autosO.erase(autosO.begin() + i);
		}
		else if (autosOInKVSouth.size() <= 2 && autosOInKVWest.empty() && autosO[i]->spawn == Direction::SOUTH)
		{
			autosOInKVSouth.push_back(autosO[i]); std::cout << "AutosSouth:  " << autosOInKVSouth.size() << std::endl;
			autosO.erase(autosO.begin() + i); 
		}
		else
		{
			autosO[i]->moveBeforeKV(autosO[i]->spawn, 0);
		}
	}
}

void SimulationKreis::moveAutosOutKV()
{
	for (int i = 0; i < autosOOutKv.size(); i++)
	{
		autosOOutKv[i]->RotateAuto(autosOOutKv[i]->originalDirection);
		autosOOutKv[i]->beschleunigeOutKv();
		autosOOutKv[i]->moveOutKV(autosOOutKv[i]->originalDirection, autosOOutKv[i]->weg);
	}
}

void SimulationKreis::moveAutos()
{
	this->moveAutosbeforeKV();
	this->moveAutosInKV();
	this->moveAutosOutKV();
}

void SimulationKreis::spawnAutos()
{
	while (autosO.size() <= 5)
	{
		rndValueSpawn = rand() % 100;
		rndValueDirection = rand() % 100;
		rndValueType = rand() % 10;

		if (rndValueSpawn <= 14 && !Functions::checkSpawnNorth1(autosO))
		{

			spawnAutosNord();

		}
		else if (rndValueSpawn > 15 && rndValueSpawn <= 49 && !Functions::checkSpawnEast1(autosO))
		{

			spawnAutosOst();


		}
		else if (rndValueSpawn > 49 && rndValueSpawn <= 64 && !Functions::checkSpawnWest1(autosO))
		{

			spawnAutosWest();

		}
		else if (rndValueSpawn > 65 && rndValueSpawn <= 99 && !Functions::checkSpawnSouth1(autosO))
		{

			spawnAutosSued();

		}
		else
			break;
	}
	
}

void SimulationKreis::renderAutosO(sf::RenderTarget& target)
{
	for (auto* x: this->autosO)
	{
		x->render(target);
	}
	for (auto* x : this->autosOInKVEast)
	{
		x->render(target);
	}
	for (auto* x : this->autosOInKVWest)
	{
		x->render(target);
	}
	for (auto* x : this->autosOInKVNorth)
	{
		x->render(target);
	}
	for (auto* x : this->autosOInKVSouth)
	{
		x->render(target);
	}
	for (auto* x : this->autosOOutKv)
	{
		x->render(target);
	}
}


void SimulationKreis::spawnAutosNord()//spawn im Norden
{

	startCounterNorthKV++;
	if (rndValueDirection < 10)//fahr nach Norden
	{
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED , Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::EAST, 2.f));
		}
		
	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::SOUTH, 2.f));
		}
		
	}
	else //Fahr nach Westen
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::WEST, 2.f));
		}
	}
}

void SimulationKreis::spawnAutosWest()
{
	startCounterWestKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::NORTH, 2.f));
		}
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED , Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::EAST, 2.f));
		}
	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::SOUTH, 2.f));
		}

	}
	else //Fahr nach Westen
	{
		//geht nicht
	}
}

void SimulationKreis::spawnAutosOst()
{
	startCounterEastKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::NORTH, 2.f));
		}
	}


	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		//geht nicht
	}


	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::SOUTH, 2.f));
		}

	}


	else //Fahr nach Westen
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::WEST, 2.f));
		}

	}
}

void SimulationKreis::spawnAutosSued()
{
	startCounterSouthKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::NORTH, 2.f));
		}
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::EAST, 2.f));
		}
	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		//geht nicht
	}
	else //Fahr nach Westen
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::WEST, 2.f));
		}
	}
}

