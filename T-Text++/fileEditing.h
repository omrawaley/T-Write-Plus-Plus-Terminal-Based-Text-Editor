#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
/*
Copyright 2023 Om Rawaley (@omrawaley)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

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