#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//---------------------------------Librerias------------------------------------
   #include <iostream>
   #include <stdio.h>
   #include <conio.h>
   #include <string>
   #include <windows.h>
   using namespace std;

//----------------------------------Variables-----------------------------------

   int Alto = 0;
   int Ancho = 0;

//------------------------------------Métodos-----------------------------------

	 //---------------------------------Menú-------------------------------

		void menu()
		{
		   gotoxy ((Ancho - 2)/2 - , 2);
		   cout<< "Universidad De San Carlos De Guatemala";
		}



	 //-------------------------------Marcos-------------------------------

		void gotoxy(int x, int y)
		{
		   COORD coord;
		   coord.X = x;
		   coord.Y = y;
		   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2)
		{
		   for (int Cols = Col1; Cols <= Col2; Cols++)
		   {
			  for (int Fils = Fil1; Fils <= Fil2; Fils++)
			  {
				 gotoxy(Cols,Fils);
				 //Linea Vertical Derecha E Izquierda
				 if ((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
				 {
					cout << (char)186;
				 }
				 //Linea Horizontal Superior E Inferior
				 else if ((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
				 {
					cout << (char)205;
				 }
			  }
		   }

		   //Esquina Superior Izquierda
		   gotoxy(Col1,Fil1);
		   cout << (char)201;
		   //Esquina Inferior Izquierda
		   gotoxy(Col1,Fil2);
		   cout << (char)200;
		   //Esquina Superior Derecha
		   gotoxy(Col2,Fil1);
		   cout << (char)187;
		   //Esquina Inferior Derecha
		   gotoxy(Col2,Fil2);
		   cout << (char)188;

		   //Menú
		   /*gotoxy(Col2/2 - 2,Fil1 + 2);
		   cout << "Universidad De San Carlos De Guatemala";
		   gotoxy(Col2/2 - 4,Fil1 + 2);
		   cout << "Practica 1";
		   gotoxy(Col2/2 - 7,Fil1 + 4);
		   cout << "1.Crear Archivo"; */

		   menu();


		   getchar();
		}

		void MarcoPrincipal(int Col1, int Col2, int Fil1, int Fil2)
		{
		   for (int Cols = Col1; Cols <= Col2; Cols++)
		   {
			  for (int Fils = Fil1; Fils <= Fil2; Fils++)
			  {
				 gotoxy(Cols,Fils);
				 //Linea Vertical Derecha E Izquierda
				 if ((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
				 {
					cout << (char)186;
				 }
				 //Linea Horizontal Superior E Inferior
				 else if ((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
				 {
					cout << (char)205;
				 }
				 else if ((Cols != Col1) && (Fils == Fil2 - 4))
				 {
					cout << (char)205;
				 }

			  }
		   }

		   //Esquina Superior Izquierda
		   gotoxy(Col1,Fil1);
		   cout << (char)201;
		   //Esquina Inferior Izquierda
		   gotoxy(Col1,Fil2);
		   cout << (char)200;
		   //Esquina Superior Derecha
		   gotoxy(Col2,Fil1);
		   cout << (char)187;
		   //Esquina Inferior Derecha
		   gotoxy(Col2,Fil2);
		   cout << (char)188;
		   //T Derecha
		   gotoxy(Col2,Fil2 - 4);
		   cout << (char)185;
		   //T Izquierda
		   gotoxy(Col1,Fil2 - 4);
		   cout << (char)204;

		   //Textos
		   gotoxy(Col1 + 40,Fil2 - 2);
		   cout << "^w (Buscar Y Remplazar)";
		   gotoxy(Col1 + 80,Fil2 - 2);
		   cout << "^c (Reportes)";
		   gotoxy(Col1 + 110,Fil2 - 2);
		   cout << "^s (Guardar)";

		   getchar();
		}

	 //-----------------------------Fullscreen-----------------------------

		void Fullscreen()
		{
		   keybd_event(VK_MENU,
						  0x38,
							 0,
							 0);
		   keybd_event(VK_RETURN,
							0x1c,
							   0,
							   0);
		   keybd_event(VK_RETURN,
							0x1c,
				 KEYEVENTF_KEYUP,
							   0);
		   keybd_event(VK_MENU,
						  0x38,
			   KEYEVENTF_KEYUP,
							 0);
		   return;
		}

	 //---------------------Obtener Resolución Pantalla--------------------

		void Resolucion()
		{
			Ancho = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
			Alto = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
		}

	 //------------------------Posición Cursor-----------------------------



//-------------------------------------Main-------------------------------------
	 int _tmain(int argc, _TCHAR* argv[])
	 {
		Fullscreen();
		Resolucion();
		system("color 0b");
		clrscr();
		int Op = 0;
		MarcoMenu(0,Ancho - 2,0,Alto + 6);
		//MarcoPrincipal(0,Ancho - 2,0,Alto + 6);

		menu();

		do
		{

		   switch(Op)
		   {
			  case 1:
				 clrscr();
				 system("pause");
			  break;

			  case 2:
				 cout<< "Opcion 1" << endl;
				 system("Pause > NULL");
			  break;

			  case 3:
				 cout<< "Opcion 1" << endl;
				 system("Pause > NULL");
			  break;
		   }
           cout<<endl<<endl;
		   system("cls");
		}

		while(Op != 4);
		cout<< "\n";
		cout<< "\n";
		cout<< "Aplicacion Finalizada";
		cout<< "\n";
		cout<< "\n";
		system("pause");

		return 0;
	 }



