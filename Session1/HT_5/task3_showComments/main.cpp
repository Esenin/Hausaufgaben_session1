#include <iostream>
#include "commentWriter.h"

using namespace std;

void findLineComments(char const fileName[])
{
    CommentWriter commFinder(fileName);
    commFinder.writeLineComments();
}

void sample()
{
    cout << "This is sample #1 for file 'main.cpp':\n";
    findLineComments("main.cpp");
    cout << "end of test.\n";
}

int main()
{
    //test comment
    //sample();       Uncomment this for autotest "main.cpp"

    /*
      big comment must not be written:
        // fake comment
      */

    int const maxNameLen = 255; //post-line comment
    cout << "Write filename with file extension (ex. main.cpp) :\n";
    char fileName[maxNameLen] = {};
    cin.getline(fileName, maxNameLen);

    findLineComments(fileName);

    return 0;
}

