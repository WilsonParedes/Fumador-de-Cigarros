#pragma once

#include <iostream>


using namespace std;

class BitacoraP {
private:
    string NoProceso;
    string TemaEjecucion;
    string pp;
    string tiempoejecución;
    string estadoproceso;
    string tiempopendiente;
    int hijopendiente;
    string enumInsumos;

public:

    BitacoraP(string NoProceso, string TemaEjecucion, string pp, string tiempoejecucion, string tiempopendiente, string estadoproceso, int hijopendiente, string enumInsumos) {
        this->NoProceso = NoProceso;
        this->TemaEjecucion = TemaEjecucion;
        this->pp = pp;
        this->tiempoejecución = tiempoejecucion;
        this->estadoproceso = estadoproceso;
        this->tiempopendiente = tiempopendiente;
        this->hijopendiente = hijopendiente;
        this->enumInsumos = enumInsumos;

        }

    void setNoProceso(string NoProceso) {
        this->NoProceso = NoProceso;
    }
    void setTemaEjecucion(string TemaEjecucion) {
        this->TemaEjecucion = TemaEjecucion;
    }
    void setPrioridadProceso(string pp) {

        this->pp = pp;
    }

    void setTiempoEjecucion(string tiempoejecución) {
        this->tiempoejecución = tiempoejecución;
    }

    void setEstadoProceso(string estadoproceso) {
        this->estadoproceso = estadoproceso;
    }

    void setTiempoPendiente(string tiempopendiente) {
        this->tiempopendiente = tiempopendiente;
    }

    void setHijoPendiente(int hijopendiente) {
        this->hijopendiente = hijopendiente;
    }

    void setEnumInsumos(string enumInsumos) {
        this->enumInsumos = enumInsumos;
    }

    string getNoProceso() {
        return NoProceso;
    }
    string getTemaEjecucion() {
        return TemaEjecucion;
    }
    string getPrioridadProceso() {
        return pp;
    }
    string getTiempoEjecucion() {
        return tiempoejecución;
    }
    string getEstadoProceso() {
        return estadoproceso;
    }

    string getTiempoPendiente() {
        return tiempopendiente;
    }

    string getEnumInsumos() {
        return enumInsumos;
    }

    int getHijoPendiente() {
        return hijopendiente;
    }

    string toString() {
        return NoProceso + "\t\t" + " | " + TemaEjecucion + "\t\t" + " | " + pp + "\t\t" + " | " + tiempoejecución + "\t\t\t" + " | " + tiempopendiente + "\t\t | " + estadoproceso + "\t\t\t | " + enumInsumos;
    }



};