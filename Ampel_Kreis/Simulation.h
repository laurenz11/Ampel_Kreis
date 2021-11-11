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


	GUI* gui;
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


	void backToGUI(); //erm�glich es Zeit, Anzahl Fahrzeuge an das GUI zu �bergeben und zu rendern

	int endCounterNorth;
	int endCounterEast;
	int endCounterSouth;
	int endCounterWest;

	int startCounterNorth;
	int startCounterEast;
	int startCounterSouth;
	int startCounterWest;

	//Counter f�r den Kreisverkehr
	int endCounterNorthKV;
	int endCounterEastKV;
	int endCounterSouthKV;
	int endCounterWestKV;

	int startCounterNorthKV;
	int startCounterEastKV;
	int startCounterSouthKV;
	int startCounterWestKV;
};