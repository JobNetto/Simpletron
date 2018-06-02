#include <iostream>
#include "simpletron.h"
using namespace std;

int main(int argc, char **argv)
{
	Simpletron *maquina = new Simpletron();

	if (argc > 1)
		maquina->Load(argv[1]);
	
	try
	{
		maquina->Run();
	
	}catch(exception)
	{
		cout << "Ocorreu um erro inesperado! Reinicei o processo." << endl;
	}
	

			
			
		
	return 0;
}