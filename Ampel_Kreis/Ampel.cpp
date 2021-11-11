#include "Ampel.h"
#include "CarProp.h"


Ampel::Ampel()
{
    initAmpelNord(Ampel_Farbe::GREEN);
    initAmpelSued(Ampel_Farbe::GREEN);
    initAmpelOst(Ampel_Farbe::RED);
    initAmpelWest(Ampel_Farbe::RED);
    initScale();
    cycle = true;
}

void Ampel::initScale()
{
    spriteNord.setScale(0.4, 0.4);
    spriteSued.setScale(0.4, 0.4);
    spriteOst.setScale(0.4, 0.4);
    spriteWest.setScale(0.4, 0.4);
}

Ampel::~Ampel()
{

}

void Ampel::initAmpelSued(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureSued.loadFromFile("images/GRUEN1.png"); break;
    case Ampel_Farbe::YELLOW: this->textureSued.loadFromFile("images/GELB1.png"); break;
    case Ampel_Farbe::RED: this->textureSued.loadFromFile("images/ROT1.png"); break;
    }
    this->spriteSued.setTexture(this->textureSued);

        this->spriteSued.setPosition(570.f, 620.f); 
        this->spriteSued.setRotation(0.f);
        std::cout << "Sued aufgerufen" << std::endl;
        
        
}

void Ampel::initAmpelNord(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureNord.loadFromFile("images/GRUEN1.png");  std::cout << "GREEN loaded" << std::endl; break;
    case Ampel_Farbe::RED: this->textureNord.loadFromFile("images/ROT1.png");  std::cout << "RED loaded" << std::endl; break;
    case Ampel_Farbe::YELLOW: this->textureNord.loadFromFile("images/GELB1.png"); break;
    }
    this->spriteNord.setTexture(textureNord);
    this->spriteNord.setPosition(430.f, 410.f);
    this->spriteNord.setRotation(180.f);
   
}

void Ampel::initAmpelOst(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureOst.loadFromFile("images/GRUEN1.png"); break;
    case Ampel_Farbe::RED: this->textureOst.loadFromFile("images/ROT1.png"); break;
    case Ampel_Farbe::YELLOW: this->textureOst.loadFromFile("images/GELB1.png"); break;
    }
    this->spriteOst.setTexture(textureOst);

    this->spriteOst.setPosition(570.f, 410.f);
    this->spriteOst.setRotation(270.f);
   
}

void Ampel::initAmpelWest(Ampel_Farbe color)
{
    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureWest.loadFromFile("images/GRUEN1.png"); break;
    case Ampel_Farbe::RED: this->textureWest.loadFromFile("images/ROT1.png"); break;
    case Ampel_Farbe::YELLOW: this->textureWest.loadFromFile("images/GELB1.png"); break;
    }
    this->spriteWest.setTexture(textureWest);

    this->spriteWest.setPosition(430.f, 625.f);
    this->spriteWest.setRotation(90.f);
    
}

void Ampel::cycleAmpel()
{
   //std::cout << "called" << std::endl;
    //std::cout << timer.getElapsedTime().asSeconds() << std::endl;

    if (timer.getElapsedTime().asSeconds() <= 10 && cycle == true)
    {
        initAmpelNord(Ampel_Farbe::GREEN);
        initAmpelSued(Ampel_Farbe::GREEN);
        initAmpelOst(Ampel_Farbe::RED);
        initAmpelWest(Ampel_Farbe::RED);
        cycle = false;
  
    }
    else if (timer.getElapsedTime().asSeconds() > 10 && timer.getElapsedTime().asSeconds()<= 11 && cycle == false)
    {
        initAmpelNord(Ampel_Farbe::YELLOW);
        initAmpelSued(Ampel_Farbe::YELLOW);
        initAmpelOst(Ampel_Farbe::YELLOW);
        initAmpelWest(Ampel_Farbe::YELLOW);
        cycle = true;
  
    }
    else if (timer.getElapsedTime().asSeconds() >11 && timer.getElapsedTime().asSeconds() <= 20 && cycle == true)
    {
        initAmpelNord(Ampel_Farbe::RED);
        initAmpelSued(Ampel_Farbe::RED);
        initAmpelOst(Ampel_Farbe::GREEN);
        initAmpelWest(Ampel_Farbe::GREEN);
        cycle = false;
    }
    else if (timer.getElapsedTime().asSeconds() > 21 && cycle == false)
    {
        timer.restart();
        cycle = true;
    }

     
}


void Ampel::startTimer()
{
    timer.restart();
}
bool Ampel::Ampel_GreenOben_Unten()
{
    return ampel_green_oben_unten;
}

bool Ampel::Ampel_GreenRechts_Links()
{
    return ampel_green_rechts_links;
}

void Ampel::render(sf::RenderTarget& target)
{
    target.draw(this->spriteSued);
    target.draw(this->spriteNord);
    target.draw(this->spriteWest);
    target.draw(this->spriteOst);
}
