//
// Created by MnLCz on 16/2/2021.
//

#pragma once
#include <vector>
#include "TanqueDeAgua.h"

namespace UNDAV_CONTROLADOR
{
    class Controlador
    {
    private:
        int cantidadMaxima;
        std::vector<UNDAV_TANQUE::Tanque> tanques;
    public:
        explicit Controlador(int capacidad);
        Controlador(int capacidad, std::vector<UNDAV_TANQUE::Tanque>* tanques);
        Controlador(int capacidad, UNDAV_TANQUE::Tanque* tanque);

        int getCantidadMaxima() const;
        int getCantidadTanques() const;
        float getCaudalTotal() const;
        float getCapacidadTotal() const;
        int getTanquesVacios() const;
        int getTanquesLlenos() const;

        std::vector<UNDAV_TANQUE::Tanque> getTanques();
        void LlenarTanques();
        void VaciarTanques();
        void AgregarTanque(UNDAV_TANQUE::Tanque* tanque);
        void QuitarTanque(UNDAV_TANQUE::Tanque* tanque);
        void QuitarTanquesLlenos();
        void QuitarTanquesVacios();
        void QuitarTodos();

    };
};