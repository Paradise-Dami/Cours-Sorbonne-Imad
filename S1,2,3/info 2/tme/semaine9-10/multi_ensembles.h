typedef struct _element_t element_t;
struct _element_t{
  int valeur;
  int frequence;
  element_t *suivant;
};

element_t *Recherche_val(element_t *ensemble, int val);
element_t *ajout_tete_ensemble(element_t *ensemble, int val, int freq);
void affiche_ensemble(element_t *ensemble);
element_t * Creation_ensemble(int n);
element_t *Supprime_total_element_ensemble(element_t *element, int val);
element_t *Supprime_element_ensemble(element_t *element, int val);
element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq);
element_t *Supprime_element_ensemble_trie(element_t *liste, int val);
element_t *Supprime_total_element_ensemble_trie(element_t *liste, int val);
int taille(element_t *ensemble);
element_t *Supprime_frequence_inf_seuil(element_t *ensemble, int val);
element_t* ajout_suivant(element_t* element, int val, int freq);
int inclus_rec(element_t *ens1, element_t *ens2);
element_t *unionME(element_t *ens1, element_t *ens2);