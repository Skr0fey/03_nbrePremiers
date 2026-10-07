/*
  ------------------------------------------------------------------------------
  Fichier     : nbre_1er.cpp
  Auteur(s)   : Skriabin Tymofii
  Date        : 07.10.2026

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib> // pour EXIT_SUCCESS
#include <limits>  // requis pour numeric_limits
#include <iomanip> // requis pour setw

using namespace std;

// Déclaration des constantes globales pour les bornes du programme
constexpr int BORNE_MIN = 2;
constexpr int BORNE_MAX = 1000;

int main() {
    // Nombre de colonnes pour l'affichage, défini localement dans le main
    constexpr int n_col = 5;
    string choix;

    // Boucle principale : permet de rejouer ou de quitter le programme
    do {
        int limite;

        // Boucle de saisie avec contrôle des bornes [2-1000]
        do {
            cout << "Entrer une valeur [" << BORNE_MIN << "-" << BORNE_MAX << "] : ";
            cin >> limite;

            // Nettoyage sécurisé du buffer après la saisie d'un entier
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (limite < BORNE_MIN || limite > BORNE_MAX);

        cout << "\nVoici la liste des nombres premiers\n";

        int compteur = 0; // Compteur pour gérer l'affichage sur n_col colonnes

        // Boucle externe : itération à travers tous les nombres jusqu'à la limite
        for (int n = 2; n <= limite; n++) {

            // Logique de test de primalité
            bool estPremier = true;

            // Optimisation mathématique : test des diviseurs jusqu'à la racine carrée de n
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    estPremier = false; // Diviseur trouvé, le nombre n'est pas premier
                    break;              // Sortie immédiate de la boucle interne
                }
            }

            // Affichage du nombre premier si le drapeau est resté vrai
            if (estPremier) {
                // Utilisation de setw(8) pour un alignement parfait en colonnes
                cout << setw(8) << n;
                compteur++;

                // Retour à la ligne dès que le nombre maximum de colonnes est atteint
                if (compteur == n_col) {
                    cout << '\n';
                    compteur = 0;
                }
            }
        }
        cout << "\n\n";

        // Boucle de saisie du menu de redémarrage avec validation stricte [O/N]
        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> choix;

            // Nettoyage du buffer après la saisie du caractère/chaîne
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (!(choix == "O" || choix == "N"));

    } while (choix == "O");

    cout << "\nFin de programme\n";
    return EXIT_SUCCESS;
}


