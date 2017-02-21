#include "Application.hpp"
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

//Application* currentApplication = NULL;

Application::Application():
    state(stateReady),
    width(640),
    height(480),
    title("Sample Application")
{
    //currentApplication=this;

    cout<<"[Info] GLFW initialisation"<<endl;

    // initialize the GLFW library
    if (!glfwInit())
    {
        throw std::runtime_error("Couldn't init GLFW");
    }

    // TODO:setting the opengl version
    int major = 3;
    int minor = 2;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create the window
    window = glfwCreateWindow(width,height,title.c_str(),NULL,NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Couldn't create a window");
    }

    glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
    GLenum err = glewInit();

    if ( err != GLEW_OK)
	{
        glfwTerminate();
        throw std::runtime_error(string("Could initialize GLEW, error = ") + (const char*)glewGetErrorString(err));
	}


    // get version info
    const GLubyte* renderer = glGetString (GL_RENDERER);
    const GLubyte* version = glGetString (GL_VERSION); 
    cout << "Renderer: " << renderer << endl;
    cout << "OpenGL version supported " << version << endl;

    // opengl configuration
    glEnable (GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer"

    // vsync
    //glfwSwapInterval(false);

}

Application::~Application() {

}
void Application::run()
{
    state = stateRun;

    //Make the window's context current
    glfwMakeContextCurrent(window);

    time = glfwGetTime();

    while( state == stateRun )
    {

        // compute new time and delta time
        float t = glfwGetTime();
        deltaTime = t - time;
        time = t;
        
        // detech window related changes
        detectWindowDimensionChange();

        // execute the frame code
        loop();

        // Swap Front and Back buffers (double buffering)
        glfwSwapBuffers(window);

        // Pool and process events
        glfwPollEvents();
    }
    
    glfwTerminate();
}

void Application::detectWindowDimensionChange()
{
    int w,h;
    glfwGetWindowSize(getWindow(), &w, &h);
    dimensionChange = ( w!= width || h != height) ;
    if (dimensionChange) 
    {
        width = w;
        height = h;
        glViewport(0, 0, width, height);
    }
}

void Application::loop()
{
    cout<<"[INFO] : loop"<<endl;
}






