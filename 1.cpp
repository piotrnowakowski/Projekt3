// projekt_Nowakowski.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void display_macierz(double** mac, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("  %.4lf  ", mac[i][j]);
        printf("\n");
    }
}
void LU_decomp(double** mat, double** upper, double** lower, double** diagonal, int n)
{

    diagonal[0][0] = mat[0][0];
    // building diagonal
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum = sum + (lower[i][k] * upper[k][i] * diagonal[k][k]);
            }
            
            diagonal[i][i] = mat[i][i] - sum;
           
        }
  
        // upper triandular 
        for (int j = i; j < n; j++)  // czy tak ma być czy ma być  i o co chodzi ? 
        {
            if (j == 0)
            {
                upper[0][i] = mat[0][i] / diagonal[0][0];
            }
            else
            {
                // Summation of L(i, j) * U(j, k)
                double sum = 0;
                for (int k = 0; k < i; k++)
                    sum += (lower[i][k] * upper[k][j] * diagonal[k][k]);

                // Evaluating U(i, k)
            //System.out.println("i= " + i + " diagonal = " + diagonal[i][i]);
                upper[i][j] = (mat[i][j] - sum) / diagonal[i][i];
            }
        }
        // Lower triangular
        for (int j = i; j < n; j++)
        {
            if (j == 0)
            {
                lower[i][0] = mat[i][0] / diagonal[0][0];
            }
            else
            {
                // Summation of L(k, j) * U(j, i)
                double sum = 0;
                for (int k = 0; k < i; k++)
                    sum += (lower[j][k] * upper[k][i] * diagonal[k][k]);
                // Evaluating L(k, i)
                lower[j][i] = (mat[j][i] - sum) / diagonal[i][i];
            }
        }
    }
}

void wypelnij_mac(double** mac, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("podaj cały rząd macierz\n");
        for (int i = 0; i < n; i++)
        {
            printf("liczba %d to ", i);
            int x = 0;
            scanf_s("%d", &x);
            double y = 0;
            y = (double)x;
            mac[j][i] = y;
        }
    }
}

int rozwiaz_rownanie(double** mat, double** upper, double** lower, double** diagonal, int n)
{

}
void zeruj(double** mac, int  n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            mac[j][i] = 0;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "pl_PL");


    int n = 3;
    printf("podaj rząd macierzy");
    scanf_s("%d", &n);

    //////////////////////// alokacje pamięci
    double** diagonal;
    diagonal = (double**)malloc(sizeof(double*) * n);
    if (!diagonal) printf("coś sie popsuło");
    for (int i = 0; i < n; i++)
    {
        diagonal[i] = (double**)malloc(sizeof(int*) * n);
        if (!diagonal[i]) printf("coś sie popsuło");
    }
    double** lower;
    lower = (double**)malloc(sizeof(double*) * n);
    if (!lower) printf("coś sie popsuło");
    for (int i = 0; i < n; i++)
    {
        lower[i] = (double**)malloc(sizeof(double*) * n);
        if (!lower[i]) printf("coś sie popsuło");
    }
    double** upper;
    upper = (double**)malloc(sizeof(double*) * n);
    if (!upper) printf("coś sie popsuło");
    for (int i = 0; i < n; i++)
    {
        upper[i] = (double**)malloc(sizeof(double*) * n);
        if (!upper[i]) printf("coś sie popsuło");
    }
    double** mac;
    mac = (double**)malloc(sizeof(double*) * n);
    if (!mac) printf("coś sie popsuło");
    for (int i = 0; i < n; i++)
    {
        mac[i] = (double**)malloc(sizeof(double*) * n);
        if (!mac[i]) printf("coś sie popsuło");
    }
    ////////////////////
    zeruj(diagonal, n);
    display_macierz(diagonal, n);
    zeruj(upper, n);
    zeruj(lower, n);

    wypelnij_mac(mac, n);
    display_macierz(mac, n);
    
    LU_decomp(mac, upper, lower, diagonal, n);
    printf("macierz główna \n");
    display_macierz(mac, n);
    printf("macierz górnotrójkątna \n");
    display_macierz(upper, n);
    printf("macierz dolnotrójkątna \n");
    display_macierz(lower, n);
    printf("macierz diagonalna \n");
    display_macierz(diagonal, n);


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
