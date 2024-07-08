#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
public:

	// The program ID
	unsigned int ID;
	// Constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);

	void setBool(const std::string &name, bool value) const;
	void setFloat(const std::string &name, float value) const;
	void setInt(const std::string &name, int value) const;
	void setMat4(const std::string& name , glm::mat4& trans) const;


	// Use the shader program
	void use();

private:
	

	// Utility function for checking shader compilation/linking errors
	void checkCompileErrors(GLuint shader, std::string type);
};

#endif // SHADER_H
