//
// Created by 服部篤樹 on 2018/10/24.
//

#ifndef DSMC_RECT_MYDSMC_H
#define DSMC_RECT_MYDSMC_H

#include <stdio.h>
#include <cmath>
#include <random>
#include <iostream> //入出力ライブラリ
#include <fstream> //iostreamのファイル入出力をサポート
#include <time.h>     // for clock()
#include <vector>       // ヘッダファイルインクルード

#include "mydef.h"		//define を集めてある場所

class MyDSMC {
public:
    int dsmc(double v0, double akn, double dt);

private:
    const int flag_body_rotate;
    const double rgas, t0, d, twall, vref, tref, r_uni, mol_mass, p0, rho;
    const double xmin , xmax, ymin, ymax, zmin, zmax;
    const double xbody1, xbody2, ybody1, ybody2;
    const int sides = 8;				//物体の辺の数
    double body_point[sides][2][2];
    const double I ;							//質量の無次元化はする？
    const double dx, dy, body_dx, body_dy;
    const int nlast, nlp, ns;
    const double fgmax, gmax, mass_particle, mass_part_2;	    //無次元化はする？？
    int nmol;												//<----危ないかも

//////////////////大きな配列の置き場所/////////////////////////

    double (*particle_x_y)[2];				//粒子の位置 [x座標][y座標]		ただし、[0]の値は使わないとする。
    double (*particle_x_y_new)[2];
    double (*particle_c)[3];				//粒子の速度 [速度u][速度v]		上と同じ
    double (*particle_c_new)[3];
    double (*grid_density)[my];					//グリッド内の粒子密度
    double (*velocity_data);

//格子の座標を定義
    double xgrid[mx + 1][my + 1] = {};
    double ygrid[mx + 1][my + 1] = {};
    double xcg[mx][my] = {};
    double ycg[mx][my] = {};
    double area[mx][my] = {};
    double col[mx][my] = {};

////格子内での平均値
    double rou[mdx][mdy] = {};
    double u[mdx][mdy] = {};
    double v[mdx][mdy] = {};
    double smol[mdx][mdy] = {};
    double u1[mdx][mdy] = {};
    double v1[mdx][mdy] = {};
    double w1[mdx][mdy] = {};
    double su1[mdx][mdy] = {};
    double sv1[mdx][mdy] = {};
    double sw1[mdx][mdy] = {};

////Body 表面にグリッドを張る
    double body_xgrid[B_mx] = {};
    double body_ygrid[B_my] = {};

    double xbody_force_x[2][B_my] = {};
    double xbody_force_y[2][B_my] = {};
    double xbody_energy[2][B_my] = {};
    double ybody_force_x[2][B_mx] = {};
    double ybody_force_y[2][B_mx] = {};
    double ybody_energy[2][B_mx] = {};

};


#endif //DSMC_RECT_MYDSMC_H
