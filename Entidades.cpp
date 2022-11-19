#include <iostream>


using namespace std;

class Plantilla
{
    protected:
    string nombre;
    public:
    virtual void CobrarSalario(){};
    virtual void PrintNombre(){
        cout << nombre << endl;
    }
};

class Estudiante : public virtual Plantilla
{
    protected:
    int salario; 
    int total;
    int horas_clases_recibidas;
    int total_clases;

    public:
    Estudiante(string nombre, int salarioN, int horas_claseN)
    {
        Plantilla::nombre = nombre;
        salario=salarioN;
        horas_clases_recibidas=horas_claseN;
        total = 0;
        total_clases = 0;
    }
    void RecibirClase()
    {
        total_clases+=horas_clases_recibidas;
    }
    virtual void CobrarSalario()
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
    int GetTotalHorasClases(){return total_clases;}
};

class Trabajador : public virtual Plantilla
{
    protected:
    int salario;
    int total;
    public:
    Trabajador(string nombre, int salarioN)
    {
        Plantilla::nombre = nombre;
        salario=salarioN;
        total = 0;
    }
    virtual void CobrarSalario()
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
    Profesor(string nombre, int salarioN,int horas_claseN):Trabajador(nombre, salarioN)
    {
        horas_clase_impartidas=horas_claseN;
    }
    void ImpartirClase()
    {
        horas_clase_impartidas+=15;
    }
};

class Profesor_Adiestrado: public Profesor
{
    private:
    int horas_clase_recibidas;
    public:
    Profesor_Adiestrado(string nombre, int salarioN,int horas_clase_impartidasN,int horas_clase_recibidasN):Profesor(nombre, salarioN,horas_clase_impartidasN)
    {
        Plantilla::nombre = nombre;
        horas_clase_recibidas=horas_clase_recibidasN;
    }
    void RecibirClase()
    {
        horas_clase_recibidas+=15;
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
    Alumno_Ayudante(string nombre, int salarioN, int horas_clase_recibidasN, int horas_clase_impartidasN):Estudiante(nombre, salarioN,horas_clase_recibidasN),Trabajador(nombre, salarioN)
    {
        Plantilla::nombre = nombre;
        horas_clase_impartidas=horas_clase_impartidasN;
        salario = Estudiante::salario + Trabajador::salario;
        total = 0;
    }
    Alumno_Ayudante(string nombre,
                    int salario_estudiante, 
                    int salario_trabajador, 
                    int horas_clase_recibidasN, 
                    int horas_clase_impartidasN
                    ):
    Estudiante(nombre, salario_estudiante, horas_clase_recibidasN), Trabajador(nombre, salario_trabajador)
    {
        Plantilla::nombre = nombre;
        horas_clase_impartidas=horas_clase_impartidasN;
        total = 0;
        salario = Estudiante::salario + Trabajador::salario;
    }
    void ImpartirClase()
    {
        horas_clase_impartidas+=1;
    }

    void CobrarSalario(){
        Estudiante::CobrarSalario(); Trabajador::CobrarSalario();
    }
    int GetSalario(){return Estudiante::salario + Trabajador::salario;}
    int GetTotal(){return total + Estudiante::total + Trabajador::total;}
    int GetHorasClasesImpartidas(){return horas_clase_impartidas;}
};

int main()
{
    Alumno_Ayudante AA("Belsai y Daniela", 150,50,2,10);
    AA.Estudiante::CobrarSalario();
    cout << AA.GetSalario()<<endl;
    cout << AA.Estudiante::GetSalario()<< endl;
    cout << AA.Trabajador::GetSalario() << endl;
    cout << AA.GetTotal() << endl;
    AA.CobrarSalario();
    cout << AA.GetTotal() << endl;
    AA.PrintNombre();

    Profesor_Adiestrado PF("Belsai y Daniela", 150,50,2);
    PF.PrintNombre();

    return 0;
}