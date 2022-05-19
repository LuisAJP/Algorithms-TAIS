#include<iostream>
#include<fstream>
#include<vector>
//#include<functional>
#include<algorithm>//sort
using namespace std;


//Coste es O (NlogN), donde N es el numero de usuarios
bool resuelveCaso(){
	int P;//Peso Maximo telesilla de 2 plazas
	int N;//numero de usuarios
	cin >> P >> N;
	if (!cin)return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	//Coste es O (NlogN), donde N es el numero de usuarios
 	sort(v.begin(),v.end(),less<>());
	int telesilla = 0;
	int i = 0;
	for (int j = N-1; i <= j; j--){
		if (v[i] + v[j] <= P)
			i++;
		telesilla++;
	}
	cout << telesilla << "\n";
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