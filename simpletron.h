#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <exception>

using std::exception;
using namespace std;

class Simpletron
{
private:

	int counter;
	int accumulador;
	int instructionRegister;
	int operationCode;
	int operand;
	int *memory;

	void Decodifica();
	
	void SelecionarOperacao();

	void ImprimirMemoria();

	void ORead();
	void OWrite();
	void OLoad();
	void OStore();
	void OAdd();
	void OSub();
	void ODiv();
	void OMul();
	void OGoto();
	void OGotoIfN();
	void OGotoIfZ();
	void OHalt();
	void OInc();
	void ODec();
public:
	Simpletron();	
	void Run();
	void Load(const char *);
	
};

Simpletron::Simpletron()
{
	memory = new int[100];
	for (int i = 0; i < 100; i++) 
	{
		memory[i] = 0;
	}
	counter=0;
	accumulador=0;
	instructionRegister=0;
	operand=0;
	operationCode=0;

}

void Simpletron::Decodifica()
{
	operand=instructionRegister%100;
	operationCode=instructionRegister/100;
}

void Simpletron::SelecionarOperacao( )
{
	switch (operationCode)
	{
		case 10:ORead(); break;
		case 11:OWrite(); break;
		case 20:OLoad(); break;
		case 21:OStore(); break;
		case 30:OAdd(); break;
		case 31:OSub(); break;
		case 32:ODiv(); break;
		case 33:OMul(); break;
		case 40:OGoto(); break;
		case 41:OGotoIfN(); break;
		case 42:OGotoIfZ(); break;
		case 43:OHalt(); break;
		case 50:OInc();break;
		case 51:ODec();break;
		default:break;
	}
}

void Simpletron::ImprimirMemoria()
{
	
	cout << "REGISTRADOR:"<< endl;
	cout << "Acumulador:                   "<< showpos << setw(5) << setfill('0') << internal  << accumulador << endl;
	cout << "Contador de instrucao:        "<< noshowpos << setw(2) << setfill('0') << internal <<  counter << endl;
	cout << "Registrador de instrucao:     "<< showpos << setw(5) << setfill('0') << internal << instructionRegister << endl;
	cout << "Codigo operacao:              " << noshowpos<< setw(2) << setfill('0') << internal << operationCode << endl;
	cout << "Parametro:                    " << noshowpos<< setw(2) << setfill('0') << internal << operand << endl;
	cout << "" << endl;
	cout << "MEMORIA:" << endl;
	cout << "   0     1     2     3     4     5     6     7     8     9" << endl;
	
	cout << "00 ";
	for (int i = 0; i<10; i++) {
		cout << showpos << setw(5) << setfill('0') << internal << memory[i] << " ";
	}
	cout << endl;
	for (int j = 10; j<100; j = j + 10) {
		cout << noshowpos << j << " ";
		for (int i = 0; i<10; i++) {
			cout << showpos << setw(5) << setfill('0') << internal << memory[j + i] << " ";
		}
		cout << endl;
	}
}

void Simpletron::ORead()
{
	cin >> memory[operand];
}

void Simpletron::OWrite()
{
		cout << memory[operand];
}

void Simpletron::OLoad()
{
	accumulador=(memory[operand]);
}

void Simpletron::OStore()
{
	memory[operand] = accumulador;
}

void Simpletron::OAdd()
{
	accumulador = accumulador + memory[operand];
}

void Simpletron::OSub()
{
	accumulador = accumulador - memory[operand];
}

void Simpletron::ODiv()
{
	accumulador = memory[operand]/accumulador;
}

void Simpletron::OMul()
{
	accumulador = memory[operand]*accumulador;
}

void Simpletron::OGoto()
{
	counter = operand;
}

void Simpletron::OGotoIfN()
{
	if(accumulador<0)
	{
		counter = operand;
	}
}

void Simpletron::OGotoIfZ()
{
	if(accumulador==0)
	{
		counter = operand;
	}
}
void Simpletron::OHalt()
{
	counter = 100;
}

void Simpletron::OInc()
{
	accumulador+=1;
}

void Simpletron::ODec()
{
	accumulador-=1;
}

void Simpletron::Run()
{

	
	if(memory[0] == 0)
	{
		int op;
		int j = 0;	
		do
		{
		cout << "?"; cin >> op;
		if(op!=-99999)
		memory[j] = op;
				j++;

		} while (op > 0);
	}
	
	
	while(counter<100)
	{
		instructionRegister = memory[counter];
		counter++;
		Decodifica();
		
			SelecionarOperacao();
		
		
	}
	
	ImprimirMemoria();
	system("read -p \"Pressione enter para sair\" saindo");

}

void Simpletron::Load(const char *s)
{
	FILE *arq = fopen(s, "r");
	int i = 0;
	while (!feof(arq))
	{
		fscanf(arq,"%d",&memory[i]);
		i++; 
	}
		
	fclose(arq);
}