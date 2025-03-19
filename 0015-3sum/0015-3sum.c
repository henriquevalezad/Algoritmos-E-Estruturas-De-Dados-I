/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL; 

    qsort(nums, numsSize, sizeof(int), comparar); 

    int** resultado = (int**)malloc(numsSize * numsSize * sizeof(int*)); 
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        int esquerda = i + 1, direito = numsSize - 1;
        while (esquerda < direito) {
            int sum = nums[i] + nums[esquerda] + nums[direito];
            if (sum == 0) {
                resultado[*returnSize] = (int*)malloc(3 * sizeof(int));
                resultado[*returnSize][0] = nums[i];
                resultado[*returnSize][1] = nums[esquerda];
                resultado[*returnSize][2] = nums[direito];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (esquerda < direito && nums[esquerda] == nums[esquerda + 1]) esquerda++;
                while (esquerda < direito && nums[direito] == nums[direito - 1]) direito--;

                esquerda++;
                direito--;
            } else if (sum < 0) {
                esquerda++; 
            } else {
                direito--;
            }
        }
    }

    return resultado;
}
