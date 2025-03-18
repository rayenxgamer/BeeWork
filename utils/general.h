#pragma once

#include <glad/glad.h>

//
//* VAO utils
//
GLuint CreateVAO(unsigned int VAO){
    glGenVertexArrays(1,&VAO);
    return VAO;
}

void BindVAO(unsigned int VAO){
    glBindVertexArray(VAO);
}

void UnBindVAO(){
    glBindVertexArray(0);
}

//
//* VBO utils
//

GLuint CreateVBO(unsigned int VBO){
    glGenBuffers(1,&VBO);
    return VBO;
}

void BindVBO(unsigned int VBO){
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void BufferVBO(GLsizeiptr size, const GLvoid *data){
    glBufferData(GL_ARRAY_BUFFER, size, data,GL_DYNAMIC_DRAW);
}

void UnBindVBO(){
    glBindVertexArray(0);
}

//
//* EBO utils
//

GLuint CreateEBO(unsigned int EBO){
    glGenBuffers(1,&EBO);
    return EBO;
}

void BufferEBO(GLsizeiptr size, const GLvoid *data){
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size,data,GL_STATIC_DRAW);
}

void BindEBO(unsigned int EBO){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
}

void UnBindEBO(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


