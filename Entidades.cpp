#include <iostream>


using namespace std;

class Estudiante
{
    protected:
    int salario; 
    int total;
    int horas_clase_recibida;
    public:
    Estudiante(int salarioN, int horas_claseN)
    {
        salario=salarioN;
        horas_clase_recibida=horas_claseN;
        cout<<"Estudiante called"<< endl;
    }
    void RecibirClase()
    {
        horas_clase_recibida+=48;
    }
    void CobrarSalario()
    {
        total += salario;
    }
};

class Trabajador
{
    protected:
    int salario;
    public:
    Trabajador(int salarioN)
    {
        salario=salarioN;
         cout<<"Trabajador called"<< endl;
    }
    void CobrarSalario()
    {
        salario+=500;
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
    
    public:
    int salario;
    Alumno_Ayudante(int salarioN, int horas_clase_recibidasN, int horas_clase_impartidasN):Estudiante(salarioN,horas_clase_recibidasN),Trabajador(salarioN)
    {
        horas_clase_impartidas=horas_clase_impartidasN;
        cout<<"Alumno_Ayudante called"<< endl;
        salario = Estudiante::salario + Trabajador::salario;
    }
    Alumno_Ayudante(int salario_estudiante, 
                    int salario_trabajador, 
                    int horas_clase_recibidasN, 
                    int horas_clase_impartidasN, 
                    Trabajador Trabajador
                    ):
    Estudiante(salario_estudiante, horas_clase_recibidasN), Trabajador(salario_trabajador)
    {
        horas_clase_impartidas=horas_clase_impartidasN;
        cout<<"Alumno_Ayudante called"<< endl;
        salario = Estudiante::salario + Trabajador::salario;
    }
    void ImpartirClase()
    {
        horas_clase_impartidas+=10;
        cout<<horas_clase_impartidas<< endl;
    }

    virtual int DevolverSalario(){
        return Estudiante::salario + Trabajador::salario;
    }
};

int main()
{
    Alumno_Ayudante AA(150,5,10);
    AA.Estudiante::CobrarSalario();
    cout << AA.salario<< endl;
    cout << AA.DevolverSalario() << endl;
    return 0;
}