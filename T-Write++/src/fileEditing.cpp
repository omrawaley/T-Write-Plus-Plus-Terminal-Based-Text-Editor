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

#include "fileEditing.h"
#include "menu.h"

void FileEditing::readFile(std::string filename)
{
    std::ifstream file(filename);

    std::cout << "\n" << file.rdbuf() << "\n";

    file.close();

    menu.selectAction();
}

void FileEditing::editFile(std::string filename)
{
    std::fstream file(filename);

    std::string fileContent((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())); 

    std::string saved = saveStatus.notSaved;

    while(true)
    {
        std::cout << "\033[2J\033[1;1H";
        //system("CLS"); //if you are on Windows, comment the line above and uncomment this one

        std::cout << "Editing: " << filename << "  " << saved << "  " << "Cursor Index: " << cursor.getCursorIndex();
        std::cout << "\n" << "————————————————————————————————————————————————————————————————————————————" << "\n\n"; 
        std::cout << fileContent;

        system("stty -echo"); //only works on Unix-like systems (MacOS, Linux, etc.)
        system("stty raw"); //only works on Unix-like systems (MacOS, Linux, etc.)
        
        int key = getc(stdin);

        system("stty echo"); //only works on Unix-like systems (MacOS, Linux, etc.)
        system("stty cooked"); //only works on Unix-like systems (MacOS, Linux, etc.)

        switch(key)
        {
            case Keys::save:
            {
                std::ofstream fileSave(filename);

                fileSave << fileContent;

                saved = saveStatus.saved;
            }
                break;
            
            case Keys::enter:
                fileContent += "\n";

                cursor.setCursorIndex(cursor.getCursorIndex() + 1);

                saved = saveStatus.notSaved;
                break;

            case Keys::backspace:
                if(cursor.getCursorIndex() > 0)
                {
                    cursor.setCursorIndex(cursor.getCursorIndex() - 1);

                    fileContent.erase(cursor.getCursorIndex(), 1);
                }

                saved = saveStatus.notSaved;
                break;

            case Keys::exit:
                fileContent = "";

                file.close();

                std::cout << "\n";

                menu.selectAction();
                break;

            case Keys::cursorLeft:
                if(cursor.getCursorIndex() > 0) 
                    cursor.moveCursorLeft();
                break;

            case Keys::cursorRight:
                if(cursor.getCursorIndex() < fileContent.length())
                    cursor.moveCursorRight();
                break;

            default: 
                fileContent.insert(cursor.getCursorIndex(), 1, key);

                cursor.setCursorIndex(cursor.getCursorIndex() + 1);

                saved = saveStatus.notSaved;
                break;
        }
    }
}

void FileEditing::createFile(std::string filename)
{
    std::ofstream file(filename);

    std::cout << "\nFile successfully created.\n\n";

    std::string edit;

    std::cout << "Edit file?: ";

    std::cin >> edit;

    if(edit == "yes")
    {
        editFile(filename);
    }
    else if(edit == "no")
    {
        menu.selectAction();
    }
}

void FileEditing::deleteFile(std::string filename)
{
    remove(filename.c_str());

    std::cout << "\nFile successfully deleted.\n";

    menu.selectAction();
}