/*
Copyright 2023 Om Rawaley (@omrawaley)

This file is part of T-Write++.

T-Write++ is free software: you can redistribute it and/or modify it under the terms of the GNU General 
Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
option) any later version.

T-Write++ is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even 
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with T-Write++. If not, see 
<https://www.gnu.org/licenses/>. 
*/

#pragma once

#include <string>

class Cursor
{
	private:
		std::string::size_type cursorIndex;

	public:
		void moveCursorLeft();
		void moveCursorRight();

		std::string::size_type getCursorIndex();
		void setCursorIndex(std::string::size_type cursorIndex);
};

extern Cursor cursor;