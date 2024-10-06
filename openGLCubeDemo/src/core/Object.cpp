#include "Object.h"
#include "../SceneManager.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::render()
{
	//Matrix viewMatrix = SceneManager::getInstance()->getCamera()->getViewMatrix();
	//Matrix projectionMatrix = SceneManager::GetInstance()->GetProjectionMatrix();
	//GLfloat deltaTime = SceneManager::GetInstance()->GetDeltaTime();
	//Camera camera = SceneManager::GetInstance()->GetCamera();
	//Vector4 cameraPosition = camera._position;
	//Vector4 ambientColor = SceneManager::GetInstance()->GetAmbientColor();
	//GLfloat ambientWeight = SceneManager::GetInstance()->GetAmbienWeight();

	//glUseProgram(m_Shaders->program);
	//Matrix MVP = m_WorldMatrix * viewMatrix * projectionMatrix;
	//GLfloat eyePos[4] = { cameraPosition.x, cameraPosition.y, cameraPosition.z, cameraPosition.w };
	////Setting the texture uniform
	//int uniform1Loc = glGetUniformLocation(m_Shaders->program, "u_WVPmatrix");
	//glUniformMatrix4fv(uniform1Loc, 1, GL_FALSE, (GLfloat*)MVP.m);
	//int uniform2Loc = glGetUniformLocation(m_Shaders->program, "u_Wmatrix");
	//if (uniform2Loc != -1)
	//{
	//	glUniformMatrix4fv(uniform2Loc, 1, GL_FALSE, (GLfloat*)m_WorldMatrix.m);
	//}
	//int uniform3Loc = glGetUniformLocation(m_Shaders->program, "u_eyePos");
	//if (uniform3Loc != -1)
	//{
	//	glUniform4fv(uniform3Loc, 1, (GLfloat*)eyePos);
	//}
	//int uniform4Loc = glGetUniformLocation(m_Shaders->program, "u_camPosition");
	//if (uniform4Loc != -1)
	//{
	//	glUniform3f(uniform4Loc, cameraPosition.x, cameraPosition.y, cameraPosition.z);
	//}

	//int uniformLightnumLoc = glGetUniformLocation(m_Shaders->program, "u_lightnum");
	//if (uniformLightnumLoc != -1)
	//{
	//	glUniform1i(uniformLightnumLoc, m_Light_num);
	//}

	//int uniformLightTypeLoc = glGetUniformLocation(m_Shaders->program, "u_lightType");
	//if (uniformLightTypeLoc != -1)
	//{
	//	GLint* lightType = new GLint[m_Light_num];
	//	for (unsigned int i = 0; i < m_Light_num; i++)
	//	{
	//		if (!strcmp(m_Light[i]->m_LightType, "POINT"))
	//			lightType[i] = 1;
	//		else
	//			if (!strcmp(m_Light[i]->m_LightType, "SPOT"))
	//				lightType[i] = 2;
	//			else
	//				lightType[i] = 0;
	//	}
	//	glUniform1iv(uniformLightTypeLoc, m_Light_num, (GLint*)lightType);
	//	delete[] lightType;
	//}



	//int uniformLightAmbientColorLoc = glGetUniformLocation(m_Shaders->program, "u_ambientColor");
	//if (uniformLightAmbientColorLoc != -1)
	//{
	//	glUniform3f(uniformLightAmbientColorLoc, ambientColor.x, ambientColor.y, ambientColor.z);
	//}

	//int uniformLightAmbientWeightLoc = glGetUniformLocation(m_Shaders->program, "u_weight");
	//if (uniformLightAmbientWeightLoc != -1)
	//{
	//	glUniform1f(uniformLightAmbientWeightLoc, ambientWeight);
	//}

	//int uniformLightPosLoc = glGetUniformLocation(m_Shaders->program, "u_lightPos");
	//int uniformLightDiffuseColorLoc = glGetUniformLocation(m_Shaders->program, "u_lightDiffuseColor");
	//int uniformLightSpecularColorLoc = glGetUniformLocation(m_Shaders->program, "u_lightSpecularColor");
	//int uniformSpotLightDirectionLoc = glGetUniformLocation(m_Shaders->program, "u_spotlightDirection");
	//int uniformSpotLightAngleLoc = glGetUniformLocation(m_Shaders->program, "u_spotlightAngle");
	//if ((uniformLightPosLoc != -1) && (uniformLightDiffuseColorLoc != -1) && (uniformLightSpecularColorLoc != -1))
	//{
	//	GLfloat* lightPos = new GLfloat[m_Light_num * 3];
	//	GLfloat* lightDiffuseColor = new GLfloat[m_Light_num * 4];
	//	GLfloat* lightSpecularColor = new GLfloat[m_Light_num * 4];
	//	GLfloat* spotlightDirection = new GLfloat[m_Light_num * 3];
	//	GLfloat* spotlightAngle = new GLfloat[m_Light_num];
	//	for (unsigned int i = 0; i < m_Light_num; i++)
	//	{
	//		lightPos[i * 3] = m_Light[i]->m_Position.x;
	//		lightPos[i * 3 + 1] = m_Light[i]->m_Position.y;
	//		lightPos[i * 3 + 2] = m_Light[i]->m_Position.z;
	//		lightDiffuseColor[i * 4] = m_Light[i]->m_LightColor.x;
	//		lightDiffuseColor[i * 4 + 1] = m_Light[i]->m_LightColor.y;
	//		lightDiffuseColor[i * 4 + 2] = m_Light[i]->m_LightColor.z;
	//		lightDiffuseColor[i * 4 + 3] = 1.0f;
	//		lightSpecularColor[i * 4] = m_Light[i]->m_LightColor.x;
	//		lightSpecularColor[i * 4 + 1] = m_Light[i]->m_LightColor.y;
	//		lightSpecularColor[i * 4 + 2] = m_Light[i]->m_LightColor.z;
	//		lightSpecularColor[i * 4 + 3] = 1.0f;
	//		if (!strcmp(m_Light[i]->m_LightType, "SPOT"))
	//		{
	//			spotlightDirection[i * 3] = m_Light[i]->m_Direction.x;
	//			spotlightDirection[i * 3 + 1] = m_Light[i]->m_Direction.y;
	//			spotlightDirection[i * 3 + 2] = m_Light[i]->m_Direction.z;
	//			spotlightAngle[i] = m_Light[i]->m_Angle;
	//		}
	//	}
	//	glUniform3fv(uniformLightPosLoc, m_Light_num, (GLfloat*)lightPos);
	//	glUniform4fv(uniformLightDiffuseColorLoc, m_Light_num, (GLfloat*)lightDiffuseColor);
	//	glUniform4fv(uniformLightSpecularColorLoc, m_Light_num, (GLfloat*)lightSpecularColor);
	//	if ((uniformSpotLightDirectionLoc != -1) && (uniformSpotLightAngleLoc != -1))
	//	{
	//		glUniform3fv(uniformSpotLightDirectionLoc, m_Light_num, (GLfloat*)spotlightDirection);
	//		glUniform1fv(uniformSpotLightAngleLoc, m_Light_num, (GLfloat*)spotlightAngle);
	//		delete[] spotlightDirection;
	//		delete[] spotlightAngle;
	//	}
	//	delete[] lightPos;
	//	delete[] lightDiffuseColor;
	//	delete[] lightSpecularColor;
	//}

	//GLfloat fogMaxDist = 200.0f;
	//GLfloat fogMinDist = 100.0f;
	//int ifogColorLoc = glGetUniformLocation(m_Shaders->program, "u_fogColor");
	//if (ifogColorLoc != -1)
	//{
	//	glUniform4f(ifogColorLoc, 1.0f, 1.0f, 1.0f, 1.0f);
	//}
	//int ifogMaxDistLoc = glGetUniformLocation(m_Shaders->program, "u_fogMaxDist");
	//if (ifogMaxDistLoc != -1)
	//{
	//	glUniform1f(ifogMaxDistLoc, fogMaxDist);
	//}
	//int ifogMinDistLoc = glGetUniformLocation(m_Shaders->program, "u_fogMinDist");
	//if (ifogMinDistLoc != -1)
	//{
	//	glUniform1f(ifogMinDistLoc, fogMinDist);
	//}

	//char* TextureArray[4] = { "u_texture","u_texture1","u_texture2","u_texture3" };

	//GLenum TextureType;
	//Texture*** CurrentTexture;
	//GLuint TextureNum;
	//GLint* iTextureLoc;

	//if (m_CubeTexture_num > 0)
	//{
	//	TextureType = GL_TEXTURE_CUBE_MAP;
	//	TextureNum = m_CubeTexture_num;
	//	CurrentTexture = &m_CubeTexture;
	//}
	//else
	//{
	//	TextureType = GL_TEXTURE_2D;
	//	TextureNum = m_Texture_num;
	//	CurrentTexture = &m_Texture;
	//}

	//iTextureLoc = new GLint[TextureNum];
	//for (unsigned int i = 0; i < TextureNum; i++)
	//{
	//	if (iTextureLoc[i] != -1)
	//	{
	//		glActiveTexture(GL_TEXTURE0 + i);
	//		iTextureLoc[i] = glGetUniformLocation(m_Shaders->program, TextureArray[i]);
	//		glUniform1i(iTextureLoc[i], i);
	//		glBindTexture(TextureType, (*CurrentTexture)[i]->location);
	//	}
	//}

	//int normalTextureLoc = glGetUniformLocation(m_Shaders->program, "u_normalMap");
	//if (normalTextureLoc != -1)
	//{
	//	glUniform1i(normalTextureLoc, 1);
	//	glBindTexture(GL_TEXTURE_2D, m_Texture[m_Texture_num - 1]->location);
	//}

	//passAdditionalUniforms();

	//glBindBuffer(GL_ARRAY_BUFFER, m_Model->vboId);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Model->iboId);


	//if (m_Shaders->positionAttribute != -1)
	//{
	//	glEnableVertexAttribArray(m_Shaders->positionAttribute);
	//	glVertexAttribPointer(m_Shaders->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	//}

	//if (m_Shaders->uvAttribute != -1)
	//{
	//	glEnableVertexAttribArray(m_Shaders->uvAttribute);
	//	glVertexAttribPointer(m_Shaders->uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)0 + sizeof(Vector3));
	//}

	//for (unsigned int i = 0; i < m_Shaders->m_State_num; i++)
	//{
	//	if (m_Shaders->m_State[i] == GL_CULL_FACE)
	//		glEnable(GL_CULL_FACE);
	//	if (m_Shaders->m_State[i] == GL_DEPTH_TEST)
	//		glEnable(GL_DEPTH_TEST);
	//}
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glDrawElements(GL_TRIANGLES, m_Model->m_Indices_num, GL_UNSIGNED_INT, 0);

	//glDisable(GL_CULL_FACE);
	//glDisable(GL_DEPTH_TEST);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindTexture(TextureType, 0);
	//delete[] iTextureLoc;

}

void Object::readFile(FILE*& f)
{
}

void Object::passAdditionalUniforms()
{
}

void Object::update()
{
}

void Object::cleanUp()
{
}
