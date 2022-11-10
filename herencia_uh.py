class Persona_Plantilla:
    def __init__(self,nombre,salario):
        self.nombre = nombre    # Nombre de la persona que constituye una plantila
        self.salario = salario  # Salario o estipendio de la persona que constituye una plantila

    def CobrarSalario(self):
        print(self.nombre+" ha Cobrado $"+ str(self.salario))

class Trabajador(Persona_Plantilla):
    def __init__(self, nombre, salario):
        Persona_Plantilla.__init__(nombre, salario)

class Estudiante(Persona_Plantilla):
    def __init__(self,nombre,salario,h_clases):
        Persona_Plantilla.__init__(self,nombre,salario)
        self.h_clases = h_clases
    
    def RecibirClase(self,clase):
        print(self.nombre+'Recibe clase de '+ clase)

class Profesor(Trabajador):
    def __init__(self, nombre, salario,h_clases):
        Trabajador.__init__(self,nombre,salario)
        self.h_clases = h_clases
        
    def ImpartirClase(self,clase):
        print(self.nombre+'Imparte clase de ' + clase)

class AlumnoAyudante(Estudiante,Profesor):
    def __init__(self,nombre,salario,h_clases_rec,salario_extra,horas_clase_imp):
        Profesor.__init__(self,nombre,salario_extra,horas_clase_imp)
        Estudiante.__init__(self,nombre,salario,h_clases_rec)
        self.salario_extra=salario_extra

    def CobrarSalarioExtra(self):
        print(self.nombre + 'Cobra extra $'+str(self.salario_extra))

class ProfesorAdiestrado(Profesor,Estudiante):
    def __init__(self,nombre,salario,h_clases_imp,h_clases_rec):
        Profesor.__init__(self,nombre,salario,h_clases_imp)
        Estudiante.__init__(self,nombre,salario,h_clases_rec)

