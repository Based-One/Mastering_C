// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
//
// typedef struct NodoHuffman {
//     char caracter;
//     struct NodoHuffman* izquierda;
//     struct NodoHuffman* derecha;
// } NodoHuffman;
//
// NodoHuffman* crearNodo(char caracter) {
//     NodoHuffman* nodo = (NodoHuffman*)malloc(sizeof(NodoHuffman));
//     nodo->caracter = caracter;
//     nodo->izquierda = NULL;
//     nodo->derecha = NULL;
//     return nodo;
// }
//
// void insertar(NodoHuffman* raiz, const char* codigo, char caracter) {
//     NodoHuffman* actual = raiz;
//     for (int i = 0; codigo[i] != '\0'; i++) {
//         if (codigo[i] == '0') {
//             if (!actual->izquierda) {
//                 actual->izquierda = crearNodo('\0');
//             }
//             actual = actual->izquierda;
//         } else if (codigo[i] == '1') {
//             if (!actual->derecha) {
//                 actual->derecha = crearNodo('\0');
//             }
//             actual = actual->derecha;
//         }
//     }
//     actual->caracter = caracter;
// }
//
// void decodificar(NodoHuffman* raiz, const char* mensajeCodificado, char* mensajeDecodificado) {
//     NodoHuffman* actual = raiz;
//     int i = 0, j = 0;
//
//     while (mensajeCodificado[i] != '\0') {
//         if (mensajeCodificado[i] == '0') {
//             actual = actual->izquierda;
//         } else if (mensajeCodificado[i] == '1') {
//             actual = actual->derecha;
//         }
//
//         if (actual->izquierda == NULL && actual->derecha == NULL) {
//             mensajeDecodificado[j++] = actual->caracter;
//             actual = raiz;
//         }
//         i++;
//     }
//     mensajeDecodificado[j] = '\0';
// }
//
// void liberarArbol(NodoHuffman* nodo) {
//     if (nodo == NULL) return;
//
//     liberarArbol(nodo->izquierda);
//     liberarArbol(nodo->derecha);
//     free(nodo);
// }
//
// int main() {
//     NodoHuffman* raiz = crearNodo('\0');
//
//     // Huffman table
//     insertar(raiz, "001", 'a');
//     insertar(raiz, "0000", 'b');
//     insertar(raiz, "0001", 'c');
//     insertar(raiz, "010", 'd');
//     insertar(raiz, "011", 'e');
//     insertar(raiz, "1", 'f');
//
//     // Mensaje codificado
//     const char* mensajeCodificado = "010011101100010010100010100110001001010001101100100000110000011";
//     char mensajeDecodificado[100];
//
//     // Decodificar el mensaje
//     decodificar(raiz, mensajeCodificado, mensajeDecodificado);
//
//     // Imprimir el mensaje
//     printf("Mensaje decodificado: %s\n", mensajeDecodificado);
//
//     // Liberar la memoria
//     liberarArbol(raiz);
//
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoHuffman {
    char caracter;
    int frecuencia;
    struct NodoHuffman* izquierda;
    struct NodoHuffman* derecha;
} NodoHuffman;

typedef struct {
    char caracter;
    char codigo[10];
} TablaHuffman;

NodoHuffman* crearNodo(char caracter, int frecuencia) {
    NodoHuffman* nodo = (NodoHuffman*)malloc(sizeof(NodoHuffman));
    nodo->caracter = caracter;
    nodo->frecuencia = frecuencia;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

void construirTabla(NodoHuffman* raiz, char* codigoActual, int profundidad, TablaHuffman* tabla, int* indice) {
    if (!raiz) return;

    if (!raiz->izquierda && !raiz->derecha) {
        tabla[*indice].caracter = raiz->caracter;
        strncpy(tabla[*indice].codigo, codigoActual, profundidad);
        tabla[*indice].codigo[profundidad] = '\0';
        (*indice)++;
        return;
    }

    codigoActual[profundidad] = '0';
    construirTabla(raiz->izquierda, codigoActual, profundidad + 1, tabla, indice);

    codigoActual[profundidad] = '1';
    construirTabla(raiz->derecha, codigoActual, profundidad + 1, tabla, indice);
}

char* huffman(TablaHuffman* tabla, int n, char letra) {
    for (int i = 0; i < n; i++) {
        if (tabla[i].caracter == letra) {
            return tabla[i].codigo;
        }
    }
    return NULL;
}

void liberarArbol(NodoHuffman* nodo) {
    if (nodo == NULL) return;
    liberarArbol(nodo->izquierda);
    liberarArbol(nodo->derecha);
    free(nodo);
}

// int main() {
//     NodoHuffman* raiz = crearNodo('\0', 133);
//     raiz->izquierda = crearNodo('\0', 48);
//     raiz->derecha = crearNodo('f', 85);
//
//     NodoHuffman* nodoIzq = raiz->izquierda;
//     nodoIzq->izquierda = crearNodo('\0', 21);
//     nodoIzq->derecha = crearNodo('e', 27);
//
//     NodoHuffman* nodoIzqIzq = nodoIzq->izquierda;
//     nodoIzqIzq->izquierda = crearNodo('\0', 9);
//     nodoIzqIzq->derecha = crearNodo('d', 13);
//
//     NodoHuffman* nodoIzqIzqIzq = nodoIzqIzq->izquierda;
//     nodoIzqIzqIzq->izquierda = crearNodo('b', 2);
//     nodoIzqIzqIzq->derecha = crearNodo('c', 7);
//
//     NodoHuffman* nodoIzqIzqDer = nodoIzqIzq->derecha;
//
//     int numCaracteres = 6;
//     TablaHuffman tabla[numCaracteres];
//     char codigoActual[10];
//     int indice = 0;
//
//     construirTabla(raiz, codigoActual, 0, tabla, &indice);
//
//     printf("Caso 1: Entrada 'b', Salida: %s\n", huffman(tabla, numCaracteres, 'b'));
//     printf("Caso 2: Entrada 'c', Salida: %s\n", huffman(tabla, numCaracteres, 'c'));
//
//     liberarArbol(raiz);
//     return 0;
// }
