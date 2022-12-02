#ifndef Voiture_hpp
#define Voiture_hpp
#include "Vehicule.hpp"

class Voiture : public  virtual Vehicule {

  public :
    Voiture(int vitesseMax=0, int nbPlaces=1, int occupants=0) : Vehicule(vitesseMax,nbPlaces,occupants){}
    void demarrer();
    void arreter();

};


#endif /* Voiture_hpp */