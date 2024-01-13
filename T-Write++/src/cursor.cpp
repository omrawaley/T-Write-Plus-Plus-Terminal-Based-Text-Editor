/*
Copyright 2023-2024 Om Rawaley (@omrawaley)

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

#include "cursor.h"

std::string::size_type Cursor::getCursorIndex()
{
	return(this->cursorIndex);
}

void Cursor::setCursorIndex(std::string::size_type cursorIndex)
{
	this->cursorIndex = cursorIndex;
}

void Cursor::moveCursorLeft()
{
	--this->cursorIndex;
}

void Cursor::moveCursorRight()
{
	++this->cursorIndex;
}