/*
 *    WiFiBeat - Parse 802.11 frames and store them in ElasticSearch
 *    Copyright (C) 2017 Thomas d'Otreppe de Bouvette 
 *                       <tdotreppe@aircrack-ng.org>
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CONFIG_STRUCTS_H
#define CONFIG_STRUCTS_H

#include "hopping.h"
#include "decryptionKeys.h"
#include "outputBase.h"
#include "es.h"
#include <string>
#include <vector>
#include <map>


using std::string;
using std::vector;
using std::map;

struct PCAPOutputStruct {
	bool enabled;
	string prefix;
	PCAPOutputStruct() : enabled(false), prefix("") { }
};

struct persistentQueueStruct {
	bool enabled;
	unsigned int maxSize;
	string directory;
	persistentQueueStruct() : enabled(false), maxSize(1000) { }
};

struct LogstashConnection : outputBeatBase{
	int pipelining; // 0
	string proxyURL;
	bool loadBalance; // true
	bool proxyUseLocalResolver; // false
	LogstashConnection() : pipelining(0), proxyURL(""), loadBalance(true), proxyUseLocalResolver(false) { }
};

#endif // CONFIG_STRUCTS_H