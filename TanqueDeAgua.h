//
// Created by MnLCz on 13/2/2021.
//

// TODO: validar en los contructores que el caudal no pueda superar la capacidad.
#pragma once

namespace UNDAV_TANQUE
{
    class Tanque
    {
    private:
        float capacidad;
        float caudal;
    public:
        Tanque() : capacidad(0), caudal(0){};
        explicit Tanque(float capacidad) : capacidad(capacidad), caudal(0){};
        Tanque(float capacidad, float caudal) : capacidad(capacidad), caudal(caudal){};

        float getCapacidad() const;
        float getCaudal() const;
        bool SonIguales(Tanque* tanque) const;
        bool EstaVacio() const;
        bool EstaLleno() const;

        void setCapacidad(float capacidad);
        void AumentarCaudal(float caudal);
        void ReducirCaudal(float caudal);
        void Llenar();
        void Vaciar();
    };
}