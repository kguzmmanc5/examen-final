#include <iostream>
#include <stdlib.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Pila{
		int tope;
	int capacidad;
	int* arreglo;
};

//CREAMOS LA PILA, ASIGNAMOS TAMAÑO, ASI COMO CREAR EL ARREGLO DONDE SE ALMACENARAN LAS CALIFICACIONES
struct Pila* crearPila(int capacidad){
	
	struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila)); //Reserva del bloque de memoria
	pila->capacidad = capacidad; //Asignamos el tamaño de la pila
	pila->tope = -1; //Inicializamos el valor en el tope de la pila
	pila->arreglo = (int*)malloc(pila->capacidad*sizeof(int)); //Creamos un arreglo que almacenara los datos
	return pila;
}

//FUNCION QUE UTILIZAMOS PARA REVISAR SI LA PILA ESTA LLENA
int estaLlena(struct Pila* pila){
	return pila->tope == pila->capacidad-1;
}
	
//FUNCION QUE UTILIZAMOS PARA REVISAR SI LA PILA ESTA VACIA
int estaVacia (struct Pila* pila){
	return pila->tope == -1;
	}

//OPERACION DE AGREGAR UN ELEMENTO A LA PILA
void PUSH(struct Pila* pila, int elemento){
	if (estaLlena(pila))
		return;
	pila->arreglo[++pila->tope] = elemento;
}

//FUNCION QUE UTILIZAMOS PARA RETIRAR UN ELEMENTO DE LA PILA
int POP(struct Pila* pila){
	if (estaVacia(pila))
		return INT_MIN;
	return pila->arreglo[pila->tope--];
}

//MOSTRAMOS EL NUMERO DE ELEMENTOS DE LA PILA
int numElementos(struct Pila* pila){
	return pila->tope+1;
}

//FUNCION PARA MOSTRAR LA INFORMACION DE LA PILA
void imprimir(struct Pila* pila){
	for (int i = 0; i <= pila->tope; i++)
		printf("\t%i\n", pila->arreglo[i]);	
}

//FUNCION PRINCIPAL
int main(int argc, char** argv) {
	
	struct Pila* pila;
	
	int op=0;
	int tam;
	int calif;
	
	
	do{
		system("cls");
		cout<<"\n\n\t1.- Establecer tamanio del arreglo"<<endl;
		cout<<"\t2.- Funcion PUSH"<<endl;
		cout<<"\t3.- Funcion POP"<<endl;
		cout<<"\t4.- Mostrar pila"<<endl;
		cout<<"\t5.- Finalizar";
		cout<<"\n\n\tOpcion: ";
		cin>>op;
		
		switch(op){
			case 1: cout<<"\n\tCaptura el tamanio del arreglo: ";
					cin>>tam;
					pila=crearPila(tam); //Creamos la pila con 10 espacios
				break;
				
			case 2:	cout<<"\n\tCaptura la calificacion a ingresar: ";
					cin>>calif;
					PUSH(pila, calif);
					break;
			
			case 3:	cout<<"\n\tRetiramos un elemento de la pila";
					POP(pila);
					cout<<"\n\tSe ha retirado un elemento de la pila";
					break;
			
			case 4:	cout<<"\n\tImprimimos los elementos de la pila\n";
					imprimir(pila);
					system("pause");
					break;
			
			case 5:	cout<<"\n\tTermina la ejecucion del programa:";
					break;
			
			default:	cout<<"\n\tOpcion no valida";
					break;

		}
		
	}while(op!=5);
	
	
//	PUSH(pila, 100);
//	PUSH(pila, 70);
//	PUSH(pila, 80);
//	PUSH(pila, 60);
//	PUSH(pila, 100);
//	PUSH(pila, 100);
//	PUSH(pila, 80);
//	PUSH(pila, 90);
//	PUSH(pila, 80);
//	PUSH(pila, 70);
//		
//	POP(pila);
//	POP(pila);
//	
//	
//	
//	imprimir(pila);
//	
//	printf("La pila tiene %i elementos\n",numElementos(pila));
	
	return 0;
}
