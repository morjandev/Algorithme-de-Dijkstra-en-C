#include <stdio.h>
#include <stdlib.h>
#define N 5  // Nombre de sommets (A à E)
#define INFINI 1000000000 

char indiceVersChar(int indice) {
    return 'A' + indice;
}
int charVersIndice(char c) {
    return c - 'A';
}
void AfficherMatriceChar(int M[N][N]) {
    printf("Matrice d'adjacence :\n");
    printf("   ");
    for (int j = 0; j < N; j++) {
        printf(" %c  ", indiceVersChar(j));
    }
    printf("\n");
    
    for (int i = 0; i < N; i++) {
        printf("%c ", indiceVersChar(i));
        for (int j = 0; j < N; j++) {
            printf(" %2d ", M[i][j]);
        }
        printf("\n");
    }
}

void initMatriceAdj(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = 0;
        }
    }
}

void ajouterArc(int M[N][N], char src, char dest, int poids) {
    int srcIndice = charVersIndice(src);
    int destIndice = charVersIndice(dest);
    M[srcIndice][destIndice] = poids;
}
void supprimerArc(int M[N][N], char src, char dest) {
    int srcIndice = charVersIndice(src);
    int destIndice = charVersIndice(dest);
    M[srcIndice][destIndice] = 0;
}
void marquerSommet(int SM[N]) {
    for (int i = 0; i < N; i++) {
        SM[i] = 0;
    }
}
void Dijkstra(int M[N][N], char sommetDepart) {
    int s = charVersIndice(sommetDepart);
    int SM[N];        
    int distance[N];   
    char P[N];         
    int i, j;
    int min_dist_M; 
    for (i = 0; i < N; i++) {
        SM[i] = 0;     
        if (i == s) {
            distance[i] = 0;
            P[i] = '-';    
        } else {
            distance[i] = INFINI;
            P[i] = '-';
        }
    }
    min_dist_M = 0;
    while (min_dist_M != INFINI) {
        int x = -1;
        for (i = 0; i < N; i++) {
            if (SM[i] == 0 && distance[i] == min_dist_M) {
                x = i;
                break;
            }
        }
        if (x == -1) {
            break;
        }
        SM[x] = 1;
        for (j = 0; j < N; j++) {
            if (M[x][j] > 0 && SM[j] == 0) { 
                if (distance[x] + M[x][j] < distance[j]) {
                    distance[j] = distance[x] + M[x][j];                    
                    P[j] = indiceVersChar(x);  
                }
            }
        }
        min_dist_M = INFINI;
        for (i = 0; i < N; i++) {
            if (SM[i] == 0 && distance[i] < min_dist_M) {
                min_dist_M = distance[i];
            }
        }
    }
    printf("\nResultats de l\'algorithme de Dijkstra  partir du sommet %c:\n", sommetDepart);
    printf("Sommet |  Distance | Predecesseur\n");
    printf("-------------------------------\n");
    for (i = 0; i < N; i++) {
        if (distance[i] == INFINI) {
            printf("  %c    | INFINI    |    %c\n", indiceVersChar(i), P[i]);
        } else {
            printf("  %c    |  %2d       |    %c\n", indiceVersChar(i), distance[i], P[i]);
        }
    }
    printf("\nChemins les plus courts depuis %c:\n", sommetDepart);
    for (i = 0; i < N; i++) {
        if (i != s && distance[i] != INFINI) {  
            printf("Chemin vers %c (distance = %d): ", indiceVersChar(i), distance[i]);
            char chemin[N];
            int longueur = 0;
            int currentNode = i;
            while (currentNode != s) {
                chemin[longueur++] = indiceVersChar(currentNode);
                currentNode = charVersIndice(P[currentNode]);
            }
            chemin[longueur++] = sommetDepart;
            for (j = longueur - 1; j >= 0; j--) {
                printf("%c", chemin[j]);
                if (j > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
}

int main() {
    int M[N][N];
    initMatriceAdj(M);
    ajouterArc(M, 'A', 'B', 4);
    ajouterArc(M, 'A', 'C', 2);
    ajouterArc(M, 'A', 'D', 4);
    ajouterArc(M, 'B', 'E', 2);
    ajouterArc(M, 'C', 'B', 1);
    ajouterArc(M, 'C', 'D', 2);
    ajouterArc(M, 'C', 'E', 4);
    ajouterArc(M, 'D', 'E', 4);
    AfficherMatriceChar(M);
    Dijkstra(M, 'A');
    
    return 0;
}