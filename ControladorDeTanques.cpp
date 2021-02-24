//
// Created by MnLCz on 16/2/2021.
//

#include "ControladorDeTanques.h"
#include <iostream>
using std::cout, std::endl;

UNDAV_CONTROLADOR::Controlador::Controlador(int capacidad)
{
    this->cantidadMaxima = capacidad;
}

UNDAV_CONTROLADOR::Controlador::Controlador(int capacidad, std::vector<UNDAV_TANQUE::Tanque> *tanques)
{
    this->tanques = *tanques;
    this->cantidadMaxima = capacidad;
}

UNDAV_CONTROLADOR::Controlador::Controlador(int capacidad, UNDAV_TANQUE::Tanque *tanque)
{
    this->cantidadMaxima = capacidad;
    std::vector<UNDAV_TANQUE::Tanque> vectorTanques;
    vectorTanques.push_back(*tanque);
    this->tanques = vectorTanques;
}

int UNDAV_CONTROLADOR::Controlador::getCantidadMaxima() const
{
    return this->cantidadMaxima;
}

int UNDAV_CONTROLADOR::Controlador::getCantidadTanques() const
{
    return this->tanques.size();
}

std::vector<UNDAV_TANQUE::Tanque> UNDAV_CONTROLADOR::Controlador::getTanques()
{
    return this->tanques;
}

void UNDAV_CONTROLADOR::Controlador::AgregarTanque(UNDAV_TANQUE::Tanque *tanque)
{
    if(this->tanques.size() == this->cantidadMaxima)
    {
        cout << "No se puede agregar mas tanques al controlador" << endl;
        return;
    }
    else
    {
        this->tanques.push_back(*tanque);
    }
}

void UNDAV_CONTROLADOR::Controlador::QuitarTanque(UNDAV_TANQUE::Tanque *tanque)
{
    if(this->cantidadMaxima == 0)
    {
        cout << "El controlador no posee ningun tanque" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < this->cantidadMaxima; i++)
        {
            UNDAV_TANQUE::Tanque *tanqueAUX = &this->tanques[i];
            if (tanque->SonIguales(tanqueAUX))
            {
                this->tanques.erase(tanques.begin() + i);
                break;
            }
            else
            {
                cout << "Tanque no encontrado" << endl;
            }
        }
    }
}

float UNDAV_CONTROLADOR::Controlador::getCaudalTotal() const
{
    float total = 0;
    for(int i = 0; i < this->getCantidadTanques(); i++)
    {
        total += this->tanques[i].getCaudal();
    }

    return total;
}

float UNDAV_CONTROLADOR::Controlador::getCapacidadTotal() const
{
    float total = 0;
    for(int i = 0; i < this->getCantidadTanques(); i++)
    {
        total += this->tanques[i].getCapacidad();
    }

    return total;
}

int UNDAV_CONTROLADOR::Controlador::getTanquesVacios() const
{
    int tanquesVacios = 0;
    for(int i = 0; i < this->getCantidadTanques(); i++)
    {
        if(this->tanques[i].EstaVacio())
            tanquesVacios++;
    }
    return tanquesVacios;
}

int UNDAV_CONTROLADOR::Controlador::getTanquesLlenos() const
{
    int tanquesLlenos = 0;
    for(int i = 0; i < this->getCantidadTanques(); i++)
    {
        if(this->tanques[i].EstaLleno())
            tanquesLlenos++;
    }
    return tanquesLlenos;
}

void UNDAV_CONTROLADOR::Controlador::LlenarTanques()
{
    for(int i = 0; i < this->getCantidadTanques(); i++)
        this->tanques[i].Llenar();
}

void UNDAV_CONTROLADOR::Controlador::VaciarTanques()
{
    for(int i = 0; i < this->getCantidadTanques(); i++)
        this->tanques[i].Vaciar();
}

void UNDAV_CONTROLADOR::Controlador::QuitarTanquesLlenos()
{
    int contadorAUX = 0; // El tamaño del vector se modifica al quitarse un tanque, y por lo tanto, el indice usado en la linea 143 no seria correcto.
    int cantidadTanques = this->getCantidadTanques(); // Si se pusiera directamente el getCantidadTanques dentro del for, este cambiaria a medida que se quitan tanques.
    for(int i = 0; i < cantidadTanques; i++)
    {
        UNDAV_TANQUE::Tanque tanqueAUX = this->tanques[i - contadorAUX]; // Restando la variable auxiliar permite un seguimiendo a los indices luego de eliminar un tanque.
        if(tanqueAUX.EstaLleno())
            this->QuitarTanque(&tanqueAUX);
            contadorAUX++;
    }
}

void UNDAV_CONTROLADOR::Controlador::QuitarTanquesVacios() // Ver comentarios de la funcion QuitarTanquesLlenos()
{
    int contadorAUX = 0;
    int cantidadTanques = this->getCantidadTanques();
    for(int i = 0; i < cantidadTanques; i++)
    {
        UNDAV_TANQUE::Tanque tanqueAUX = this->tanques[i - contadorAUX];
        if(tanqueAUX.EstaVacio())
            this->QuitarTanque(&tanqueAUX);
            contadorAUX++;
    }
}

void UNDAV_CONTROLADOR::Controlador::QuitarTodos()
{
    this->tanques = {};
}