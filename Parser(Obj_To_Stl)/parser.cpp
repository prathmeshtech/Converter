#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class Parser
{
public:
    vector<string> facet;
    vector<string> vertex_pos;
    vector<int> vx;
    vector<int> vy;
    vector<int> vz;
    vector<int> vn;

public:
    void writeOnFile()
    {
        ofstream onfile;
        onfile.open("stlfile.stl");
        onfile << "solid cube" << endl;

        for (int i = 0; i < vx.size(); i++)
        {

            onfile << "    facet normal"
                   << " " << vertex_pos[vx[i] - 1] << endl;
            // << " " << facet[i] << endl
            onfile << "        outerloop" << endl;
            onfile << "            vertex"
                   << " " << vertex_pos[vx[i] - 1] << endl;
            onfile << "            vertex"
                   << " " << vertex_pos[vy[i] - 1] << endl;
            onfile << "            vertex"
                   << " " << vertex_pos[vz[i] - 1] << endl;
            onfile << "        endloop" << endl;
            onfile << "    endfacet" << endl;
        }
        onfile << "endsolid cubePS";
        onfile.close();
    }

public:
    void readingFile(void)
    {
        bool read_vn = false;

        ifstream file("obj_human.obj");

        if (file.is_open())
        {
            while (file.eof() == 0)
            {
                char arr[255];
                file >> arr;

                if (strcmp(arr, "#") == 0)
                {
                    file.getline(arr, 255);
                }

                else if (strcmp(arr, "v") == 0) // if we got v (vertices)
                {
                    string x, y, z;
                    file >> x >> y >> z;
                    string vertex = x + " " + y + " " + z;
                    // cout << vertex << endl;
                    vertex_pos.push_back(vertex);
                }

                else if (strcmp(arr, "vn") == 0) // If there is vertex normal;
                {
                    read_vn = true;
                    string nx, ny, nz;
                    file >> nx >> ny >> nz;

                    string normal = nx + " " + ny + " " + nz;
                    // cout << normal << endl;
                    facet.push_back(normal);
                }

                else if (strcmp(arr, "f") == 0) // when we come across faces;
                {
                    for (int i = 0; i < 3; i++)
                    {
                        string fa, fb, fc;
                        file >> fa >> fb >> fc;
                        // cout << fa[0] << " " << fb[0] << " " << fc[0] << endl;
                        int a = stoi(fa);
                        int b = stoi(fb);
                        int c = stoi(fc);
                        vx.push_back(a);
                        vy.push_back(b);
                        vz.push_back(c);

                        // cout << fa[2] << " " << fb[2] << " " << fc[2] << endl;
                        int normal1 = stoi(fa);
                        // cout << normal1 << endl;
                        vn.push_back(fa[2]);

                        break;
                    }
                }
            }
            for (int i = 0; i < vx.size(); i++)
            {
                cout << vertex_pos[vx[i] - 1] << endl;
                cout << vertex_pos[vy[i] - 1] << endl;
                cout << vertex_pos[vz[i] - 1] << endl;
                cout << endl;
            }
            writeOnFile();
        }
        else
        {
            cout << "Cant Find File";
        }

        file.close();
    }
};

int main()
{
    Parser p1;
    p1.readingFile();
    // writeOnFile();
    return 0;
}
