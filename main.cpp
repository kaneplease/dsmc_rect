// myDSMC.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
//質量だけ無次元化してない
#define _USE_MATH_DEFINES // for C
//#define M_PI 3.1415926535

#include <stdio.h>
#include <cmath>
#include <random>
#include <iostream> //入出力ライブラリ
#include <fstream> //iostreamのファイル入出力をサポート
#include <time.h>     // for clock()
#include <vector>       // ヘッダファイルインクルード

#include "mydef.h"		//define を集めてある場所
#include "MyDSMC.h"

int main(){
    MyDSMC calc;
    calc.dsmc();
    return 0;
}