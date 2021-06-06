#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

bool buscar(ABB arbol, int dato)
{
     int r=0;   // 0 indica que no lo encontre

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = buscar(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = buscar(arbol->der, dato);
     else
     	r = 1;   // son iguales, lo encontre

     return r;
}


int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo
	int op;
	int num;
	
    cout << "\n\t\t ARBOL BINARIO DE BUSQUEDA \n\n";

	do{
		
		cout<<"1.- Insertar un nodo en el arbol"<<endl;
		cout<<"2.- Mostrar el arbol completo"<<endl;
		cout<<"3.- Buscar un nodo especifico"<<endl;
		cout<<"4.- Recorrer el arbol, pre-orden, in-orden, pos-orden"<<endl;
		cout<<"5.- Borrar un nodo del arbol"<<endl;
		cout<<"6.- Finaliza"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		
		switch(op){
			case 1: cout << " Captura el numero de nodos del arbol:  ";
    				cin >> n;
    				cout << endl;

    				for(int i=0; i<n; i++)
    				{
        				cout << " Numero del nodo " << i+1 << ": ";
        				cin >> x;
        				insertar( arbol, x);
    				}
    				break;
    		
			case 2: cout << "\n Mostrando ABB \n\n";
    				verArbol( arbol, 0);
    				break;
    		
    		case 3: cout<<"Captura el nodo a buscar: ";
    				cin>>num;
    				if(buscar(arbol, num)){
						cout<<"Nodo encontrado"<<endl;
						getch();
					}else{
						cout<<"Nodo no encontrado"<<endl;
						getch();
					}
			
			case 4: cout << "\n Recorridos del ABB";
					
					cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
				    cout << "\n\n In orden   :  ";   enOrden(arbol);
				    cout << "\n\n Pos Orden :  ";   postOrden(arbol);
			
			case 5: cout<<"Introduzca el nodo a eliminar";
					//Funcion Elimina Nodo
					break;
			
			case 6: cout<<"Finaliza el programa";
					break;
    		
		}
		
	}while(op!=6);

    cout << endl << endl;

    system("pause");
    return 0;
}
