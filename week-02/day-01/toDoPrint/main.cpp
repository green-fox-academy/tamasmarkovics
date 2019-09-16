#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string todoText = " - Buy milk\n";
    // Add "My todo:" to the beginning of the todoText
    todoText.insert(0, "todo:\n");
    // Add " - Download games" to the end of the todoText
    todoText.append(" - Donlod gamez\n");
    todoText.append("    - Diablo\n");
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::cout << todoText << std::endl;

    return 0;
}