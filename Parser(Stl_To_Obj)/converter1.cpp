#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class converter
{
public:
    unordered_map<string, int> mppvertex;
    vector<string> mppvertexvec;
    vector<string> vecface;
    vector<string> vx;
    vector<string> vy;
    vector<string> vz;
    vector<int> f1;
    vector<int> f2;
    vector<int> f3;

    unordered_map<string, int> mppnormal;
    vector<string> mppnormalnor;
    vector<string> norface;
    vector<int> fn;
    int count = 0;

public:
    void writeOnFile()
    {
        ofstream onfile;
        onfile.open("objfile.obj");
        onfile << "Converted by Prathmesh Singh" << endl;

        for (auto itr : mppvertex)
        {
            onfile << "v"
                   << " " << itr.first << endl;
        }
        onfile << "#normal" << endl;
        for (auto i : mppnormal)
        {
            onfile << "vn"
                   << " " << i.first << endl;
        }
        onfile << "#Faces" << endl;

        for (int i = 0; i < f1.size(); i++)
        {
            onfile << "f"
                   << " "
                   << f1[i] + 1
                   << "/"
                   << fn[i] + 1
                   << " " << f2[i] + 1 << "/"
                   << fn[i] + 1
                   << " " << f3[i] + 1 << "/"
                   << fn[i] + 1 << endl;
        }
        onfile.close();
    }

public:
    void readingFile(void)
    {
        ifstream file("cube.stl");

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

                else if (strcmp(arr, "vertex") == 0) // if we got vertex (vertices)
                {
                    string x, y, z;
                    file >> x >> y >> z;
                    string vertex = x + " " + y + " " + z;

                    vecface.push_back(vertex);

                    if (mppvertex.find(vertex) == mppvertex.end())
                    {
                        mppvertex[vertex] = 1;
                        mppvertexvec.push_back(vertex);
                    }
                }

                else if (strcmp(arr, "facet") == 0) // If there is facet normal;
                {
                    count++;
                    string nw, nx, ny, nz;
                    file >> nw >> nx >> ny >> nz;

                    string normal = nx + " " + ny + " " + nz;
                    // cout << normal << endl;
                    norface.push_back(normal);

                    if (mppnormal.find(normal) == mppnormal.end())
                    {
                        mppnormal[normal] = 1;
                        mppnormalnor.push_back(normal);
                    }
                }
            }
            // cout << count << endl;
            for (int i = 0; i < vecface.size() - 2; i += 3)
            {
                // cout << i << " " << vecface[i] << endl;
                vx.push_back(vecface[i]);
                vy.push_back(vecface[i + 1]);
                vz.push_back(vecface[i + 2]);
            }

            for (int p = 0; p < vx.size(); p++)
            {
                for (int q = 0; q < mppvertexvec.size(); q++)
                {
                    if (vx[p] == mppvertexvec[q])
                    {
                        f1.push_back(q);
                    }
                }
            }
            // for (int i = 0; i < f1.size(); i++)
            // {
            //     cout << i << " " << f1[i] + 1 << endl;
            // }

            for (int m = 0; m < vy.size(); m++)
            {
                for (int n = 0; n < mppvertexvec.size(); n++)
                {
                    if (vy[m] == mppvertexvec[n])
                    {
                        f2.push_back(n);
                    }
                }
            }

            for (int a = 0; a < vz.size(); a++)
            {
                for (int b = 0; b < mppvertexvec.size(); b++)
                {
                    if (vz[a] == mppvertexvec[b])
                    {
                        f3.push_back(b);
                    }
                }
            }

            for (int i = 0; i < norface.size(); i++)
            {
                for (int j = 0; j < mppnormalnor.size(); j++)
                {
                    if (norface[i] == mppnormalnor[j])
                    {
                        fn.push_back(j);
                    }
                }
            }

            // for (int i = 0; i < fn.size(); i++)
            // {
            //     cout << i << " " << fn[i] + 1 << endl;
            // }
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
    converter c1;
    c1.readingFile();
    // writeOnFile();
    return 0;
}
