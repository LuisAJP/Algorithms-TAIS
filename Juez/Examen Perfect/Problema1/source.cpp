#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include "PriorityQueue.h"
using namespace std;

/*
Problema1 Bases en Marte
Autor: Luis Alberto Jaramillo Pulido
team: TAIS36
*/

typedef struct{
	int id;
	int duracion;
	int carga;
}tInfo;


bool operator <(const tInfo a,const tInfo &b){
	return a.duracion < b.duracion || a.duracion == b.duracion && a.id < b.id;
}



//Coste O(BlogB + R) donde B es el numero de baterias y R es el numero de repuesto de baterias
//El coste de insertar las baterias con la operacion push O(logB)
//El coste de insertar las baterias de repuesto con la operacion push O(R) usando colas
//El coste de ir actualizando la duracion de las baterias usando push y pop(ambos tienen coste logB), 

bool resuelveCaso(){
	int B;//numero de baterias
	cin >> B;
	if (!cin)return false;
	PriorityQueue<tInfo> pq;
	tInfo info;
	for (int i = 1; i <= B; i++){//O(BlogB)
		info.id = i;
		cin >> info.duracion;
		info.carga = info.duracion;
		pq.push(info);//O(logB)
	}
	int R;//numero baterias de repuesto
	cin >> R;
	queue<tInfo>q;
	for (int i = 1; i <= R;i++){//O(R)
		info.id = B + i;
		cin >> info.duracion;
		info.carga = info.duracion;
		q.push(info);//O(1)
	}
	int P;//Penalización de recarga
	int T;//tiempo de consulta
	int p;
	cin >> P >> T;
	bool salir=false;
	while (pq.size()>0 && !salir){
		info = pq.top(); pq.pop();//O(logB)
		if (info.duracion>T){
			pq.push(info);//O(logB)
			salir = true;
		}
		else{
			p = info.carga - P;//tiempo al restarle la penalizacion
			if (p <= 0){//Necesita bateria de repuesto
				if (!q.empty()){//si existen baterias de repuesto
					info.carga = q.front().carga;
					info.duracion = info.duracion + q.front().duracion;
					info.id = q.front().id;
					q.pop();//O(1)
					pq.push(info);//O(logB)
				}
			}
			else{//al efectuar la recarga se actualiza la duracion de la bateria y la carga 
				info.carga = p;
				info.duracion=info.duracion + p;
				pq.push(info);//O(logB)
			}
		}
	}
	if (!pq.empty()){
		if (pq.size() == B)
			cout << "CORRECTO\n";
		else
			cout << "FALLO EN EL SISTEMA\n";
		while (pq.size() > 0){
			info = pq.top(); pq.pop();
			cout << info.id << " " << info.duracion << "\n";
		}
			
	}
	else
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
	cout << "---\n";
	return true;
}

int main(){

#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}