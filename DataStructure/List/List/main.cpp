#include<iostream>
typedef struct Node
{
	int data;
	struct Node* sig;
}TesList;

struct Node* head;
using namespace std;
//Crear lista Vacia 
TesList *CrearListaVacia(TesList *list)
{
	list = NULL;
	return list;
}

void insertarInicio(TesList *&lista, int valor)
{
	TesList *q;
	q = new TesList();
	q->data = valor;
	q->sig = lista;
	lista = q;
	
}
//una solucion iterativa
//Iterativa por while
void insertarFinal1(TesList *&lista, int valor)
{
	TesList *t, *q = new(struct Node);

	if (lista == NULL)
	{
		lista = q;
	}
	else
	{
		t = lista;
		while (t->sig!=NULL)
		{
			t = t->sig;
		}
		t->sig = q;
	}
}

//mi solucion
//Recursiva
void insertarFinal(TesList *&lista, int valor)
{
	if (lista->sig != NULL)
	{
		insertarFinal(lista->sig, valor);
	}
	TesList* q;
	q = new TesList();
	q->data = valor;
	lista->sig = q;
	lista->data = q->data;
	
	
}

int nsertarAntesDespues()
{

	int _op, band;
	cout << endl;
	cout << "\t 1. Antes de la posicion		" << endl;
	cout << "\t 2. Despues de la posicion	" << endl;


	cout << "\n\t Opcion : "; cin >> _op;

	if (_op == 1)
		band = -1;
	else
		band = 0;
	
	return band;

}

void insertarElemento(TesList *&lista, int valor, int pos)
{
	if (lista == NULL)
	{
		return;
	}
	TesList *q, *t;
	int i;
	q = new(struct Node);
	q->data = valor;
	if (pos == 1)
	{
		q->sig = lista;
		lista = q;
	}
	else
	{
		int x = nsertarAntesDespues();
		t = lista;

		for (i = 1; t != NULL; i++)
		{
			if (i == pos + x)
			{
				q->sig = t->sig;
				t->sig = q;
				return;
			}
			t = t->sig;
		}
	}
	cout << " Error...Posicion no encontrada...!" << endl;

}


void InicializarLista()
{
	Node* A;
	A = NULL;
	Node* temp = new Node();
	Node* temp1 = A;
	while (temp1->sig!=NULL)
	{
		temp1 = temp->sig;
	}
	temp1->sig = temp;
}


void Insert(int x);
void Print();

int main()
{
	head = NULL;
	printf("How many numbers? \n");
	int n, i, x;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		printf("Enter the number \n");
		cin >> x;
		Insert(x);
		Print();
	}
	
}
//inserta nodo al principio
//freeCodeCamp.org
void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->sig = NULL;
	if (head != NULL) temp->sig = head;
	head = temp;
}

void Print()
{
	struct Node* temp = head;
	printf("List is:");
	while (temp != NULL)
	{
		printf(" %d ", temp->data);
		temp = temp->sig;
	}
	cout<<"\n";
}

/*
Node* CrearListaVacia()
{
	Node* A;
	A = NULL;
	return A;

}
*/
/*
void InsertarEnListainicio(Node *&a, int dato)
{
	if (a == NULL)
	{
		a = CrearListaVacia();
	}

	Node *temp = new Node();
	temp->data = dato;
	Node *aux 
	

	temp = new Node();
}
*/
