//
// Created by W0L1D on 12/5/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"



// la fct creer liste
TPile* createTPile()
{// declaration + allocation de la memoire
    TPile *pile = (TPile*) malloc(sizeof(TPile));
    pile->sommet = -1;//
    if (!pile)//si liste existe
    {
        printf("Erreur de location de la memoire");
        exit(0);
    }
    return((TPile *)pile) ;
}//fin fct

// fct qui initialise la pile
TPile* init_TPile(TPile *pile)
{//si pile existe
    if (pile)
        free(pile);
    //sinon creer une pile
    pile = createTPile();
    return ((TPile*)pile);
}//fin fct

// taille pile
int taille_TPile(TPile pile)
{ return ((int)pile.sommet+1);
}//fin fct

// fct qui vide la pile
int vider_pile(TPile *pile)
{
    if (!pile)
        return 0;
    pile->sommet = -1; //modifier la valeur
    return 1;
}//fin fct

// fct verifier si la pile est vide retourne 1 si vide
// et 1 sinon
int est_TPile_vide(TPile pile)
{
    return !(pile.sommet+1);
}//fin fct

//Fct empile une valeur dans la pile
int empiler_Tab(TPile *pile, int val)
{
    if (!pile) // pile n'existe pas
        return ((int) -1);
    //pile existe pas
    if ((pile->sommet+1) == MAX_ELEMS) //pile est saturee
        return ((int) -2);


    // empilage et incrementation du sommet
    pile->tab[++(pile->sommet)] = val;

    return((int)1); // empilage est bien effectuÃ©e
}//fin fct


// fct depile la pile retourne nombre element si l'element est depiler sinon 0
int depiler_Tab(TPile *pile)
{
    if (!pile) // pile n'existe pas
        return ((int)-1);


    if ((!(pile->sommet+1))) //si le sommet == -1
        return ((int)0); //pile est vide

    // depilage et decrementation du sommet
    return 1; // retourne la valeur depiler

}//fin fct

int getSommet_TPile(TPile pile) {
    return pile.tab[pile.sommet];
}

//fct inverese l'ordre des elements de la pile et retourne la liste apres modification ,null sinon
TPile* inverser_TPile(TPile *pile)
{
    //pile n'exist pas
    if (!pile)
    {
        return((TPile*) NULL);
    }
    // TPile est vide
    if (!(pile->sommet+1))
        return ((TPile*)pile);

// utiliser une pile tmp pour empiler les elements depiler de liste
    TPile *tmp = createTPile();
    int val_depile;

    while (!est_TPile_vide(*pile))//tant que pile n'est pas vide
    {

        val_depile = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depile);
    }

    free(pile);
    return ((TPile*)tmp);//retourne la pile tmp
}//fin fct

// fct qui trouve si un element se trouve dans une pile
//retourne sa position si existe, sinon retourne un zero
//affcher l'element qui se trouve a la position p
int trouver_val_TPile(TPile *pile, int val, int *status)
{
    *status = 1;

    if (!pile) //pile n'exist pas
    {
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }
    //pile existe
    if (est_TPile_vide(*pile))
    {
        *status = 0;
        return((int) 0); //pile est vide
    }

    TPile *tmp;
    int indice = -1,
    val_depiler;
    tmp = createTPile();

    while (!est_TPile_vide(*pile))
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        //si indice != -1 et val donne == valeur depile
        if ((val_depiler == val) && !(indice+1))
            indice = pile->sommet +2; //le sommet point sur l'indice la valeur au desous du val
    }
    while (!est_TPile_vide(*tmp))
    {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }

    return indice;
}//fin fct



int max_val_TPile(TPile *pile, int *status)
{
    *status = 1;
    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return ((int)0);
    }
// pile tmp pour empiler les element depiler par pile principale
    TPile *tmp;
    int val_depiler, max_elem;

    tmp = createTPile();

    max_elem = getSommet_TPile(*pile);

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        //si indice != -1 et val donne == valeur depile
        if (max_elem < getSommet_TPile(*tmp))
            max_elem = getSommet_TPile(*tmp);// stocker le nouveau element max
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }

    return max_elem;
}//fin fct



// fct qui retourne l'element min de la pile
int min_val_TPile(TPile *pile, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return ((int)0);
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return ((int)0);
    }

    TPile *tmp;
    int val_depiler, min_elem;

    tmp = createTPile();
// considerer le min = l'element qui se trouve au sommet
    min_elem = getSommet_TPile(*pile);

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        //si indice != -1 et val donne == valeur depile
        if (min_elem > getSommet_TPile(*tmp))
            min_elem = getSommet_TPile(*tmp);
    }


    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }


    return min_elem;
} //FIN de fonction max_val_TPile




// fct qui retourne le nombre d'occurence d'un element
int nbr_occur_TPile(TPile *pile, int val, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    TPile *tmp;
    int val_depiler, nbr_occur;

    tmp = createTPile();

    nbr_occur = 0;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        //si indice != -1 et val donne == valeur depile
        if (val == getSommet_TPile(*tmp))
            nbr_occur++;
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }


    return nbr_occur;
} //FIN de fonction nbr_occur_TPile

//affcher l'element qui se trouve a la position p
int trouver_pos_TPile(TPile *pile, int pos, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return 0;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return 0;
    }

    TPile *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        //si sommet == position donnee
        if (pos == tmp->sommet)
        {
            val_pos = getSommet_TPile(*tmp);// stocker l'element a la position p
            break;
        }
    }

    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }


    return val_pos;
} //FIN de fonction trouver_pos_TPile



//supprimer le premier occurence du val
void supprimer_val_TPILE(TPile *pile, int val, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    TPile *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        if (val == val_depiler)
            break;

        empiler_Tab(tmp, val_depiler);
    }


    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }



} //FIN de fonction supprimer_val_TPILE





//supprimer toutes les occurences du val
void supprimer_all_occur_TPILE(TPile *pile, int val, int *status)
{
    *status = 1;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    TPile *tmp;
    int val_depiler, val_pos;

    tmp = createTPile();

    val_pos = -1;

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        if (val != val_depiler)
            empiler_Tab(tmp, val_depiler);
    }


    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }



} //FIN de fonction supprimer_all_occur_TPILE



//supprimer le premier occurence du val
void supprimer_pos_TPILE(TPile *pile, int pos, int *status)
{
    *status = -4;

    if (!pile)
    {   //pile n'exist pas
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }

    if (est_TPile_vide(*pile))
    {   //pile est vide
        *status = 0;
        return;
    }

    TPile *tmp;
    int val_depiler;

    tmp = createTPile();


    while (!est_TPile_vide(*pile))// tant que pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);

        if (pos-1 == pile->sommet)
        {
            *status = 1;
            break;
        }

        empiler_Tab(tmp, val_depiler);

    }


    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }


} //FIN de fonction supprimer_pos_TPILE



// fct affiche tout les elements de la pile
void affiche_TPile(TPile *pile, int *status)
{
    int i;
    //pile n'exist pas
    if (!pile)
    {
        printf("\nListe n'est pas initialisee\n");
        *status = -1;
        return;
    }
    // TPile est vide
    if (!(pile->sommet+1))
    {
        *status = 0;
        printf("\nla liste est vide\n");
        return;
    }

    TPile *tmp;
    int val_depiler;

    tmp = createTPile();

    printf("\nle elements de la pile : \n");

    while (!est_TPile_vide(*pile))// tant que la pile n'est pas vide
    {
        val_depiler = getSommet_TPile(*pile);
        depiler_Tab(pile);
        empiler_Tab(tmp, val_depiler);
        printf("%d\t", val_depile);
    }


    while (!est_TPile_vide(*tmp)) {
        val_depiler = getSommet_TPile(*tmp);
        depiler_Tab(tmp);
        empiler_Tab(pile, val_depiler);
    }
}

// fonction de gestion d'erreurs
int handle_errors_TPile(int cd)
{
    switch (cd) {

        case 1:
            return 1;
        case -1:
            printf("\nLa pile n'existe pas\n");
            break;
        case -2:
            printf("\nLa pile est saturee\n");
            break;

        case -3:
            printf("\nLa valeur n'est pas trouve\n");
            break;

        case -4:
            printf("\nLa position n'est pas correcte\n");
            break;

        case 0:
            printf("\nLa pile est vide\n");
            break;

    }
    return 0;
}// fin fct




