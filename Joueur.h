//---------------------------------------------------------------------------

#ifndef JoueurH
#define JoueurH
//---------------------------------------------------------------------------
#endif

class Joueur{
	private:
		int minutes, secondes;
		bool trait;
	public:
		Joueur();
		int Minutes(), Secondes();
		void Initialiser(int m, int s), Decrementer(), DonnerLeTrait(), RetirerLeTrait();
		bool DefaiteAuTemps(), Trait();
};