#include <stdio.h>

//FUNÇÃO BUBBLE SORT
void bubble_sort(int vet[], int n){ //void pq não precisa retornar nada
    int trocou = 1; //saber se houve troca e terá que repetir novamente
    do{
        for(int i = 0; i < n - 1; i++){ //percorrer todo o vetor até o penúltimo
                for(int j = 1; j < n; j++){ //o j será usado pra saber o primeiro e o segundo da dupla
                    if(vet[j] < vet[j - 1]){ //se o segundo for menor que o primeiro faz a troca
                        int aux = vet[j - 1];
                        vet[j - 1] = vet[j];
                        vet[j] = aux;
                        trocou = 1; //houve troca
                    } else trocou = 0; //não houve troca
                }
            }
    } while(trocou); //repetir enquanto tiver acontecido trocas
}

//FUNÇÃO INSERTION SORT -- não sei o motivo mas só funcionou para a última posição com o while
void insertion_sort(int vet[], int n){
    int i, j, aux;
    for(int i = 1; i < n; i++){ //percorrer todo o vetor
        aux = vet[i]; //guardar o valor do vetor da próxima posição
        j = i - 1; // posição anterior
        while(j >= 0 && vet[j] > aux){ //compara o da próxima posição com o da anterior enquanto não chegar a primeira posição e o da proxima for menor
            vet[j + 1] = vet[j]; //vai substituindo de trás pra frente
            j--;
        } vet[j + 1] = aux;
    }
}

//FUNÇÃO SELECTION SORT
void selection_sort(int vet[], int n){
    int i, j;
    int menor, troca; //menor é a posição do menor e troca é o aux da troca
    for(int i = 0; i < n - 1; i++){ //percorre todo o vetor até o penúltimo
        menor = i; //o menor por enquanto será o primeiro
        for(int j = i + 1; j < n; j++){ //j sempre será a posição depois do i
            if(vet[j] < vet[menor]) menor = j; //se o vetor de j for menor que o menor, j é a nova posição do menor
        } if(i != menor){ //se i não for a menor posição faz a troca pelo menor
            troca = vet[i];
            vet[i] = vet[menor];
            vet[menor] = troca;
        }
    }
}

//FUNÇÃO PRINCIPAL (TESTAR)
int main(){
    int n;
    printf("Insira a quantidade de números do conjunto: \n");
    scanf("%d", &n);
    int vet[n];
    printf("Agora insira os valores: \n");
    for(int i = 0; i < n; i++) scanf("%d", &vet[i]); //conjunto que será ordenado

    //bubble_sort(vet, n);
    insertion_sort(vet, n);
    //selection_sort(vet, n);
    for(int i = 0; i < n; i++) printf("%d ", vet[i]); //imprime o vetor ordenado

    return 0;
}
