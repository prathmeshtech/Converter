// #include <iostream>

// using namespace std;

// int main()
// {
// cout << "solid circle" << endl;
// cout << "    "
//      << "facet normal" << endl;
// cout << "        "
//      << "outerloop" << endl;
// cout << "        "
//      << "endloop" << endl;
// cout << "    "
//      << "endfacet" << endl;
// cout << "  "
//      << "endsolid circle";
// cout << "solid circle" << endl;
// std::cout << std::string(4, ' ');
// cout << "facet normal" << endl;
// std::cout << std::string(8, ' ');
// cout << "outerloop" << endl;

//     return 0;
// }

// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "Hello";
    ofstream onfile;
    onfile.open("C:/Users/Admin/Desktop/CCTech/Assignment_1/Parser(Obj_To_Stl)/stlfile.stl");
    onfile << "facet normalheell yeah" << endl;
    onfile << "    outerloop" << endl;
    // onfile << vertex_pos[v[0]] << endl;
    // onfile << vertex_pos[v[0 + 1]] << endl;
    // onfile << vertex_pos[v[0 + 2]] << endl;
    onfile << "    endloop" << endl;
    onfile << "endfacet" << endl;
    onfile << "        Hello" << endl;
    onfile.close();
    return 0;
}


    // cout << "solid cube" << endl;
    // for (int i = 0; i < vertex_pos.size(); i++)
    // {
    //     cout << "    facet normal" << endl;
    //     cout << "        outerloop" << endl;
    //     cout << "            vertex"
    //          << " ";
    //     for (int j = 0; j < vertex_pos[0].size(); j += 9)
    //     {
    //         cout << vertex_pos[i][j] << " ";
    //         cout << vertex_pos[i][j + 1] << " ";
    //         cout << vertex_pos[i][j + 2] << " " << endl;
    //         cout << "            vertex"
    //              << " ";
    //         cout << vertex_pos[i][j + 3] << " ";
    //         cout << vertex_pos[i][j + 4] << " ";
    //         cout << vertex_pos[i][j + 5] << " " << endl;
    //         cout << "            vertex"
    //              << " ";
    //         cout << vertex_pos[i][j + 6] << " ";
    //         cout << vertex_pos[i][j + 7] << " ";
    //         cout << vertex_pos[i][j + 8] << " ";
    //     }
    //     cout << endl;
    //     cout << "        endloop" << endl;
    //     cout << "    endfacet" << endl;
    // }
    // cout << "endsolid cube";