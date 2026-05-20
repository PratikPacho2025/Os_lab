#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

char M[100][4];
char R[4];
char IR[4];
int IC;
bool C;
char Buffer[41];
ifstream inputFile;
ofstream outputFile;

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = ' ';
        }
    }
    for (int i = 0; i < 4; i++) {
        R[i] = ' ';
        IR[i] = ' ';
    }
    IC = 0;
    C = false;
}

void READ() {
    int row = (IR[2] - '0') * 10 + (IR[3] - '0');
    if (inputFile.getline(Buffer, 41)) {
        int k = 0;
        int len = strlen(Buffer);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 4; j++) {
                if (k < len) M[row + i][j] = Buffer[k++];
                else M[row + i][j] = ' ';
            }
        }
    }
}

void WRITE() {
    int row = (IR[2] - '0') * 10 + (IR[3] - '0');
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            outputFile << M[row + i][j];
        }
    }
    outputFile << endl;
}

void TERMINATE() {
    outputFile << endl << endl;
}

void MOS(int SI) {
    if (SI == 1) READ();
    else if (SI == 2) WRITE();
    else if (SI == 3) TERMINATE();
}

void startExecution() {
    while (true) {
        for (int i = 0; i < 4; i++) {
            IR[i] = M[IC][i];
        }
        IC++;

        int row = (IR[2] - '0') * 10 + (IR[3] - '0');

        if (IR[0] == 'G' && IR[1] == 'D') {
            MOS(1);
        } else if (IR[0] == 'P' && IR[1] == 'D') {
            MOS(2);
        } else if (IR[0] == 'H') {
            MOS(3);
            break;
        } else if (IR[0] == 'L' && IR[1] == 'R') {
            for (int i = 0; i < 4; i++) R[i] = M[row][i];
        } else if (IR[0] == 'S' && IR[1] == 'R') {
            for (int i = 0; i < 4; i++) M[row][i] = R[i];
        } else if (IR[0] == 'C' && IR[1] == 'R') {
            C = true;
            for (int i = 0; i < 4; i++) {
                if (R[i] != M[row][i]) {
                    C = false;
                    break;
                }
            }
        } else if (IR[0] == 'B' && IR[1] == 'T') {
            if (C) IC = row;
        }
    }
}

void LOAD() {
    int m = 0;
    while (inputFile.getline(Buffer, 41)) {
        if (Buffer[0] == '$' && Buffer[1] == 'A' && Buffer[2] == 'M' && Buffer[3] == 'J') {
            init();
            m = 0;
        } else if (Buffer[0] == '$' && Buffer[1] == 'D' && Buffer[2] == 'T' && Buffer[3] == 'A') {
            startExecution();
        } else if (Buffer[0] == '$' && Buffer[1] == 'E' && Buffer[2] == 'N' && Buffer[3] == 'D') {
            continue;
        } else {
            int len = strlen(Buffer);
            for (int i = 0; i < len; i += 4) {
                for (int j = 0; j < 4; j++) {
                    if (i + j < len) M[m][j] = Buffer[i + j];
                    else M[m][j] = ' ';
                }
                m++;
            }
        }
    }
}

int main() {
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    if (!inputFile.is_open()) return 1;
    LOAD();
    inputFile.close();
    outputFile.close();
    return 0;
}
