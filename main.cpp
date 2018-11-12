// myDSMC.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
//質量だけ無次元化してない
#define _USE_MATH_DEFINES // for C
//#define M_PI 3.1415926535

#include <cmath>
#include <random>
#include <iostream> //入出力ライブラリ
#include <fstream> //iostreamのファイル入出力をサポート
#include <vector>       // ヘッダファイルインクルード
// #include <omp.h>

#include "mydef.h"		//define を集めてある場所
#include "MyDSMC.h"

int main(){
    double v = 1000;
    double akn = 0.4;

//    #pragma omp parallel for
    for(int i = 0; i<100; i++){
        MyDSMC calc(v, akn);
        calc.dsmc();
    }
    return 0;
}

