#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <Echiquier.h>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) 
{
	Echiquier test;
	int idep, jdep, iarr, jarr;
	bool police;
    char promo;
	while(true){
		cout << test.VisualiserEchiquier();
        cout << "Tour des " << test.Trait() << endl;
		cin >> idep >> jdep >> iarr >> jarr;
        promo = ' ';
		if(test.LireCaseEchiquier(idep, jdep) == 'P' && iarr==0){
			cout << "Piece promo(D T F C):";
            cin >> promo;
		}
		else if(test.LireCaseEchiquier(idep, jdep) == 'p' && iarr==7){
			cout << "Piece promo(d t f c):";
			cin >> promo;
		}
		police = test.Deplacer(idep, jdep, iarr, jarr, promo);
		if(!police){
        	cout << "coup ill?gal" << endl;
		}
		else{
			test.ChangerLeTrait();
		}
	}
	system("pause");
	return 0;
}
