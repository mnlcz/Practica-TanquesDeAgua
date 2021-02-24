#include <iostream>
#include "TanqueDeAgua.h"
#include "ControladorDeTanques.h"
#define CAPACIDAD 1000
using namespace UNDAV_TANQUE;
using namespace UNDAV_CONTROLADOR;

void pruebasTanques();
void mostrarInfoTanques(Tanque* tanquePrueba);
void pruebasControlador();
void mostrarInfoControlador(Controlador* controladorPrueba);

int main()
{
    pruebasTanques();
    pruebasControlador();
    return 0;
}

void pruebasTanques()
{
    std::cout << "---------------- PROBANDO TANQUES ----------------" << std::endl;
    // Tanque vacio
    auto tanquePrueba = Tanque(CAPACIDAD);
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "LLENANDO" << std::endl;
    tanquePrueba.Llenar();
    if(tanquePrueba.EstaLleno())
        std::cout << "Tanque lleno" << std::endl;
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "VACIANDO" << std::endl;
    tanquePrueba.Vaciar();
    if(tanquePrueba.EstaVacio())
        std::cout << "Tanque vacio" << std::endl;
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "AGREGANDO 500L" << std::endl;
    tanquePrueba.AumentarCaudal(500);
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "AGREGANDO 1000L (INVALIDO)" << std::endl;
    tanquePrueba.AumentarCaudal(1000);
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "QUITANDO 250L" << std::endl;
    tanquePrueba.ReducirCaudal(250);
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "QUITANDO 1000L (INVALIDO)" << std::endl;
    tanquePrueba.ReducirCaudal(1000);
    mostrarInfoTanques(&tanquePrueba);
    std::cout << "AUMENTANDO CAPACIDAD A 2000L" << std::endl;
    tanquePrueba.setCapacidad(2000);
    mostrarInfoTanques(&tanquePrueba);
}

void mostrarInfoTanques(Tanque* tanquePrueba)
{
    std::cout << "Capacidad: " << tanquePrueba->getCapacidad() << "L" << std::endl;
    std::cout << "Caudal: " << tanquePrueba->getCaudal() << "L" << std::endl;
    std::cout << std::endl;
}

void pruebasControlador()
{
    std::cout << "---------------- PROBANDO CONTROLADORES ----------------" << std::endl;
    // Controlador vacio
    std::cout << "NUEVO CONTROLADOR" << std::endl;
    auto controlador1 = Controlador(10);
    mostrarInfoControlador(&controlador1);
    // Controlador a partir de un tanque
    std::cout << "NUEVO CONTROLADOR" << std::endl;
    auto tanquePruebaLleno = Tanque(1000, 1000);
    auto tanquePruebaVacio = Tanque(1000, 0);
    auto controlador2 = Controlador(5, &tanquePruebaLleno);
    mostrarInfoControlador(&controlador2);
    // Controlador a partir de un vector de tanques
    std::cout << "NUEVO CONTROLADOR" << std::endl;
    std::vector<Tanque> vectorTanques;
    vectorTanques.reserve(5);
    for(int i = 0; i < 5; i++)
        vectorTanques.emplace_back(1000, 1000);
    auto controlador3 = Controlador(10, &vectorTanques);
    mostrarInfoControlador(&controlador3);
    std::cout << "AGREGANDO TANQUE" << std::endl;
    controlador3.AgregarTanque(&tanquePruebaLleno);
    mostrarInfoControlador(&controlador3);
    std::cout << "QUITANDO TANQUE" << std::endl;
    controlador3.QuitarTanque(&tanquePruebaLleno);
    mostrarInfoControlador(&controlador3);
    std::cout << "VACIANDO TANQUES" << std::endl;
    controlador3.VaciarTanques();
    mostrarInfoControlador(&controlador3);
    std::cout << "LLENANDO TANQUES" << std::endl;
    controlador3.LlenarTanques();
    mostrarInfoControlador(&controlador3);
    std::cout << "QUITANDO TODOS LOS TANQUES" << std::endl;
    controlador3.QuitarTodos();
    mostrarInfoControlador(&controlador3);
    std::cout << "AGREGANDO 2 TANQUES VACIOS" << std::endl;
    controlador3.AgregarTanque(&tanquePruebaVacio);
    controlador3.AgregarTanque(&tanquePruebaVacio);
    mostrarInfoControlador(&controlador3);
    std::cout << "AGREGANDO 2 TANQUES LLENOS" << std::endl;
    controlador3.AgregarTanque(&tanquePruebaLleno);
    controlador3.AgregarTanque(&tanquePruebaLleno);
    mostrarInfoControlador(&controlador3);
    std::cout << "QUITANDO TANQUES VACIOS" << std::endl;
    controlador3.QuitarTanquesVacios();
    mostrarInfoControlador(&controlador3);
    std::cout << "QUITANDO TANQUES LLENOS" << std::endl;
    controlador3.QuitarTanquesLlenos();
    mostrarInfoControlador(&controlador3);
}

void mostrarInfoControlador(Controlador* controladorPrueba)
{
    std::cout << "El controlador posee una capacidad de " << controladorPrueba->getCantidadMaxima() << " tanques" << std::endl;
    std::cout << "El controlador posee " << controladorPrueba->getCantidadTanques() << " tanques" << std::endl;
    std::cout << "Tanques vacios: " << controladorPrueba->getTanquesVacios() << std::endl;
    std::cout << "Tanques llenos: " << controladorPrueba->getTanquesLlenos() << std::endl;
    std::cout << "El controlador posee un caudal total de " << controladorPrueba->getCaudalTotal() << " litros" << std::endl;
    std::cout << "El controlador puede almacenar " << controladorPrueba->getCapacidadTotal() << " litros" << std::endl;

    std::cout << std::endl;

}