#include <iostream>
#include <string>
using namespace std;

// nodo final apunta al inicial de manera "circular"

struct Nodo{

    int id;
    int edad;
    int peso;
    string owner;
    string raza;
    

    Nodo *sig; // * Dirección del siguiente nodo

};


class ListaCircularSimple
{

private:
    /* data */
    Nodo *pInicio;

public:

    ListaCircularSimple();
    ~ListaCircularSimple();
    void insertNodo();
    void insInicio(int, int, int, string, string);
    void mostrarListaID(int);
    void eliminarListaCirRec(Nodo *);

};


ListaCircularSimple::ListaCircularSimple(void)
{
    pInicio = NULL; // *el nodo cada vez que se crea tiene su puntero inical a NULL asi es el último y el primero siempre.
                    
}


ListaCircularSimple::~ListaCircularSimple(){

    cout << "Destructor ejecutandose..." << endl;
    if(pInicio)
        eliminarListaCirRec(pInicio);
    
    pInicio = NULL;
}


void ListaCircularSimple::eliminarListaCirRec(Nodo *p){

    if(p->sig != pInicio)
        eliminarListaCirRec(p->sig);
    delete p;
}


void ListaCircularSimple::insInicio(int id, int edad, int peso, string owner, string raza)
{
    Nodo *nuevo, *saltarin;

    nuevo = new Nodo; 
    nuevo -> id = id; 
    nuevo -> edad = edad;
    nuevo -> peso = peso;
    nuevo -> owner = owner; 
    nuevo -> raza = raza;

    if(!pInicio){
        pInicio = nuevo;
        pInicio -> sig = pInicio;

    } else {
        nuevo -> sig = pInicio;
        Nodo *saltarin = pInicio;

        while (saltarin->sig != pInicio)
        {
            saltarin = saltarin->sig;

        }
        saltarin -> sig = nuevo;
        pInicio = nuevo;
    } 
    
}


void ListaCircularSimple::mostrarListaID(int id)
{
    cout << "Buscando..." << endl << endl;
    Nodo *saltarin;
    saltarin = pInicio;
    
    if(pInicio){
        do
        {
            /* code */
            if(saltarin -> id == id){

                cout << "Dueño: " <<saltarin ->owner << endl;
                cout << "Raza: " << saltarin ->raza << endl;
                cout << "Peso(lb): "<< saltarin -> peso << endl;
                cout << "Edad: "<<saltarin -> edad << endl;
            } else {
                saltarin = saltarin -> sig;
            }
        } while (saltarin != pInicio);
    }

}


int menu(){

    int opcion = 0;
    cout << endl;
    cout << "1) Agregar mascota." << endl;
    cout << "2) Mostrar su mascota." << endl;
    cout << "3) Eliminar." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();

    cout << endl;
    return opcion;
}


int main(void)
{
    /* code */
    ListaCircularSimple objListaCircular;
    cout << endl;
    cout << "Administracion de veterinaria" << endl;

    string nombre = "", owner = "", raza = "";
    int edad = 0, peso = 0, id = 0;
    bool opcion = true;
    int p = 0;

    do {
        switch (menu())
        {
        case 1:
            /* code */
            cout << "Id: ";
            cin >> id; cin.ignore();

            cout << "Nombre del dueño: ";
            getline(cin, owner);

            cout << "Raza: ";
            getline(cin, raza);

            cout << "Peso(lb): ";
            cin >> peso;

            cout << "Edad: ";
            cin >> edad; cin.ignore();
            objListaCircular.insInicio(id, edad, peso, owner, raza);
            break;
        case 2:

            cout << "Ingresar ID de la mascota a buscar: ";
            cin >> p;

            objListaCircular.mostrarListaID(p);
            break;
        
        case 3:
    
            opcion = false;
            break;

        default:
        
            break;
        }

    }while(opcion);

    
    cout << endl;
    return 0;

}