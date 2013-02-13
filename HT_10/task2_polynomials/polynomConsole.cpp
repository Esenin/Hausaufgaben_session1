#include "polynomConsole.h"

PolynomConsole::PolynomConsole() :
    maxPolynoms(50),
    listCount(0)
{
    polynomArray = new PolynomList[maxPolynoms];
}

PolynomConsole::~PolynomConsole()
{
    delete[] polynomArray;
}

void PolynomConsole::polynomMaker()
{
    int input = -1;
    do
    {
        clearScreen();
        cout << "Enter number what do you want:\n";
        cout << "1) Create new polynom\n"
             << "2) Edit one of polynoms\n"
             << "3) Delete some polynom\n"
             << "4) Show all available\n"
             << "0) go back\n";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            createPolynome();
            break;
        }
        case 2:
        {
            editPolynom();
            break;
        }
        case 3:
        {
            deletePolynome();
            break;
        }
        case 4:
        {
            showAllPolynoms();
            waiting();
            break;
        }
        }
    }
    while (input != 0);

}

void PolynomConsole::polynomeProcessor()
{
    int input = -1;
    do
    {
        clearScreen();
        cout << "Enter number what do you want:\n";
        cout << "1) Create and edit some polynomes (Polynomes Editor)\n"
             << "2) Add two polynomes to a new one\n"
             << "3) Calculate polynome with x-param\n"
             << "4) Check if is two poynomes equal\n"
             << "5) Show all available polynomes\n"
             << "0) exit\n";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            polynomMaker();
            break;
        }
        case 2:
        {
            pollynomesAdditor();
            break;
        }
        case 3:
        {
            calculate();
            break;
        }
        case 4:
        {
            checkEquals();
            break;
        }
        case 5:
        {
            showAllPolynoms();
            waiting();
            break;
        }
        }
    }
    while (input != 0);
}

void PolynomConsole::createPolynome()
{
    clearScreen();
    cout << "With your polynome  a1 *x^y1 + a2 *x^ y2 + ... + aN *x^ yN \n"
         << "Enter just coefficient and degree of component  a[i] y[i]:\n"
         << "Put '0 0' as finish indicator\n"
         << "Sample:  x^2 -3*x + 7 input:  1 2   -3 1   7 0   0 0\n"
         << "Input here:   ";

    int factor = 0;
    int degree = 0;
    cin >> factor;
    cin >> degree;
    while (factor != 0 || degree != 0)
    {
        polynomArray[listCount].addPrimitiveComponent(factor, degree);
        cin >> factor;
        cin >> degree;
    }
    cout << endl;
    if (polynomArray[listCount].isEmpty())
        return;

    cout << "Your new polynom based at number " << listCount << endl;
    cout << "Your polynom is:\n";
    polynomArray[listCount].printPolynom();
    listCount++;
    waiting();
}

void PolynomConsole::waiting()
{
    char x;
    cout << "\ntype any char to continue...\n";
    cin >> x;
}

void PolynomConsole::showAllPolynoms()
{
    if (listCount < 1)
    {
        cout << "There are no polynomes\n";
        return;
    }

    cout << "Here all polynoms:\n";
    for (int i = 0; i < listCount; i++)
    {
        cout << i << ") ";
        polynomArray[i].printPolynom();
    }
    cout << endl;
}

void PolynomConsole::editPolynom()
{
    showAllPolynoms();
    cout << "Enter number of polynome which you want to edit or '-1' to go back:\n";
    int index = -1;
    cin >> index;
    if (index < 0)
        return;

    cout << "You've chosen:\n";
    polynomArray[index].printPolynom();
    cout << "Now you can edit polynome by adding components\n"
         << "e.x. to delete component 7*x^3 you must add -7*x^3 by typing '-7 3'\n"
         << "input 0 0 to finish:\n";
    int degree = 0;
    int factor = 0;
    cin >> factor;
    cin >> degree;
    while (factor != 0 || degree != 0)
    {
        polynomArray[index].addPrimitiveComponent(factor, degree);
        cout << "current polynome is: ";
        polynomArray[index].printPolynom();
        cout << "input:\n";
        cin >> factor;
        cin >> degree;
    }
    waiting();
}

void PolynomConsole::clearScreen()
{
    #ifdef WIN32
        std::system ( "CLS" );
    #else
         std::system ( "clear" );
    #endif
}


void PolynomConsole::deletePolynome()
{
    showAllPolynoms();
    cout << "Input number of polynome you want to delete or '-1' to go back :\n";
    int index = -1;
    cin >> index;
    if (index < 0)
        return;

    polynomArray[index].clearList();
    cout << "done\n";
    waiting();
}

void PolynomConsole::pollynomesAdditor()
{
    clearScreen();
    showAllPolynoms();
    cout << "Type two polynomes you want to add at new one\n"
         << "New polynome will have id " << listCount << endl
         << "Input '-1 -1' to go back\n";
    int left = -1;
    int right = -1;
    cin >> left;
    cin >> right;
    if (left < 0 || right < 0 || left >= listCount || right >= listCount)
        return;

    PolynomList *buffer = PolynomList::add(polynomArray[left], polynomArray[right]);
    polynomArray[listCount].copyConstructor(buffer);
    delete buffer;

    cout << "Here new polynome with id = " << listCount << endl;
    polynomArray[listCount].printPolynom();
    listCount++;
    waiting();
}

void PolynomConsole::checkEquals()
{
    clearScreen();
    showAllPolynoms();
    cout << "Type two polynomes you want to check on equaling\n"
         << "Input '-1 -1' to go back\n";
    int left = -1;
    int right = -1;
    cin >> left;
    cin >> right;
    if (left < 0 || right < 0)
        return;

    if (PolynomList::equals(polynomArray[left], polynomArray[right]))
        cout << "True\n";
    else
        cout << "False\n";
    waiting();
}

void PolynomConsole::calculate()
{
    clearScreen();
    showAllPolynoms();
    cout << "Type id of polynome you want to calculate with x-param\n"
         << "Input '-1' to go back\n";
    int index = -1;
    cin >> index;

    if (index < 0)
        return;

    cout << "Now input X - value:\n";
    int param = 0;
    cin >> param;
    cout << "Answer is:\n" << polynomArray[index].getValue(param);
    waiting();
}


