#include <iostream>
void arrayDisplayer(int tab [], int size){
    for (int i = 0; i<size; i++){
        printf("%d ", tab[i]);
    }
}
void bubbleSort(int tab [], int size){
    printf("Przed sortowaniem: \n");
    arrayDisplayer(tab, size);
    printf("\n---------\n");
    int helper;
    for (int i = 0; i<size-1; i++){
        printf("\n---------");
        printf("\n%d wykonanie (iteracja) petli - przed sortowaniem:\n", i+1);
        arrayDisplayer(tab,size);
        printf("\nPo sortowaniu: \n");
        for (int j = i+1; j<size; j++){
            if(tab[i] > tab[j]){
                helper = tab[i];
                tab[i] = tab[j];
                tab[j] = helper;
            }
        }
        arrayDisplayer(tab,size);
    }
    for (int i = 0; i<size; i++){
        std::cout<<tab[i] << " ";
    }
}
int main() {
    int ar [] = {5, 2, 10, 1, 4, 8, 9, 9, 3, 12};
    int size = sizeof(ar)/sizeof(int);
    bubbleSort(ar,size);
    return 0;
}


