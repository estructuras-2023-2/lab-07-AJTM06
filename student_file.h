#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Metodo llamado Torneo 
//Parametros vector<int> habilidades, int N, int K
//Metodo denominacion: vector<int> Torneo(vector<int>, int N, int K)
vector<int> Torneo (vector<int> habilidades, int N, int K){
    //Numero de jugadores, ganador, perdedor, juegos ganados
    int jugadores = habilidades.size();
    int ganador = habilidades[0];
    int perdedor = habilidades[1];
    int j_ganados = 0;
    //Retornar vector<int> 
    vector<int> resultado; 
    /*se coloca max y min para que en habilidades[0] y habilidades[1], 
    salga ganador el que tenga mayor valor de habilidades y 
    para el perdedor el minimo valor*/
    //ganador = max(habilidades[0], habilidades[1]);
    //perdedor = min(habilidades[0], habilidades[1]);
    /*El juego empieza en 1 y este lo juegan los de habilidades[0] 
    habilidades[1] que en este caso serian gandor y perdedor*/
     for (int juego = 1; juego < K; juego++) {
         /*Se determinar un ganador(si gano N juegos seguidos)
         y el otro seria el perdedor*/
       if (j_ganados >= N) {
            swap(ganador, perdedor);
            j_ganados = 0;
        }

        if (juego == K) {
            resultado = {perdedor, ganador};
            return resultado;
        }

        int siguiente_jugador = (j_ganados < N - 1) ? 2 : (j_ganados == N - 1) ? N : N - 1;
        ganador = max(ganador, habilidades[siguiente_jugador]);
        perdedor = min(perdedor, habilidades[siguiente_jugador]);

        j_ganados++;
    }

    return resultado;
}