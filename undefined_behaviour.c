#include <stdio.h>  // Dit is een header-bestand dat nodig is voor input en output (zoals printf)

#include <stdlib.h> // Dit is een header-bestand dat functies bevat voor geheugenbeheer (zoals malloc en free)

int main() {
    // Stap 1: Geheugen toewijzen
    int *ptr = (int *)malloc(sizeof(int));  // Dynamisch geheugen toewijzen voor een integer

    /* Uitleg:
       - `int *ptr`: Dit maakt een pointer aan die een geheugenadres kan opslaan waar een integer is opgeslagen.
       - `malloc(sizeof(int))`: `malloc` vraagt een stukje geheugen aan dat groot genoeg is voor één integer.
       - `sizeof(int)`: Dit geeft aan hoeveel bytes een integer nodig heeft (meestal 4 bytes).
       - `(int *)`: Dit is een "type cast", het verandert het type van het teruggegeven adres naar een pointer naar een integer.
    */

    // Stap 2: Geheugen initialiseren
    *ptr = 42;  // De waarde 42 wordt opgeslagen in het dynamisch toegewezen geheugen

    /* Uitleg:
       - `*ptr = 42;`: De `*` betekent "dereferencing", dit geeft toegang tot de waarde in het geheugen waar de pointer naar wijst.
       - Dit betekent dat we het dynamisch toegewezen geheugen gebruiken om de waarde 42 op te slaan.
    */

    // Stap 3: Waarde afdrukken
    printf("Value before free: %d\n", *ptr);  // Print de waarde van het toegewezen geheugen

    /* Uitleg:
       - `printf`: Dit is een functie die tekst op het scherm afdrukt.
       - `%d`: Dit is een formaat-specifier voor het printen van een integer.
       - `*ptr`: Hier printen we de waarde waar `ptr` naar wijst, wat 42 is.
    */

    // Stap 4: Geheugen vrijgeven
    free(ptr);  // Geheugen vrijgeven dat met malloc werd toegewezen

    /* Uitleg:
       - `free(ptr);`: Dit geeft het geheugen terug aan het systeem. Na deze stap is het geheugen waar `ptr` naar wijst niet meer bruikbaar.
       - Hierna is `ptr` een "dangling pointer", wat betekent dat hij nog steeds naar een geheugenlocatie wijst, maar we mogen die niet meer gebruiken.
    */

    // Stap 5: Toegang tot vrijgegeven geheugen (undefined behavior)
    printf("Accessing freed memory: %d\n", *ptr);  // Probeer de waarde in het vrijgegeven geheugen af te drukken

    /* Uitleg:
       - `*ptr`: Hier proberen we weer toegang te krijgen tot de waarde waar `ptr` naar wijst.
       - Dit is een fout omdat we het geheugen al hebben vrijgegeven met `free(ptr)`. We mogen het niet meer gebruiken.
       - Dit veroorzaakt "undefined behavior", omdat het niet duidelijk is wat er nu in dat geheugen zit. Het programma kan crashen, rare waarden weergeven of "correct" lijken te werken, afhankelijk van de omstandigheden.
    */

    return 0;  // Het programma eindigt hier
}
