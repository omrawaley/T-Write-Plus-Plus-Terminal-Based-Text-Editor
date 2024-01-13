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

#include <iostream>

#include "src/menu.h"
#include "src/fileEditing.h"

Menu menu;
FileEditing fileEditing;
Cursor cursor;

int main()
{
    std::cout << "\nT-Write++  1.1.0\n";
    std::cout << "\nType \"help\" for a list of commands.\n";

    menu.selectAction();
}