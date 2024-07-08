#include "texture_manager.h"

TextureManager* TextureManager::m_Instance = 0;
TextureManager* TextureManager::getInstance()
{

    if (m_Instance)
        return m_Instance;

    m_Instance = new TextureManager();

    return m_Instance;
}


TextureManager::TextureManager() {}

unsigned int TextureManager::loadTexture(std::string fileName)
{
    unsigned int textureID;

    // Check if the texture is already loaded
    if (m_TextureMap.find(fileName) != m_TextureMap.end())
    {
        return m_TextureMap[fileName];
    }

    // Load the texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Load the image, create the texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);  

    unsigned char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    else
    {
        std::cout << "Failed to load texture: " << fileName << std::endl;
    } 

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);


    // Store the texture ID in the map and return it
    m_TextureMap[fileName] = textureID;
    return textureID;
}