#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream saldoA; 
    saldoA.open("saldo.txt", ios::binary);
    int pare;
    saldoA.read((char*)&pare, sizeof(pare));
    saldoA.close();
    int ulog, n = 1, m = 7, temp1, temp2, broj, priv, number, brojac = 0, odabir, tim1, tim2, novac, choice, pobjeda, o, a, u, unos;
    time_t t;
    printf("\n=====================================================");
    printf("\n||          --------------------------------       ||");
    printf("\n||        |Dobrodosli u Online kladionicu Gogi|    ||");
    printf("\n||          --------------------------------       ||");
    printf("\n||                                                 ||");
    printf("\n||                    |Menu igara|                 ||");
    printf("\n||                                                 ||");
    printf("\n||   1.Utrka konja                                 ||");
    printf("\n||   2.Loto 7/39                                   ||");
    printf("\n||   3.Bingo                                       ||");
    printf("\n||   4.Nogomente utakmice                          ||");
    printf("\n||   5.Izlaz                                       ||");
    printf("\n||                                                 ||");
    printf("\n=====================================================");
    printf("\nUnesite broj novac koji zelite staviti na racun: ");
    cin >> pare;
    while(1)
    { 
        printf("\n\nUpisite broj igre koju zelite igrati:");
        scanf("%d", &odabir);
        if (odabir == 1)
        {
            printf("\n\t\t\t\t|Dobrodosli u Utrku konja|\n\nPravila igre:Izaberite jedan broj izmedu 1 i 5 koji ce odgovarati broju vaseg konja.\nUkratko utrka se sastoji od 5 konja i samo je jedan pobjednik.\nVas dobitak ovisiti ce o poziciji vaseg konja u utrci.\n\n");
        }
        else if (odabir == 2)
        {
            printf("\n\t\t\t\t|Dobrodosli u Loto 7/39|\n\nPravila igre: morate izabrati 7 brojeva izmedu 1 i 39.\nKolicina pogodenih brojeva ce odgovarati svoti novca koju ste osvojili.\nBrojeve upisujete jedan po jedan.\n");
        }
        else if (odabir == 3)
        {
            printf("\n\t\t\t\t\t|Dobrodosli u Bingo|\n\nPravila igre: Da bi zapoceli ovu igru potrebno je unaprijed uloziti 100kn.\nU ovoj igri ce se nasumicno izabrati tri broja izmedu 1 i 9.\nAko se brojevi ponove dva ili tri puta osvajate nagradu ovisno o kolicini ponovljenih brojeva.");
            printf("\n\nZelite li zapoceti igru tako da ulozite 100kn?(1==DA/2==NE): ");
            scanf("%d", &ulog);
            if (ulog == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    srand(time(NULL));
                    int a = rand() % 10;
                    int b = rand() % 10;
                    int c = rand() % 10;
                    printf("\n\nDobijeni brojevi su:: |%d|%d|%d|", a, b, c);
                    if (a == b || b == c || a == c)
                    {
                        printf("\n\nCestitamo.\nOsvojili ste 200kn.\n");
                        pare += 200;
                    }
                    else if (a == b == c)
                    {
                        printf("Cestitamo na pobjedi.\nOsvojili ste 500kn.\n");
                        pare += 500;
                    }
                    else
                    {
                        printf("\n\nNazalost niste nista osvojili.\nVise srece drugi put.\n");
                    }
                }
            }
            else
            {
                exit(1);
            }
        }
        if (odabir == 1)
        {
            srand((unsigned)time(&t));
            for (int i = 0; i < n; i++)
            {
                printf("Izaberite broj konja na kojeg se kladite:  ");
                scanf("%d", &broj);
                if (broj < 1 || broj>5)
                {
                    printf("\nUpisali ste krivi broj! Pokusajte ponovno.\n\n\n");
                    exit(1);
                }
                temp1 = rand() % 6;
            }
            if (temp1 == broj)
            {
                printf("\nPobijedili ste.\n");
                printf("Vas dobitak je 500kn.\n\n\n");
                pare += 500;
            }
            else
            {
                printf("\nNiste pobijedili.\n");
                do
                {
                    srand((unsigned)time(&t));
                    for (int j = 0; j < n; j++)
                    {
                        temp2 = rand() % 6;
                    }
                } while (temp2 == 0 || temp2 == 1);
                printf("Konj na kojeg ste se kladili je zavrsio %d.\n", temp2);
                if (temp2 == 2)
                {
                    printf("Vas dobitak je 250kn.\n\n\n");
                    pare += 250;
                }
                else if (temp2 == 3)
                {
                    printf("Vas dobitak je 100kn.\n\n\n");
                    pare += 100;
                    
                }
                else if (temp2 > 3)
                {
                    printf("Vas konj je bio toliko los da niste nista osvojili. Vise srece drugi put!\n\n\n");
                }
            }
        }
        else if (odabir == 2)
        {
            srand((unsigned)time(&t));
            for (int x = 0; x < m; x++)
            {
                printf("\nUpisite broj: ");
                scanf("%d", &number);
                if (number < 1 || number>39)
                {
                    printf("Upisali ste pogresan broj");
                }
                do
                {
                    srand((unsigned)time(&t));
                    for (int y = 0; y < m; y++)
                    {
                        priv = rand() % 40;
                    }
                } while (priv == 0);
                if (number == priv)
                {
                    brojac++;
                    printf("Pogodili ste dobar broj(%d)\n", number);
                }
            }
            for (int i = 0; i <= 21; i++)
            {
                if (brojac == i)
                {
                    printf("\nPogodeni brojevi: %d\n", i);
                    printf("Dobitak: %dkn\n", i = i * 1000);
                    pare += i;
                }
            }
        }
        else if (odabir == 4)
        {
            srand(time(NULL));
            tim1 = rand() % 4;
            tim2 = rand() % 4;
            printf("\n                   |Nogometne utakmice|");
            printf("\n\nUtakmice na koje se mozete kladiti su:");
            printf("\n\n1.AGF Aarhus-Randers FC");
            printf("\n2.Guadalupe FC-Perez Zeledon");
            printf("\n3.Vit.Guimaraes-Vit.Setubal");
            printf("\n4.Maritimo Fun-Benfica Lis");
            printf("\n5.Pacos Ferreira-FC Porto");
            printf("\n6.Skala IF-AB Argir");
            printf("\n7.KI Klaksvik-EB Streymur");
            printf("\n8.Sporting San Jose-AD Carmelita");
            printf("\n9.Tsitsipas S.-Thompson J.");
            printf("\n\nUpisite broj utakmice na koju se zelite kladiti:");
            scanf("%d", &o);
            if (o == 1)
            {
                printf("\n\t\t\t|1.AGF Aarhus-2.Randers FC|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 2)
            {
                printf("\n\t\t\t|1.Guadalupe FC-2.Perez Zeledon|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 3)
            {
                printf("\n\t\t\t|1.Vit.Guimaraes-2.Vit.Setubal|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 4)
            {
                printf("\n\t\t\t|1.Maritimo Fun-2.Benfica Lis|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 5)
            {
                printf("\n\t\t\t|1.Pacos Ferreira-2.FC Porto|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 6)
            {
                printf("\n\t\t\t|1.Skala IF-2.AB Argir|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 7)
            {
                printf("\n\t\t\t|1.KI Klaksvik-2.EB Streymur|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 8)
            {
                printf("\n\t\t\t|1.Sporting San Jose-2.AD Carmelita|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (o == 9)
            {
                printf("\n\t\t\t|1.Tsitsipas S.-2.Thompson J.|");
                printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: ");
                scanf("%d", &choice);
            }
            if (choice == 0 && tim1 > tim2)
            {
                printf("Prvi tim je pobjedio.Niste nista osvojili.");
            }
            else if (tim1 > tim2)
            {
                printf("\nPobijedio je vas tim, sa rezultatom %d:%d", tim1, tim2);
                pare = pare * 3;
                printf("\nOsvojili ste %dkn.", pare);

            }
            else if (choice == 0 && tim2 > tim1)
            {
                printf("Pobjedio je drugi tim.Niste nista osvojili.");
            }
            else if (tim2 > tim1)
            {
                printf("\nPobijedio je protivnicki tim, sa rezultatom %d:%d", tim1, tim2);
                printf("\nNiste nista osvojili, vas tim je izgubio.");

            }
            else if (choice == 0 && tim1 == tim2)
            {
                pare = pare * 3;
                printf("Utakmica je odigrana izjednaceno.Osvojili ste: %dkn", pare);
            }
            else if (tim1 == tim2)
            {
                printf("\nUtakmica je odigrana izjednaceno, sa rezultatom %d:%d", tim1, tim2);
            }
        }
        else if (odabir == 5)
        {
        break;
        }
    } 
    cout << "Dovidenja" << endl;
    ofstream saldo;
    saldo.open("saldo.txt", ios::binary);
    saldo.write((char*)&pare,sizeof(pare));
    saldo.close();
    return 0;
}