#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
int x;
Arv   *a=cria(1,
 cria(2,
 inicializa(),
 cria(5, inicializa(), inicializa())
 ),
 cria(3,
 cria(5, inicializa(), inicializa()),
 cria(6, inicializa(), inicializa())
 )
 );
 Arv   *b=cria(1,
 cria(2,
 inicializa(),
 cria(5, inicializa(), inicializa())
 ),
 cria(3,
 cria(5, inicializa(), inicializa()),
 cria(6, inicializa(), inicializa())
 )
 );

imprimenivel1(a,3);
    return 0;
}
