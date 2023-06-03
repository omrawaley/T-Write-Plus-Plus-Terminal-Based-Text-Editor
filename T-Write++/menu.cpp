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

#include "menu.h"
#include "fileEditing.h"

void Menu::selectAction()
{
    std::string choice;

    std::cout << "\n> ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == "help")
    {
        this->help();
    }

    if(choice == "license")
    {
        this->license();
    }

    if(choice == "path")
    {
        //this->setPath();
    }

    if(choice == "quit")
    {
        exit(true);
    }

    if(choice == "read")
    {
        fileEditing.readFile(getFilename());
    }

    if(choice == "edit")
    {
        fileEditing.editFile(getFilename());
    }

    if(choice == "create")
    {
        fileEditing.createFile(getFilename());
    }

    if(choice == "delete")
    {
        fileEditing.deleteFile(getFilename());
    }
}

void Menu::help()
{
    std::cout << "\nSyntax:\n";

    std::cout << "\nread: read file";
    std::cout << "\nedit: edit file";
    std::cout << "\ncreate: create file";
    std::cout << "\ndelete: delete file";
    //std::cout << "\npath: set command line path";
    std::cout << "\nlicense: copyright/license";
    std::cout << "\nquit: quit program\n\n";

    std::cout << "File Editing:\n";

    std::cout << "\nGrave (`): save file";
    std::cout << "\nEnter: insert newline";
    std::cout << "\nBackspace: delete last character";
    std::cout << "\nESC: return to menu\n";

    std::cout << "\nCTRL + J: move cursor left";
    std::cout << "\nCTRL + L: move cursor right\n";

    menu.selectAction();
}

void Menu::license()
{
    std::string projectLicense = 
    "Copyright 2023 Om Rawaley (@omrawaley)\n\nT-Text++ is free software: you can redistribute it and/or modify it under the terms of the GNU General \nPublic License as published by the Free Software Foundation, either version 3 of the License, or (at your \noption) any later version.\n\nT-Text++ is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even \nthe implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the \nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License along with T-Text++. If not, see \n<https://www.gnu.org/licenses/>.\n"; 

    std::cout << "\n" << projectLicense;

    menu.selectAction();
}

std::string Menu::getFilename()
{
    std::string filename;

    std::cout << "\nFilename: ";

    std::getline(std::cin, filename);

    return filename;
}

void Menu::setPath()
{
    
}