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
    MyDSMC(double v0_rec, double akn_rec);
    int dsmc();

private:
    //  グローバル変数
    int flag_body_rotate;
    double rgas, v0, t0, d, twall, akn, vref, tref, r_uni, mol_mass, p0, rho;
    double xmin , xmax, ymin, ymax, zmin, zmax;
    double xbody1, xbody2, ybody1, ybody2;
    double body_point[sides][2][2];
    double I ;							//質量の無次元化はする？
    double dx, dy, body_dx, body_dy;
    int nlast, nlp, ns;
    double dtv, dtc, dt;
    double fgmax, gmax, mass_particle, mass_part_2;	    //無次元化はする？？
    int nmol;												//<----危ないかも

    int lc[mx][my], lc0[mx][my];
    std::vector<int> lcr;
    std::vector<std::vector<int>> i_j_cel;

//////////////////大きな配列の置き場所/////////////////////////
    std::vector<std::vector<double>> particle_x_y, particle_x_y_new, particle_c, particle_c_new, grid_density;
    std::vector<double> velocity_data;

//    double (*particle_x_y)[2] = new double[nmax][2];				//粒子の位置 [x座標][y座標]		ただし、[0]の値は使わないとする。
//    double (*particle_x_y_new)[2] = new double[nmax][2];
//    double (*particle_c)[3] = new double[nmax][3];				//粒子の速度 [速度u][速度v]		上と同じ
//    double (*particle_c_new)[3] = new double[nmax][3];
//    double (*grid_density)[my] = new double[mx][my];					//グリッド内の粒子密度
//    double (*velocity_data) = new double[nmax];

//格子の座標を定義
    double xgrid[mx + 1][my + 1], ygrid[mx + 1][my + 1];
    double xcg[mx][my], ycg[mx][my], area[mx][my], col[mx][my];

////格子内での平均値
    double rou[mdx][mdy], u[mdx][mdy], v[mdx][mdy], smol[mdx][mdy], u1[mdx][mdy], v1[mdx][mdy], w1[mdx][mdy];
    double su1[mdx][mdy], sv1[mdx][mdy],sw1[mdx][mdy];

////Body 表面にグリッドを張る
    double body_xgrid[B_mx], body_ygrid[B_my];
    double xbody_force_x[2][B_my], xbody_force_y[2][B_my], xbody_energy[2][B_my];
    double ybody_force_x[2][B_mx], ybody_force_y[2][B_mx], ybody_energy[2][B_mx];

    /*-------------------------------------------------関数の宣言--------------*/
//int body_collision(int mol, double dtfly, double part_x, double part_y, double part_cx, double part_cy, double part_hit[7]);
    int particle_injection(double xbuf1, double xbuf2, double ybuf1, double ybuf2, std::vector<std::vector<double>> &part_xy, std::vector<std::vector<double>> &part_c);
    int re_indexing(std::vector<std::vector<double>> &part_xy, std::vector<std::vector<double>> &part_c, int lc[][my],std::vector<int> &lcr, int lc0[][my], std::vector<std::vector<int>> &i_j_cel);
    int collision(std::vector<std::vector<double>> &part_xy, std::vector<std::vector<double>> &part_c, double col[mx][my], int lc[][my], std::vector<int> &lcr, int lc0[][my]);
    double uniform_random();
    double min_thit(double thit[4]);
    double injection_update(double xzone1, double xzone2, double yzone1, double yzone2, std::vector<std::vector<double>> &part_xy, std::vector<std::vector<double>> &part_c);
    double body_force_and_heat(double part_hit[], double c_x, double c_y, double xbody_force_x[][B_my], double xbody_force_y[][B_my], double xbody_energy[][B_my], double ybody_force_x[][B_mx], double ybody_force_y[][B_mx], double ybody_energy[][B_mx]);
    double line_body_collsion(int mol, double body_point_pair[][2][2], double dtfly, double part_x, double part_y, double part_cx, double part_cy, double part_hit[]);
    double rotation(double theta, double xy[], double after_xy[]);
    double angle_vectors(double vect_x, double vect_y);
    double body_rotate(double theta);
    double delete_particle_in_body();
    double calc_torque(double hit_x, double hit_y, double u, double v);
    double intersec_lines(double a_bef[2], double b_bef[2], double a_aft[2], double b_aft[2], double c[2]);
    double near_point_on_line(double a_bef[2], double b_bef[2], double d[2]);
    double rotate_collsion_line(double dtheta, double sum_torque);
    double c_new_generate(double a_dash[2], double b_dash[2], double theta_sign, double v_part_new[2]);
    double check_particle_in_body();
/*-------------------------------------------------------------------------*/
};


#endif //DSMC_RECT_MYDSMC_H
