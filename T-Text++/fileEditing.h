/*
	Copyright 2023 Om Rawaley (@omrawaley)

    This file is part of T-Text++.

    T-Text++ is free software: you can redistribute it and/or modify it under the terms of the GNU General 
	Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
	option) any later version.

    T-Text++ is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even 
	the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
	GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with T-Text++. If not, see 
	<https://www.gnu.org/licenses/>. 
*/

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class FileEditing
{
	private:
		struct SaveStatus
		{
			std::string saved = "File Saved";
			std::string notSaved = "File not saved";
		};
		
		struct Keys
		{
			static constexpr int grave = 96;
			static constexpr int enter = 13;
			static constexpr int backspace = 127;
			static constexpr int esc = 27;
		};

	public:
		void readFile(std::string filename);
		void editFile(std::string filename);
		void createFile(std::string filename);
		void deleteFile(std::string filename);

	SaveStatus saveStatus;
};

extern FileEditing fileEditing;