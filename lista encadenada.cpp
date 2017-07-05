#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
struct emp 
	{
    int cod;
	char nom[20];
    char tel[12];
    char dir[20];
    char gen[2];
    char estciv[2];
    char depto[2];
    char pue[20];
    int base;
    int extras;
    int iggs;
    int desc;
	int liq;
	int act;
	
	emp *siguiente;
    };
 
struct emp *primero, *ultimo;
 
int ext, x, eli, n, n1; 
 
void menu() 
{
	system ("cls");
    printf("\nMenu\n\n");
    printf("Ingrese el numero de la opcion que desea\n");
    printf("1. Ingresar Empleado\n");
    printf("2. Borrar Registro\n");
    printf("3. Buscar Registro\n");
    printf("4. Mostrar Empleados\n");
    printf("5. Salir\n\n");
    fflush(stdin);

}
 

int ingresar() 
{
	struct emp *nuevo;

	nuevo=(struct emp *) malloc(sizeof (struct emp));
	if (nuevo==NULL) 
	{
		printf( "No hay memoria disponible!\n");
		system ("pause");
	}
	system("cls");		
	printf("\nNuevo elemento\n\n");
    
	x++;  
	nuevo->cod=x;
	
	printf("\nNombre: "); 
	fflush(stdin);
	gets(nuevo->nom);
	system("cls");
	printf("\nTelefono: ");
	fflush(stdin);
	gets(nuevo->tel);
	system("cls");
	printf("\nDireccion: ");
	fflush(stdin);
	gets(nuevo->dir);
	system("cls");
	printf("\nIngrese el numero que corresponde al genero del empleado\n\n1. Masculino\n2. Femenino\n");
	fflush(stdin);
	gets(nuevo->gen);
	system("cls");
	printf("\nIngrese el numero que corresponde al estado civil del empleado\n\n1. Soltero\n2. Casado\n3. Divorciado\n4. Viudo\n");
	fflush(stdin);
	cin>>nuevo->estciv;
	system("cls");
	printf("\nIngrese el numero que corresponde al departamento del empleado\n\n1. Administracion\n2. Contabilidad\n3. Informatica\n4. Compras\n5. Ventas\n6. Recursos Humanos\n7. Operaciones\n8. Seguridad\n9. Servicio al cliente\n10. Marketing\n");
	fflush(stdin);
	cin>>nuevo->depto;
	system("cls");
	printf("\nPuesto: ");
	fflush(stdin);
	gets(nuevo->pue);
	system("cls");
	printf("\nSueldo Base: ");
	fflush(stdin);
	cin>>nuevo->base;
	system("cls");
	printf("\nHoras Extras: ");
	fflush(stdin);
	cin>>ext;
	system("cls");
	printf("\nDescuentos (Iggs se calcula automaticamente): ");
	fflush(stdin);
	cin>>nuevo->desc;
	
	nuevo->extras=(((nuevo->base/30)/8)*ext);
	nuevo->iggs=((nuevo->base+nuevo->extras)*0.0483);
	nuevo->liq=(nuevo->base+nuevo->extras-nuevo->desc-nuevo->iggs);
	
	nuevo->siguiente = NULL;
 
	if (primero==NULL) 
	{
    	printf( "Primer elemento\n");
    	primero = nuevo;
    	ultimo = nuevo;
	}
	else 
	{
	ultimo->siguiente = nuevo;
	ultimo = nuevo;
	}
}
 
int mostrar(struct emp *primero) 
{
    struct emp *auxiliar;
    int i;
 
    i=0;
    auxiliar = primero;
    system("cls");
    printf("\nLista de Empleados:\n");
	printf("\nDepartamentos:\n\n1. Administracion\n2. Contabilidad\n3. Informatica\n4. Compras\n5. Ventas\n6. Recursos Humanos\n7. Operaciones\n8. Seguridad\n9. Servicio al cliente\n10. Marketing\n");    
	printf("\nEstado civil\n\n1. Soltero\n2. Casado\n3. Divorciado\n4. Viudo\n\n");
	printf("\nGenero\n\n1. Masculino\n2. Femenino\n\n");
	
    while (auxiliar!=NULL)
	{
			cout<<"Codigo:    "<<auxiliar->cod<<endl;
			printf("Nombre:    %s\nTelefono:  %s\nDireccion: %s\nGenero:    %s\nEstado C.: %s\nDepto.:    %s\nPuesto:    %s\n",
			auxiliar->nom,auxiliar->tel,auxiliar->dir,auxiliar->gen,auxiliar->estciv,auxiliar->depto,auxiliar->pue);
			cout<<"Sueldo:    "<<auxiliar->liq<<endl;
			printf("----------------------------------------\n");
		
		//------------------------------------

		int bill_200=0,cta200=0; 
		int bill_100=0,cta100=0; 
    	int bill_50=0,cta50=0; 
    	int bill_20=0,cta20=0; 
    	int bill_10=0,cta10=0; 
    	int bill_5=0,cta5=0; 
    	int bill_1=0,cta1=0;
    	int dinero=0; 

			dinero=auxiliar->liq; 

    		for(bill_200=200;bill_200<=dinero;){ 
        		dinero=dinero-bill_200; 
        		cta200++; 
    		} 
		    for(bill_100=100;bill_100<=dinero;){ 
		        dinero=dinero-bill_100; 
		        cta100++; 
		    } 
		    for(bill_50=50;bill_50<=dinero;){ 
		        dinero=dinero-bill_50; 
		        cta50++; 
		    } 
		    for(bill_20=20;bill_20<=dinero;){ 
		        dinero=dinero-bill_20; 
		        cta20++; 
		    } 
		    for(bill_10=10;bill_10<=dinero;){ 
		        dinero=dinero-bill_10; 
		        cta10++; 
		    } 
		    for(bill_5=5;bill_5<=dinero;){ 
		        dinero=dinero-bill_5; 
		        cta5++; 
		    }
		     for(bill_1=1;bill_1<=dinero;){ 
		        dinero=dinero-bill_1; 
		        cta1++;
		    }
		
		    if(dinero==0){ 
				
				cout<<"\nRESUMEN DE EFECTIVO "<<endl;
		        if(cta200!=0)cout<<cta200<<" Billete/s de 200 Quetzales.\n"; 
		        if(cta100!=0)cout<<cta100<<" Billete/s de 100 Quetzales.\n"; 
		        if(cta50!=0)cout<<cta50<<" Billete/s de 50 Quetzales.\n"; 
		        if(cta20!=0)cout<<cta20<<" Billete/s de 20 Quetzales.\n"; 
		        if(cta10!=0)cout<<cta10<<" Billete/s de 10 Quetzales.\n"; 
		        if(cta5!=0)cout<<cta5<<" Billete/s de 5 Quetzales.\n"; 
		        if(cta1!=0)cout<<cta1<<" Billete/s de 1 Quetzales.\n";

				system("pause");
						}
		//------------------------------------
		
			auxiliar = auxiliar->siguiente;
	        i++;
	}
		system("pause");
    if (i==0) 
	{
	printf( "\nLa lista está vacía!!\n" );
	}
}

int eliminar(emp *&primero, int n) 
{
  	if(primero != NULL){
		emp *aux_borrar;
		emp *anterior = NULL;
		
		aux_borrar = primero;
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->cod != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"Codigo de empleado Invalido"<<endl; system("pause");
		}	
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			primero = primero->siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero, no es el primer nodo
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}	
 
/* 
void buscarLista(emp *primero,int &n1)
{
	bool band = false;
	
	emp *actual = new emp();
	actual = primero;
	
do{
		if(actual->cod == n1){
			band = true;
		}
			
		actual = actual->siguiente;
	}while((actual != NULL) && (actual->cod <= n1));
	
	if(band == true){
			cout<<"Codigo:    "<<actual->cod<<endl;
//    		printf("Nombre:    %s\nTelefono:  %s\nDireccion: %s\nGenero:    %s\nEstado C.: %s\nDepto.:    %s\nPuesto:    %s\n",
//			auxiliar->nom,auxiliar->tel,auxiliar->dir,auxiliar->gen,auxiliar->estciv,auxiliar->depto,auxiliar->pue);
//			cout<<"Sueldo:    "<<actual->liq<<endl;
			system("pause");
	}
	else{
		cout<<"Elemento "<<n1<<" NO a sido encontrado en lista\n";
		system("pause");
	}
}
*/

void buscarLista(struct emp *primero,int)
{
    struct emp *auxiliar;
    int l,bus;
 
    l=0;
    auxiliar = primero;
    cout<<"\nIngrese el codigo del empleado que desea ver\n";
    cin>>bus;
    system("cls");
//    printf("\nLista de Empleados:\n");
	/*printf("\nDepartamentos:\n\n1. Administracion\n2. Contabilidad\n3. Informatica\n4. Compras\n5. Ventas\n6. Recursos Humanos\n7. Operaciones\n8. Seguridad\n9. Servicio al cliente\n10. Marketing\n");    
	printf("\nEstado civil\n\n1. Soltero\n2. Casado\n3. Divorciado\n4. Viudo\n\n");
	printf("\nGenero\n\n1. Masculino\n2. Femenino\n\n");*/
	
	while ((auxiliar!=NULL) and (auxiliar->cod==n1));
	{
			cout<<"Codigo:    "<<auxiliar->cod<<endl;
//    		printf("Nombre:    %s\nTelefono:  %s\nDireccion: %s\nGenero:    %s\nEstado C.: %s\nDepto.:    %s\nPuesto:    %s\n",
//			auxiliar->nom,auxiliar->tel,auxiliar->dir,auxiliar->gen,auxiliar->estciv,auxiliar->depto,auxiliar->pue);
			cout<<"Sueldo:    "<<auxiliar->liq<<endl;
			printf("----------------------------------------\n");
		
			auxiliar = auxiliar->siguiente;
	        l++;
	}    
		system("pause");
    if (l==0) 
	{
	printf( "\nLa lista está vacía!!\n" );
	}
} 
 
int main() 
{
	system("color 70");
    char opcion;
 
    primero = (struct emp *) NULL;
    ultimo = (struct emp *) NULL;
    do 
		{
       	menu();
        cin>>opcion;
        
        switch(opcion) 
			{
        
		case '1': 
			ingresar();
        break;
        
		case '2':  
			cout<<"Ingrese el codigo del empleado que desea eliminar: "; cin>>n;
			eliminar(primero,n);
        break;
        
		case '3': 
//			cout<<"Ingrese el codigo del empleado que desea buscar: "; cin>>n1;
			buscarLista(primero, n1);
        break;

		case '4': 
			mostrar(primero);
        break;
            
		case '5': 
			exit (1);
            default: printf("Opción no valida\n");
        break;
    		}
     	} while (opcion!='5');
}
