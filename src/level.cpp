#include "../include/level.h"
#include "../include/globals.h"
#include "../include/tinyxml2.h"

Level::Level() {}
Level::~Level() {}

void Level::update(int elapsedTime)
{
}

void Level::draw(Graphics &graphics)
{
    for (Sprite tile : this->_backgroundTileList)
        tile.draw(graphics);

    for (Sprite tile : this->_midgroundTileList)
        tile.draw(graphics);

    for (Sprite tile : this->_foregroundTileList)
        tile.draw(graphics);
}

// Every tile sprite will be placed into one PNG file.
// I don't want to go back and change the XML file everytime I decide to change something
void Level::loadMap(Graphics &graphics, std::string mapName)
{
    int tileWidth, tileHeight;
    int levelWidth, levelHeight;

    tinyxml2::XMLDocument levelDocument;
    levelDocument.LoadFile(mapName.c_str());

    if (levelDocument.Error())
    {
        levelDocument.PrintError();
        return;
    }

    tinyxml2::XMLElement *mapElement = levelDocument.FirstChildElement("map");
    if (mapElement == nullptr)
    {
        printf("Map Element does not exist in XML Document: %s\n", mapName);
        return;
    }

    mapElement->QueryIntAttribute("tilewidth", &tileWidth);
    mapElement->QueryIntAttribute("tileheight", &tileHeight);
    mapElement->QueryIntAttribute("width", &levelWidth);
    mapElement->QueryIntAttribute("height", &levelHeight);

    tinyxml2::XMLElement *layerElement = mapElement->FirstChildElement("layer");
    while (layerElement != nullptr)
    {
        tinyxml2::XMLElement *dataElement = layerElement->FirstChildElement("data");

        std::string layerName = layerElement->Attribute("name");

        int cnt = 0;
        while (dataElement != nullptr)
        {
            char *data = (char *)dataElement->GetText();
            std::vector<Sprite> spriteList;

            char *token = strtok(data, ",");
            while (token != NULL)
            {
                int gid = std::stoi(token);

                if (gid != 0)
                {
                    int tilesetX = (gid - 1) % (globals::TILESET_WIDTH / globals::TILE_WIDTH) * globals::TILE_WIDTH ;
                    int tilesetY = (gid - 1) / (globals::TILESET_WIDTH / globals::TILE_WIDTH) * globals::TILE_WIDTH ;

                    int positionX = (cnt % levelWidth) * globals::TILE_WIDTH * globals::SPRITE_SCALE;
                    int positionY = (cnt / levelWidth) * globals::TILE_HEIGHT * globals::SPRITE_SCALE;

                    Sprite tileSprite = Sprite(graphics, globals::TILESET_FILE_PATH, Vector2(tilesetX, tilesetY), Vector2(globals::TILE_WIDTH, globals::TILE_HEIGHT), Vector2(positionX, positionY));
                    spriteList.push_back(std::move(tileSprite));
                }
                cnt++;
                token = strtok(NULL, ",");
            }

            if (layerName == "background")
                this->_backgroundTileList = std::move(spriteList);
            if (layerName == "midground")
                this->_midgroundTileList = std::move(spriteList);
            if (layerName == "foreground")
                this->_foregroundTileList = std::move(spriteList);

            dataElement = dataElement->NextSiblingElement("data");
        }

        layerElement = layerElement->NextSiblingElement("layer");
    }
}