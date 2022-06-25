// Tecnologico de Costa Rica - Estructuras de Datos Gr02 - Laboratorio Huffman -  Jose Pablo Aguero Mora 2021126372 - Katerine Guzman Flores 2019390523 - Prof: Victor Garro Abarca


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

bool BitEncendido(int Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	if ((Simbolo & Mascara) == 0) {
		return false;  // Da 0 lo que significa que la posicion cual estaba en 0
	}
	else {
		return true;	// Da <>0 lo que significa que la posicion cual estaba en 1
	}
}

bool BitApagado(int Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	if ((Simbolo & Mascara) == 0)
		return true; // Da 0 lo que significa que la posicion cual estaba en 0
	else return false;	// Da <>0 lo que significa que la posicion cual estaba en 1

}

void EncenderBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Simbolo = Simbolo | Mascara;
}


void ApagarBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Mascara = ~Mascara;
	Simbolo = Simbolo & Mascara;
}

void PinteBits(int Simbolo)
{
	int Uno = 1;
	int Cero = 0;
	for (int i = 7; i >= 0; --i)
	{
		if (BitEncendido(Simbolo, i))
			printf("%d ", Uno);
		else
			printf("%d ", Cero);
	}

	printf("\n");
}

void InvertirBit(int& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Simbolo = Simbolo ^ Mascara;
}

void Invertir_x_valor(int& Simbolo) // Ejercicio 2
{
	for (int i = 7; i >= 0; --i)
	{
		int Mascara = 1;

		Mascara = Mascara << i;
		Mascara = ~Mascara;
		Simbolo = Simbolo ^ Mascara;
	}
}

int Byte_to_integer(int& Simbolo) // Ejercicio 3
{
	int total = 0;

	for (int i = 0; i <= 7; ++i)
	{
		if (BitEncendido(Simbolo, i))
			total += (pow(2, i) * 1);
		else
			total += (pow(2, i) * 0);
	}
	return total;
}

bool BitsIguales(int& Simbolo, int posA, int posB) // true si son iguales / Parte del ejercicio 1
{
	if (BitEncendido(Simbolo, posA) == BitEncendido(Simbolo, posB)) {
		return true;
	}
	else {
		return false;
	}
}

void Invertir_x_posicion(int& Simbolo) // Ejercicio 1
{
	int contador = 0;

	for (int i = 7; i >= 4; --i)
	{
		if (BitsIguales(Simbolo, i, contador) == false) {
			InvertirBit(Simbolo, i);
			InvertirBit(Simbolo, contador);
		}
		contador += 1;
	}
}

void main(int argc, char* argv[])
{
	int Prueba = 0;
	int j;

	for (j = 0; j <= 7; j++)
	{
		printf("%s \n", "------------------");
		EncenderBit(Prueba, j);       // Enciende el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);
		ApagarBit(Prueba, j);		// Apaga el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);//Queda en 0 porque apago el Bit encendido.
	}
	for (j = 0; j <= 255; j++)
	{
		printf("Numero %d : ", j);
		PinteBits(j);
	}

	// Ejercicios árboles binarios de Huffman

	printf("\n %s \n", "--------- Ejercicio 2.2.a ---------");
	int Prueba2 = 201;
	printf("Sin invertir posiciones: %d = ", Prueba2); PinteBits(Prueba2);
	Invertir_x_posicion(Prueba2);
	printf("Posiciones invertidas: %d = ", Prueba2); PinteBits(Prueba2);

	printf("\n %s \n", "--------- Ejercicio 2.2.b ---------");
	int Prueba3 = 16;
	printf("Sin invertir valores: %d = ", Prueba3); PinteBits(Prueba3);
	Invertir_x_valor(Prueba3);
	printf("Valores invertidos: %d = ", Prueba3); PinteBits(Prueba3);

	printf("\n %s \n", "--------- Ejercicio 2.2.c ---------");
	int Prueba4 = 124;
	int resultado = Byte_to_integer(Prueba4);
	printf("Decimal: %i = ", resultado); printf("Binario: "); PinteBits(Prueba4);
}

//void ApagarBit(int &Simbolo, int cual)
//{
//	int Mascara = 1;
//   if (BitEncendido(Simbolo,cual))
//	{
//		Mascara = Mascara << cual;
//		Simbolo = Simbolo ^ Mascara;
//	}
//}

