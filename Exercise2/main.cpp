#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double map(double val) // map the point in the interval [-1,2]
{
    double a = 3./4;
    double b = -7./4;
    return a*val + b;
}

int main()
{
    string fileName = "data.csv";
    ifstream fsr(fileName);

    if(fsr.fail())
    {
        cerr << "File doesn't exist" << endl;
        return 1;
    }

    double val = 0;
    unsigned int n = 0;
    double sumVal = 0;
    string header = "N Mean";

    ofstream outFile("result.csv");
    outFile << header << endl; // add the required header

    while(fsr >> val)
    {
        val = map(val);
        n++;
        sumVal += val;
        double meanVal = sumVal / n; // compute the mean of the first n mapped values
        outFile << fixed << setprecision(16) << scientific << meanVal << endl; // print the result in the required file
    }

    fsr.close();
    outFile.close();

    return 0;
}
