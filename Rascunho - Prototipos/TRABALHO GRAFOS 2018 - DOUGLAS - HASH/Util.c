#include <stdlib.h>
#include "Util.h"

static int ARRAY_NUMEROS_PRIMOS[] = {11, 59, 109, 257, 571, 1039, 1259, 1483, 1697, 2251, 3371, 4637, 6269, 8431, 9931, 10709, 15013, 20939, 26347, 32653};

int Retorna_Numero_Primo(int minimo)
{
    for (int i = 0; i < TOTAL_ARRAY_PRIMOS; i++)
    {
        if (ARRAY_NUMEROS_PRIMOS[i] > minimo)
            return ARRAY_NUMEROS_PRIMOS[i];
    }

    return ARRAY_NUMEROS_PRIMOS[TOTAL_ARRAY_PRIMOS - 1];
}
