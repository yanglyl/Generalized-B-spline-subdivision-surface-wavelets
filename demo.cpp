/*

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish and distribute.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
  AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
  AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

  Copyright 2005 -   Li Yang
					 Computer Science Department
                     NUS Singapore
		     
  PLEASE DO NOT REMOVE THIS COPYRIGHT NOTICE. 
		     
 */ 

#include "Quadtree.h"
#include "Quadnode.h"
#include "Mytree.h"
#include "Mynode.h"
#include "Surface.h"
#include "SetList.h"
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

/*float Vertex[8][3] = 
{
	{0, 0, 0},
	{113, 0, 0},
	{113, 0, 113},
	{0, 0, 113},
	{113, 113, 0},
	{113, 113, 113},
	{0, 113, 113},
	{0, 113, 0}

	{20, 20, 20},
	{85, 20, 20},
	{85, 20, 85},
	{20, 20, 85},
	{85, 85, 20},
	{85, 85, 85},
	{20, 85, 85},
	{20, 85, 20}
};*/

float Vertex[8][3] = 
{
	{-6, -6, -6},
	{6, -6, -6},
	{6, -6, 6},
	{-6, -6, 6},
	{6, 6, -6},
	{6, 6, 6},
	{-6, 6, 6},
	{-6, 6, -6}
};

short Faces[6][4] = 
{
	{0,1,2,3},
	{2,5,6,3},
	{4,7,6,5},
	{1,0,7,4},
	{1,4,5,2},
	{0,3,6,7}
};

Surface* Sur = new Surface(6, 7, 8, Vertex, Faces);

void main()
{
	int i,j;
	char fname[50];

	Sur->ReadCof("IBSR_seg_11_R_Caudate_Reg.coef");
	Sur->Inv_DWT(0,6);
	Sur->MeshOut("IBSR_seg_11_R_Caudate_Reg_Level6.off",6);

	Sur->ReadCof("IBSR_seg_11_R_Caudate_Reg.coef");
	Sur->Inv_DWT(0,5);
	Sur->CC_Subd(5,6);
	Sur->MeshOut("IBSR_seg_11_R_Caudate_Reg_Level5.off",6);

	Sur->ReadCof("IBSR_seg_11_R_Caudate_Reg.coef");
	Sur->Inv_DWT(0,4);
	Sur->CC_Subd(4,6);
	Sur->MeshOut("IBSR_seg_11_R_Caudate_Reg_Level4.off",6);

	Sur->ReadCof("IBSR_seg_11_R_Caudate_Reg.coef");
	Sur->Inv_DWT(0,3);
	Sur->CC_Subd(3,6);
	Sur->MeshOut("IBSR_seg_11_R_Caudate_Reg_Level3.off",6);

	Sur->ReadCof("IBSR_seg_11_R_Caudate_Reg.coef");
	Sur->Inv_DWT(0,2);
	Sur->CC_Subd(2,6);
	Sur->MeshOut("IBSR_seg_11_R_Caudate_Reg_Level2.off",6);	

	/*for (i=1;i<=18;i++)
	{
		sprintf(fname,"IBSR_seg_%02d_R_Caudate_Reg.off",i);
		Sur->MeshIn(fname,6);
		Sur->MeshOut(fname,6);
		Sur->DWT(6,0);
		sprintf(fname,"IBSR_seg_%02d_R_Caudate_Reg.coef",i);
		Sur->SaveCof(fname);
	}*/

	/*for (j=1;j<=4;j++)
	{
		for (i=1;i<=5;i++)
		{
			sprintf(fname,"IBSR_R_Caudate_Aligned_Level%d_Plus%d.coef",j,i);
			Sur->ReadCof(fname);
			Sur->Inv_DWT(0,6);
			sprintf(fname,"IBSR_R_Caudate_Aligned_Level%d_Plus%d.off",j,i);
			Sur->MeshOut(fname,6);

			sprintf(fname,"IBSR_R_Caudate_Aligned_Level%d_Minus%d.coef",j,i);
			Sur->ReadCof(fname);
			Sur->Inv_DWT(0,6);
			sprintf(fname,"IBSR_R_Caudate_Aligned_Level%d_Minus%d.off",j,i);
			Sur->MeshOut(fname,6);
		}	
	}*/	
}
