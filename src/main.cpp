#include <iostream>
#include "./class/list/list.cpp"
using namespace std;

struct Persona{
    int cedula;
    string nombre;
    int edad;
};

int main()
{
    List <Persona> list;

    Persona personas[12] = {
        {30310936, "Pedro", 30},
        {24406569, "Carlos", 25},
        {7789250, "Andres", 35},
        {9745535, "Nestor", 40},
        {26394578, "Tucupita", 28},
        {31005785, "Marcelo", 21},
        {23445789, "Rodrigo", 15},
        {30005987, "Carrizo :v", 22},
        {7665345,"David", 12},
        {6533212, "Elsa Polindo", 15},
        {34550233, "Elmer Curio", 21},
        {26458973, "Elvis Tek", 14}
    };

    for (int i = 0; i < 12; i++) {
        list.insert(personas[i]);
    }

    //ORDENAMOS LOS ELEMENTOS

    list.ordenarMayorMenor();
    cout <<"Lista ordenada de mayor a menor segun la cedula:"<<endl<<endl;
    list.print();

    list.ordenarMenorMayor();
    cout <<"Lista ordenada de menor a mayor segun la cedula:"<<endl<<endl;
    list.print();

    cout<<endl<<endl;
    cout<<"Datos dentro del intervalo de edad"<<endl<<endl;

    //OBTENER DATOS DE PERSONAS EN UN INTERVALOR - EDAD
    list.obtenerReferencia(25,35);

    //ELIMINAMOS DATOS DE PERSONAS EN UN INTERVALO - EDAD
    cout<<"Se eliminaron los datos en el intervalo de edad"<<endl<<endl;
    list.borrarElementosIntervalo(25,35);
    list.print();

}