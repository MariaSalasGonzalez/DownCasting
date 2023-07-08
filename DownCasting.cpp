#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
	//contenido de persona

};


class Empleado: public Persona {
private:
	string nombre;
	double salario;
public:
	Empleado(string nom, double sal) {
		nombre = nom;
		salario = sal;
	}

	string nombre() {
		return nombre;
	}

	double getSueldo() {
		return salario;
	}

	void mostrar() {
		cout << "Nombre..." << nombre << endl;
		cout << "Salario..." << salario << endl;
	}

	void agregarBono(double bono) {
		salario += bono;
	}
};

class Administrador :public Empleado {
private:
	double comision;
public:
	Administrador(string nom, string sal, double comm) :
		Empleado(nom, sal) {
		comision = comm;
	}

	double getComm() {
		return comision;
	}
};

class Secretario :public Empleado {
private:
	Administrador * admin;
public:
	Secretario(string nom, double sal, Administrador* ad) :
		Empleado(nom, sal) {
		admin = ad;
	}
	Administrador* getAdministrador() {
		return admin;
	}
};

//El Downcast o Downcasting es el proceso inverso de un upcast.
//Convierte puntero de la clase base a puntero de la clase derivada
//El downcast debe hacerse manualmente, Esto significa que el programador
//tiene que especificar el tipo de conversion explicita
//Downcast no es seguro como upcast
//todo programador sabe que un objeto de la clase dereviada puede ser
//tratado como un objeto de la clase base de lo ontario no es correcto
//por ejemplo: un gerente es siempre una persona, sin embargo, la persona
//no siempre es un gerente. El programador tiene que utilizar una conversion explicita
//para el Downcast

int main() {
	cout << "--------DOWNCASTING------------" << endl;
	cout << "-------------------------------" << endl;
	Empleado e1("Pedro", 1400);
	//Intentar convertir Empleado en Administrador

	//Administrador* m3 = (Administrador*)(&e1); 
	//cout <<m3->getNombre(); << "--->" << m3->getComm() << endl;

	//e1 no es un ojeto de la clase administrador 
	//e1 no contiene ninguna informacion acerca de la comision
	//Por eso una operacion de este tipo puede producit resultados
	//inesperados. Este es el gran peligro del DownCast
	//Se puede utilizar un molde de seguridad que nos puede ayudar
	//a saber si un tipo puede convertirse correctamente en otro tipo.
	//De lo contario devuelve un nullptr
	//dynamic_cast tiene la siguiente sintaxis.
	// dynamic_cast<NEW_TYPE>(objeto);
	//Si se utiliza ese elenco dinamico, las clases deben ser polimorficas.
	//Deben tener al menos una funcion virtual 


	Empleado e1("Pedro", 1400);
	Administrador* m3 = dynamic_cast<Administrador*>(&e1);

	if (m3) { //quiere decir que m3 existe y si es posible la conversion
		cout << m3->getComm() << endl;
	}else {
			cout << "No es posible la conversion" << endl;
		}
	//tarea moral
	//covertir la jerarquia anterior en una herencia polimorfica
	// y asi saber si funciona el dynamic_cast.


}
