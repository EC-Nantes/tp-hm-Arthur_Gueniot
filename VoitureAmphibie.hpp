#ifndef VoitureAmphibie_hpp
#define VoitureAmphibie_hpp
#include "Bateau.hpp"
#include "Voiture.hpp"

class VoitureAmphibie : public Voiture, public Bateau {
  public :
    VoitureAmphibie(int vitesseMax=0, int nbPlaces=1, int occupants=0) : Voiture(vitesseMax,nbPlaces,occupants), Bateau(vitesseMax,nbPlaces,occupants), Vehicule(vitesseMax,nbPlaces,occupants);

};


#endif /* VoitureAmphibie_hpp */