#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int elemento;
    struct nodo* successivo;

} nodo;


//AGGIUNTA DI NODI NELLA LISTA
nodo* aggiungi_in_testa(int n, nodo* testa);
nodo* aggiungi_in_coda(int n,nodo* testa);
nodo* aggiungi_in_posizione(int n, int posizione, nodo* testa);

//RIMOZIONE DI NODI DALLA LISTA
nodo* rimuovi_in_testa(nodo* testa);
nodo* rimuovi_in_coda(nodo* testa);
nodo* rimuovi_in_posizione(int posizione,nodo* testa);

//ALTRE FUNZIONI
void stampa_lista(nodo* testa);
int cerca(int n, nodo* testa);
int conta(nodo* testa);


int main(){

    //Creo il nodo di testa e lo inserisco nella lista
    nodo *lista = NULL;
    lista = aggiungi_in_testa(1, lista);

    //LISTA: 1 -> NULL
    stampa_lista( lista );

    //Aggiungo un nodo alla fine della lista
    lista = aggiungi_in_coda(3, lista);

    //LISTA: 1 -> 3 -> NULL
    stampa_lista( lista );

    //Aggiungo nodo tra il primo e il secondo
    lista = aggiungi_in_posizione(2, 1, lista);

    //LISTA: 1 -> 2 -> 3 -> NULL
    stampa_lista( lista );

    //Conto il numero di nodi
    printf("Nodi: %d\n", conta( lista ) );

    //Cerco il nodo con elemento di valore 3 e lo elimino
    int posizioneDaEliminare = cerca(3, lista);
    lista = rimuovi_in_posizione(posizioneDaEliminare, lista);

    //LISTA: 1 -> 2 -> NULL
    stampa_lista( lista );

    return 0;

}



nodo* aggiungi_in_testa(int n, nodo* testa){
    if(testa != NULL){
        nodo* nodoSuccessivo = testa;
        testa = (nodo*) malloc(sizeof(nodo));
        testa -> elemento = n;
        testa -> successivo = nodoSuccessivo;
    }
    else{
        testa = (nodo*) malloc(sizeof(nodo));
        testa -> elemento = n;
        testa -> successivo = NULL;
    }
    return testa;
}

nodo* aggiungi_in_coda(int n, nodo* testa){
    if(testa != NULL){
        nodo* nodoSuccessivo = testa;
        while(nodoSuccessivo -> successivo != NULL){
            nodoSuccessivo = nodoSuccessivo -> successivo;
        }
        nodoSuccessivo -> successivo = aggiungi_in_testa(n, NULL);
    }
    else{
        testa = aggiungi_in_testa(n, testa);
    }
    return testa;
}

nodo* aggiungi_in_posizione(int n, int posizione, nodo* testa){

    if(posizione == 0 || testa == NULL){
        testa = aggiungi_in_testa(n, testa);
    }
    else if(posizione > 0){
        int i=1;
        nodo* nodoSuccessivo = testa;
        while(i < posizione && nodoSuccessivo -> successivo != NULL){
            nodoSuccessivo = nodoSuccessivo -> successivo;
            i++;
        }
        nodoSuccessivo -> successivo = aggiungi_in_testa(n, nodoSuccessivo -> successivo);
    }
    return testa;
}

nodo* rimuovi_in_testa(nodo* testa){
    if(testa != NULL){
        nodo* daEliminare = testa;
        testa = testa -> successivo;
        free(daEliminare);
    }

    return testa;
}

nodo* rimuovi_in_coda(nodo* testa){
    if(testa != NULL){
        if(testa -> successivo != NULL){

            nodo* attuale = testa;
            nodo* daEliminare = testa -> successivo;

            while(daEliminare -> successivo != NULL){
                attuale = daEliminare;
                daEliminare = daEliminare -> successivo;
            }
            attuale -> successivo = rimuovi_in_testa(daEliminare);
        }
        else{
            testa = rimuovi_in_testa(testa);
        }
    }

    return testa;
}

nodo* rimuovi_in_posizione(int posizione, nodo* testa){


    if(posizione == 0 || testa -> successivo == NULL){
        testa = rimuovi_in_testa(testa);
    }
    else if(posizione > 0){
        int i=1;

        nodo* attuale = testa;
        nodo* daEliminare = testa -> successivo;

        while(i < posizione && daEliminare-> successivo != NULL){
            attuale = daEliminare;
            daEliminare = daEliminare -> successivo;
            i++;
        }
        attuale -> successivo = rimuovi_in_testa( daEliminare -> successivo);

    }
    return testa;
}


void stampa_lista(nodo * testa){
    if(testa != NULL){
        printf("TESTA -> ");
        while(testa != NULL){
            printf("%d -> ",testa->elemento);
            testa = testa -> successivo;
        }
        printf("NULL \n");
    }
    else {
        printf("LISTA VUOTA \n");
    }
}

int cerca(int n,nodo* testa){
    int posizione = -1;
    int trovato = 0;
    int i=0;
    while(testa != NULL && trovato == 0){
        if(testa -> elemento == n){
            posizione = i;
            trovato = 1;
        }
        i++;
        testa = testa -> successivo;
    }
    return posizione;
}

int conta(nodo* testa){
    int i=0;
    while(testa != NULL){
        i++;
        testa = testa -> successivo;
    }
    return i;
}