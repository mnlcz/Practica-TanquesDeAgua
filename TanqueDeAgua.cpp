//
// Created by MnLCz on 13/2/2021.
//

#include "TanqueDeAgua.h"
#include <iostream>
using std::cout, std::endl;

bool SePuedeLlenar(UNDAV_TANQUE::Tanque* tanque, float caudal);
bool SePuedeVaciar(UNDAV_TANQUE::Tanque* tanque, float caudal);

float UNDAV_TANQUE::Tanque::getCapacidad() const
{
    return this->capacidad;
}

float UNDAV_TANQUE::Tanque::getCaudal() const
{
    return this->caudal;
}

void UNDAV_TANQUE::Tanque::setCapacidad(float capacidad)
{
    Tanque::capacidad = capacidad;
}

void UNDAV_TANQUE::Tanque::AumentarCaudal(float caudal)
{
    if (!SePuedeLlenar(this, caudal))
    {
        cout << "ERROR: no se puede agregar mas de " << this->getCapacidad() - this->getCaudal() << " litros" << endl;
        return;
    }
    else
    {
        this->caudal += caudal;
    }
}

void UNDAV_TANQUE::Tanque::ReducirCaudal(float caudal)
{
    if (!SePuedeVaciar(this, caudal))
    {
        cout << "ERROR: no se puede quitar mas de " << this->getCaudal() << " litros" << endl;
        return;
    }
    else
    {
        this->caudal -= caudal;
    }
}

void UNDAV_TANQUE::Tanque::Llenar()
{
    this->caudal = this->capacidad;
}

void UNDAV_TANQUE::Tanque::Vaciar()
{
    this->caudal = 0;
}

bool UNDAV_TANQUE::Tanque::SonIguales(UNDAV_TANQUE::Tanque *tanque) const
{
    return (tanque->getCaudal() == this->caudal && tanque->getCapacidad() == this->capacidad);
}

bool UNDAV_TANQUE::Tanque::EstaVacio() const
{
    return this->caudal == 0;
}

bool UNDAV_TANQUE::Tanque::EstaLleno() const
{
    return this->caudal == this->capacidad;
}

bool SePuedeLlenar(UNDAV_TANQUE::Tanque* tanque, float caudal)
{
    return (tanque->getCapacidad() >= tanque->getCaudal() + caudal);
}

bool SePuedeVaciar(UNDAV_TANQUE::Tanque* tanque, float caudal)
{
    return (tanque->getCaudal() - caudal >= 0);
}