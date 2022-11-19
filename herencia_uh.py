from abc import ABC, abstractmethod


class Aprendiz(ABC):
    @abstractmethod
    def RecibirClase(self,clase):
        pass
        

class Instructor(ABC):
    @abstractmethod
    def ImpartirClase(self,clase):
        pass
       


class Persona_Plantilla():
    def __init__(self,nombre,salario):
        self.nombre = nombre    # Nombre de la persona que constituye una plantila
        self.salario = salario  # Salario o estipendio de la persona que constituye una plantila

    def CobrarSalario(self):
        print(self.nombre+" ha cobrado $"+ str(self.salario))


class Trabajador(Persona_Plantilla):
    def __init__(self, nombre, salario):
        Persona_Plantilla.__init__(self,nombre, salario)


class Estudiante(Persona_Plantilla,Aprendiz):
    def __init__(self,nombre,salario,h_clases):
        Persona_Plantilla.__init__(self,nombre,salario)
        self.h_clases = h_clases
    
    def RecibirClase(self,clase):
        print(self.nombre+' recibe clase de '+ clase)



class Profesor(Trabajador,Instructor):
    def __init__(self, nombre, salario,h_clases):
        Trabajador.__init__(self,nombre,salario)
        self.h_clases = h_clases
   
    def ImpartirClase(self,clase): 
       print(self.nombre+' imparte clase de ' + clase)


class AlumnoAyudante(Estudiante,Trabajador,Instructor):
    def __init__(self,nombre,salario,h_clases_rec,salario_extra,horas_clase_imp):
        Trabajador.__init__(self,nombre,salario_extra)
        Estudiante.__init__(self,nombre,salario,h_clases_rec)
        self.salario_extra=salario_extra
        self.horas_clase_imp = horas_clase_imp
    
    def CobrarSalario(self):
        print(self.nombre+" ha cobrado $"+ str(self.salario+self.salario_extra))
        
     
class ProfesorAdiestrado(Profesor,Aprendiz):
    def __init__(self,nombre,salario,h_clases_imp,h_clases_rec):
        Profesor.__init__(self,nombre,salario,h_clases_imp)
        self.h_clases_rec = h_clases_rec

    def RecibirClase(self,clase):
        print(self.nombre+' recibe clase de '+ clase)



