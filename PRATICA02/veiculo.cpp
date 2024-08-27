//  implementações de métodos das classes.
#include <iostream>
#include "veiculo.h"

// Veiculo:
// void Veiculo::mover()
// {
//     cout << "O veiculo " << this->nome << " Moveu" << endl;
// };

// Terrestre:
int Terrestre::getCap_Pass()
{
    return cap_pass;
};
void Terrestre::setCap_Pass(int value)
{
    cap_pass = value;
};
void Terrestre::mover()
{
    cout << "O veiculo " << this->nome << " (terrestre) Moveu" << endl;
};
// Aquatico:

int Aquatico::getCarga_max()
{
    return carga_max;
};
void Aquatico::setCarga_max(int value)
{
    carga_max = value;
};
void Aquatico::mover()
{
    cout << "O veiculo " << this->nome << " (aquatico) Moveu" << endl;
};
// Aereo:

int Aereo::getVel_max()
{
    return vel_max;
};
void Aereo::setVel_max(int value)
{
    vel_max = value;
};

void Aereo::mover()
{
    cout << "O veiculo " << this->nome << " (aereo) Moveu" << endl;
};