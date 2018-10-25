//============================================================================
// Name        : proyecto_pinguino.cpp
// Author      : Harry Alvarado
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>

#define size_array = 50;

using namespace std;

class Contacto {

	private: // atributos que son privados de la clase Contacto.
		string nombre;
		string celular;
		string correo1;
		string correo2;

	public: // metodos y contructor que son publicos de la clase Contacto.
		Contacto(string nombre, string celular, string correo1, string correo2){
			this->nombre = nombre;
			this->celular = celular;
			this->correo1 = correo1;
			this->correo2 = correo2;
		}

		/*
		 * A continuación se muestran los metodos geter y seter
		 * de los atributos de la clase Contacto.
		 *
		 * */

		string getNombre(){
			return nombre;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		string getCelular(){
			return celular;
		}
		void setCelular(string celular){
			this->celular = celular;
		}
		string getCorreo1(){
			return correo1;
		}
		void setCorreo1(string correo1){
			this->correo1 = correo1;
		}
		string getCorreo2(){
			return correo2;
		}
		void setCorreo2(string correo2){
			this->correo2 = correo2;
		}

};


class Prospecto : public Contacto{

	private: // atributos que son privados de la clase Prospecto.
		string nombreEmpresa;
		string web;

	public: // metodos y constructor que son publicos de la clase Prospecto y el constructor padre.
		Prospecto (string nombre, string celular, string correo1, string correo2, string nombreEmp, string web) : Contacto( nombre,  celular, correo1, correo2){
			nombreEmpresa = nombreEmp;
					this->web = web;
				}

		/*
		 * A continuación se muestran los metodos geter y seter
		 * de los atributos de la clase Prospecto.
		 *
		 * */
		string getNombreEmpresa(){
			return nombreEmpresa;
		}

		void setNombreEmpresa(string nombreEmpresa){
			this->nombreEmpresa = nombreEmpresa;
		}

		string getWeb(){
			return web;
		}

		void setWeb(string web){
			this->web = web;
		}

};

class Colega : public Contacto{

	private: // atributos que son privados de la clase Colega.
		string departamento;

	public: // metodos y constructor que son publicos de la clase Colega y el constructor padre.
		Colega(string nombre, string celular, string correo1, string correo2, string departamento) : Contacto( nombre,  celular, correo1, correo2){
			this->departamento = departamento;
		}
		/*
		 * A continuación se muestran los metodos geter y seter
		 * de los atributos de la clase Colega.
		 *
		 * */
		string getDepartamento(){
			return departamento;
		}

		void setDepartamento(string departamento){
			this->departamento = departamento;
		}

};


void menu_screen(){
	/*
	 * Se crea sub-metodo que contiene el menu
	 * */
	cout<<"\t\tContactos"<<endl;
	cout<<"1. Introducir contactos"<<endl;
	cout<<"2. Modificar contactos"<<endl;
	cout<<"3. Eliminar contactos"<<endl;
	cout<<"4. Buscar contactos"<<endl;
	cout<<"5. Listar todos los contactos"<<endl;
	cout<<"6. Listar los contactos que son prospectos"<<endl;
	cout<<"7. Listar los contactos que son colegas"<<endl;
	cout<<"8. Desea salir?"<<endl;
}

void menu(int op){
	/*
	 * En el siguiente metodo veremos la ejecución de cada uno
	 * */
	// se declaran las varibles que se utilizaran.
	string nombre, celular, correo1, correo2, nombreEmpr, web, departamento;
	// se declaran igualmente objetos a utilizar.
	Prospecto *cp [50];
	Colega *cc [50];
	// declaramos e inicializamos el contador.
	int count_p = 0;
	int count_c = 0;
	//el try{}catch(){} nos permitira apañar las excepciones generadas.
	try{
		do{
				switch (op){
					case 1:
						//Introducir contactos
						system("cls");

						cout <<"1) Prospecto"<<endl;
						cout <<"2) Colega"<<endl;
						cout <<"Escoger la opción: "; cin>> op;

						if(op == 1){
							cout <<"Nombre: "; cin >> nombre;
							cout <<"Celular: ";cin >>celular;
							cout <<"Primer Correo: ";cin >>correo1;
							cout <<"Segundo Correo: ";cin >>correo2;
							cout <<"Nombre Empresa: ";cin >>nombreEmpr;
							cout <<"Web: ";cin >>web;
							// se instancia los elementos que se iran creando al tomar esta opción.
							cp[count_p] = new Prospecto(nombre,celular,correo1,correo2,nombreEmpr,web);
							count_p++;
						}else if(op == 2){
							cout <<"Nombre: "; cin >> nombre;
							cout <<"Celular: ";cin >>celular;
							cout <<"Primer Correo: ";cin >>correo1;
							cout <<"Segundo Correo: ";cin >>correo2;
							cout <<"Departamento: ";cin >>departamento;
							// se instancia los elementos que se iran creando al tomar esta opción.
							cc[count_c] = new Colega(nombre,celular,correo1,correo2,departamento);
							count_c++;
						}else{
							cout << "Opcion no correcta!!"<<endl;
						}
						menu_screen();
						cin >> op;

						break;
					case 2:
						//Modificar contactos
						system("cls");
						char x;
						cout <<"1) Prospecto"<<endl;
						cout <<"2) Colega"<<endl;
						cout <<"Escoger la opción: "; cin>> op;

						cout <<"";
						if(op == 1){
							cout <<"1) Datos de Prospecto"<<endl;
							cout <<"Nombre: "; cin >> nombre;

							for(int i=0;i<count_p;i++){
								if (nombre == cp[i]->getNombre()){

									cout <<"Modificar del Prospecto:::: " <<endl;
									cout <<"\tEl nombre, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> nombre;
											cp[i]->setNombre(nombre);
										}
									cout <<"\tEl Celular, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> celular;
											cp[i]->setCelular(celular);
										}
									cout <<"\tCorreo Principal, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> correo1;
											cp[i]->setCorreo1(correo1);
										}
									cout <<"\tCorreo Segundario, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> correo2;
											cp[i]->setCorreo2(correo2);
										}
									cout <<"\tNombre de la Empresa, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> nombreEmpr;
											cp[i]->setNombreEmpresa(nombreEmpr);
										}
									cout <<"\tSitio Web, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> web;
											cp[i]->setWeb(web);
										}
									break;
								}
							}

						}else if(op == 2){
							cout <<"2) Colega"<<endl;
							cout <<"Nombre: "; cin >> nombre;

							for(int i=0;i<count_c;i++){
								if (nombre == cc[i]->getNombre()){

									cout <<"Modificar del Prospecto:::: " <<endl;
									cout <<"\tEl nombre, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> nombre;
											cc[i]->setNombre(nombre);
										}
									cout <<"\tEl Celular, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> celular;
											cc[i]->setCelular(celular);
										}
									cout <<"\tCorreo Principal, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> correo1;
											cc[i]->setCorreo1(correo1);
										}
									cout <<"\tCorreo Segundario, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> correo2;
											cc[i]->setCorreo2(correo2);
										}
									cout <<"\tNombre de la Empresa, desea modificar(y/n): "<<endl; cin >> x;
										if(x == 'y'){cout << ":: "; cin >> departamento;
											cc[i]->setDepartamento(departamento);
										}
									break;
								}
							}

						}else{
							cout << "Opcion no correcta!!"<<endl;

						}

						menu_screen();
						cin >> op;

						break;
					case 3:
						//Eliminar contactos
						system("cls");

						menu_screen();
						cin >> op;

						break;
					case 4:
						//Buscar contactos
						system("cls");

						cout <<"1) Prospecto"<<endl;
						cout <<"2) Colega"<<endl;
						cout <<"Escoger la opción: "; cin>> op;

						if(op == 1){
							cout <<"1)Datos de Prospecto"<<endl;
							cout <<"Nombre: "; cin >> nombre;

							for(int i=0;i<count_p;i++){

								if (nombre == cp[i]->getNombre()){

									cout <<"Datos del Contacto:::: "<<endl;
									cout <<"\tEl nombre es: "<< cp[i]->getNombre() <<endl;
									cout <<"\tEl Celular es: "<< cp[i]->getCelular() <<endl;
									cout <<"\tCorreo Principal: "<< cp[i]->getCorreo1()<<endl;
									cout <<"\tCorreo Segundario: "<< cp[i]->getCorreo2() <<endl;
									cout <<"\tNombre de la Empresa: "<< cp[i]->getNombreEmpresa() <<endl;
									cout <<"\tSitio Web: "<< (cp[i]->getWeb()) <<endl;

									break;
								}
							}

						}else if(op == 2){
							cout <<"2) Colega"<<endl;
							cout <<"Nombre: "; cin >> nombre;

							for(int i=0;i<count_c;i++){

								if (nombre == cp[i]->getNombre()){

									cout <<"Datos del Contacto:::: "<<endl;
									cout <<"\tEl nombre es: "<< cc[i]->getNombre() <<endl;
									cout <<"\tEl Celular es: "<< cc[i]->getCelular() <<endl;
									cout <<"\tCorreo Principal: "<< cc[i]->getCorreo1()<<endl;
									cout <<"\tCorreo Segundario: "<< cc[i]->getCorreo2() <<endl;
									cout <<"\tDepartamento "<< cc[i]->getDepartamento() <<endl;

									break;
								}
							}

						}else{
							cout << "Opcion no correcta!!"<<endl;

						}

						menu_screen();
						cin >> op;
						break;
					case 5:
						//Listar todos los contactos
						system("cls");
						cout <<"Datos del Prospecto:::: "<<endl;
						for(int i=0; i<count_p; i++){
							cout <<"_____________________________________ "<<endl;
							cout <<"\tEl nombre es: "<< cp[i]->getNombre() <<endl;
							cout <<"\tEl Celular es: "<< cp[i]->getCelular() <<endl;
							cout <<"\tCorreo Principal: "<< cp[i]->getCorreo1()<<endl;
							cout <<"\tCorreo Segundario: "<< cp[i]->getCorreo2() <<endl;
							cout <<"\tNombre de la Empresa: "<< cp[i]->getNombreEmpresa() <<endl;
							cout <<"\tSitio Web: "<< (cp[i]->getWeb()) <<endl;

						}
						cout <<"Datos del colega:::: "<<endl;
						for(int i=0;i<count_c;i++){
							cout <<"_____________________________________ "<<endl;
							cout <<"\tEl nombre es: "<< cc[i]->getNombre() <<endl;
							cout <<"\tEl Celular es: "<< cc[i]->getCelular() <<endl;
							cout <<"\tCorreo Principal: "<< cc[i]->getCorreo1()<<endl;
							cout <<"\tCorreo Segundario: "<< cc[i]->getCorreo2() <<endl;
							cout <<"\tDepartamento: "<< cc[i]->getDepartamento() <<endl;

						}
						menu_screen();
						cin >> op;
						break;
					case 6:
						//Listar los contactos que son prospectos
						system("cls");
						cout <<"Datos del Contacto:::: "<<endl;
						for(int i=0; i<count_p; i++){
							cout <<"_____________________________________ "<<endl;
							cout <<"\tEl nombre es: "<< cp[i]->getNombre() <<endl;
							cout <<"\tEl Celular es: "<< cp[i]->getCelular() <<endl;
							cout <<"\tCorreo Principal: "<< cp[i]->getCorreo1()<<endl;
							cout <<"\tCorreo Segundario: "<< cp[i]->getCorreo2() <<endl;
							cout <<"\tNombre de la Empresa: "<< cp[i]->getNombreEmpresa() <<endl;
							cout <<"\tSitio Web: "<< (cp[i]->getWeb()) <<endl;
						}
						menu_screen();
						cin >> op;
						break;
					case 7:
						//Listar los contactos que son colegas
						system("cls");
						cout <<"Datos del Contacto:::: "<<endl;
						for(int i=0;i<count_c;i++){
							cout <<"_____________________________________ "<<endl;
							cout <<"\tEl nombre es: "<< cc[i]->getNombre() <<endl;
							cout <<"\tEl Celular es: "<< cc[i]->getCelular() <<endl;
							cout <<"\tCorreo Principal: "<< cc[i]->getCorreo1()<<endl;
							cout <<"\tCorreo Segundario: "<< cc[i]->getCorreo2() <<endl;
							cout <<"\tDepartamento: "<< cc[i]->getDepartamento() <<endl;
						}
						menu_screen();
						cin >> op;

						break;
					case 1997:
						system("cls");
						menu_screen();
						cout <<"Escoger la opción: ";cin >> op;

						break;
					default:
						system("cls");
						cout << "Menu no valido!!"<<endl;
						cout <<"Escoger la opción: ";cin >> op;
				}
			}while(op != 8);
	}catch(...){
		cout<<"algo salio mal"<<endl;
	}
}

int main() {
	// se llama al metodo menu() para realizar las acciones del programa.
	menu(1997/*Valor 1997 para setear el menu*/);
	cout << "¡¡¡Has salido!!!" << endl;

	return 0;
}
