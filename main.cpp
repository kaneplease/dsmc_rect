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
//    for(double v = 1000; v <= 10000; v += 500){
//        for(double akn = 0.1; akn <= 1.0; akn += 0.1){
//            MyDSMC calc(v, akn);
//            calc.dsmc();
//        }
//    }
    MyDSMC calc(8000, 0.4);
    calc.dsmc();
    std::cout << "finished" << std::endl;
    return 0;
}