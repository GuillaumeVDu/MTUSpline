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

#ifndef TRANSLATEOPENSIMCEINMS_H_
#define TRANSLATEOPENSIMCEINMS_H_

#include <vector>
using std::vector;
#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <boost/config.hpp>
#include <boost/bimap.hpp>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * Class for translating CEINMS name into OpenSim name and vice-versa.
 */
class TranslateOpenSimCEINMS
{
public:
	TranslateOpenSimCEINMS();
	TranslateOpenSimCEINMS(const string& filename);
	virtual ~TranslateOpenSimCEINMS(){}
	inline const string& OpenSimToCEINMS(const string& openSimName) const
	{
		return translate_.right.at(openSimName.c_str());
	}
	inline const string& CEINMSToOpenSim(const string& ceinmsName) const
	{
		return translate_.left.at(ceinmsName);
	}
private:
	typedef boost::bimap<string, string> bimapStrStr;
	typedef bimapStrStr::value_type position;
	bimapStrStr translate_;
};

#endif /* TRANSLATEOPENSIMCEINMS_H_ */
