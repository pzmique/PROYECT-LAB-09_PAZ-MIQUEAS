#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Transaccion{
    string tipo;
    string nombre;
    int cantidad;
    float precio;
    float total;
};
    int totalcompra;
    int totalventa;
    int totalfinal;

    bool stateProgram = true;

void RegisterTransaction (Transaccion);
void ViewTransaction (void);
void SearchTransaction (void);
void UpdateTransaction (void);
void calculateProfitLoss();


const int MaxTransaccion=100;
Transaccion transacciones[MaxTransaccion];
int cont_transaccion=0;



int main(){
	int opcion;
	int totalSegundos = 5;
	Transaccion t;


    for (int i = 0; i < MaxTransaccion; i++){
    cout<<"seleccione una opcion:"<<endl;
	cout<<"escriba 1 para comprar o venta"<<endl;								
	cout<<"escriba 2 para buscar una transaccion"<<endl;
	cout<<"escriba 3 para editar una transaccion"<<endl;
	cout<<"escriba 4 para mostrar las perdidas y ganancias"<<endl;
	cout<<"escriba 5 para salir del programa"<<endl;
	cin>>opcion;
	switch(opcion){
		case 1:
			RegisterTransaction(t);
    		break;
		case 2:
			SearchTransaction();
			break;
		case 3:
			UpdateTransaction();
			break;
		case 4:
			calculateProfitLoss();
			break;
		case 5:
			cout << "----------------------------------------" << endl;
			cout << "gracias por usar el programa" << endl;
			for (int segundos = 0; segundos < totalSegundos; segundos++)
			{
				cout << "el programa se cerrara en " << segundos << endl;
				this_thread::sleep_for(chrono::seconds(1)); //Aca lo que hace esta linea es por cada iteracion que hace el for añade un delay de 1 segundo
			}
			cout << "----------------------------------------" << endl;
			exit(0); 
			break;
		}
    }

	return 0;
}

void RegisterTransaction(Transaccion t){//registro y creacion de transacciones
	cout << "tipo: ";
	cin >> t.tipo;
	while(t.tipo=="compra" or t.tipo=="venta"){
		cout << "nombre: ";
		cin >> t.nombre;
		cout << "cantidad: ";
		cin >> t.cantidad;
		cout << "precio: ";
		cin >> t.precio;
	
		t.total=t.cantidad*t.precio;
	
		if(t.tipo=="compra"){
			totalcompra=t.total+totalcompra;	
		}

		if(t.tipo=="venta"){
			totalventa=t.total+totalventa;	
		}
	
		transacciones[cont_transaccion] = t;
		cont_transaccion++;
		break;
		ViewTransaction ();
	}

	cout<<"----------------------------"<<endl;
	main();
	
}

void ViewTransaction (){//visualizacion de las transacciones creadas
	cout<<"----------------------------"<<endl;
	
    for (int i = 0; i < cont_transaccion; i++){
    	cout<<"TRANSACCION:"<<endl;
        cout<<"tipo: "<<transacciones[i].tipo<<endl;
        cout<<"nombre: "<<transacciones[i].nombre<<endl;
        cout<<"cantidad: "<<transacciones[i].cantidad<<endl;
        cout<<"precio: "<<transacciones[i].precio<<endl;
        cout<<"total: "<<transacciones[i].total<<endl;
        cout<<""<<endl;
    }
	
    cout<<"----------------------------"<<endl;
}

void SearchTransaction() {//buscador y visualizador de transacciones especificas
	string producto;
	bool encontrado=false;
	cout <<"ingrese un producto: ";
	cin >> producto;
	for(int i=0;i < MaxTransaccion;i++ ){
		if (transacciones[i].nombre==producto){
            cout<<"TRANSACCION ENCONTRADA:"<<endl; 
            cout<<"tipo: "<<transacciones[i].tipo<<endl;
        	cout<<"nombre: "<<transacciones[i].nombre<<endl;
        	cout<<"cantidad: "<<transacciones[i].cantidad<<endl;
        	cout<<"precio: "<<transacciones[i].precio<<endl;
        	cout<<"total: "<<transacciones[i].total<<endl;
			encontrado=true;
		}
	}
	if(encontrado==false){
		cout<<"no se encontro ninguna transaccion con ese nombre"<<endl;
	}
	cout<<"----------------------------"<<endl;
}

void UpdateTransaction(){//editador de transacciones especificas
    string producto;
    bool encontrado=false;
    cout<< "ingrese un producto"<<endl;
    cin>> producto;
    for (int i = 0; i < MaxTransaccion; i++)
    {
        if (transacciones[i].nombre==producto){
        	if(transacciones[i].tipo=="compra"){
			totalcompra=totalcompra-transacciones[i].total;
			}
			if(transacciones[i].tipo=="venta"){
			totalventa=totalventa-transacciones[i].total;	
			}
            cout << "tipo: ";
			cin >> transacciones[i].tipo;
			cout << "nombre: ";
			cin >> transacciones[i].nombre;
			cout << "cantidad: ";
			cin >> transacciones[i].cantidad;
			cout << "precio: ";
			cin >> transacciones[i].precio;
			transacciones[i].total=transacciones[i].cantidad*transacciones[i].precio;
			if(transacciones[i].tipo=="compra"){
			totalcompra=transacciones[i].total+totalcompra;	
			}
			if(transacciones[i].tipo=="venta"){
			totalventa=transacciones[i].total+totalventa;	
			}
            encontrado = true;
            ViewTransaction ();
        }
    }
    if(encontrado==false){
		cout<<"no se encontro ninguna transaccion con ese nombre"<<endl;
	}
	main();
}

void calculateProfitLoss(){//visualizador de ganancias y perdidas realizadas en transacciones
	for(int i=0; i<MaxTransaccion; i++){
		if(transacciones[i].tipo=="compra"){
			cout<<"compras: ARS$"<<transacciones[i].total<<endl;
		}

		if(transacciones[i].tipo=="venta"){
			cout<<"ventas: ARS$"<<transacciones[i].total<<endl;
		}
	}

	cout<<"GANANCIA TOTAL: ARS$"<< totalventa	<< endl;
	cout<<"PERDIDA TOTAL: ARS$" << totalcompra	<< endl;
	totalfinal= totalventa - totalcompra;
	cout<<"TOTAL GANANCIA FINAL(si es positivo es ganancia): ARS$"<<totalfinal<<endl;
	
	cout<<"----------------------------"<<endl;
}


