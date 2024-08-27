// definições das classes
using namespace std;
#include <iostream>

// Classe Mãe
class Veiculo
{

protected:
    string nome;

public:
    Veiculo(const char *nome)
    {

        this->nome = string(nome);
        cout << "Objeto: " << this->nome << " criado" << endl;
    };
    virtual void mover() = 0;

    virtual ~Veiculo()
    {
        cout << "Objeto: " << this->nome << " asdasdasdsad destruído" << endl;
    };
};

// Terrestre:
class Terrestre : public virtual Veiculo
{

public:
    Terrestre(const char *nome) : Veiculo(nome){

                                  };

    void setCap_Pass(int value);
    int getCap_Pass();
    void mover();

    virtual ~Terrestre()
    {
        cout << "Objeto: " << this->nome << " destruído" << endl;
    };

private:
    int cap_pass = 5; // Número máximo de passageiros.

protected:
    Terrestre() : Veiculo(""){};
};

// Aquatico:
class Aquatico : public virtual Veiculo
{
public:
    Aquatico(const char *nome) : Veiculo(nome){

                                 };

    void setCarga_max(int value);
    int getCarga_max();

    void mover();

    virtual ~Aquatico()
    {
        cout << "Objeto: " << this->nome << " destruído" << endl;
    };

private:
    float carga_max = 10; // Carga máxima em toneladas.

protected:
    Aquatico() : Veiculo(""){};
};

// Aereo:
class Aereo : public Veiculo
{
public:
    Aereo(const char *nome) : Veiculo(nome){

                              };
    void setVel_max(int value);
    int getVel_max();
    void mover();

    virtual ~Aereo()
    {
        cout << "Objeto: " << this->nome << " destruído" << endl;
    };

private:
    float vel_max = 100; // Velocidade máxima em km/h.
};

class Anfibio : public Terrestre, public Aquatico
{

    public:
    Anfibio(const char *nome) : Veiculo(nome), Terrestre(nome), Aquatico(nome){

                                                                };

    void mover() {
        Terrestre::mover();
        Aquatico::mover();
    };

};