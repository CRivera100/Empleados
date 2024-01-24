#include <iostream>
#include <string>

using namespace std;

class Empleado{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;
public:
    Empleado(int,string,string,float,string);

    void Imprime();
    void CambiaDomic(string&);
    void CambiaReportaA(string&);
    void ActualSueldo(float);

    int getClaveEmpleado();
    float getActualSueldo();
};

Empleado::Empleado(int a, string b, string c, float d, string e)
{
    ClaveEmpleado = a;
    Nombre = b;
    Domicilio = c;
    Sueldo = d;
    ReportaA = e;
}

void Empleado::Imprime()
{
    cout << "Clave: " << ClaveEmpleado << endl
         << "Nombre: " << Nombre << endl
         << "Domicilio: " << Domicilio << endl
         << "Sueldo: " << Sueldo << endl
         << "Jefe: " << ReportaA << endl << endl;
}

void Empleado::CambiaDomic(string& a)
{
    Domicilio = a;
}

void Empleado::CambiaReportaA(string& a)
{
    ReportaA = a;
}

void Empleado::ActualSueldo(float a)
{
    Sueldo = a;
}

int Empleado::getClaveEmpleado()
{
    return ClaveEmpleado;
}

float Empleado::getActualSueldo()
{
    return Sueldo;
}

enum Opciones
{
    OPC_IMPRIME = 1,
    OPC_CAMBIADOMIC,
    OPC_CAMBIAREPORTAA,
    OPC_ACTUALSUELDO,
    OPC_SALIR
};

int main(){

    Empleado JefePlanta(1234,"Anabel","salsipuedes123",float(3300.00),"Gerente");
    Empleado JefePersonal(9876,"Kevin","yacasillego300",float(2800.00),"Gerente");

    int opc,res,code;
    string nuevoDom,nuevoJefe;
    float adv,adv2,nuevoSueldo,sueldo;

    do{

    cout << "Que desea hacer: " << endl <<
    OPC_IMPRIME << ". Imprimir Datos" << endl <<
    OPC_CAMBIADOMIC << ". Cambia Domicilio" << endl <<
    OPC_CAMBIAREPORTAA << ". Cambiar Jefe" << endl <<
    OPC_ACTUALSUELDO << ". Sueldo" << endl <<
    OPC_SALIR << ". Salir " << endl << endl;
    cin >> opc;
    cin.ignore();

    switch(opc)
    {
    case OPC_IMPRIME:
        cout << "Digite el codigo del Empleado: ";
        cin >> code;
             if(code == JefePlanta.getClaveEmpleado())
             {
                 JefePlanta.Imprime();
             }
             else
                if(code == JefePersonal.getClaveEmpleado())
             {
                 JefePersonal.Imprime();
             }
             else
             {
                 return 1;
             }break;
    case OPC_CAMBIADOMIC:
        cout << "Digite el codigo del Empleado: ";
        cin >> code;
        cin.ignore();
        if(code == JefePlanta.getClaveEmpleado())
        {
            cout << "Nuevo Domicilio: ";
            getline(cin,nuevoDom);
            JefePlanta.CambiaDomic(nuevoDom);
        }
        else
            if(code == JefePersonal.getClaveEmpleado())
        {
            cout << "Nuevo Domicilio: ";
            getline(cin,nuevoDom);
            JefePersonal.CambiaDomic(nuevoDom);
        }
        else
        {
            return 1;
        }break;
    case OPC_CAMBIAREPORTAA:
        cout << "Cambiar Jefe de " << endl
             << "1. Jefe de Planta" << endl
             << "2. Jefe de Personal" << endl;
             cin >> res;
             cin.ignore();
             if(res == 1)
             {
                 cout << "Nuevo Jefe: ";
                 getline(cin,nuevoJefe);
                 JefePlanta.CambiaReportaA(nuevoJefe);
             }
             else
                if(res == 2)
             {
                 cout << "Nuevo Jefe: ";
                 getline(cin,nuevoJefe);
                 JefePersonal.CambiaReportaA(nuevoJefe);
             }
             else
             {
                 return 1;
             }break;
    case OPC_ACTUALSUELDO:
        cout << "Digite el codigo del Empleado: ";
        cin >> code;
            if(code == JefePlanta.getClaveEmpleado())
            {
                cout << "Digite el porcentaje a incrementar: ";
                cin >> adv;
                adv2 = adv / 100;
                sueldo = JefePlanta.getActualSueldo();
                nuevoSueldo = (sueldo * adv2) + sueldo;
                JefePlanta.ActualSueldo(nuevoSueldo);
            }
            else
                if(code == JefePersonal.getClaveEmpleado())
            {
                cout << "Digite el porcentaje a incrementar: ";
                cin >> adv;
                adv2 = adv / 100;
                sueldo = JefePersonal.getActualSueldo();
                nuevoSueldo = (sueldo * adv2) + sueldo;
                JefePersonal.ActualSueldo(nuevoSueldo);
            }
            else
            {
                return 1;
            }break;
    case OPC_SALIR:
        cout << "Vuelva Pronto!" << endl;
        break;
    default:break;
    }

    }while(opc != OPC_SALIR);

    return 0;
}
