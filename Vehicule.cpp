#include "Vehicule.hpp"

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants) {
  cout << "Creation du Vehicule" << endl;
  this->vitesseMax_ = vitesseMax;
  this->nbPlaces_ = nbPlaces;
  this->occupants_ = occupants;
  this->vitesse_ = 0;
  this->etat_ = ARRET;
}

void Vehicule::demarrer() {
  try {
    if (this->etat_ == ARRET) {
      this->etat_ = MARCHE;
    } else {
      throw std::invalid_argument(
          "La voiture peut démarrer dans l'état ARRET uniquement");
    }
  } catch (const std::invalid_argument &err_msg) {
    std::cerr << "Exception : " << err_msg.what() << std::endl;
  }
}

void Vehicule::arreter() { this->etat_ = ARRET; }

void Vehicule::depanner() { this->etat_ = ARRET; }

void Vehicule::accelerer(int increment) {
  try {
    if ((this->vitesse_ + increment) < 0) {
      throw std::invalid_argument("Vitesse ne peut pas être nulle");
    } else {
      if (this->vitesse_ + increment > this->vitesseMax_) {
        throw std::invalid_argument(
            "Vitesse ne peut pas être supérieur à vitesse Max");
      } else {
        this->vitesse_ += increment;
      }
    }
  } catch (const std::invalid_argument &err_msg) {
    std::cerr << "Exception : " << err_msg.what() << std::endl;
  }
}

void Vehicule::monter(int nbOcc) {
  try {
    if ((this->occupants_ + nbOcc) > this->nbPlaces_) {
      throw std::invalid_argument(
          "La voiture ne doit pas être pleine pour ajouter des occupants");
    } else {
      this->occupants_ -= nbOcc;
    }
  } catch (const std::invalid_argument &err_msg) {
    std::cerr << "Exception : " << err_msg.what() << std::endl;
  }
}

void Vehicule::descendre(int nbOcc) {
  try {
    if ((this->occupants_ - nbOcc) < 0) {
      throw std::invalid_argument(
          "On ne peut pas faire descendre plus d'occupants qu'il n'y en a");
    } else {
      this->occupants_ += nbOcc;
    }
  } catch (const std::invalid_argument &err_msg) {
    std::cerr << "Exception : " << err_msg.what() << std::endl;
  }
}

void Vehicule::mettreEnPanne(double random) {
  if (random < 0.5) {
    this->etat_ = PANNE_LEGERE;
  } else {
    this->etat_ = PANNE_SEVERE;
  }
}

string Vehicule::getEtat() const { 
  string ret="";
  switch(this->etat_)
  {
    case ARRET  : ret = "ARRET\n";   break;
    case MARCHE:  ret = "MARCHE\n"; break;
    case PANNE_LEGERE : ret = "PANNE_LEGERE\n";  break;
    case PANNE_SEVERE : ret = "PANNE_SEVERE\n";  break;
    default: string ret=""; break;
  }
  return ret; 
}

// string Vehicule::getEtat() const { return "toto"; }

Vehicule::~Vehicule() { cout << "Destruction du Vehicule" << endl; }

ostream &operator<<(ostream &s, Vehicule const &v) {
  s << "Vehicule :\n"
    << "\tEtat : " << v.getEtat() << "\tVitesse : " << v.vitesse_
    << "\n\tVitesse Max : " << v.vitesseMax_
    << "\n\tNombre de places : " << v.nbPlaces_
    << "\n\tOccupants : " << v.occupants_;
  return s;
}