// Copyright (c) 2015, Guillaume Durandau and Massimo Sartori
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// - Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "TranslateOpenSimCEINMS.h"

TranslateOpenSimCEINMS::TranslateOpenSimCEINMS()
{

	//					CEINMS/OpenSim

	//5 DOF
	translate_.insert(position("R_hip_fe", "hip_flexion_r"));
	translate_.insert(position("R_hip_aa", "hip_adduction_r"));
	translate_.insert(position("R_hip_rot", "hip_rotation_r"));
	translate_.insert(position("R_knee_fe", "knee_angle_r"));
	translate_.insert(position("R_ankle_fe", "ankle_angle_r"));

	// 35 Muscles
	translate_.insert(position("addbrev_r", "add_brev_r"));
	translate_.insert(position("addlong_r", "add_long_r"));
	translate_.insert(position("addmag1_r", "add_mag1_r"));
	translate_.insert(position("addmag2_r", "add_mag2_r"));
	translate_.insert(position("addmag3_r", "add_mag3_r"));
	translate_.insert(position("bicfemlh_r", "bifemlh_r"));
	translate_.insert(position("gmax1_r", "glut_max1_r"));
	translate_.insert(position("gmax2_r", "glut_max2_r"));
	translate_.insert(position("gmax3_r", "glut_max3_r"));
	translate_.insert(position("gmed1_r", "glut_med1_r"));
	translate_.insert(position("gmed2_r", "glut_med2_r"));
	translate_.insert(position("gmed3_r", "glut_med3_r"));
	translate_.insert(position("gmin1_r", "glut_min1_r"));
	translate_.insert(position("gmin2_r", "glut_min2_r"));
	translate_.insert(position("gmin3_r", "glut_min3_r"));
	translate_.insert(position("gra_r", "grac_r"));
	translate_.insert(position("illiacus_r", "iliacus_r"));
	translate_.insert(position("psoas_r", "psoas_r"));
	translate_.insert(position("recfem_r", "rect_fem_r"));
	translate_.insert(position("sar_r", "sar_r"));
	translate_.insert(position("semimem_r", "semimem_r"));
	translate_.insert(position("semiten_r", "semiten_r"));
	translate_.insert(position("tfl_r", "tfl_r"));
	translate_.insert(position("perbrev_r", "per_brev_r"));
	translate_.insert(position("bicfemsh_r", "bifemsh_r"));
	translate_.insert(position("gaslat_r", "lat_gas_r"));
	translate_.insert(position("gasmed_r", "med_gas_r"));
	translate_.insert(position("perlong_r", "per_long_r"));
	translate_.insert(position("perter_r", "per_tert_r"));
	translate_.insert(position("sol_r", "soleus_r"));
	translate_.insert(position("tibant_r", "tib_ant_r"));
	translate_.insert(position("vasint_r", "vas_int_r"));
	translate_.insert(position("vaslat_r", "vas_lat_r"));
	translate_.insert(position("vasmed_r", "vas_med_r"));
}

TranslateOpenSimCEINMS::TranslateOpenSimCEINMS(const string& filename)
{
	ifstream nameFile(filename.c_str());
	if (!nameFile.is_open())
	{
		cout << "ERROR: " << filename << " could not be open\n";
		exit(EXIT_FAILURE);
	}
	while(!nameFile.eof())
	{
		string word1, word2, line;
		getline(nameFile, line);
		if(nameFile.eof())
			break;
		stringstream ss(line);
		getline(ss, word1, '\t');
		getline(ss, word2, '\t');
//		cout << word1 << " ; " << word2 << endl;
		translate_.insert(position(word1, word2));
	}
}
