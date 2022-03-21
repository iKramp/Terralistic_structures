#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum class blockType { NOTHING, AIR, DIRT, STONE_BLOCK, GRASS_BLOCK, STONE, WOOD, LEAVES, CANOPY, BRANCH, SAND, SNOWY_GRASS_BLOCK, SNOW_BLOCK, ICE_BLOCK, IRON_ORE, COPPER_ORE, GRASS, TORCH, CACTUS};

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

    structures.push_back(structure("tree_1", 5, 12, {
            blockType::CANOPY, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::LEAVES, blockType::BRANCH, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::BRANCH, blockType::LEAVES,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::AIR, blockType::WOOD, blockType::WOOD, blockType::WOOD, blockType::AIR,
    }));

    structures.push_back(structure("tree_0", 5, 12, {
            blockType::CANOPY, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::AIR, blockType::AIR, blockType::WOOD, blockType::BRANCH, blockType::LEAVES,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::LEAVES, blockType::BRANCH, blockType::WOOD, blockType::AIR, blockType::AIR,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::NOTHING, blockType::AIR, blockType::WOOD, blockType::AIR, blockType::NOTHING,
            blockType::AIR, blockType::WOOD, blockType::WOOD, blockType::WOOD, blockType::AIR,
    }));

    structures.push_back(structure("cactus_0", 2, 6, {
            blockType::NOTHING, blockType::CACTUS,
            blockType::CACTUS, blockType::CACTUS,
            blockType::CACTUS, blockType::CACTUS,
            blockType::CACTUS, blockType::NOTHING,
            blockType::CACTUS, blockType::NOTHING,
            blockType::SAND, blockType::NOTHING,
    }));

    structures.push_back(structure("cactus_1", 3, 8, {
            blockType::NOTHING, blockType::CACTUS, blockType::NOTHING,
            blockType::CACTUS, blockType::CACTUS, blockType::NOTHING,
            blockType::CACTUS, blockType::CACTUS, blockType::CACTUS,
            blockType::CACTUS, blockType::CACTUS, blockType::CACTUS,
            blockType::NOTHING, blockType::CACTUS, blockType::CACTUS,
            blockType::NOTHING, blockType::CACTUS, blockType::NOTHING,
            blockType::NOTHING, blockType::CACTUS, blockType::NOTHING,
            blockType::NOTHING, blockType::SAND, blockType::NOTHING,
    }));

    structures.push_back(structure("cactus_2", 2, 4, {
            blockType::CACTUS, blockType::CACTUS,
            blockType::CACTUS, blockType::CACTUS,
            blockType::CACTUS, blockType::NOTHING,
            blockType::SAND, blockType::NOTHING,
    }));
    

    ofstream structureFile;
    structureFile.open("/home/nejc/CLionProjects/Terralistic/Resources/resourcePack/misc/structures.asset", ios::out | ios::trunc);

    for (structure& i : structures) {
        int size = (int)i.name.size() + (i.x_size * i.y_size * 2) + 5;
        char* data = new char[size];
        data[0] = (char)i.name.size();
        for (int i2 = 0; i2 < i.name.size(); i2++)
            data[i2 + 1] = i.name[i2];
        char* arr_section = data + i.name.size() + 1;
        arr_section[0] = (char)((i.x_size >> 8) & 0xff);
        arr_section[1] = (char)(i.x_size & 0xff);
        arr_section[2] = (char)((i.y_size >> 8) & 0xff);
        arr_section[3] = (char)(i.y_size & 0xff);
        for (int i2 = 0; i2 < i.x_size * i.y_size; i2++) {
            arr_section[i2 * 2 + 4] = (char) (((int)i.blocks[i2] >> 8) & 0xff);
            arr_section[i2 * 2 + 5] = (char) ((int)i.blocks[i2] & 0xff);
        }
        structureFile.write(data, size);
    }

    structureFile.close();


    structureFile.open("/home/nejc/CLionProjects/Terralistic/cmake-build-debug/Resources/resourcePack/misc/structures.asset", ios::out | ios::trunc);

    for (structure& i : structures) {
        int size = (int)i.name.size() + (i.x_size * i.y_size * 2) + 5;
        char* data = new char[size];
        data[0] = (char)i.name.size();
        for (int i2 = 0; i2 < i.name.size(); i2++)
            data[i2 + 1] = i.name[i2];
        char* arr_section = data + i.name.size() + 1;
        arr_section[0] = (char)((i.x_size >> 8) & 0xff);
        arr_section[1] = (char)(i.x_size & 0xff);
        arr_section[2] = (char)((i.y_size >> 8) & 0xff);
        arr_section[3] = (char)(i.y_size & 0xff);
        for (int i2 = 0; i2 < i.x_size * i.y_size; i2++) {
            arr_section[i2 * 2 + 4] = (char) (((int)i.blocks[i2] >> 8) & 0xff);
            arr_section[i2 * 2 + 5] = (char) ((int)i.blocks[i2] & 0xff);
        }
        structureFile.write(data, size);
    }

    structureFile.close();

}


int main() {
   createDataBlock();
}
