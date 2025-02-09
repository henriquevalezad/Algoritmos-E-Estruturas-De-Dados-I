typedef struct {
    int proximo;
    int capacidade;
    int *ocupado;
} SeatManager;

SeatManager* seatManagerCreate(int n) {
    SeatManager *assentos = (SeatManager*)malloc(sizeof(SeatManager));
    assentos->proximo = 0;
    assentos->capacidade = n;
    assentos->ocupado = (int*)calloc(n, sizeof(int));
    
    return assentos;
}

int seatManagerReserve(SeatManager* obj) {
    int assentos = obj->proximo +1;
    obj->ocupado[obj->proximo] = 1;

    while (obj->proximo < obj->capacidade && obj->ocupado[obj->proximo]) {
        obj->proximo++;
    }

    return assentos;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    int posicao = seatNumber - 1;
    obj->ocupado[posicao] = 0;

    if (posicao < obj->proximo) {
        obj->proximo = posicao;
    }
}

void seatManagerFree(SeatManager* obj) {
    free(obj->ocupado);
    free(obj);
}