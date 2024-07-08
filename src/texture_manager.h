#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <map>
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class TextureManager
{
    public:

    unsigned int loadTexture(std::string fileName);

    static TextureManager* getInstance();

    private:
    TextureManager();

    static TextureManager* m_Instance;

    std::map<std::string, unsigned int> m_TextureMap;
};


#endif // TEXTURE_MANAGER_H