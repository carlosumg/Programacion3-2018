#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <cstdio>
using namespace std;

struct nodo {
	int n;
	nodo *siguiente;
	nodo *anterior;
};
struct cola
{
	char nombre[20];
	struct cola *sig;
}*cabeza, *auxiliar, *final;

struct pila {
	int numero;
	struct pila *sig;
}*ini = NULL, *fin = NULL;

void insertarCola();
void extraerCola();
void visualizarCola();
void InsertarPila();
void ExtraerPila();
void VisualizarPila();


void agregarH(nodo *head) {
	int num;
	cout << "Ingresar numero: \n";
	cin >> num;

	head->n = num;
	head->siguiente = NULL;
	head->anterior = NULL;
}

void agregarSiguiente(nodo *head) {
	int num;
	cout << "Ingresar numero: \n";
	cin >> num;

	nodo *lista = head;
	nodo *nuevo = new nodo();

	nuevo->n = num;
	nuevo->siguiente = NULL;
	while (lista) {
		if (lista->siguiente == NULL) {
			lista->siguiente = nuevo;
			break;
		}
		lista = lista->siguiente;
	}
}

nodo *agregarAnterior(nodo *head) {
	int num;
	cout << "Ingresar numero: \n";
	cin >> num;

	nodo *nuevo = new nodo();

	nuevo->n = num;
	nuevo->anterior = NULL;
	nuevo->siguiente = head;
	head->anterior = nuevo;
	head = nuevo;
	return head;
}

void agregarPosicion(nodo *head, int tamañoLista) {
	int posicion, i = 1;
	cout << "Ingresar posicion donde desea insertar el numero: ";
	cin >> posicion;
	if (posicion == 1) {
		system("cls");
		agregarH(head);
	}
	if (posicion == tamañoLista) {
		system("cls");
		agregarSiguiente(head);
	}
	else {
		if ((posicion > 1) && (posicion < tamañoLista)) {
			system("cls");
			int num;
			cout << "Ingresar numero: \n";
			cin >> num;
			nodo *lista = head;
			nodo *nuevo = new nodo;
			nuevo->n = num;
			while (posicion != 1) {

				lista = lista->siguiente;
				i++;
			}
			lista->anterior->siguiente = nuevo;
			nuevo->siguiente = lista;
			nuevo->anterior = lista->anterior;
			lista->anterior = nuevo;
		}
		else {
			cout << "posicion invalida!!";
			_getch();
		}
	}
}

nodo *eliminar(nodo *head) {
	int num;
	nodo *h = head;
	nodo *lista = head;
	cout << "Ingrese numero a eliminar: ";
	cin >> num;

	if (lista->n == num) {
		head = head->siguiente;
		free(lista);
	}
	else {
		while ((lista->siguiente)->n != num) {
			lista = lista->siguiente;
		}
		nodo *aux = lista->siguiente;
		lista->siguiente = (lista->siguiente)->siguiente;
		free(aux);
	}
	return head;
}

void mostrar(nodo *head) {
	nodo *lista = head;
	if (lista != NULL) {
		while (lista) {
			cout << lista->n << endl;
			lista = lista->siguiente;
		}
	}
	else {
		cout << "Lista vacia!";
		_getch();
	}
	_getch();
}



void MenuLista() {
	int opc = 0, cont = 0, aceptar = 1;
	nodo *head = new nodo();
	system("cls");
	do {
		system("cls");
		cout << "\t\tMENU LISTAS\n\n";
		cout << "\t1. Agregar atras\n";
		cout << "\t2. Agregar adelante\n";
		cout << "\t3. Agregar en una posicion\n";
		cout << "\t4. Mostrar Lista\n";
		cout << "\t5. Eliminar\n";
		cout << "\t6. Salir\n";
		cin >> opc;
		switch (opc) {
		case 1:
			system("cls");
			if (cont == 0) {
				agregarH(head);
				cont++;
			}
			else {
				agregarSiguiente(head);
				cont++;
			}
			break;
		case 2:
			system("cls");
			if (cont == 0) {
				agregarH(head);
				cont++;
			}
			else {
				head = agregarAnterior(head);
				cont++;
			}
			break;
		case 3:
			system("cls");
			agregarPosicion(head, cont);
			cont++;
			break;
		case 4:
			system("cls");
			mostrar(head);
			break;
		case 5:
			system("cls");
			head = eliminar(head);
			break;
		}
	} while (opc != 6);
}
void MenuCola() {
	int opc = 0;

	do {
		system("color 3f");
		system("cls");
		cout << " \n Programa para gestionar turnos para atencion";
		cout << " \n\n\n1. asignar turno";
		cout << " \n2. visualizar turnos en espera";
		cout << " \n3. atender turno";
		cout << " \n4. Salir";
		cout << " \nDigite la opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			insertarCola();
			break;
		case 2:
			visualizarCola();
			break;
		case 3:
			extraerCola();
			break;
		
		}
		_getch();
	} while (opc != 4);
	_getch();
}

void insertarCola() {
	system("COLOR 4F");
	auxiliar = new cola;
	system("cls");
	cout << "Asignacion de turnos ";
	cout << "Digite el nombre:";
	cin >> (auxiliar->nombre);
	auxiliar->sig = NULL;
	if (final == NULL) {
		final = cabeza = auxiliar;
	}
	else {
		final->sig = auxiliar;
		final = auxiliar;
	}
}

void visualizarCola() {
	system("COLOR 6F");
	if (cabeza == NULL) {
		system("cls");
		cout << "no hay personas en la lista";
	}
	else {
		system("cls");
		cout << "Listado de usuarios en espera: \n\n\n";
		auxiliar = cabeza;
		while (auxiliar != NULL) {
			cout << "Nombre: " << auxiliar->nombre << endl;
			auxiliar = auxiliar->sig;
		}
	}
	_getch();
}

void extraerCola() {
	if (final == NULL) {
		system("cls");
		cout << "no hay personas en la lista";
		_getch();
	}
	else {
		cout << "La persona que se atendera es: " << cabeza->nombre;
		auxiliar = cabeza;
		cabeza = cabeza->sig;
		delete auxiliar;
		_getch();
	}
}

void InsertarPila() {
	ini = new pila;
	system("cls");
	cout << "Digite el tipo de tipo entero: ";
	cin >> ini->numero;
	if (fin == NULL) {
		fin = ini;
		ini->sig = NULL;
	}
	else {
		ini->sig = fin;
		fin = ini;
	}
}

void VisualizarPila() {
	if (final == NULL) {
		system("cls");
		cout << "no hay elemenots a listar";
	}
	else {
		system("cls");
		cout << "Elementos insertados en la pila: \n\n\n";
		ini = fin;
		while (ini != NULL) {
			cout << "Numero: " << ini->numero << endl;
			ini = ini->sig;
		}
	}
	_getch();
}

void ExtraerPila() {
	if (final == NULL) {
		system("cls");
		cout << "No hay elementos a eliminar";
		_getch();
	}
	else {
		ini = fin;
		system("cls");
		cout << "funcion eliminar elementos de la pila \n\n\n";
		cout << "El dato a eliminar es: " << ini->numero;
		_getch();
		final = final->sig;
		delete ini;
	}
}
void MenuPila() {
	int opc = 0;

	do {
		system("color 9f");
		system("cls");
		cout << " \n MANEJO DE UNA ESTRUCTURA TIPO PILA";
		cout << " \n\n\n1. Insertar";
		cout << " \n2. Visualizar";
		cout << " \n3. Extraer";
		cout << " \n4. Salir";
		cout << " \nDigite la opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			InsertarPila();
			break;
		case 2:
			VisualizarPila();
			break;
		case 3:
			ExtraerPila();
			break;

		}
		_getch();
	} while (opc != 4);
}
int main() {
	int opci = 0;
	do {
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\t\t\tMENU PRINCIPAL\n\n";
		cout << "\t\t1. Programa LISTA SIMPLE\n";
		cout << "\t\t2. Programa COLA \n";
		cout << "\t\t3. Programa Pila\n";
		cout << "\t\t4.\n";
		cout << "\t\t5.\n";
		cout << "\t\t6.\n";
		cout << "\t\t7.\n";
		cout << "\t\t8.\n";
		cout << "\t\t9.\n";
		cout << "\t\t10.\n";
		cout << "\t\t11. Salir\n\n\n";
		cout << "\tIngrese la opcion que desea usar: ";
		cin >> opci;
		//cout << "\n\n\n\n\tProgramacion 3: Norman-Carlos-Vincenzo-Javier" << endl;
		switch (opci) {
		case 1:
			MenuLista();
			break;
		case 2:
			MenuCola();
			break;
		case 3:
			MenuPila();
			break;
		}
		_getch();
	} while (opci != 11);
	
}