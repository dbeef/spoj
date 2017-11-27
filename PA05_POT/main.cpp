#include <iostream>

using namespace std;

int main() {

    //1 indeks jaka jest ostatnia cyfra podstawy
    //3 jaki jest wynik modulo przez komórkę z modulo[]
    unsigned short results[10][1][4] = {
            {       //0
                    {0}
            },{
                    //1
                    {1}
            },{
                    //2
                    {6, 2, 4, 8}
            },{
                    //3
                    {1, 3, 9, 7}
            },{
                    //4
                    {6, 4}
            },{
                    //5
                    {5}
            },{
                    //6
                    {6}
            },{
                    //7
                    {1, 7, 9 ,3}
            },{
                    //8
                    {6, 8, 4, 2}
            },{
                    //9
                    {1, 9}
            },
    };

    unsigned short modulo[] = {1, 1, 4, 4, 2};

    //Pattern na modulo: 1 4 4 2 1
    //Modulo przez 5
    //Dla 1 - 1
    //Dla 2 - 4
    //Dla 3 - 4
    //Dla 4 - 2
    //Dla 0 - 1

    //Liczba: 1
    //Potęgi 1 2 3 4 5 6 7 8 9
    //Wyniki:1 1 1 1 1 1 1 1 1
    //Powtarzanie: [1]

    //Liczba: 2
    //Potęgi 1 2 3 4  5  6  7   8   9
    //Wyniki:2 4 8 16 32 64 128 256 512
    //Powtarzanie: [2 4 8 6]
    //Modulo przez 4:
    //1 - 2
    //2 - 4
    //3 - 8
    //0 - 6

    //Liczba: 3
    //Potęgi 1 2 3  4   5
    //Wyniki:3 9 27 81  243
    //Powtarzanie: [3 9 7 1]
    //Modulo przez 4:
    //1 - 3
    //2 - 9
    //3 - 7
    //0 - 1

    //Liczba: 4
    //Potęgi 1 2  3  4    5
    //Wyniki:4 16 64 256  1024
    //Powtarzanie: [4 6]
    //Modulo przez 2:
    //1 - 4
    //0 - 6

    //Liczba: 5
    //Potęgi 1 2  3   4
    //Wyniki:5 25 125 625
    //Powtarzanie: [5]
    //Modulo przez 1:
    //0 - 5

    //Liczba: 6
    //Potęgi 1 2  3   4
    //Wyniki:6 36 216 1296
    //Powtarzanie: [6]
    //Modulo przez 1:
    //0 - 6

    //Liczba: 7
    //Potęgi 1 2  3   4    5
    //Wyniki:7 49 343 2401 16807
    //Powtarzanie: [7 9 3 1]
    //Modulo przez 4:
    //1 - 7
    //2 - 9
    //3 - 3
    //0 - 1

    //Liczba: 8
    //Potęgi 1 2  3   4    5
    //Wyniki:8 64 512 4096 32768
    //Powtarzanie: [8 4 2 6]
    //Modulo przez 4:
    //1 - 8
    //2 - 4
    //3 - 2
    //0 - 6

    //Liczba: 9
    //Potęgi 1 2  3   4    5
    //Wyniki:9 81 729 6561 59049
    //Powtarzanie: [9 1]
    //Modulo przez 2:
    //1 - 9
    //0 - 1

    //Liczba: 10
    //Potęgi 1
    //Wyniki:10
    //Powtarzanie: [0]
    //Modulo przez 1:
    //0 - 0



    //Pomijam potęgi x^1

    long n;
    cin >> n;

    long cases[n][2];

    for(long a =0;a<n;a++)
        cin >> cases[a][0] >> cases[a][1];

    for(long a =0;a<n;a++){

        if(cases[a][0] == 1) {
            cout << 1 << '\n';
            continue;
        }
        if(cases[a][1] == 1) {
            cout << cases[a][0] << '\n';
            continue;
        }

        unsigned short moduloDivisorIndex = (cases[a][0] % 5);
//        cout << "Modulo divisor index: " << moduloDivisorIndex << endl;

        unsigned short moduloDivisor = modulo[moduloDivisorIndex];
//        cout << "Modulo divisor: " << moduloDivisor << endl;

        unsigned short lastDigit = cases[a][0] % 10;
//        cout << "Last digit: " << lastDigit << endl;

        long moduloIndex = cases[a][1] % moduloDivisor;
//        cout << "Modulo index: " << moduloIndex << endl;

        cout << results[lastDigit][0][moduloIndex] << '\n';
    }

    cout << endl;

    return 0;
}