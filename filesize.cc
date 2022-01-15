#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1
//

int countLines(char* argv[], int arg);

int main( int argc, char* argv[] )
{
    std::cout << "program: " << argv[0] << '\n';
    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 1; arg < argc; ++arg)
            std::cout << " " << argv[arg] << ": " << countLines(argv, arg) << '\n' ;

    exit(0); // this means that the program executed correctly!
}

int countLines(char* argv[], int arg){
    int count = 0;
    string line;
    ifstream file(argv[arg]);

    // Check to see if the file failed to open
    if(file.fail()){
        return -1;
    }

    while(!file.eof()){
        getline(file, line);
        // Blank lines are not being counted in this project
        if(line != ""){
            count++;
        }
    }

    file.close(); // Always close the file after use

    return count;
}
