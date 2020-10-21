#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

enum donas{sencilla, rellena_leche, moca, caramelo};
enum platos{desayuno, almuerzo, cena};

struct Producto {
    string nombre;
    float precio_unitario;
};
Producto producto;

struct Pedido {
    string apellido;
    vector<Producto> productos;
};
Pedido pedido;
Pedido pedido2;
vector<Producto> listaProductos;
vector<Producto> listaProductos2;

void menuDonas(queue<Pedido> &);
void menuPlatos(queue<Pedido> &);
void choosePush(queue<Pedido> &, queue<Pedido>);
void cobrarDonas(queue<Pedido> *, float, float);
void cobrarPlatos(queue<Pedido> *, float, float);

int main(){

    queue<Pedido> donas;
    queue<Pedido> platos;
    float pago = 0;
    float amount = 0;
    float pago2 = 0;
    float amount2 = 0;

    int option;
    bool status = true;
    float totalDonas = 0;
    float totalPlatos = 0;
    
    while(status){

        cout << "\n***** DONAS AL 2X1  *****" << endl << endl;
        cout << "1) Atender pedidos de clientes" << endl;
        cout << "2) Calcular ganancia por ventas de donas" << endl;
        cout << "3) Calcular ganancia por venta de platos fuertes" << endl;
        cout << "4) Salir" << endl << endl;

        cout << "Ingrese la opcion: ";
        cin >> option;
        cin.ignore();

        switch (option) {

            case 1:
                
                int name;
                cout << "\nDigite el apellido del cliente: ";
                getline(cin, pedido.apellido);

                choosePush(donas, platos);
        
                break;
            case 2: 
                cobrarDonas(&donas, pago, amount);
                break;
            case 3:
                cobrarPlatos(&platos, pago2, amount2);
                break;
            case 4: cout << "\nFin del programa..." << endl << endl; status = false; break;
            default: cout << "\nEsa opcion no existe" << endl << endl; break;
        }    
    } 
    return 0;
}

void choosePush(queue<Pedido> &donas, queue<Pedido> platos){

    int option;

    cout << "\nQue desea comprar?" << endl << endl;
    cout << "\t1) Donas" << endl;
    cout << "\t2) Platos fuertes" << endl;
    cout << "\nIngrese su opcion: ";
    cin >> option;

    switch (option) {

        case 1:
            menuDonas(donas);   
            pedido.productos = listaProductos;
            donas.push(pedido);  
            listaProductos.clear();
            break;
        case 2:
            menuPlatos(platos);
            pedido2.productos = listaProductos2;
            platos.push(pedido2);  
            listaProductos2.clear();
            break;
        default: cout << "\nOpcion erronea!" << endl << endl; break;
    }
}

void menuDonas(queue<Pedido> &donas){

    char option;
    bool status = true;
    float monto = 0;

    while (status){

        cout << "\n*****Menu de donas" << endl << endl;
        cout << "(S) Dona Sencilla $1.00" << endl;
        cout << "(L) Dona Rellena de Leche $1.25" << endl;
        cout << "(M) Dona Especial Moca $1.50" << endl;
        cout << "(C) Dona Especial Caramelo $1.50" << endl;
        cout << "(X) Satisfecho" << endl;

        cout << "\nQue DONA desea agregar a su pedido?: ";
        cin >> option;

        switch(option){

            case 's':
            case 'S': 
                producto.nombre = sencilla; 
                producto.precio_unitario = 1.00;  
                monto += producto.precio_unitario;
                listaProductos.push_back(producto);
                break;
            case 'l':
            case 'L': 
                producto.nombre = rellena_leche; 
                producto.precio_unitario = 1.25; 
                monto += producto.precio_unitario;
                listaProductos.push_back(producto);
                break;
            case 'm':
            case 'M': 
                producto.nombre = moca; 
                producto.precio_unitario = 1.50; 
                monto += producto.precio_unitario;
                listaProductos.push_back(producto);
                break;
            case 'c': 
            case 'C': 
                producto.nombre = caramelo; 
                producto.precio_unitario = 1.50; 
                monto += producto.precio_unitario;
                listaProductos.push_back(producto);
                break;
            case 'x':
            case 'X': status = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    } 
    cout << "\nSu monto es de: " << monto << " dolares" << endl;
    
}

void menuPlatos(queue<Pedido> &platos){

    char option;
    bool status = true;
    float monto;

    while (status){

        cout << "\n*****Menu de Platos Fuertes" << endl << endl;
        cout << "(D) Doesayuno $2.50" << endl;
        cout << "(A) Almuerzo $5.00" << endl;
        cout << "(C) Cena $3.50" << endl;
        cout << "(X) Satisfecho" << endl;

        cout << "\nQue PLATO desea agregar a su pedido?: ";
        cin >> option;

        switch(option){

            case 'd':
            case 'D': 
                producto.nombre = desayuno; 
                producto.precio_unitario = 2.50; 
                monto += producto.precio_unitario;
                listaProductos2.push_back(producto);
                break;
            case 'a':
            case 'A': 
                producto.nombre = almuerzo; 
                producto.precio_unitario = 5.00;
                monto += producto.precio_unitario;
                listaProductos2.push_back(producto);
                break;
            case 'c':
            case 'C': 
                producto.nombre = cena; 
                producto.precio_unitario = 3.50;
                monto += producto.precio_unitario;
                listaProductos2.push_back(producto);
                break;
            case 'x':
            case 'X': status = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }
    cout << "\nSu monto es de: " << monto << " dolares" << endl;
}

void cobrarDonas(queue<Pedido> *donas, float pago, float amount) {

    if(donas->empty()) {
        cout << "\nNo se ha realizado ningun cobro, no habia clientes en la cola" << endl << endl;
    }else {

        while(!donas->empty()) {

            Pedido ped = donas->front();

            for(int i = 0; i < pedido.productos.size(); i++) {

                pago += ped.productos.at(i).precio_unitario;

            }
            donas->pop();
        }
        cout << "\nEl pago del cliente en la cola es de " << pago << " dolares" << endl;
    } 
    amount += pago;
    cout << "Las ganancias por las venta de DONAS es de " << amount << endl;

}

void cobrarPlatos(queue<Pedido> *platos, float pago2, float amount2){

    if(platos->empty()) {
        cout << "\nNo se ha realizado ningun cobro, no habia clientes en la cola" << endl;
    }else {

        while(!platos->empty()) {

            Pedido ped = platos->front();

            for(int i = 0; i < pedido2.productos.size(); i++) {

                pago2 += ped.productos.at(i).precio_unitario;

            }
            platos->pop();
        }
        cout << "\nEl pago del cliente en la cola es de " << pago2 << " dolares" << endl;
    }
    amount2 += pago2;
    cout << "Las ganancias por las venta de Platos es de " << amount2 << endl;
}
