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

#ifndef MTUSPLINEINTERFACE_H_
#define MTUSPLINEINTERFACE_H_

#ifdef WIN32
#include <windows.h>
#endif

#include <string>
#include <vector>
#include "MTUSplineDataRead.h"
#include "ExecutionXmlReader.h"
#include <memory>

using namespace std;

class MTUSplineInterface
{
public:
	MTUSplineInterface();
	MTUSplineInterface(const std::string& subjectSpecificXml, /*!< CEINMS specific XML */const std::string& subjectName /*!< Name of the subject */);
	~MTUSplineInterface();

	vector< vector<double> > getMA();
	vector<double> getLMT();
	void setPosition(vector<double> position);
	void initialisation();
	void initialisationFromXML();
	void setDOFName(vector<string> DofName);
	void setMusclesNamesOnDof(std::vector<std::vector<std::string> > 	musclesNamesOnDof);
	void setMuscleName(std::vector<std::string> muscleNames);
	std::vector<std::string> getMuscleName();
	std::vector<std::vector<std::string> > getMusclesNamesOnDof();
	vector<string> getDOFName();


protected:

	// Template function for Spline computation with order > 1 
	template<class T>
	void computeLmtMafromSplines(
		T& splines, int dim,
		const std::vector<double>& angles, std::vector<double>& lmt,
		std::vector<std::vector<double> >& ma
	);

	// Template function for Spline conputation with order 1
	void computeLmtMafromSplines(
		std::vector<std::shared_ptr<MTUSpline<1> > >& splines,
		const std::vector<double>& angles, std::vector<double>& lmt,
		std::vector<std::vector<double> >& ma
	);

	std::vector<std::vector<std::string> > 	musclesNamesOnDof_; /*!< Name of the muscle on the different DOF from the model */
	std::vector<std::string> 				dofNames_; 			/*!< Dof name from the model */
	std::vector<std::string>				muscleNames_;
	std::string 							subjectSpecificXml_;/*!< CEINMS subject XML */
	std::string 							subjectName_;		/*!< name of the subject */
	std::string 							executionName_;		/*!< name of the execution XML */
	std::vector<std::vector<double> >		ma_;
	std::vector<double>						lmt_;
	std::vector<MTUSplineDataRead::Task>	taskMTU_;
	int										noMuscles_;
	MTUSplineDataRead*						splineData_;
};

#endif