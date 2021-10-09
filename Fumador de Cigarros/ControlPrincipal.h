#pragma once
#include "BitacoraP.h";
#include<vector>;
#include<fstream>;
#include<iostream>;
#include<iomanip>;
#include<stdlib.h>;
#include<cstring>;
#include<istream>;
#include<string>;
#include <iostream>
#include<windows.h>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class ControlPrincipal
{

/*DECLARACIÓN DE VARIABLES PARA EL FUNCIONAMIENTO PRINCIPAL DEL PROYECTO*/
public:
	ifstream l, car1; 
	ofstream in, car;
	vector<BitacoraP> almacen;
	vector<BitacoraP> ContenedorTXT;/*ALMACENA EL ARRAY DE LA BITACORA*/
	vector<BitacoraP> ContenedorTXTAuxiliar;
	vector<string> Insumos;
	string insumoGloblal = "";
	int conteGlobal;

/*CONSTRUCTOR PRINCIPAL*/
public:
	ControlPrincipal() {

	};

	/*ALMACENA EN EL ARRAY LOS DOS INSUMOS NECESARIOS QUE GENERA EL AGENTE*/
	void agregarInsumos(string insumo) {
		Insumos.push_back(insumo);
	}

	/*PROCEDIMIENTO QUE ALMACENA TODOS LOS PROCESOS PRINCIPALES Y A LOS HIJOS, Y SERÁ NUESTRA BITACORA PRNCIPAL QUE SE MOSTRARÁ AL USUARIO*/
	void agregarProceso(BitacoraP bitacora) {
		almacen.push_back(bitacora);

	}


	/*PROCEDIMIENTO ENCARGADO DE ALMACENAR EL TXT EN EL ARRAY CONTENEDORTXT, ESTO LLEVA EL CONTROL DE LA BITACORA COMO UN AUXILIAR INTERNO*/
	void agregarProcesoaContenedorTXT(BitacoraP bitacora) {
		ContenedorTXT.push_back(bitacora);
	}

	/*ESTE PROCEDIMIENTO, ALMACENARÁ EN UN ARRAY INDEPENDIENTE UNICAMENTE A LOS HIJOS, CON LA FINALIDAD DE ATENDERLOS EN ORDEN DE PRIORIODAD SEGÚN EL PROCESOS 
	PRINCIPAL
	void agregarProcesoAuxiliar(BitacoraP bitacora) {

		ContenedorTXTAuxiliar.push_back(bitacora);
	}*/



	/*ESTE PROCEDIMIENTO, IMPRIME LO QUE SE ENCUENTRA ALMACENADO EN EL VECTOR ALMACEN, CON LA FINALIDAD DE MOSTRAR AL USUARIO A TODOS LOS
	PROCESOS Y SUS INSUMOS ASIGNADOS*/
	void mostrarProcesos() {
		system("cls");
		cout << "LISTADO DE PROCESOS PENDIENTES:\n\n";
		cout << "No. Proceso\t | Tema\t\t\t | Prioridad\t | T. de Ejecución\t | T. Pendiente\t | Estado del Proceso\t\t | Insumos  ";
		cout << endl;
		for (int i = 0; i < almacen.size(); i++) {
			cout << almacen[i].toString();
			cout << endl;
		}
		cout << endl;
	}



	/*MUESTRA LO QUE SE ALMACENÓ EN EL VECTOR CONTENEDORTXT SOLO A LOS PROCESOS PRINCIPALES, NO TIENE HIJOS Y ADICIONAL SOLO ES PARA CONTROL
	INTERNO Y APOYO PARA LOS PROGRAMADORES, CON EL FIN DE VISUALIZAR EN UN ARRAY INDEPENDIENTE LOS PROCESOS PRINCIPALES*/
	void mostrarProcesosContenedroTXT() {
		system("cls");
		cout << "No. Proceso\t | Tema\t\t\t | Prioridad\t | T. de Ejecución\t | T. Pendiente\t | Estado del Proceso\t\t | Insumos  ";
		cout << endl;
		for (int i = 0; i < ContenedorTXT.size(); i++) {
			cout << ContenedorTXT[i].toString();
			cout << endl;

		}
		cout << endl;
	}

	/*ESTA PROCEDIMIENTO, LIMPIARA EL VECTOR INSUMOS, CADA VEZ QUE SE TERMINE DE EJECUTAR UN PROCESO*/
	void limpiarInsumos() {
		Insumos.clear();
	}

	/*ESTE PROCEDIMIENTO, MUESTRA EN CONSOLA AL USUARIO, TODOS LOS INSUMOS GENERADOS POR VEZ*/
	void MostrarInsumos() {
		for (int i = 0; i < Insumos.size(); i++) {
			cout << Insumos[i] + "\n";
		}
	}

	void EliminarElementoVectorAlmacen(int index) {
		almacen.erase(almacen.begin()+index);
	}

	/*PROCEDIMIENTO ENCARGADO DE LEER EL FICHERO E IMPRIMIRLO EN CONSOLA*/
	void LecturadeFichero() {
		
		/*ALMACENA LOS DATOS DEL TXT DE FORMA SEPARADA, CON LA FINALIDAD DE ENVIARLO AL OBJETO CONTROLPRINCIPAL Y QUE LO GUARDE EN EL ARRAY CONTENEDORTXT */
		string temp;
		string  animacion = "";
		string temNoProceso, tempTema, tempEstado, tempPaternidad, tempTiempo, tempAleatorio;
		string pp;
		string leer; // SE DECLARAN 2 VARIABLES UNA PARA ABRIR EL FICHERO Y OTRA PARA ALMACENAR LA INFORMACIÓN QUE SE ENCUENTRA EN EL FICHERO
		int cont = 0;
		l.open("PCB.txt", ios::in);//SE ABRE EL FICHERO
		if (l.fail()) {// MUESTRA ERROR EN CASO EL FICHERO ESTE DAÑADO O NO EXISTA
			cout << endl << "El archivo no se pudo abrir, puede que este danado o no exista, compruebe que en la carpeta se encuentre el archivo PCB.txt" << endl;

			exit(1);
		}// FIN DE ERROR
		system("cls");

		while (!l.eof()) {//LECTURA DEL FICHERO
			cont = 0;

			getline(l, leer);// ALMACENA LA INFORMACIÓN DEL FICHERO EN LA VARIABLE LEER 

			stringstream input_stringstream(leer);

			while (getline(input_stringstream, temp, '|')) {

				if (cont == 0) {
					temNoProceso = temp;
				}if (cont == 1) {
					tempTema = temp;
				}if (cont == 2) {
					pp = temp;
				}if (cont == 3){
					tempTiempo = temp;
				}

				cont++;
			}
			tempAleatorio = GeneraNumeroAleatorio();
			animacion = animacion + ".";
			cout << "SE ESTAN ASIGNADO INSUMOS A LOS PROCESOS PRINCIPALES, PUEDE DEMORAR UNOS SEGUNDOS"+ animacion;
			Sleep(1300);
			system("cls");
			agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(temNoProceso, tempTema, pp, tempTiempo, tempTiempo, "NUEVO", 0, tempAleatorio));
			agregarProceso(BitacoraP::BitacoraP(temNoProceso, tempTema, pp, tempTiempo, tempTiempo, "NUEVO", 0, tempAleatorio));
		}l.close();	// FIN DE LA LECTURA DEL ARCHIVO	

		cout << "Lectura del TXT cargada con éxito" << endl;
		/*mostrarProcesosContenedroTXT();*/
		/*SE LLAMA AL PROCESO ENCARGADO DE ORDENAR POR PRIORIDAD, LUEGO DE SER ASIGNADO LOS INSUMOS*/
		OrdenArrayPorPrioridadContenedorTXT();/*ORDENA EL VECTOR CONTENEDORTXT*/
		OrdenArrayPorPrioridadAlmacen();/*ORDENA EL VECTOR ALMACEN*/
		mostrarProcesos();
		/*LUEGO SE LLAMA AL PROCESO CREAR HIJOS, CON LA FINALIDAD DE QUE CREE LOS SUBPROCESOS SEGÚN EL REQUERIMIENTO INCREMENTANDO EN UNO */
		/*crearHijosalosProcesos();*/
	}



	/*GENERA NUMEROS ALEATORIOS PARA ASIGNAR A LOS PROCESOS, 1 = TABACO, 2 = PAPEL, 3 = CERILLAS*/
	string GeneraNumeroAleatorio() {
		srand(time(NULL)); 
		int aleatorio = (rand() % 3)+1;
		if (aleatorio == TABACO) {
			return "TABACO";
		}
		else if(aleatorio==PAPEL){
			return "PAPEL";
		}
		else if (aleatorio == CERILLAS) {
			return "CERILLAS";
		}
		
		
	}

	/*ESTE PROCESO, ORDENA POR ORDEN DE PRIORIODAD EL VECTOR GENERADO POR CONTENEDORTXT, QUE SE ALIMENTA DEL ARCHIVO DEL INGENIERO*/
	void OrdenArrayPorPrioridadContenedorTXT() {
		string temp, temp1;
		int contenedor = 0;
		int contendor1 = 0;

		/*Metodo burbuja*/
		for (int j = 0; j < ContenedorTXT.size() - 1; j++) {

			for (int i = 0; i < ContenedorTXT.size() - 1; i++) {
				contenedor = atoi(ContenedorTXT[i].getPrioridadProceso().c_str());
				contendor1 = atoi(ContenedorTXT[i + 1].getPrioridadProceso().c_str());
				if (contenedor > contendor1) {
					string tempProceso = ContenedorTXT[i].getNoProceso();
					string tempTema = ContenedorTXT[i].getTemaEjecucion();
					string tempPP = ContenedorTXT[i].getPrioridadProceso();
					string tempTiempo = ContenedorTXT[i].getTiempoEjecucion();
					string tempEstado = ContenedorTXT[i].getEstadoProceso();
					string tempInsumos = ContenedorTXT[i].getEnumInsumos();
					ContenedorTXT[i] = ContenedorTXT[i + 1];
					ContenedorTXT[i + 1] = BitacoraP::BitacoraP(tempProceso, tempTema, tempPP, tempTiempo, tempTiempo, tempEstado, 0,tempInsumos);
				}
			}
		}

	}


	/*ESTE PROCESO, ORDENA POR ORDEN DE PRIORIODAD EL VECTOR GENERADO POR CONTENEDORTXT, QUE SE ALIMENTA DEL ARCHIVO DEL INGENIERO*/
	void OrdenArrayPorPrioridadAlmacen() {
		string temp, temp1;
		int contenedor = 0;
		int contendor1 = 0;

		/*Metodo burbuja*/
		for (int j = 0; j < almacen.size() - 1; j++) {

			for (int i = 0; i < almacen.size() - 1; i++) {
				contenedor = atoi(almacen[i].getPrioridadProceso().c_str());
				contendor1 = atoi(almacen[i + 1].getPrioridadProceso().c_str());
				if (contenedor > contendor1) {
					string tempProceso = almacen[i].getNoProceso();
					string tempTema = almacen[i].getTemaEjecucion();
					string tempPP = almacen[i].getPrioridadProceso();
					string tempTiempo = almacen[i].getTiempoEjecucion();
					string tempEstado = almacen[i].getEstadoProceso();
					string tempInsumos = almacen[i].getEnumInsumos();
					almacen[i] = almacen[i + 1];
					almacen[i + 1] = BitacoraP::BitacoraP(tempProceso, tempTema, tempPP, tempTiempo, tempTiempo, tempEstado, 0, tempInsumos);
				}
			}
		}

	}



	/*ESTE PROCEDIMIENTO, SERÁ EL ENCARGADO DE REALIZAR LA ASIGNACIÓN DE INSUMOS DE CADA PROCESO, YA QUE NO SE PODRÁN EJECUTAR POR ORDEN DE
	PRIORIDAD, SINO QUE POR INSUMOS ASIGNADOS*/
	void AgenteColocaInsumos() {
		system("cls");
		cout << "EL AGENTE ESTA GENERANDO DOS INSUMOS DE FORMA ALEATORIA\n";

		if (conteGlobal > 4) {
			limpiarInsumos();
			conteGlobal = 0;
			AgenteColocaInsumos();
		}
		else {
			//limpiarInsumos();
			
			string insumo, tempInsumo = "";
			if (!Insumos.empty()) {
				for (int i = 1; i < 2; i++) {
					insumo = GeneraNumeroAleatorio();
					if (insumo._Equal(insumoGloblal)) {
						Sleep(500);
						AgenteColocaInsumos();
					}
					else {
						Sleep(500);
						agregarInsumos(insumo);/*VECTOR INSUMOS*/
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					insumo = GeneraNumeroAleatorio();
					if (insumo._Equal(tempInsumo)) {
						Sleep(500);
						limpiarInsumos();
						AgenteColocaInsumos();

					}
					else {
						Sleep(500);
						tempInsumo = insumo;
						agregarInsumos(insumo);/*VECTOR INSUMOS*/
						
					}
				}
			}

		}
		
		
	}

	

	/*PROCEDIMIENTO QUE DETERMINA SI SE EJECUTA O NO EL PROCESO ADECUADO, Y DEVUELVE LA POSICIÓN EXACTA DEL PROCESO QUE SE EJECUTARÁ*/
	int UbicaciondeProcesoqueseejecuta() {
		bool salida = true;
		int conteo =0;
		/*SE EVALUA SI EL ALMACEN ESTA LLENO*/
		if (!almacen.empty()) {
			if (almacen.size() != 1) {/*EVALUA SI ALMACEN SOLO TIENE UN VALOR*/
				for (int i = 0; i < almacen.size(); i++) {
					if (salida) {
						for (int j = 0; j < 1; j++) {
							if (!almacen[i].getEnumInsumos()._Equal(Insumos[0]) && !almacen[i].getEnumInsumos()._Equal(Insumos[1])) {
								salida = false;
							}
							else {
								break;
							}
						}
						conteo++;
						if (conteo == almacen.size()&& salida) {
							conteo = -2;
						}

					}
					else {
						break;
					}
				}
			}
			else {
				for (int i = 0; i < almacen.size(); i++) {
					if (salida) {
						for (int j = 0; j < 1; j++) {
							if (!almacen[i].getEnumInsumos()._Equal(Insumos[0]) && !almacen[i].getEnumInsumos()._Equal(Insumos[1])) {
								salida = false;
								conteo++;
							}
							else {
								ControlDeProcesamientoCentral();
							}
						}
					}
					else {
						break;
					}
				}
			}
			
		}
		else {
			system("cls");
			cout << "YA NO HAY PROCESOS PENDIENTES\n";
			Sleep(1000);
		}
		return conteo;
	}


	/*ESTE ALGORITMO ES LA LÓGICA CENTRAL DEL PROGRAMA, EJECUTRÁ POR VEZ, CADA PROCESOS DEPENDIENDO DE LOS INSUMOS QUE GENERÉ EL AGENTE*/
	void ControlDeProcesamientoCentral() {
		while (!almacen.size()==0) {
			int posicion = 0;
			do {
				AgenteColocaInsumos(); /*EL AGENTE GENERA INSUMOS Y LOS ALMACENA EN EL VECTOR INSUMOS*/
				conteGlobal++;
				posicion = UbicaciondeProcesoqueseejecuta(); /*SE BUSCA LA POSICIÓN DEL PROCESO DENTRO DEL VECTOR CONTENEDORTXT DONDE ESTA EL INSUMO FALTANTE*/
			} while (posicion == -2);

			conteGlobal = 0;

			int casteo, casteo2, k = 0;
			bool salida = false;
			int prioridad = 0;
			int tiempoacumulado = 0;
			int tiemporestante = 0;
			int dormir = 1000;
			string temporal;

			system("cls");
			cout << "PROCESOS PENDIENTES:\n";
			mostrarProcesos();

			/*ESTE FOR, INGRESA A LA POSICIÓN DEL PROCESOS DENTRO DEL VECTOR QUE SE VA A EJECUTAR*/
			for (int i = 0; i < almacen.size(); i++) {
				/*EL CONDICIONAL INDICA SI LA POSICIÓN ES LA CORRECTA, SI ES VERDADERA, EMPEZARÁ LA EJECUCIÓN DEL PROCESO Y POSTERIORMENTE SU ELIMINACIÓN*/
				if ((posicion - 1) == i) {
					temporal = almacen[i].getTiempoEjecucion(); /*ALMACENA EL TIEMPO DEL PROCESO*/
					casteo = atoi(temporal.c_str());
					/*EVALUAMOS LOS TIEMPOS DE EJECUCIÓN*/
					if (casteo <= 0) {
					}
					else {
						/*SE ACTUALIZA EL ESTADO DEL PROCESO A EJECUTAR Y SE ALMACENA EN LA BITACORA*/
						if ((atoi(almacen[i].getTiempoPendiente().c_str())) != 0) {
							/*SE AGREGA A LA BITACORA EL ESTADO LISTO*/
							agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoEjecucion(), "LISTO", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));
							mostrarProcesos();/*SE MUESTRAN PROCESOS PENDIENTES*/
							almacen[i].setEstadoProceso("LISTO"); /*SE CAMBIA EL ESTADO DEL PROCESO PENDIENTE*/
							mostrarProcesos();
							if (casteo>20) {
								cout << "\nCARGANDO PROCESO AL CPU MAYOR 20 SEGUNDOS\n" << endl; /*SE CARGA EL PROCESO*/
								Sleep(2000);
								almacen[i].setEstadoProceso("EJECUCIÓN");
								casteo2 = atoi(temporal.c_str());
								//casteo2 = atoi(temporal.c_str() - atoi(temporal.c_str()));//tiempo restante
								agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoEjecucion(), "EJECUCION", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));

								/*SE AGREGA EL ESTADO EN LA BITACORA*/
								if (casteo <= 0) {
									casteo = 1;
									dormir = 1000;
								}
								for (int k = 0; k < 20; k++) {
									cout << "\n\nINSUMOS EN LA MESA:\n";
									MostrarInsumos(); /*SE IMPRIME EN CONSOLA LO QUE CONTIENE EL VECTOR INSUMOS */
									cout << endl << "\n\nSE ESTA EJECUTANDO EL PROCESO PRINCIAPL " + almacen[i].getNoProceso() + " : --> ";
									cout << (k + 1);
									casteo2--;
									almacen[i].setTiempoPendiente(to_string(casteo2));
									Sleep(dormir);
									mostrarProcesos();
								}
								almacen[i].setTiempoEjecucion(to_string(casteo2));
								cout << endl << "PROCESO           --> " + almacen[i].getNoProceso() + " \nTIEMPO PENDIENTE  --> " << almacen[i].getTiempoPendiente() + "\nTIEMPO EJECUTADO  --> 20" +  "\nESTADO            --> BLOQUEADO" + "\nSE DEJA INSUMO    --> " + almacen[i].getEnumInsumos() << endl;
								//Sleep(4000);
								system("pause");
								system("cls");
								agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoPendiente(), "BLOQUEADO", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));
								agregarProceso(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoPendiente(), "BLOQUEADO", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));
								almacen[i].setEstadoProceso("BLOQUEADO");
								almacen[i].setTiempoPendiente(to_string(casteo2));
								mostrarProcesos();
								insumoGloblal = almacen[i].getEnumInsumos();
								limpiarInsumos();
								agregarInsumos(insumoGloblal);
								EliminarElementoVectorAlmacen(posicion - 1);
							}
							else {
								
								cout << "\nCARGANDO PROCESO AL CPU\n" << endl; /*SE CARGA EL PROCESO*/
								Sleep(2000);
								almacen[i].setEstadoProceso("EJECUCIÓN");
								casteo2 = atoi(temporal.c_str());
								//casteo2 = atoi(temporal.c_str() - atoi(temporal.c_str()));//tiempo restante
								agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoEjecucion(), "EJECUCIÓN", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));

								/*SE AGREGA EL ESTADO EN LA BITACORA*/
								if (casteo <= 0) {
									casteo = 1;
									dormir = 1000;
								}
								for (int k = 0; k < casteo; k++) {
									cout << "\n\nINSUMOS EN LA MESA:\n";
									MostrarInsumos(); /*SE IMPRIME EN CONSOLA LO QUE CONTIENE EL VECTOR INSUMOS */
									cout << endl << "\n\nSE ESTA EJECUTANDO EL PROCESO PRINCIAPL " + almacen[i].getNoProceso() + " : --> ";
									cout << (k + 1);
									casteo2--;
									almacen[i].setTiempoPendiente(to_string(casteo2));
									Sleep(dormir);
									mostrarProcesos();
								}
								cout << endl << "PROCESO           --> " + almacen[i].getNoProceso() + " \nTIEMPO PENDIENTE  --> " << almacen[i].getTiempoPendiente() + "\nTIEMPO EJECUTADO  --> " + almacen[i].getTiempoEjecucion() + "\nESTADO            --> TERMINADO" + "\nSE DEJA INSUMO    --> " + almacen[i].getEnumInsumos() << endl;

								system("pause");
								//Sleep(4000);
								system("cls");
								agregarProcesoaContenedorTXT(BitacoraP::BitacoraP(almacen[i].getNoProceso(), almacen[i].getTemaEjecucion(), almacen[i].getPrioridadProceso(), almacen[i].getTiempoEjecucion(), almacen[i].getTiempoPendiente(), "TERMINADO", almacen[i].getHijoPendiente(), almacen[i].getEnumInsumos()));
								almacen[i].setEstadoProceso("TERMINADO");
								almacen[i].setTiempoPendiente(to_string(casteo2));
								mostrarProcesos();
								insumoGloblal = almacen[i].getEnumInsumos();
								limpiarInsumos();
								agregarInsumos(insumoGloblal);
								EliminarElementoVectorAlmacen(posicion - 1);
							}
							


						}/*SE AGREAGA A LA BITACORA EL ESTADO EJECUCIÓN*/
						else {

						}


						
					} 

				}
			}

		}
	}


	enum Insumos {
		TABACO = 1,
		PAPEL = 2,
		CERILLAS = 3
	};
	

};



