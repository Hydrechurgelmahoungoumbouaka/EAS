
#include <stdio.h>
#include <string.h>
#include "morador.h"
#include "area.h"
#include "reserva.h"

#define MAX_MORADORES 100
#define MAX_AREAS 10
#define MAX_RESERVAS 100

int getMoradorGrupo(Morador *grupo, int nGrupo, char *cpf)
{

    for (int i = 0; i < nGrupo; i++)
    {
        if (verificaCPFMorador(grupo[i], cpf))
        {
            return i;
        }
    }

    return -1;
}

int getAreaGrupo(Area *grupo, int nGrupo, char *id)
{

    for (int i = 0; i < nGrupo; i++)
    {
        if (verificaIdArea(grupo[i], id))
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int nMoradores, nAreas, nReservas, nReservasSol = 0;
    Morador grupoMoradores[MAX_MORADORES];
    Area grupoAreas[MAX_AREAS];
    Reserva grupoReservas[MAX_RESERVAS];

    scanf("%d\n", &nAreas);
    for (int i = 0; i < nAreas; i++)
    {
        grupoAreas[i] = lerArea();

        
    }

    scanf("%d\n", &nMoradores);
    for (int i = 0; i < nMoradores; i++)
    {
        grupoMoradores[i] = lerMorador();
    }

    scanf("%d\n", &nReservas);
    char idArea[MAX_TAM_ID];
    char cpf[MAX_TAM_CPF];
    Data data;
    int qtdConvidados;

    for (int i = 0; i < nReservas; i++)
    {
        scanf("%s\n", idArea);
        scanf("%s\n", cpf);
        data = lerData();
        scanf("%d\n", &qtdConvidados);

        int posMorador, posArea;
        Morador morador;
        Area area;

        posMorador = getMoradorGrupo(grupoMoradores, nMoradores, cpf);
        posArea = getAreaGrupo(grupoAreas, nAreas, idArea);

        if (posMorador == -1 || posArea == -1)
        {
            continue;
        }
        else
        {
            morador = grupoMoradores[posMorador];
            area = grupoAreas[posArea];
        }

        if (verificaSolicitacaoReserva(grupoReservas, nReservasSol, morador, area, data, qtdConvidados))
        {
            Reserva r = criaReserva(morador, area, data, qtdConvidados);
            grupoReservas[nReservasSol] = r;
            nReservasSol++;
        }
    }

    for (int i = 0; i < nReservasSol; i++)
    {
        imprimeReserva(grupoReservas[i]);
    }

    return 0;
}