#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <fstream>
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

typedef struct no no_hash;
struct no {
	int data;
	int state;/*0 para vacio, 1 para removido y 2 para ocupado*/
};


int matriz[100][100];
int matriz2[100][100];
int vect1[100];
int vect2[100];

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
typedef struct nodo *ABB;

ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->n = x;
	nuevoNodo->anterior = NULL;
	nuevoNodo->siguiente = NULL;

	return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(x);
	}
	else if (x < arbol->n)
		insertar(arbol->anterior, x);
	else if (x > arbol->n)
		insertar(arbol->siguiente, x);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->n << " ";
		preOrden(arbol->anterior);
		preOrden(arbol->siguiente);
	}
}

void inOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		inOrden(arbol->anterior);
		cout << arbol->n << " ";
		inOrden(arbol->siguiente);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->anterior);
		postOrden(arbol->siguiente);
		cout << arbol->n << " ";
	}
}
//busqueda
bool busqueda(nodo *arbol, int n)
{
	if (arbol == NULL)
	{
		return false;
	}
	else if (arbol->n == n)
	{
		return true;
	}
	else if (n < arbol->n)
	{
		return busqueda(arbol->anterior, n);
	}
	else {
		return busqueda(arbol->siguiente, n);
	}
}

void Recorridos()
{
	ABB arbol = NULL;

	int n;
	int x;

	cout << "\n\t\t  ARBOL BINARIO DE BUSQUEDA Y RECORRIDOS  \n\n";

	cout << " Numero de nodos del arbol:  ";
	cin >> n;
	cout << endl;

	for (int i = 0; i<n; i++)
	{
		cout << " Numero del nodo " << i + 1 << ": ";
		cin >> x;
		insertar(arbol, x);
	}

	cout << "\n Recorridos del ABB";

	cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
	cout << "\n\n In orden   :  ";   inOrden(arbol);
	cout << "\n\n Post Orden :  ";   postOrden(arbol);

	cout << endl << endl;

	system("pause");
}
void menu()
{
	//system("cls");
	cout << "\n\t\t  ARBOL BINARIO \n\n";
	cout << "\t 1.  INSERTAR NODO \n";
	cout << "\t 3.  MOSTRAR RECORRIDOS \n";
	cout << "\t 4.  BUSCAR NODO \n";
	cout << "\t 6. SALIR                              \n";

	cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
	//system("cls");   // para limpiar pantalla
	cout << endl;
	cout << "\t 1. EN ORDEN \n";
	cout << "\t 2. PREORDEN \n";
	cout << "\t 3. POSTORDEN \n";
	cout << "\n\t     Opcion :  ";
}

	int funcion(int k, int m, int i)
	{
		return((k + i) % m);
	}
	//crea la tabla hash
	no_hash*Crea_Hash(int m) {
		no_hash*temp;
		int i;
		if ((temp = (no_hash*)malloc(m * sizeof(no_hash))) != NULL)
		{
			for (i = 0; i < m; i++)
				temp[i].state = 0;
			return temp;
		}
		else exit(0);
	}
	//inserta un elemento k en la tabla de T tamaño m
	void Inserta_Hash(no_hash*T, int m, int k)
	{
		int j, i = 0;
		do {
			j = funcion(k, m, i);
			if (T[j].state == 0 || T[j].state == 1)
			{
				T[j].state = k;
				T[j].state = 2;
				cout << "Elemento insertado con exito";
				return;
			}
			else
				i++;
		} while (i < m);
		cout << "\nTabla llena";
	}
	int Busca_Hash(no_hash*T, int m, int k, int i)
	{
		int j;
		if (i < m) {
			j = funcion(k, m, i);
			if (T[j].state == 0)
				return -1;
			else
				if (T[j].state == 1)
					return Busca_Hash(T, m, k, i + 1);
				else
					if (T[j].data == k)
						return j;
					else
						return Busca_Hash(T, m, k, i + 1);
		}
		return -1;
	}
	int Remove_Hash(no_hash *T, int m, int k) {
		int i;
		i = Busca_Hash(T, m, k, 0);
		if (i == -1) {
			return -1;
		}
		else {
			T[i].state = 1;
			return 1;
		}
	}

	void TablaHash() {
		int m, i, k;
		char resp;
		no_hash *T;
		cout << "\nEntre con el tamano de la tabla";
		cin >> m;
		T = Crea_Hash(m);
		while (1) {
			cout << "\nInsertar(i) Buscar (b) Remover (r) Salir (s)\n";
			resp = _getche();
			_getch();
			switch (resp) {
			case 1:
				cout << "\nIngrese el numero a ser insertado en la tabla: ";
				cin >> k;
				Inserta_Hash(T, m, k);
				break;
			case 2:
				cout << "\nIngrese el numero a ser buscado en la tabla: ";
				cin >> k;
				i = Busca_Hash(T, m, k, 0);
				if (i == -1) {

					cout << "\nNumero no encontrado!";
				}
				else {
					cout << "\nNumero encontrado!";
				}
				break;
			case 3:
				cout << "\nIngrese el numero a ser eliminados de la tabla";
				cin >> k;
				i = Remove_Hash(T, m, k);
				if (i == -1) {
					cout << "\nNumero no encontrado";
				}
				else {
					cout << "Numero encontrado";
				}
				break;
			case 4:
				exit(0);
				break;
			}
		}
	}
	void llenarMatrizDistancias(int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					cout << "Ingrese valor de la posicion: (" << i + 1 << "," << j + 1 << "): ";
					cin >> matriz[i][j];
				}
				else {
					matriz[i][j] = NULL;
				}
			}
		}
	}

	void llenarMatrizAdyacencia(int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matriz2[i][j] = j + 1;
			}
		}
	}

	void mostrarMDistancias(int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Valor de la posicion: (" << i + 1 << "," << j + 1 << "): " << matriz[i][j] << endl;
			}
		}
		_getch();
	}

	void mostrarMAdyacencia(int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Valor de la posicion: (" << i + 1 << "," << j + 1 << "): " << matriz2[i][j] << endl;
			}
		}
		_getch();
	}
	void realizarCalculos(int n) {

		int i, j, suma;
		int bucle;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				vect1[i] = matriz[i][j];
				vect2[i] = matriz[j][i];
			}

			for (int t = 1; t <= n; t++)
				for (j = 1; j <= n; j++) {
					if (vect2[t] == 999 || vect1[j] == 999) suma = 999;
					else suma = vect2[t] + vect1[j];
					if (suma < matriz[i][j]) {
						matriz[t][j] = suma;
						//matriz2[t][j] = bucle;
					}
				}
		}
	}

	void Floyd() {
		system("cls");
		int n, op;
		do {
			system("cls");
			cout << "1.Ingresar tamaño de la matriz\n";
			cout << "2.Ingresar valores\n";
			cout << "3.Mostrar Matriz de Distancias\n";
			cout << "4.Mostrar Matriz de Adyacencia\n";
			cout << "5.Salir\n";
			cout << "Ingrese opcion: ";
			cin >> op;
			switch (op) {
			case 1: system("cls");
				cout << "Ingrese tamaño de la matriz cuadrada: ";
				cin >> n;
				break;
			case 2: system("cls");
				llenarMatrizDistancias(n);
				llenarMatrizAdyacencia(n);
				break;
			case 3: system("cls");
				mostrarMDistancias(n);
				break;
			case 4: system("cls");
				mostrarMAdyacencia(n);
				break;
			}
		} while (op != 5);
		_getch();
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
		cout << "\t\t4. Programa Recorridos arboles binario \n";
		cout << "\t\t5. Programa tabla de hash \n";
		cout << "\t\t6. Programa Floyd Warshall \n";
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
		case 4:	
			Recorridos();
			break;
		case 5:
			TablaHash();
			break;
		case 6:
			Floyd();
			break;
		}
		_getch();
	} while (opci != 11);

}