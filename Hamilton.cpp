// Hamilton.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

const int n = 8;
int tab[n][n];
int A[n];
int iter = 0;

void dp(int w, int k) {
	if (w >= 0 && w < n && k >= 0 && k < n) {
		tab[w][k] = 1;
		std::cout << w << "->" << k << std::endl;
	}
	else {
		std::cout << "Niepoprawne wierzcholki" << std::endl;
	}
}

void wypiszCykl(int c[]) {
	for (int i = 0; i < n-1; i++) {
		std::cout << c[i] << "-";
	}
	std::cout << c[n - 1] << std::endl;
}

void wypiszTablice() {
	std::cout << "\n\nMacierz:\n\n";
	for (int w = 0; w < n; w++) {
		for (int k = 0; k < n; k++) {
			std::cout << tab[w][k];
		}
		std::cout << std::endl;
	}
}

void szukajCykle(std::list<int>& wezly, int st) {
	if (st == n - 1) {
		A[st] = wezly.front();
		if (tab[A[st]][A[0]] == 1) {
			wypiszCykl(A);
		}
	}
	else {
		for (int i = 0; i < wezly.size(); i++) {
			A[st] = wezly.front();
			wezly.pop_front();
			if (tab[A[st - 1]][A[st]] == 1) {
				szukajCykle(wezly, st + 1);
			}
			wezly.push_back(A[st]);
		}
	}
}


int main()
{
	std::vector <int> wezlyA;
	std::list <int> wezlyB;
	int wezlyT[n];
	for (int i = 1; i < n; i++) {
		wezlyA.push_back(i);
		wezlyT[i] = i;
	}
	for (int i = 1; i < n; i++) {
		wezlyB.push_back(i);
	}

	std::cout << "\n\nPolaczenia:" << std::endl;
	//dodawanie połączeń -  dp(w, k): z 'w' do 'k':
	dp(1, 2);

	dp(2, 1);
	dp(2, 3);
	dp(2, 0);

	dp(3, 0);

	dp(4, 5);

	dp(5, 1);
	dp(5, 3);
	dp(5, 4);

	dp(6, 4);

	dp(7, 6);
	dp(7, 5);

	dp(0, 7);

	//wypisanie macierzy:
	wypiszTablice();

	std::cout << "\n\nCykle:\n" << std::endl;

	A[0] = 0;
	szukajCykle(wezlyB, 1);

	std::cin.get();
}


