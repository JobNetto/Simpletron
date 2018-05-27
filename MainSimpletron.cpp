#include <iostream>
#include "simpletron.h"
using namespace std;

int main(int argc, char **argv)
{
	Simpletron *maquina = new Simpletron();

	if (argc > 1)
		maquina->Load(argv[1]);

	maquina->Run();

	return 0;
}