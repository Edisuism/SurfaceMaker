#ifndef _DRT_H
#define _DRT_H

// For CycleDiscovery Project
// use Sum of Area Metric Only: weight = {1,0,0,0}, use interface 1
// use Sum of Edge Metric Only: weight = {0,1,0,0}, use interface 1
// use Sum of Dihedral Metric Only: weight = {0,0,1,0}, use interface 1
// use Dihedral & Board Normal Metric together: weight = {0,0,1,1} (two of 1's), use interface 2

// return type:
// 0: error, could be (a) bad input (b) no solution from MWT (c) unknown error
// 1: correct results
// 2: degenerated case, input is a plain, no result returned

// Function declarations
int delaunayRestrictedTriangulation(const double* inCurve, const int inNum, double** outCurve, int* outPn, double** outFaces, int* outNum, float* weights, bool dosmooth, int subd, int laps);

int delaunayRestrictedTriangulation(const double* inCurve, const float* inNorm, const int inNum, double** outCurve, float** outNorm, int* outPn, double** outFaces, int* outNum, float* weights, bool dosmooth, int subd, int laps);

int delaunayRestrictedTriangulation(const double* inCurve, const float* inNorm, const int inNum, double** outCurve, float** outNorm, int* outPn, int** outFaces, int* outNum, float* weights);


#endif