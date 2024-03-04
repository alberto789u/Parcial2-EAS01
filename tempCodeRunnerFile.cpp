#include <iostream>
#include <string>
#include <cstdlib> // Función rand().
#include <ctime>   // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x;

class Jugador
{
public:
    int hp;
    int dmg;
    string n;
    Jugador *pJ;
    Jugador();
    Jugador(int h, int dm, string no);

    void atacar(Jugador *jd);
};

int main()
{
    srand(time(0));

    Jugador j2(181, 15, "Pete");
    Jugador j1(150, 18, "Jhon");

    j2.atacar(&j1);
    j1.pJ = &j2;
    while (1)
        if (j1.hp <= 0)
        {
            log(j1.n);
            log("perdió :(");
            log('\n')
                log(j2.n);
            log("ganó :(");
            log('\n') return 0;
        }
        else
        {

            j2.pJ = &j1;
            (j1.atacar(j2.pJ));
        }
    if (j2.hp <= 0)

    {
        log(j2.n);
        log(" perdió :(");
        log('\n')
            log(j1.n);
        log(" ganó :(");
        log('\n') return 0;
    }
    else
    {
        j1.pJ = &j2(j2.atacar(j1.pJ));
    }
    return 0;
}

Jugador::Jugador()
{
    hp = 100;
    dmg = 5;
    n = "no definido";
}

Jugador::Jugador(int h, int dm, string no)
{
    if (h < 0)
        this->hp = 1;
    else if (h > 200)
        this->hp = 200;
    else
        this->hp = h;
    if (dmg < 0)
        this->dmg = 1;
    else if (dm > 20)
        this->dmg = 20;
    else
        this->dmg = dm;
    this->n = no;
}

void Jugador::atacar(Jugador *jd)
{

    int p = (rand() % 5);
    if (p == 0)
    {
        log(n);
        log(" atacó a ");
        log(jd->n);
        log("pero fallo, vida restante de");
        log(jd->n);
        log(" es ");
        log(jd->hp);
        log('\n')
    }
    else
    {
        jd->hp -= dmg;
        log(n);
        log(" atacó a ");
        log(jd->n);
        log(" e hizo ");
        log(dmg);
        log(" de daño, vida restante de ");
        log(jd->n);
        log(" es ");
        log(jd->hp);
        log('\n')
    }
}