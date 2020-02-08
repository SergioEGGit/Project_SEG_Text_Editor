//---------------------------------------------------------------------------

#ifndef ListaDobleCaracteresH
#define ListaDobleCaracteresH


	struct CaracteresLD
	{
	   int Id;
	   struct CaracteresLD *sgte;
	   struct CaracteresLD *ant;
	};

	typedef struct CaracteresLD *ListaDobleCaracteres;

	void InsertarLD();


//---------------------------------------------------------------------------
#endif

