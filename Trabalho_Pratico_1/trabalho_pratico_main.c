#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers( int* flowerbed, int flowerbedSize, int n ) {

    int flowers = 0;
    for ( int i = 0; i < flowerbedSize; i++ )
    {
         if ( flowerbed[i] == 0 &&(i == 0 || flowerbed[i - 1] == 0) &&(i == flowerbedSize - 1 || flowerbed[i + 1] == 0) ) {
            flowerbed[i] = 1;
            flowers++;
        }
    }

    if ( n <= flowers ) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int flowerbed[] = {1, 1, 1, 1, 1};
    int flowerbedSize = 5;
    int n = 1;

    printf("É possivel plantar todas as flores?");
    if (canPlaceFlowers(flowerbed, flowerbedSize, n)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
