/**
 * Example of using a callback function with the GFLW library
 * The function will process the keys inserted by user and it saves
 * them into a buffer.
 *
 * @author:      Marco "soniyj" Matascioli
 * @date:        25 March 2013
 * @file:        callback.cpp
 *
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

string word;
int times=2;
int iv=0;

/**
 * Callback function for keys typed by user
 * Saves the chars in to the word buffer and
 * erases it after two insertions.
 * @param nc character
 * @param isPressed 1 key pressed
 */
void cbfun(int nc, int isPressed) {
    char c=nc;
    cout << "is pressed: " << isPressed << endl;
    cout << "char: " << c << endl;
    if(iv<times) {
        word.push_back(c);
        cout << "i: " << iv << endl;
        iv++;
    }
    if(iv==times) {
        cout << "word: " << word.c_str() << endl;
        iv=0;
        word.clear();
    }
}

/**
 * GLFW main
 * @return -1 if it fails, 0 otherwise
 */
int glfw_Window() {
    if(!glfwInit()) {
        cout << "Error\n";
        return -1;
    }

    if(!glfwOpenWindow(300,300,0,0,0,0,0,0,GLFW_WINDOW)) {
        cout << "Failed to open GLFW Window\n";
        glfwTerminate();
        return -1;
    }

    glfwSetWindowTitle("tutorial 1");
    glfwEnable(GLFW_STICKY_KEYS);

    do {
        glfwSetCharCallback(cbfun);
        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC)!=GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    glfwTerminate();

    return 0;
}

int main() {
    cout << "Hello World!\n";
    glfw_Window();
    return 0;
}
