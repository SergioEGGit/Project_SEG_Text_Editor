//---------------------------------------------------------------------------

	#ifndef ListaDoblePalabrasH
	#define ListaDoblePalabrasH
    #include <iostream>
	#include <string>
	#include <cstdlib>
	using namespace std;

//--------------------------------Estructura------------------------------------

	struct PalabrasLD
	{
		string Palabra;
		struct PalabrasLD *sgte;
		struct PalabrasLD *ante;
	};

	typedef struct PalabrasLD *ListaLDP;

	void InsertarFinalLDP(ListaLDP &Cabeza, ListaLDP &Cola, string Palabra);

	void BorrarUltimoLDP(ListaLDP &Cola);

	void MostrarLDP(ListaLDP &Cabeza);

//---------------------------------------------------------------------------
#endif
