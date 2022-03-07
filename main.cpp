#include <iostream>
/* funkcja do wyświetlania zawartości tablicy,
 * będę jej używał zamiast powtarzania po kilka razy tej samej pętli
 * funkcja jest typu void, jako argumenty przyjmuje tablice typu int
 * oraz zmienna odpowiadajaca za rozmiar (size, typ int).*/
void arrayDisplayer(int tab [], int size){
    for (int i = 0; i<size; i++){
        std::cout<<tab[i] << " ";
    }
}
/* funkcja sort jest typu void, jako argumenty przyjmuje tablicę intów tab[]
 * oraz int n, który zawiera rozmiar tablicy tab*/
void sort(int tab [], int n){
    std::cout<<"---------------------\n";
    std::cout<<"Sortowanie bąbelkowe:";
    std::cout<<("\n---------------------");
    /* dosc istotna zmienna, int helper jest pomostem dla dwoch elementow tablicy przy podmianie
     * poniewaz w pewnym momencie "znika" wartosc jednego elementu tablicy (dwa elementy po przypisaniu
     * maja ta sama wartosc) potrzebujemy czegos, co tymczasowo przetrzyma nam wartosc jednego elementu
     * tablicy. I jak zobaczymy pozniej, taka funkcje spelnia wlasnie zmienna helper.
     */
    int helper;
    /* Jeśli wyobrazimy sobie, że sortowanie bąbelkowe polega na nieustannym porównaniu dwóch
     * "szufladek" [elementów tablicy] i przesuwaniu większej w prawo, to pętla zewnętrzna
     * (iterująca na zmiennej i) odpowiada
     * właśnie za ten element "od lewej"; bądź jak kto woli - potencjalnie większy, który zostanie
     * zamieniony z szufladką po prawej (jeśli jest mniejsza);
     * za którą odpowiada pętla wewnętrzna operująca na zmiennej j.
     */
    for (int i = 0; i<n-1; i++){
        /* wyświetlanie numeru iteracji, dodaję jedynkę do zmiennej i ponieważ tablice iterujemy od
         * zera, a my przyzwyczajeni jesteśmy do iterowania od jedynki.
         */
        std::cout<<"\n"<<i+1 << " wykonanie (iteracja) petli - przed sortowaniem:\n";
        /* tutaj powołuję się na funkcję zdefiniowaną wyżej; nie chciałem duplikować już pętli
         * dwie stanowczo wystarczą :-)
         */
        arrayDisplayer(tab,n);
        std::cout<<"\nPo sortowaniu: \n";
        /* to wewnętrzna pętla, wyprzedza o jeden element pętlę zewnętrzną - czyli zgodnie z analogią powyżej
         * jest to szufladka z prawej, która jest sprawdzana jako ta "potencjalnie mniejsza". Pętla kończy się
         * na ostatnim elemencie tablicy, w przeciwieństwie do tej zewnętrznej, która kończy się o
         * jeden element wcześniej.*/
        for (int j = i+1; j<n; j++){
            /* tutaj mamy instrukcję warunkowa, sprawdzamy czy element tablicy indeksowany
             * pętlą zewnętrzną ("szufladka od lewej") jest większy od elementu indeksowanego
             * pętlą wewnętrzną ("szufladka od prawej") */
            if(tab[i] > tab[j]){
                /* jeśli tak, przypisujemy wartość jednego elementu tablicy do zmiennej pomocniczej
                 * helper - a następnie zamieniamy ze sobą wartości elementów tablicy, tak żeby z
                 * lewej strony był element mniejszy, a z prawej większy
                 * w ten sposób iterując po kolei przechodzimy przez całą tablicę
                 * w wyniku uzyskując posortowaną tablicę od najmniejszego elementu do największego */
                helper = tab[i];
                tab[i] = tab[j];
                tab[j] = helper;
            }
        }
        /* wyświetlanie stanu tablicy po każdej iteracji pętli zewnętrznej - w ten sposób uzyskuję
         * wyniki w postaci etapów */
        arrayDisplayer(tab,n);
        std::cout<<"\n---------";
    }
    //wyświetlanie ostatecznego wyniku
    std::cout<<"\nPosortowana tablica: \n";
    arrayDisplayer(tab,n);

}
int main() {
    int n; //deklaracja zmiennej przechowujacej rozmiar tablicy
    std::cout<<"Podaj rozmiar tablicy: ";
    std::cin >> n; //pobieranie rozmiaru tablicy od uzytkownika
    int tab[n]; //deklaracja tablicy o rozmiarze n
    std::cout<<"Wprowadz elementy tablicy: ";
    /* prosta petla pozwalajaca na umieszczenie elementow  podanych przez
     * uzytkownika do tablicy; petla konczy się na n-1, ponieważ zaczynamy iteracje
     * od 0. */
    for (int i = 0; i<n; i++){
        std::cin >> tab[i];
    }
    //wywołanie funkcji odpowiadajacej za sortowanie bąbelkowe
    sort(tab,n);
    return 0;
}


/* Dominik Borawski
 * Grupa A1 215IC
 * Sortowanie bąbelkowe


Podaj rozmiar tablicy: 10
Wprowadz elementy tablicy: 3 2 1 10 4 9 4 11 12 10
---------------------
Sortowanie bąbelkowe:
---------------------
1 wykonanie (iteracja) petli - przed sortowaniem:
3 2 1 10 4 9 4 11 12 10
Po sortowaniu:
1 3 2 10 4 9 4 11 12 10
---------
2 wykonanie (iteracja) petli - przed sortowaniem:
1 3 2 10 4 9 4 11 12 10
Po sortowaniu:
1 2 3 10 4 9 4 11 12 10
---------
3 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 10 4 9 4 11 12 10
Po sortowaniu:
1 2 3 10 4 9 4 11 12 10
---------
4 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 10 4 9 4 11 12 10
Po sortowaniu:
1 2 3 4 10 9 4 11 12 10
---------
5 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 4 10 9 4 11 12 10
Po sortowaniu:
1 2 3 4 4 10 9 11 12 10
---------
6 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 4 4 10 9 11 12 10
Po sortowaniu:
1 2 3 4 4 9 10 11 12 10
---------
7 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 4 4 9 10 11 12 10
Po sortowaniu:
1 2 3 4 4 9 10 11 12 10
---------
8 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 4 4 9 10 11 12 10
Po sortowaniu:
1 2 3 4 4 9 10 10 12 11
---------
9 wykonanie (iteracja) petli - przed sortowaniem:
1 2 3 4 4 9 10 10 12 11
Po sortowaniu:
1 2 3 4 4 9 10 10 11 12
---------
Posortowana tablica:
1 2 3 4 4 9 10 10 11 12


 *
 *
 *
 */