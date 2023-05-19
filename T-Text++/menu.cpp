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

    /*if(choice == "path")
    {
        this->setPath();
    }*/

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

    menu.selectAction();
}

void Menu::license()
{
    std::string projectLicense = 
    "Copyright 2023 Om Rawaley (@omrawaley)\n"
    "\n"
    "Licensed under the Apache License, Version 2.0 (the \"License\");\n"
    "you may not use this file except in compliance with the License.\n"
    "You may obtain a copy of the License at\n"
    "\n"
    "    http://www.apache.org/licenses/LICENSE-2.0\n"
    "\n"
    "Unless required by applicable law or agreed to in writing, software\n"
    "distributed under the License is distributed on an \"AS IS\" BASIS,\n"
    "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
    "See the License for the specific language governing permissions and\n"
    "limitations under the License.\n";

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
    std::string path;

    std::cout <<"\nPath: ";

    std::cin >> path;
}