#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct town
{
    int code;
    string state;
    string name;
    int pop;
    float area;
    float latitude;
    float longitude;
    int xRoad; //code for representative road intersection
    float xDist; //distance to intersection
};

unsigned int hashf(string s)
{
    unsigned int h = 987123654; // replace with my own prime multipler
    for (int i = 0; i < s.length(); i++)
        h = h * s[i];
    //if (h < 0)
    //    h = -h;
    return h;
}


vector<town> readFile(istream& stream)
{
    string line;
    vector<string> lines;
    vector<town> out;
    
    town t;

    int n = 0;
    while (getline(stream, line))
    {
        //if (!stream.eof())
        if (n < 2)
        {
            //line += "\n\n";
            cout << line;
            lines.push_back(line);

            // loop through characters
            // 0 - 7 : numeric code
            // 8 - 9 : state
            // t.state =
            //cout << line.substr(8, 9);

            //for (int i = 0; i < line.length(); i++)
            //{
            //    //cout << line;
            //        string code;
            //        //t.code = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
            //        //cout << t.code;
            //    
            //}

            n += 1;
        }
        out.push_back(t);
    }

    for (int i = 0; i < 1; i++)
    {
        cout << lines[i];// .substr(8, 9);
    }

    //for (int i = 0; i < out.size(); i++)
    //    cout << out[i].code;
    return out;
}

// int main(int argc, char* argv[])
int main()
{
    ifstream f;
    string path = "C:/Users/Amelia/Documents/town_database.txt";

    f.open(path);

    if (f.fail())
    {
        cout << "Could not open fle at path " << path << "\n";
        exit(1);
    }

    int size = 2;
    town towns[100];

    string lines[100];

    vector<town> t = readFile(f);
    //cout << file;

    // if (argc != 3)
    // {
    //     cerr << "wrong args\n";
    //     exit(1);
    // }

    //int size = 100000;
    //town towns[100000];

    //for (int i = 0; i < size; i++)
    //{
    //    lines[i] = readFile()
    //    f//  >> lines[i];

    //    cout << lines[i];

    // /*   f >> towns[i].code >> towns[i].state >> towns[i].name >> towns[i].pop
    //        >> towns[i].area >> towns[i].latitude >> towns[i].longitude >> towns[i].xRoad >> towns[i].xDist;*/


    //    if (f.fail())
    //        break;

    //    //cout << towns[i].code << towns[i].state << towns[i].name << towns[i].pop
    //    //    << towns[i].area << towns[i].latitude << towns[i].longitude << towns[i].xRoad << towns[i].xDist;
    //}

    //for (int i = 0; i < size; i++)
    //{
    //    cout << towns[i].code << towns[i].state << towns[i].name << towns[i].pop
    //        << towns[i].area << towns[i].latitude << towns[i].longitude << towns[i].xRoad << towns[i].xDist;
    //}
}
