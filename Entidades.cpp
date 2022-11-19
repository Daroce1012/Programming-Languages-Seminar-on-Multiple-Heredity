#include <iostream>


using namespace std;

class Estudiante
{
    protected:
    int salario; 
    int total;
    int horas_clases_recibidas;
    public:
    Estudiante(int salarioN, int horas_claseN)
    {
        salario=salarioN;
        horas_clases_recibidas=horas_claseN;
        cout<<"Estudiante called"<< endl;
        total = 0;
    }
    void RecibirClase()
    {
        horas_clases_recibidas+=48;
    }
    void CobrarSalario()
    {
        total += salario;
    }
    int GetSalario(){return salario;}
    int SetSalario(int valor){salario = valor;}
    int GetTotal(){
        return total;
    }
    int GetHorasClases(){return horas_clases_recibidas;}
    int SetHorasClases(int valor){horas_clases_recibidas = valor;}
};

class Trabajador
{
    protected:
    int salario;
    int total;
    public:
    Trabajador(int salarioN)
    {
        salario=salarioN;
         cout<<"Trabajador called"<< endl;
        total = 0;
    }
    void CobrarSalario()
    {
        total+=salario;
    }
    int GetSalario(){return salario;}
    int SetSalario(int valor){salario = valor;}
    int GetTotal(){
        return total;
    }
};

class Profesor: public Trabajador
{
    private:
    int horas_clase_impartidas;
    public:
    Profesor(int salarioN,int horas_claseN):Trabajador(salarioN)
    {
        horas_clase_impartidas=horas_claseN;
    }
    void ImpartirClase()
    {
        horas_clase_impartidas+=15;
        cout<<horas_clase_impartidas<< endl;
    }
};

class Profesor_Adiestrado: public Profesor
{
    private:
    int horas_clase_recibidas;
    public:
    Profesor_Adiestrado(int salarioN,int horas_clase_impartidasN,int horas_clase_recibidasN):Profesor(salarioN,horas_clase_impartidasN)
    {
        horas_clase_recibidas=horas_clase_recibidasN;
        cout<<"Profesor_Adiestrado called"<< endl;
    }
    void RecibirClase()
    {
        horas_clase_recibidas+=15;
        cout<<horas_clase_recibidas<< endl;
    }
};

class Alumno_Ayudante:public Estudiante, public Trabajador
{
    private:
    int horas_clase_impartidas;
    
    protected:
    int salario;
    int total;
    public:
    Alumno_Ayudante(int salarioN, int horas_clase_recibidasN, int horas_clase_impartidasN):Estudiante(salarioN,horas_clase_recibidasN),Trabajador(salarioN)
    {
        horas_clase_impartidas=horas_clase_impartidasN;
        cout<<"Alumno_Ayudante called"<< endl;
        salario = Estudiante::salario + Trabajador::salario;
        total = 0;
    }
    Alumno_Ayudante(int salario_estudiante, 
                    int salario_trabajador, 
                    int horas_clase_recibidasN, 
                    int horas_clase_impartidasN
                    ):
    Estudiante(salario_estudiante, horas_clase_recibidasN), Trabajador(salario_trabajador)
    {
        horas_clase_impartidas=horas_clase_impartidasN;
        cout<<"Alumno_Ayudante called"<< endl;
        total = 0;
        salario = Estudiante::salario + Trabajador::salario;
    }
    void ImpartirClase()
    {
        horas_clase_impartidas+=10;
        cout<<horas_clase_impartidas<< endl;
    }

    // virtual int DevolverSalario(){
    //     return Estudiante::salario + Trabajador::salario;
    // }
    int GetSalario(){return Estudiante::salario + Trabajador::salario;}
    int GetTotal(){return total + Estudiante::total + Trabajador::total;}
};

int main()
{
    Alumno_Ayudante AA(150,5,10);
    AA.Estudiante::CobrarSalario();
    cout << AA.GetSalario()<<endl;
    cout << AA.GetSalario()<< endl;
    cout << AA.GetSalario() << endl;
    cout << AA.GetTotal() << endl;
    return 0;
}