bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int flowers = 0;
   for (int i = 0; i < flowerbedSize; i++)
    {
         if (flowerbed[i] == 0 &&(i == 0 || flowerbed[i - 1] == 0) &&(i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            flowers++;
        }
    }

    if(n <= flowers){
        return true;
    }else{
        return false;
    }
}