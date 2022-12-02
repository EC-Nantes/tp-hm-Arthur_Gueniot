#ifndef Bateau_hpp
#define Bateau_hpp
#include "Vehicule.hpp"

class Bateau : public virtual Vehicule {
  public :
    Bateau(int vitesseMax=0, int nbPlaces=1, int occupants=0) : Vehicule(vitesseMax,nbPlaces,occupants){}
    void demarrer();
    void arreter();

};


#endif /* Bateau_hpp */