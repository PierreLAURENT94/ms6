//---------------------------------------------------------------------------

#pragma hdrstop

#include "Joueur.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Joueur::Joueur(){
	trait = false;
}

void Joueur::DonnerLeTrait(){
	trait = true;
}

void Joueur::RetirerLeTrait(){
	trait = false;
}

bool Joueur::Trait(){
	return trait;
}

int Joueur::Minutes(){
	return minutes;
}

int Joueur::Secondes(){
	return secondes;
}

void Joueur::Initialiser(int m, int s){
	minutes = m;
    secondes = s;
}

void Joueur::Decrementer(){
	secondes--;
	if(secondes<0){
		secondes=59;
		minutes--;
		if(minutes<0){
			secondes=0;
			minutes=0;
		}
	}
}
