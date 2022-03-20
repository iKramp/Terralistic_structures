#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum class blockType { NOTHING = -1, AIR, DIRT, STONE_BLOCK, GRASS_BLOCK, STONE, WOOD, LEAVES, SAND, SNOWY_GRASS_BLOCK, SNOW_BLOCK, ICE };

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

    structures.push_back(structure("Tree", 5, 12, { blockType::NOTHING, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::NOTHING,
                                                    blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES,
                                                    blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES,
                                                    blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES,
                                                    blockType::NOTHING, blockType::LEAVES, blockType::LEAVES, blockType::LEAVES, blockType::NOTHING,
                                                    blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
                                                    blockType::LEAVES, blockType::WOOD, blockType::WOOD, blockType::AIR, blockType::NOTHING,
                                                    blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
                                                    blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::WOOD, blockType::LEAVES,
                                                    blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
                                                    blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
                                                    blockType::AIR, blockType::WOOD, blockType::WOOD, blockType::WOOD, blockType::AIR,
    }));
    

    ofstream structureFile;
    structureFile.open("C:/Users/Uporabnik/source/repos/Zorz42/Terralistic/x64/Debug/Resources/Structures.asset", ios::out | ios::trunc);

    for (structure& i : structures) {
        int size = (int)i.name.size() + i.x_size * i.y_size + 3;
        char* data = new char[size];
        data[0] = (char)i.name.size();
        for (int i2 = 0; i2 < i.name.size(); i2++)
            data[i2 + 1] = i.name[i2];
        char* arr_section = data + i.name.size() + 1;
        arr_section[0] = i.x_size;
        arr_section[1] = i.y_size;
        for (int i2 = 0; i2 < i.x_size * i.y_size; i2++)
            arr_section[i2 + 2] = (char)i.blocks[i2];
        structureFile.write(data, size);
    }

    structureFile.close();


    structureFile.open("C:/Users/Uporabnik/source/repos/Zorz42/Terralistic/Client/Resources/Structures.asset", ios::out | ios::trunc);

    for (structure& i : structures) {
        int size = (int)i.name.size() + i.x_size * i.y_size + 3;
        char* data = new char[size];
        data[0] = (char)i.name.size();
        for (int i2 = 0; i2 < i.name.size(); i2++)
            data[i2 + 1] = i.name[i2];
        char* arr_section = data + i.name.size() + 1;
        arr_section[0] = i.x_size;
        arr_section[1] = i.y_size;
        for (int i2 = 0; i2 < i.x_size * i.y_size; i2++)
            arr_section[i2 + 2] = (char)i.blocks[i2];
        structureFile.write(data, size);
    }

    structureFile.close();
}


int main() {
   createDataBlock();
}
