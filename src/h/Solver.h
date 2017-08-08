/***************************************************************/
/*  FEM++ ��A C++ finite element method code for teaching      */
/*     Computational Dynamics Laboratory                       */
/*     School of Aerospace Engineering, Tsinghua University    */
/*                                                             */
/*     http://www.comdyn.cn/                                   */
/***************************************************************/

#pragma once

#include "FEM.h"

using namespace std;

// ������࣬�ṩ�������Ψһ�ӿ�Solve
// ʵ���µ��������Ҫ�̳д���
// ��Ҫ��FEM������ݴ洢��ʽ��ƥ��

class FEM;

class Solver
{
protected:
	FEM* FEMData;

public:
	Solver(FEM* FEMData);

	virtual void Solve() = 0;
};

// LDLT�ֽ������
// ��skyline�洢��ʽƥ��
class LDLTSolver : public Solver
{
public:
	LDLTSolver(FEM* FEMData) :Solver(FEMData) {};

	void LDLT();                // ���ܸն���ִ��LDLT�ֽ⣬�ֽ��洢��ԭλ�� 

	void ComputeDisplacement(); // ʹ�õ�ǰ������������λ�� 

	virtual void Solve();       // ��FEM����
};