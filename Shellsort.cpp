#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo

Nodo {
	int dato;
	Nodo * siguiente;
	Nodo * anterior;
};

void Insertar (int dato);
void visualizarLista ();
void shellSort (int N);
void cambiarAtras (Nodo * piv, int inter);
Nodo * inicio = NULL;
Nodo * final = NULL;

int main () {
	int N, dato, i;
	printf ("No. de datos:");
	scanf ("% i", & N);
	para (i = 0; i <N; i ++) {
		scanf ("% i", & dato);
		Insertar (dato);
	}
	shellSort (N);
	printf ("Lista Ordenada: \ n");
	visualizarLista ();
}

void shellSort (int N) {
	int inter = N / 2;
	Nodo * piv, * aux;
	while (inter> 0) {
		piv = aux = inicio;
		int cont = 0;
	    while (cont! = inter) {
		aux = aux-> siguiente;
		cont ++;
	    }
		while (aux! = NULL) {
	    if (piv-> dato> aux-> dato) {
			   int temp = piv-> dato;
			   piv-> dato = aux-> dato;
			   aux-> dato = temp;
			   cambiarAtras (piv, inter);
		}
		aux = aux-> siguiente;
		piv = piv-> siguiente;
        }
        inter = inter / 2;
	}
}

void cambiarAtras (Nodo * piv, int inter) {
	int cont = 0;
	Nodo * aux = piv;
	while (cont! = inter && aux! = NULL) {
		aux = aux-> anterior;
		cont ++;
	}
	si (aux == NULL)
	regreso;
	if (piv-> dato <aux-> dato) {
		int temp = piv-> dato;
		piv-> dato = aux-> dato;
		aux-> dato = temp;
		cambiarAtras (aux, inter);	   
	}
	{
		regreso;
	}
}

void Insertar (int dato) {
	Nodo * aux = inicio;
	Nodo * nuevo = (Nodo *) malloc (tama�o de (int));
	nuevo-> dato = dato;
	nuevo-> siguiente = NULL;
	nuevo-> anterior = NULL;
	if (inicio == NULL) {
		inicio = nuevo;
		final = nuevo;
	}m�s{
		final-> siguiente = nuevo;
		nuevo-> anterior = final;
		final = nuevo;
	}
}

void visualizarLista () {
	Nodo * aux = inicio;
	while (aux! = NULL) {
		printf ("% i", aux-> dato);
		aux = aux-> siguiente;
	}
}
