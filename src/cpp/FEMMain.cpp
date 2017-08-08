/***************************************************************/
/*  FEM++ ��A C++ finite element method code for teaching      */
/*     Computational Dynamics Laboratory                       */
/*     School of Aerospace Engineering, Tsinghua University    */
/*                                                             */
/*     http://www.comdyn.cn/                                   */
/***************************************************************/

#include "FEM.h"
#include "Truss.h"
#include "Outputter.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) //  Print help message
	{
	    cout << "Usage: FEM++ InputFileName\n";
		exit(1);
	}

	string filename(argv[1]);
	string InFile = filename + ".dat";
	string OutFile = filename + ".out";

	FileReader* Reader = new FileReader(InFile);

	FEM* FEMData = FEM::Instance();

	if (!FEMData->Initial(Reader))
	{
		cout << "Input Failed!" << endl;
		exit(1);
	}

	Outputter* Output = Outputter::Instance(OutFile);
	Output->OutputLogo();
	Output->OutputNodeInfo();

	FEMData->GenerateFreedom();
	
	FEMData->AllocateStiffnessMatrix();
	
	FEMData->AssemblyStiffnessMatrix();
	
	LDLTSolver* S = new LDLTSolver(FEMData);
	S->Solve();
	
	return 0;
}