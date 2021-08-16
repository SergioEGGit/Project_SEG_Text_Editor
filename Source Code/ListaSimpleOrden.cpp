//---------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias---------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <fstream>
    #include <algorithm>
	#include <functional>
	#include <cctype>
	#include <locale>
	#include <cstring>
	#include "ListaSimpleOrden.h"
	using namespace std;

//---------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------Métodos-----------------------------------

	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void InsertarFinalLS(ListaLSO &listaLSO, string PalabraBuscar, string PalabraReemplazar)
	{
		ListaLSO auxt, auxq = new(struct OrdenLS);

		auxq -> PalabraBuscar  = PalabraBuscar;
		auxq -> PalabraReemplazar = PalabraReemplazar;
		auxq -> sgte = NULL;

		if(listaLSO == NULL)
		{
			listaLSO = auxq;
		}
		else
		{
			auxt = listaLSO;
			while(auxt -> sgte != NULL)
			{
				auxt = auxt -> sgte;
			}
			auxt -> sgte = auxq;
		}
	}

	int PilaTa(PilaPL &Pila)
	{
		int contador = 0;
		PilaPL aux = Pila;

		if(aux != NULL)
		{
			while(aux != NULL)
			{
				contador++;
				aux = aux -> sgte;
			}
		}

		return contador;
	}

	void ReporteLS1(ListaLSO &listaLSO, PilaPL &Pila)
	{
		ofstream Reporte3("Reporte3.dot");
		ListaLSO aux = listaLSO;
		Reporte3<< "digraph G" << endl;
		Reporte3<< "{" << endl;
		Reporte3<< "node [shape = box, fontname = Arial, color = brown];" <<endl;
		int contador = 0;
		string temp[10000];
		string Same;
		string Asc = "";

		if(listaLSO != NULL)
		{
			do
			{
				Reporte3<< "A" << contador << " [label = " <<"\"" << aux -> PalabraBuscar << "\\l" << "Remplazada Por: " << aux -> PalabraReemplazar << "\\l" "\"]" <<endl;
				temp[contador] = "A" + to_string(contador);
				contador++;
				aux = aux -> sgte;
			}
			while(aux != NULL);

			for(int i = 0; i < contador; i++)
			{
				Same = Same + temp[i] + " ";
				if(i < contador - 1)
				{
					Asc = Asc + temp[i] + "->";
				}
				else
				{
					Asc = Asc + temp[i];
				}
			}
			Reporte3<< "{ rank = same " << Same << "}" << endl;
			Reporte3<< Asc <<endl;
			Reporte3<< " " <<endl;
			Reporte3<< "}";
			Reporte3.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng Reporte3.dot -o Reporte3.png");
			//Abrir Imagen
			system("C:\\Usac\\\"Estructuras De Datos\"\\EDD_1S2020_P1_201801628\\Win32\\Debug\\Reporte3.png &" );
		}
	}

	void ReporteLS2(ListaLSO &listaLSO, PilaPL &Pila)
	{
		ofstream Reporte31("Reporte3-1.dot");
		ListaLSO aux = listaLSO;
		Reporte31<< "digraph G" << endl;
		Reporte31<< "{" << endl;
		Reporte31<< "node [shape = box, fontname = Arial, color = orange];" <<endl;
		int contador = 0;
		string temp[10000];
		string Same;
		string Asc = "";

		if(listaLSO != NULL)
		{
			do
			{
				Reporte31<< "A" << contador << " [label = " <<"\"" << aux -> PalabraReemplazar << "\\l" << "Reemplazo A: " << aux -> PalabraBuscar << "\\l" "\"]" <<endl;
				temp[contador] = "A" + to_string(contador);
				contador++;
				aux = aux -> sgte;
			}
			while(aux != NULL);

			for(int i = 0; i < contador; i++)
			{
				Same = Same + temp[i] + " ";
				if(i < contador - 1)
				{
					Asc = Asc + temp[i] + "->";
				}
				else
				{
					Asc = Asc + temp[i];
				}
			}
			Reporte31<< "{ rank = same " << Same << "}" << endl;
			Reporte31<< Asc <<endl;
			Reporte31<< " " <<endl;
			Reporte31<< "}";
			Reporte31.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng Reporte3-1.dot -o Reporte3-1.png");
			//Abrir Imagen
			system("C:\\Usac\\\"Estructuras De Datos\"\\EDD_1S2020_P1_201801628\\Win32\\Debug\\Reporte3-1.png &" );
		}
	}

	void ReporteOrdenLS(ListaLSO &listaLSO, PilaPL &Pila)
	{
		int i, j , n;
		int T = 0;
		PilaPL aux = Pila;

		int NUM = PilaTa(Pila);

		struct Palabras
		{
			string PalabraBuscar;
			string PalabraReemplazar;
        };

		typedef struct Palabras P;

		P Orden[NUM];
		P Temp;

		//Rellenar Estructura Temporal
		for(i = 0; i < NUM; i++)
		{
			Orden[i].PalabraBuscar = aux -> PalabraBuscar;
			Orden[i].PalabraReemplazar = aux -> PalabraReemplazar;
			aux = aux -> sgte;
		}

		//Ordenar Arreglo Por Palabra Buscar
		for(i = 0; i < NUM; i++)
		{
			for(j = 0; j < NUM - 1; j++)
			{
				if(Orden[j].PalabraBuscar > Orden[i].PalabraBuscar)
				{
					Temp = Orden[i];
					Orden[i] = Orden[j];
					Orden[j] = Temp;
				}
			}
		}

		//Rellenar Lista Ordenada Por Palabra Buscar
		for (i = 0; i < NUM; i++)
		{
			InsertarFinalLS(listaLSO, Orden[i].PalabraBuscar, Orden[i].PalabraReemplazar);
		}


		//Generar Reporte Ordenado Por Palabra Buscar
		ReporteLS1(listaLSO, Pila);



		//Ordenar Arreglo Por Palabra Reemplazar
		for(i = 0; i < NUM; i++)
		{
			for(j = 0; j < NUM - 1; j++)
			{
				if(Orden[j].PalabraReemplazar > Orden[i].PalabraReemplazar)
				{
					Temp = Orden[i];
					Orden[i] = Orden[j];
					Orden[j] = Temp;
				}
			}
		}

		listaLSO = NULL;
		aux = NULL;

		//Rellenar Lista Ordenada Por Palabra Reemplazar
		for (i = 0; i < NUM; i++)
		{
			InsertarFinalLS(listaLSO, Orden[i].PalabraBuscar, Orden[i].PalabraReemplazar);
		}

		//Generar Reporte Ordenado Por Palabra Reemplazar
		ReporteLS2(listaLSO, Pila);

	}
