/**
* \file DicoSynonymes.cpp
* \brief Le code des opérateurs du DicoSynonymes.
* \author ?
* \version 0.5
* \date ?
*
* Travail pratique numéro 3.
*
*/

#include "DicoSynonymes.h"
#include "AssertionException.h"

namespace TP3
{

DicoSynonymes::DicoSynonymes() {
}

DicoSynonymes::DicoSynonymes(std::ifstream& fichier) {
}

DicoSynonymes::~DicoSynonymes() {
}

void DicoSynonymes::ajouterRadical(const std::string& motRadical) {
}

void DicoSynonymes::ajouterFlexion(const std::string& motRadical,
		const std::string& motFlexion) {
}

void DicoSynonymes::ajouterSynonyme(const std::string& motRadical,
		const std::string& motSynonyme, int& numGroupe) {
}

void DicoSynonymes::supprimerRadical(const std::string& motRadical) {
}

void DicoSynonymes::supprimerFlexion(const std::string& motRadical,
		const std::string& motFlexion) {
}

void DicoSynonymes::supprimerSynonyme(const std::string& motRadical,
		const std::string& motSynonyme, int& numGroupe) {
}

bool DicoSynonymes::estVide() const {
}

int DicoSynonymes::nombreRadicaux() const {
}

	// Méthode fournie que vous pouvez modifier si vous voulez
	void DicoSynonymes::chargerDicoSynonyme(std::ifstream& fichier)
	{
		ASSERTION(fichier.is_open());

		std::string ligne;
		std::string buffer;
		std::string radical;
		int cat = 1;

		while (std::getline(fichier, ligne)) // tant qu'on peut lire dans le fichier
		{

			if (ligne == "$")
			{
				cat = 3;
				std::getline(fichier, ligne);
			}
			if (cat == 1)
			{
				radical = ligne;
				ajouterRadical(radical);
				cat = 2;
			}
			else if (cat == 2)
			{
				std::stringstream ss(ligne);
				while (ss >> buffer)
					ajouterFlexion(radical, buffer);
				cat = 1;
			}
			else
			{
				std::stringstream ss(ligne);
				ss >> radical;
				ss >> buffer;
				int position = -1;
				ajouterSynonyme(radical, buffer, position);
				while (ss >> buffer)
					ajouterSynonyme(radical, buffer, position);
			}
		}
	}

	//Mettez l'implantation des autres méthodes demandées ici.

std::string DicoSynonymes::rechercherRadical(const std::string& mot) const {
}

float DicoSynonymes::similitude(const std::string& mot1,
		const std::string& mot2) const {
}

int DicoSynonymes::getNombreSens(std::string radical) const {
}

std::string DicoSynonymes::getSens(std::string radical, int position) const {
}

std::vector<std::string> DicoSynonymes::getSynonymes(std::string radical,
		int position) const {
}

std::vector<std::string> DicoSynonymes::getFlexions(std::string radical) const {
}

}//Fin du namespace