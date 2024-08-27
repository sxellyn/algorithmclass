#include "veiculo.h"
#include <iostream>
using namespace std;

int main()
{

  // Veiculo *v1 = new Veiculo("Shelby GT500");
  // Terrestre *v2 = new Terrestre("Sportster 2021");
  // Aquatico *v3 = new Aquatico("OceanGate");
  // Aereo *v4 = new Aereo("Boeing 747");

  Veiculo *terr, *aqua, *aereo, *anfi;

  terr = new Terrestre("VT1");
  // ((Terrestre *)terr)->setCap_Pass(45);
  dynamic_cast<Terrestre*>(terr)->setCap_Pass(45);
  
  aqua = new Aquatico("VQ1");
  // ((Aquatico *)aqua)->setCarga_max(12.5);
  dynamic_cast<Aquatico*>(aqua)->setCarga_max(12.5);

  aereo = new Aereo("VA1");
  // ((Aereo *)aereo)->setVel_max(1040.5);
  dynamic_cast<Aereo*>(aereo)->setVel_max(1040.5);

  anfi = new Anfibio("VA1");

  terr->mover();
  aqua->mover();
  aereo->mover();
  anfi->mover();

  delete terr;
  delete aqua;
  delete aereo;
  delete anfi;

  return 0;
};
