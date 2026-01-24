#include <stdio.h>
#define NB_PLANETES 8

#include <stdio.h>

/* ici la definition du type planete */

typedef struct _planete{
    char nom[10];
    float densite;
    float distance;
    int nbsat;
} planete;

void affichePlanete(planete astre){
   printf("%s : densite = %0.2f, distance soleil = %0.1f, nb satellites = %d", astre.nom, astre.densite, astre.distance, astre.nbsat);
}

void afficheToutesPlanetes(planete *systeme, int tailleSys) {
    for (int i = 0; i < tailleSys; i++) {
        affichePlanete(systeme[i]);
    }
}

void modifieDensite(planete *astre, float nouvelleDensite){
    astre->densite = nouvelleDensite;
}

int main(){
    planete systemeSolaire[NB_PLANETES] ={{"Mercure", 5.42, 58, 0},{"Venus", 5.25, 108.2, 0},{"Terre", 5.52,149.6,1},{"Mars",3.94,227.9,2},{"Jupiter",1.314,778.3,16},{"Saturne",0.69,1427,17},{"Uranus",1.19,2869,15},{"Neptune",1.6,4496,2}};
    afficheToutesPlanetes(systemeSolaire, NB_PLANETES);
    return 0;
}