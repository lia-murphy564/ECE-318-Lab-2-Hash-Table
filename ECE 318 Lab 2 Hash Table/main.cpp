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
//code state name                                               pop         area      long      lat     xroad   xdist
// 64200100PAAaronsburg                                           485      0.520877 40.900946 -77.453383 7795  7.6972

vector<town> readFile(istream& stream)
{
    string line;


    vector<town> out;

    while (getline(stream, line))
    {
        if (!stream.eof())
        {
            string parse;
            string parsed;

            string others;

            //line += "\n";
            parse += line;
            town t;

            string x = line;

            istringstream iss;

            for (int i = 0; i < line.size(); i++)
            {
                if (i < 40)
                    parsed += parse[i];
                else
                    others += parse[i];
            }
 
            iss.str(others);
            iss >> t.pop >> t.area >> t.longitude >> t.latitude >> t.xRoad >> t.xDist;

            string code, state, name;
            for (int i = 0; i < parsed.length(); i++)
            {
                if (i < 8)
                    code += parsed[i];
                else if (i < 10)
                    state += parsed[i];
                else
                    name += parsed[i];
            }

            t.code = std::stoi(code);
            t.state = state;
            t.name = name;

            out.push_back(t);
        }
    }
    //cout << out.size();
    //for (int i = 0; i < out.size(); i++)
    //{
    //    cout << out[i].code << " " << out[i].state << " " << out[i].name << " " << out[i].pop << " "
    //        << out[i].area << " " << out[i].longitude << " " << out[i].latitude << " " << out[i].xRoad << " " << out[i].xDist << "\n";
    //}
    
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
