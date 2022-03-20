#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum class blockType { AIR, DIRT, STONE_BLOCK, GRASS_BLOCK, STONE, WOOD, LEAVES, SAND, SNOWY_GRASS_BLOCK, SNOW_BLOCK, ICE };

struct structure {
    string name;
    int x_size, y_size;
    blockType* blocks;
    structure(string cname, int x, int y, vector<blockType> cBlocks) {
        name = cname;
        x_size = x;
        y_size = y;
        blocks = new blockType[x * y];
        for (int i = 0; i < x * y; i++)
            blocks[i] = cBlocks[i];
    }
};

void createDataBlock() {
    vector<structure> structures;
    structures.push_back(structure("Random", 3, 3, {blockType::WOOD, blockType::SNOWY_GRASS_BLOCK, blockType::AIR,
                                                    blockType::GRASS_BLOCK, blockType::AIR, blockType::AIR,
                                                    blockType::AIR, blockType::SNOW_BLOCK, blockType::SAND,
                                                    }));
    ofstream structureFile;
    structureFile.open("Structures.asset", ios::out | ios::trunc);

    for(structure& i : structures) {
        int size = (int)i.name.size() + i.x_size * i.y_size + 5;
        char *data = new char[size];
        data[0] = (char)i.name.size();
        for(int i2 = 0; i2 < i.name.size(); i2++)
            data[i2 + 1] = i.name[i2];
        char *arr_section = data + i.name.size() + 1;
        arr_section[0] = (((char)&i.x_size) + 0);
        arr_section[1] = (((char)&i.x_size) + 1);
        arr_section[2] = (((char)&i.y_size) + 0);
        arr_section[3] = (((char)&i.y_size) + 1);
        for(int i2 = 0; i2 < i.x_size * i.y_size; i2++)
            arr_section[i2 + 4] = (char)i.blocks[i2];
        structureFile.write(data, size);
    }

    structureFile.close();
}


int main() {
    string action;
    cin >> action;
    if (action == "read") {

    }
    else {
        createDataBlock();
    }
}
