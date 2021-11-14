#pragma once
#include"Autos.h"
#include"AutosO.h"
#include "Functions.h"
#include "Ampel.h"
#include "GUI.h"
#include <time.h>
#include "SimulationKreis.h"

class Simulation
{
private:
	sf::RenderWindow* window;
	sf::RenderWindow* window2;


	
	sf::Clock clock;

	SimulationKreis* simulationKreisverkehr;
	Ampel* ampel;
	//Autos
	//Auto rot
	int spawnTimer;
	int spawnTimerMax;

	//Autos im Kreuzverkehr
	std::vector<Autos*> autos;

	//Hintergrund
	sf::Texture KreuzverkehrTex;
	sf::Sprite Kreuzverkehr;
	sf::Texture KreisverkehrTex;
	sf::Sprite Kreisverkehr;

	void initSimulationKreisverkehr();
	void initAmpel();
	void initWindow();
	void initAuto();
	void initKreuzverkehr();
	void initKreisverkehr();
	void renderWorld();
	void initWahrscheinlichkeiten();

	//GUI-Sachen erstellen
	void initGUI();
	void initCounter();

public:
	bool startIsAllowed;
	bool startTimer;
	Simulation();
	virtual ~Simulation();
	
	

	//funktionen
	void run();
	void updateAuto();
	void updateAfterStart();
	void deleteAutos();
	void deleteAutosO();
	void update();
	void render();

	//Übernehmen der Wk´s aus dem GUI
	int WkFahrer1;
	int WkFahrer2;
	int WkFahrer3;


	GUI* gui;
	void backToGUI(); //ermöglich es Zeit, Anzahl Fahrzeuge an das GUI zu übergeben und zu rendern


	int endCounterNorth;
	int endCounterEast;
	int endCounterSouth;
	int endCounterWest;

	int startCounterNorth;
	int startCounterEast;
	int startCounterSouth;
	int startCounterWest;

	//Counter für den Kreisverkehr
};