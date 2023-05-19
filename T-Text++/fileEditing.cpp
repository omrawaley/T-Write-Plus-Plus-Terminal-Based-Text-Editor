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

        std::cout << "Editing: " << filename << "  " << saved;
        std::cout << "\n" << "————————————————————————————————————————————————————————————————————————————" << "\n\n"; 
        std::cout << fileContent;

        system("stty -echo"); //only works on Unix-like systems (MacOS, Linux, etc.)
        system("stty raw"); //only works on Unix-like systems (MacOS, Linux, etc.)
        
        int key = getc(stdin);

        system("stty echo"); //only works on Unix-like systems (MacOS, Linux, etc.)
        system("stty cooked"); //only works on Unix-like systems (MacOS, Linux, etc.)

        if(key == Keys::grave)
        {
            std::ofstream fileSave(filename);

            fileSave << fileContent;

            saved = saveStatus.saved;
        }
        else if(key == Keys::enter)
        {
            fileContent += "\n";

            saved = saveStatus.notSaved;
        }
        else if(key == Keys::backspace)
        {
            fileContent = fileContent.substr(0, fileContent.length() - 1);

            saved = saveStatus.notSaved;
        }
        else if(key == Keys::esc)
        {
            fileContent = "";

            file.close();

            std::cout << "\n";

            menu.selectAction();
        }
        else
        {
            fileContent += key;

            saved = saveStatus.notSaved;
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