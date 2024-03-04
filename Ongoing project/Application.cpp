////Created by George Kaline III
////SNHU CS-330 02/2024
//
//#pragma once
//#include <iostream>         // cout, cerr
//#include <cstdlib>          // EXIT_FAILURE
//#include <string>
//#include <sstream>
//#include <glew.h>
////#include <glad/glad.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#define GLM_ENABLE_EXPERIMENTAL
//#include <glm/gtx/transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <GLFW/glfw3.h>
//#include <vector>
//#include <camera.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//
//using namespace std; // Standard namespace
//
///*Shader program Macro*/
//#ifndef GLSL
//#define GLSL(Version, Source) "#version " #Version " core \n" #Source
//#endif
//
//// Unnamed namespace
//namespace
//{
//    const char* const WINDOW_TITLE = "Project 1: 3D Scene"; // Macro for window title
//
//    // Variables for window width and height
//    const int WINDOW_WIDTH = 800;
//    const int WINDOW_HEIGHT = 600;
//
//    // Stores the GL data relative to a given mesh
//    struct GLMesh
//    {
//        GLuint vao;         // Handle for the vertex array object
//        GLuint vbos[1];     // Handles for the vertex buffer objects
//        GLuint n1Indices;    // Number of indices of the mesh
//        GLuint n2Indices;    // Number of indices of the mesh
//        GLuint n3Indices;    // Number of indices of the mesh
//        GLuint n4Indices;    // Number of indices of the mesh
//        GLuint nVertices;
//    };
//
//    // Main GLFW window
//    GLFWwindow* gWindow = nullptr;
//    // Triangle mesh data
//    GLMesh pyramidMesh1;
//    GLMesh pyramidMesh2;
//    GLMesh pyramidMesh3;
//    GLMesh pyramidMesh4;
//
//    GLuint gTexture1;
//    GLuint gTexture2;
//    GLuint gTexture3;
//    GLuint gTexture4;
//
//    bool glsHatOn = true;
//
//    // Shader program
//    GLuint gProgramId;
//
//
//    //camera
//    Camera gCamera(glm::vec3(0.0f, 0.0f, 3.0f));
//    float gLastX = WINDOW_WIDTH / 2.0f;
//    float gLastY = WINDOW_HEIGHT / 2.0f;
//    bool gFirstMouse = true;
//    bool perspective = true;
//
//
//    //timing
//    float gDeltaTime = 0.0f; // time between current frame and last frame
//    float gLastFrame = 0.0f;
//    
//}
//
//
///* User-defined Function prototypes to:
// * initialize the program, set the window size,
// * redraw graphics on the window when resized,
// * and render graphics on the screen
// */
//bool UInitialize(int, char* [], GLFWwindow** window);
//void UResizeWindow(GLFWwindow* window, int width, int height);
//void UProcessInput(GLFWwindow* window);
//void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos);
//void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
//void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
//void UCreateMesh1(GLMesh& mesh);
//void UCreateMesh2(GLMesh& mesh);
//void UCreateMesh3(GLMesh& mesh);
//void UCreateMesh4(GLMesh& mesh);
//bool UCreateTexture(const char* filename, GLuint& textureId);
//void UDestroyTexture(GLuint textureId);
//void UDestroyMesh(GLMesh& mesh);
//void URender();
//bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId);
//void UDestroyShaderProgram(GLuint programId);
//
//
///* Vertex Shader Source Code*/
//const GLchar* vertexShaderSource = GLSL(440,
//    layout (location = 0) in vec3 position; // Vertex data from Vertex Attrib Pointer 0
//    layout (location = 2) in vec2 textureCoordinate;  // Color data from Vertex Attrib Pointer 1
//
//
//
////Global variables for the  transform matrices
//    uniform mat4 model;
//    uniform mat4 view;
//    uniform mat4 projection;
//
//    out vec2 vertexTextureCoordinate;
//
//    void main()
//    {
//        gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
//        vertexTextureCoordinate = textureCoordinate; // references incoming color data
//    }
//);
//
//
///* Fragment Shader Source Code*/
//const GLchar* fragmentShaderSource = GLSL(440,
//
//    in vec3 vertexNormal; // For incoming normals
//    in vec3 vertexFragmentPos; // For incoming fragment position
//    in vec2 vertexTextureCoordinate; // Variable to hold incoming color data from vertex shader
//
//    out vec4 fragmentColor;
//    
//    uniform sampler2D uTextureBase;
//    uniform sampler2D uTextureExtra;
//    uniform bool multipleTextures;
//
//    void main()
//    {   
//        fragmentColor = texture(uTextureBase, vertexTextureCoordinate);
//        if (multipleTextures)
//        {
//            vec4 extraTexture = texture(uTextureExtra, vertexTextureCoordinate);
//            if (extraTexture.a != 0.0)
//                fragmentColor = extraTexture;
//        }
//    }
//);
//
//// Images are loaded with Y axis going down, but OpenGL's Y axis goes up, so let's flip it
//void flipImageVertically(unsigned char* image, int width, int height, int channels)
//{
//    for (int j = 0; j < height / 2; ++j)
//    {
//        int index1 = j * width * channels;
//        int index2 = (height - 1 - j) * width * channels;
//
//        for (int i = width * channels; i > 0; --i)
//        {
//            unsigned char tmp = image[index1];
//            image[index1] = image[index2];
//            image[index2] = tmp;
//            ++index1;
//            ++index2;
//        }
//    }
//}
//
//
//int main(int argc, char* argv[])
//{
//    if (!UInitialize(argc, argv, &gWindow))
//        return EXIT_FAILURE;
//
//    // Create the meshs
//    UCreateMesh1(pyramidMesh1); // Calls the function to create the Vertex Buffer Object
//    UCreateMesh2(pyramidMesh2); // Calls the function to create the Vertex Buffer Object
//    UCreateMesh3(pyramidMesh3); // Calls the function to create the Vertex Buffer Object
//    UCreateMesh4(pyramidMesh4); // Calls the function to create the Vertex Buffer Object
//
//    // Create the shader program
//    if (!UCreateShaderProgram(vertexShaderSource, fragmentShaderSource, gProgramId))
//        return EXIT_FAILURE;
//
//    //####////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////texture files
//    
//
//    const char* texFilename = "external/textures/blue.png";
//    
//    if (!UCreateTexture(texFilename, gTexture1))//gTextureID
//    {
//        cout << "Failed to load texture " << texFilename << endl;
//        return EXIT_FAILURE;
//    }
//
//    // Load texture 2 (relative to project's directory)
//
//    texFilename = "external/textures/table.png";
//
//    if (!UCreateTexture(texFilename, gTexture2))
//    {
//        cout << "Failed to load texture " << texFilename << endl;
//        return EXIT_FAILURE;
//    }
//    
//    // Load texture 3 (relative to project's directory)
//
//    texFilename = "external/textures/orange.png";
//
//    if (!UCreateTexture(texFilename, gTexture3))
//    {
//        cout << "Failed to load texture " << texFilename << endl;
//        return EXIT_FAILURE;
//    }
//
//    // Load texture 4 (relative to project's directory)
//
//    texFilename = "external/textures/tape.png";
//
//    if (!UCreateTexture(texFilename, gTexture4))
//    {
//        cout << "Failed to load texture " << texFilename << endl;
//        return EXIT_FAILURE;
//    }
//    //####/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////texture files
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    glUseProgram(gProgramId);
//    // We set the texture as texture unit 0
//    glUniform1i(glGetUniformLocation(gProgramId, "uTexture"), 0);
//
//    // Sets the background color of the window to black (it will be implicitely used by glClear)
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//   
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(gWindow))
//    {   
//        // per-frame timing
//// --------------------
//        float currentFrame = static_cast<float>(glfwGetTime());
//        gDeltaTime = currentFrame - gLastFrame;
//        gLastFrame = currentFrame;
//        // input
//        // -----
//        UProcessInput(gWindow);
//
//        URender();
//
//        glfwPollEvents();
//    }
//
//    // Release mesh data
//    UDestroyMesh(pyramidMesh1);
//    UDestroyMesh(pyramidMesh2);
//    UDestroyMesh(pyramidMesh3);
//    UDestroyMesh(pyramidMesh4);
//
//    // Release texture
//    UDestroyTexture(gTexture1);
//    UDestroyTexture(gTexture2);
//    UDestroyTexture(gTexture3);
//    UDestroyTexture(gTexture4);
//
//    //// Release shader program
//    UDestroyShaderProgram(gProgramId);
//
//    exit(EXIT_SUCCESS); // Terminates the program successfully
//}
//
////##/Inputs and mouse movements
//// Initialize GLFW, GLEW, and create a window
//bool UInitialize(int argc, char* argv[], GLFWwindow** window)
//{
//    // GLFW: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // GLFW: window creation
//    // ---------------------
//    * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
//    if (*window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return false;
//    }
//    glfwMakeContextCurrent(*window);
//    glfwSetFramebufferSizeCallback(*window, UResizeWindow);
//    glfwSetCursorPosCallback(*window, UMousePositionCallback);
//    glfwSetScrollCallback(*window, UMouseScrollCallback);
//    glfwSetMouseButtonCallback(*window, UMouseButtonCallback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    // GLEW: initialize
//    // ----------------
//    // Note: if using GLEW version 1.13 or earlier
//    glewExperimental = GL_TRUE;
//    GLenum GlewInitResult = glewInit();
//
//    if (GLEW_OK != GlewInitResult)
//    {
//        std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
//        return false;
//    }
//
//    // Displays GPU OpenGL version
//    cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;
//
//    return true;
//}
//
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//void UProcessInput(GLFWwindow* window)
//{
//    static const float cameraSpeed = 2.5f;
//
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(FORWARD, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(BACKWARD, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(LEFT, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(RIGHT, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(UP, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//        gCamera.ProcessKeyboard(DOWN, gDeltaTime);
//    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
//        perspective = true;
//    else
//        perspective = false;
//
//}
//
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//void UResizeWindow(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (gFirstMouse)
//    {
//        gLastX = xpos;
//        gLastY = ypos;
//        gFirstMouse = false;
//    }
//
//    float xoffset = xpos - gLastX;
//    float yoffset = gLastY - ypos; // reversed since y-coordinates go from bottom to top
//
//    gLastX = xpos;
//    gLastY = ypos;
//
//    gCamera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    gCamera.ProcessMouseScroll(yoffset);
//}
//
//// glfw: handle mouse button events
//// --------------------------------
//void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
//{
//    switch (button)
//    {
//    case GLFW_MOUSE_BUTTON_LEFT:
//    {
//        if (action == GLFW_PRESS)
//            cout << "Left mouse button pressed" << endl;
//        else
//            cout << "Left mouse button released" << endl;
//    }
//    break;
//
//    case GLFW_MOUSE_BUTTON_MIDDLE:
//    {
//        if (action == GLFW_PRESS)
//            cout << "Middle mouse button pressed" << endl;
//        else
//            cout << "Middle mouse button released" << endl;
//    }
//    break;
//
//    case GLFW_MOUSE_BUTTON_RIGHT:
//    {
//        if (action == GLFW_PRESS)
//            cout << "Right mouse button pressed" << endl;
//        else
//            cout << "Right mouse button released" << endl;
//    }
//    break;
//
//    default:
//        cout << "Unhandled mouse button event" << endl;
//        break;
//    }
//}
//
////##/Inputs and mouse movements
//// Functioned called to render a frame
//// Rendering of Pyramid, cube, plane and cylinder
//void URender()
//{
//    //###/Scene Setup for everything
//    glm::mat4 scale;
//    glm::mat4 rotation;
//    glm::mat4 translation;
//    glm::mat4 model;
//    glm::mat4 view;
//    glm::mat4 worldView;
//    GLint modelLoc;
//    GLint viewLoc;
//    GLint projLoc;
//    //GLint objectColorLoc;
//
//    // Enable z-depth
//    glEnable(GL_DEPTH_TEST);
//
//    // Clear the frame and z buffers
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    // camera/view transformation
//    view = gCamera.GetViewMatrix();
//
//    glm::mat4 projection;
//    if (!perspective)
//    {
//        //perspective projection
//        projection = glm::perspective(glm::radians(gCamera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
//        
//    }
//    //ortho projection
//    else
//        projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);
//
//
//    // Set the shader to be used
//    glUseProgram(gProgramId);
//
//    // Retrieves and passes transform matrices to the Shader program
//    modelLoc = glGetUniformLocation(gProgramId, "model");
//    viewLoc = glGetUniformLocation(gProgramId, "view");
//    projLoc = glGetUniformLocation(gProgramId, "projection");
//
//    /*glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));*/
//    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//    //###/Scene Setup for everything
//    
//    //####//Shape placements
//    // Activate the VBOs contained within the mesh's VAO//////////////////////////////////////////////////////////////////////////////////pyramid
//    glBindVertexArray(pyramidMesh1.vao);
//
//    // 1. Scales the object by 1
//    scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
//    // 2. Rotates shape by 0 degrees in the x axis
//    rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
//   // 3. Place object at the origin
//    translation = glm::translate(glm::vec3(4.0f, -3.5f, 1.0f));
//// Model matrix: transformations are applied right-to-left order
//    model = translation * rotation * scale;
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));               
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, gTexture3);
//
//    // Draws the triangles
//    glDrawArrays(GL_TRIANGLES, 0, pyramidMesh1.n1Indices);
//
//
//
//    // Deactivate the Vertex Array Object
//    glBindVertexArray(0);
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////pyramid
//    
//    // Activate the VBOs contained within the mesh's VAO//////////////////////////////////////////////////////////////////////////////////plane
//    glBindVertexArray(pyramidMesh2.vao);
//
//    // 1. Scales the object by 5
//    scale = glm::scale(glm::vec3(5.0f, 5.0f, 5.0f));
//    // 2. Rotates shape by 0 degrees in the x axis
//    rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
//
//    // 3. Place object at the origin
//    translation = glm::translate(glm::vec3(6.0f, 1.0f, 1.0f));
//    // Model matrix: transformations are applied right-to-left order
//    model = translation * rotation * scale;
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, gTexture2);
//
//    // Draws the triangles
//    glDrawArrays(GL_TRIANGLES, 0, pyramidMesh2.n2Indices);
//
//
//
//    // Deactivate the Vertex Array Object
//    glBindVertexArray(0);
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////plane
//
//        // Activate the VBOs contained within the mesh's VAO//////////////////////////////////////////////////////////////////////////////////cube
//    glBindVertexArray(pyramidMesh3.vao);
//
//    // 1. Scales the object by 1
//    scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
//    // 2. Rotates shape by 1 degrees in the x axis
//    rotation = glm::rotate(1.0f, glm::vec3(0.0, 30.0f, 0.0f));
//    // 3. Place object at the origin
//    translation = glm::translate(glm::vec3(1.0f, -4.0f, 1.1f));
//    // Model matrix: transformations are applied right-to-left order
//    model = translation * rotation * scale;
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, gTexture1);
//
//    // Draws the triangles
//    glDrawArrays(GL_TRIANGLES, 0, pyramidMesh3.n3Indices);
//
//
//
//    // Deactivate the Vertex Array Object
//    glBindVertexArray(0);
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cube
//
//        // Activate the VBOs contained within the mesh's VAO//////////////////////////////////////////////////////////////////////////////////cylinder
//    glBindVertexArray(pyramidMesh4.vao);
//    // 1. Scales the object by 2.5
//    scale = glm::scale(glm::vec3(2.5f, 2.5f, 2.5f));
//    // 2. Rotates shape by 0 degrees in the x axis
//    rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
//    // 3. Place object at the origin
//    translation = glm::translate(glm::vec3(5.0f, -4.0f, -3.5f));
//    // Model matrix: transformations are applied right-to-left order
//    model = translation * rotation * scale;
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, gTexture4);
//
//    // Draws the triangles using different method. A lot of research went into finding these methods to make the modeling work for the cylinder.
//    glDrawArrays(GL_TRIANGLE_FAN, 0, pyramidMesh4.nVertices);
//    glDrawArrays(GL_TRIANGLE_FAN, 36, pyramidMesh4.nVertices);
//    glDrawArrays(GL_TRIANGLE_STRIP, 72, pyramidMesh4.nVertices);
//
//
//
//
//    // Deactivate the Vertex Array Object
//    glBindVertexArray(0);
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cylinder
//
//    glfwSwapBuffers(gWindow);    // Flips the the back buffer with the front buffer every frame.
//}
////####//Shape placements
//
////#//Shape creation
//// Implements the UCreateMesh function/////////////////////////////////////////////////////////////////////////////////////////////////////pyramid points
//void UCreateMesh1(GLMesh& mesh)
//{
//    // Position and Color data
//    GLfloat verts[] = {
//        // Vertex Positions    // Colors (r,g,b,a)     // texture coordinates
//            -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f, // Top-Right Vertex 0
//            0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f, 1.0f,    0.0f, 0.0f,// Bottom-Right Vertex 1
//            0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,      0.5f, 1.0f, // Bottom-Left Vertex 2
//
//            -0.5f, -0.5f, 0.5f,   1.0f, 0.0f, 0.0f, 1.0f,      1.0f, 1.0f, // Top-Right Vertex 0
//            0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f, 1.0f,      0.0f, 0.0f, // Bottom-Right Vertex 1
//            0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,      0.5f, 1.0f, // Bottom-Left Vertex 2
//
//            -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,      1.0f, 1.0f, // Top-Right Vertex 0
//            -0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f, 1.0f,      0.0f, 0.0f, // Bottom-Right Vertex 1
//            0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,      0.5f, 1.0f, // Bottom-Left Vertex 2
//
//            0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f,      1.0f, 1.0f, // Top-Right Vertex 0
//            0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f, 1.0f,      0.0f, 0.0f, // Bottom-Right Vertex 1
//            0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,      0.5f, 1.0f, // Bottom-Left Vertex 2
//
//            //0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, 1.0f, // Top-Right Vertex 0
//            //0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f, 1.0f, // Bottom-Right Vertex 1
//            //0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f, // Bottom-Left Vertex 2
//
//            //-0.5f, -0.5f, 0.5f,   1.0f, 0.0f, 0.0f, 1.0f, // Top-Right Vertex 0
//            //-0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f, 1.0f, // Bottom-Right Vertex 1
//            //0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f // Bottom-Left Vertex 2
//    };
//
//     //Index data to share position data
//    GLushort indices[] = {
//        0, 1, 2, // Triangle 1
//        3, 4, 5, // Triangle 2
//        6, 7, 8, // Triangle 3
//        9, 10, 11, // Triangle 4
//    };
//
//    const GLuint floatsPerVertex = 3;
//    const GLuint floatsPerColor = 4;
//    const GLuint floatsPerUV = 2;
//
//    mesh.n1Indices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerColor));
//
//    glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
//    glBindVertexArray(mesh.vao);
//
//    // Create 2 buffers: first one for the vertex data; second one for the indices
//    glGenBuffers(2, mesh.vbos);
//    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
//
//    mesh.n1Indices = sizeof(indices) / sizeof(indices[0]);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.vbos[1]);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
//    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerColor + floatsPerUV);// The number of floats before each
//
//    // Create Vertex Attribute Pointers
//    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, floatsPerColor, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
//    glEnableVertexAttribArray(1);
//
//    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerColor)));
//    glEnableVertexAttribArray(2);
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////pyramid points
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////plane points
//void UCreateMesh2(GLMesh& mesh)
//{
//    // Position and Color data
//    GLfloat verts[] = {
//        // Vertex Positions    // Colors (r,g,b)     // texture coordinates
//
//             -2.0f,  -1.0f, -2.0f,	1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
//             2.0f,  -1.0f, -2.0f,	1.0f, 1.0f, 1.0f,	1.0f, 0.0f,
//             2.0f,  -1.0f,  2.0f,	1.0f, 1.0f, 1.0f,	1.0f, 1.0f,
//             2.0f,  -1.0f,  2.0f,	1.0f, 1.0f, 1.0f,	1.0f, 0.0f,
//             -2.0f,  -1.0f,  2.0f,	1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
//             -2.0f,  -1.0f, -2.0f,	1.0f, 1.0f, 1.0f,	0.0f, 1.0f,
//
//    };
//
//    //Index data to share position data
//    GLushort indices[] = {
//          0, 1, 2,   // first triangle
//          3, 4, 5,
//
//    };
//
//
//
//    const GLuint floatsPerVertex = 3;
//    const GLuint floatsPerNormal = 3;
//    const GLuint floatsPerUV = 2;
//
//    mesh.n2Indices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal));
//
//    glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
//    glBindVertexArray(mesh.vao);
//
//    // Create 2 buffers: first one for the vertex data; second one for the indices
//    glGenBuffers(2, mesh.vbos);
//    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
//
//    mesh.n2Indices = sizeof(indices) / sizeof(indices[0]);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.vbos[1]);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
//    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);// The number of floats before each
//
//    // Create Vertex Attribute Pointers
//    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
//    glEnableVertexAttribArray(1);
//
//    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
//    glEnableVertexAttribArray(2);
//
//
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////plane points
//
//// Implements the UCreateMesh function/////////////////////////////////////////////////////////////////////////////////////////////////////cube points
//void UCreateMesh3(GLMesh& mesh)
//{
//    // Position and Color data
//    GLfloat verts[] = {
//        // Vertex Positions    // Colors (r,g,b)     // texture coordinates
//        // 
//
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,	// front left
//        -0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.5f,
//        -0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	1.0f,
//
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,	// front right
//        0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	1.0f,
//        -0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	1.0f,
//
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,	// right front
//        0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	1.0f,
//        0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	1.0f,
//
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,	// right back
//        0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	0.5f,
//        0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	1.0f,
//
//        0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	0.5f,	// back left
//        -0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	0.5f,
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	1.0f,
//
//        0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	0.5f,	// back right
//        0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.5f,	1.0f,
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	1.0f,
//
//        -0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	1.0f,	0.5f,	// left back
//        -0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	1.0f,	1.0f,
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	1.0f,
//
//        -0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	1.0f,	0.5f,	// left front
//        -0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	0.5f,
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.75f,	1.0f,
//
//        -0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.0f,	// top left
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.5f,
//        0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.0f,
//
//        -0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.5f,	// top right
//        0.5f,	1.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.0f,
//        0.5f,	1.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,
//
//        -0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.0f,	// bottom left
//        -0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.5f,
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.0f,
//
//        -0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.0f,	0.5f,	// bottom right
//        0.5f,	0.0f,	0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.0f,
//        0.5f,	0.0f,	-0.5f,	1.0f, 1.0f, 1.0f,	0.25f,	0.5f,
//    };
//
//    //Index data to share position data
//    GLushort indices[] = {
//        0,1,2,
//        0,3,2,
//        4,5,6,
//        4,7,6,
//        8,9,10,
//        8,11,10,
//        12,13,14,
//        12,15,14,
//        16,17,18,
//        16,19,18,
//        20,21,22,
//        20,23,22
//          
//    };
//
//    const GLuint floatsPerVertex = 3;
//    const GLuint floatsPerNormal = 3;
//    const GLuint floatsPerUV = 2;
//
//
//    glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
//    glBindVertexArray(mesh.vao);
//
//    // Create 2 buffers: first one for the vertex data; second one for the indices
//    glGenBuffers(2, mesh.vbos);
//    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
//
// 
//    mesh.n3Indices = sizeof(indices) / sizeof(indices[0]);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.vbos[1]);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // Strides between vertex coordinates is 6 (x, y, z, r, g, b, a). A tightly packed stride is 0.
//    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);// The number of floats before each
//
//    // Create Vertex Attribute Pointers
//    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
//    glEnableVertexAttribArray(1);
//
//    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
//    glEnableVertexAttribArray(2);
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cube points
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cylinder points
//void UCreateMesh4(GLMesh& mesh)
//{
//      
//    GLfloat verts[] = {
//
//
//        // cylinder bottom Vertexs     // Colors (r,g,b)     // texture coordinates
//        
//        1.0f, 0.0f, 0.0f,		0.0f, -1.0f, 0.0f,	0.5f,1.0f,
//        .98f, 0.0f, -0.17f,		0.0f, -1.0f, 0.0f,	0.41f, 0.983f,
//        .94f, 0.0f, -0.34f,		0.0f, -1.0f, 0.0f,	0.33f, 0.96f,
//        .87f, 0.0f, -0.5f,		0.0f, -1.0f, 0.0f,	0.25f, 0.92f,
//        .77f, 0.0f, -0.64f,		0.0f, -1.0f, 0.0f,	0.17f, 0.87f,
//        .64f, 0.0f, -0.77f,		0.0f, -1.0f, 0.0f,	0.13f, 0.83f,
//        .5f, 0.0f, -0.87f,		0.0f, -1.0f, 0.0f,	0.08f, 0.77f,
//        .34f, 0.0f, -0.94f,		0.0f, -1.0f, 0.0f,	0.04f, 0.68f,
//        .17f, 0.0f, -0.98f,		0.0f, -1.0f, 0.0f,	0.017f, 0.6f,
//        0.0f, 0.0f, -1.0f,		0.0f, -1.0f, 0.0f,	0.0f,0.5f,
//        -.17f, 0.0f, -0.98f,	0.0f, -1.0f, 0.0f,	0.017f, 0.41f,
//        -.34f, 0.0f, -0.94f,	0.0f, -1.0f, 0.0f,	0.04f, 0.33f,
//        -.5f, 0.0f, -0.87f,		0.0f, -1.0f, 0.0f,	0.08f, 0.25f,
//        -.64f, 0.0f, -0.77f,	0.0f, -1.0f, 0.0f,	0.13f, 0.17f,
//        -.77f, 0.0f, -0.64f,	0.0f, -1.0f, 0.0f,	0.17f, 0.13f,
//        -.87f, 0.0f, -0.5f,		0.0f, -1.0f, 0.0f,	0.25f, 0.08f,
//        -.94f, 0.0f, -0.34f,	0.0f, -1.0f, 0.0f,	0.33f, 0.04f,
//        -.98f, 0.0f, -0.17f,	0.0f, -1.0f, 0.0f,	0.41f, 0.017f,
//        -1.0f, 0.0f, 0.0f,		0.0f, -1.0f, 0.0f,	0.5f, 0.0f,
//        -.98f, 0.0f, 0.17f,		0.0f, -1.0f, 0.0f,	0.6f, 0.017f,
//        -.94f, 0.0f, 0.34f,		0.0f, -1.0f, 0.0f,	0.68f, 0.04f,
//        -.87f, 0.0f, 0.5f,		0.0f, -1.0f, 0.0f,	0.77f, 0.08f,
//        -.77f, 0.0f, 0.64f,		0.0f, -1.0f, 0.0f,	0.83f, 0.13f,
//        -.64f, 0.0f, 0.77f,		0.0f, -1.0f, 0.0f,	0.87f, 0.17f,
//        -.5f, 0.0f, 0.87f,		0.0f, -1.0f, 0.0f,	0.92f, 0.25f,
//        -.34f, 0.0f, 0.94f,		0.0f, -1.0f, 0.0f,	0.96f, 0.33f,
//        -.17f, 0.0f, 0.98f,		0.0f, -1.0f, 0.0f,	0.983f, 0.41f,
//        0.0f, 0.0f, 1.0f,		0.0f, -1.0f, 0.0f,	1.0f, 0.5f,
//        .17f, 0.0f, 0.98f,		0.0f, -1.0f, 0.0f,	0.983f, 0.6f,
//        .34f, 0.0f, 0.94f,		0.0f, -1.0f, 0.0f,	0.96f, 0.68f,
//        .5f, 0.0f, 0.87f,		0.0f, -1.0f, 0.0f,	0.92f, 0.77f,
//        .64f, 0.0f, 0.77f,		0.0f, -1.0f, 0.0f,	0.87f, 0.83f,
//        .77f, 0.0f, 0.64f,		0.0f, -1.0f, 0.0f,	0.83f, 0.87f,
//        .87f, 0.0f, 0.5f,		0.0f, -1.0f, 0.0f,	0.77f, 0.92f,
//        .94f, 0.0f, 0.34f,		0.0f, -1.0f, 0.0f,	0.68f, 0.96f,
//        .98f, 0.0f, 0.17f,		0.0f, -1.0f, 0.0f,	0.6f, 0.983f,
//       
//        // cylinder top	vertexs		// Colors (r,g,b)     // texture coordinates
//        1.0f, 1.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.5f,1.0f,
//        .98f, 1.0f, -0.17f,		0.0f, 1.0f, 0.0f,	0.41f, 0.983f,
//        .94f, 1.0f, -0.34f,		0.0f, 1.0f, 0.0f,	0.33f, 0.96f,
//        .87f, 1.0f, -0.5f,		0.0f, 1.0f, 0.0f,	0.25f, 0.92f,
//        .77f, 1.0f, -0.64f,		0.0f, 1.0f, 0.0f,	0.17f, 0.87f,
//        .64f, 1.0f, -0.77f,		0.0f, 1.0f, 0.0f,	0.13f, 0.83f,
//        .5f, 1.0f, -0.87f,		0.0f, 1.0f, 0.0f,	0.08f, 0.77f,
//        .34f, 1.0f, -0.94f,		0.0f, 1.0f, 0.0f,	0.04f, 0.68f,
//        .17f, 1.0f, -0.98f,		0.0f, 1.0f, 0.0f,	0.017f, 0.6f,
//        0.0f, 1.0f, -1.0f,		0.0f, 1.0f, 0.0f,	0.0f,0.5f,
//        -.17f, 1.0f, -0.98f,	0.0f, 1.0f, 0.0f,	0.017f, 0.41f,
//        -.34f, 1.0f, -0.94f,	0.0f, 1.0f, 0.0f,	0.04f, 0.33f,
//        -.5f, 1.0f, -0.87f,		0.0f, 1.0f, 0.0f,	0.08f, 0.25f,
//        -.64f, 1.0f, -0.77f,	0.0f, 1.0f, 0.0f,	0.13f, 0.17f,
//        -.77f, 1.0f, -0.64f,	0.0f, 1.0f, 0.0f,	0.17f, 0.13f,
//        -.87f, 1.0f, -0.5f,		0.0f, 1.0f, 0.0f,	0.25f, 0.08f,
//        -.94f, 1.0f, -0.34f,	0.0f, 1.0f, 0.0f,	0.33f, 0.04f,
//        -.98f, 1.0f, -0.17f,	0.0f, 1.0f, 0.0f,	0.41f, 0.017f,
//        -1.0f, 1.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.5f, 0.0f,
//        -.98f, 1.0f, 0.17f,		0.0f, 1.0f, 0.0f,	0.6f, 0.017f,
//        -.94f, 1.0f, 0.34f,		0.0f, 1.0f, 0.0f,	0.68f, 0.04f,
//        -.87f, 1.0f, 0.5f,		0.0f, 1.0f, 0.0f,	0.77f, 0.08f,
//        -.77f, 1.0f, 0.64f,		0.0f, 1.0f, 0.0f,	0.83f, 0.13f,
//        -.64f, 1.0f, 0.77f,		0.0f, 1.0f, 0.0f,	0.87f, 0.17f,
//        -.5f, 1.0f, 0.87f,		0.0f, 1.0f, 0.0f,	0.92f, 0.25f,
//        -.34f, 1.0f, 0.94f,		0.0f, 1.0f, 0.0f,	0.96f, 0.33f,
//        -.17f, 1.0f, 0.98f,		0.0f, 1.0f, 0.0f,	0.983f, 0.41f,
//        0.0f, 1.0f, 1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.5f,
//        .17f, 1.0f, 0.98f,		0.0f, 1.0f, 0.0f,	0.983f, 0.6f,
//        .34f, 1.0f, 0.94f,		0.0f, 1.0f, 0.0f,	0.96f, 0.68f,
//        .5f, 1.0f, 0.87f,		0.0f, 1.0f, 0.0f,	0.92f, 0.77f,
//        .64f, 1.0f, 0.77f,		0.0f, 1.0f, 0.0f,	0.87f, 0.83f,
//        .77f, 1.0f, 0.64f,		0.0f, 1.0f, 0.0f,	0.83f, 0.87f,
//        .87f, 1.0f, 0.5f,		0.0f, 1.0f, 0.0f,	0.77f, 0.92f,
//        .94f, 1.0f, 0.34f,		0.0f, 1.0f, 0.0f,	0.68f, 0.96f,
//        .98f, 1.0f, 0.17f,		0.0f, 1.0f, 0.0f,	0.6f, 0.983f,
//
//        // cylinder body vertexs		// Colors (r,g,b)     // texture coordinates
//        1.0f, 1.0f, 0.0f,		1.0f, 0.0f, 0.0f,		0.0,1.0,
//        1.0f, 0.0f, 0.0f,		1.0f, 0.0f, 0.0f,		0.0,0.0,
//        .98f, 0.0f, -0.17f,		1.0f, 0.0f, 0.0f,		0.0277,0.0,
//        1.0f, 1.0f, 0.0f,		0.92f, 0.0f, -0.08f,	0.0,1.0,
//        .98f, 1.0f, -0.17f,		0.92f, 0.0f, -0.08f,	0.0277,1.0,
//        .98f, 0.0f, -0.17f,		0.92f, 0.0f, -0.08f,	0.0277,0.0,
//        .94f, 0.0f, -0.34f,		0.83f, 0.0f, -0.17f,	0.0554,0.0,
//        .98f, 1.0f, -0.17f,		0.83f, 0.0f, -0.17f,	0.0277,1.0,
//        .94f, 1.0f, -0.34f,		0.83f, 0.0f, -0.17f,	0.0554,1.0,
//        .94f, 0.0f, -0.34f,		0.75f, 0.0f, -0.25f,	0.0554,0.0,
//        .87f, 0.0f, -0.5f,		0.75f, 0.0f, -0.25f,	0.0831,0.0,
//        .94f, 1.0f, -0.34f,		0.75f, 0.0f, -0.25f,	0.0554,1.0,
//        .87f, 1.0f, -0.5f,		0.67f, 0.0f, -0.33f,	0.0831,1.0,
//        .87f, 0.0f, -0.5f,		0.67f, 0.0f, -0.33f,	0.0831,0.0,
//        .77f, 0.0f, -0.64f,		0.67f, 0.0f, -0.33f,	0.1108,0.0,
//        .87f, 1.0f, -0.5f,		0.58f, 0.0f, -0.42f,	0.0831,1.0,
//        .77f, 1.0f, -0.64f,		0.58f, 0.0f, -0.42f,	0.1108,1.0,
//        .77f, 0.0f, -0.64f,		0.58f, 0.0f, -0.42f,	0.1108,0.0,
//        .64f, 0.0f, -0.77f,		0.5f, 0.0f, -0.5f,		0.1385,0.0,
//        .77f, 1.0f, -0.64f,		0.5f, 0.0f, -0.5f,		0.1108,1.0,
//        .64f, 1.0f, -0.77f,		0.5f, 0.0f, -0.5f,		0.1385,1.0,
//        .64f, 0.0f, -0.77f,		0.42f, 0.0f, -0.58f,	0.1385,0.0,
//        .5f, 0.0f, -0.87f,		0.42f, 0.0f, -0.58f,	0.1662,0.0,
//        .64f, 1.0f, -0.77f,		0.42f, 0.0f, -0.58f,	0.1385, 1.0,
//        .5f, 1.0f, -0.87f,		0.33f, 0.0f, -0.67f,	0.1662, 1.0,
//        .5f, 0.0f, -0.87f,		0.33f, 0.0f, -0.67f,	0.1662, 0.0,
//        .34f, 0.0f, -0.94f,		0.33f, 0.0f, -0.67f,	0.1939, 0.0,
//        .5f, 1.0f, -0.87f,		0.25f, 0.0f, -0.75f,	0.1662, 1.0,
//        .34f, 1.0f, -0.94f,		0.25f, 0.0f, -0.75f,	0.1939, 1.0,
//        .34f, 0.0f, -0.94f,		0.25f, 0.0f, -0.75f,	0.1939, 0.0,
//        .17f, 0.0f, -0.98f,		0.17f, 0.0f, -0.83f,	0.2216, 0.0,
//        .34f, 1.0f, -0.94f,		0.17f, 0.0f, -0.83f,	0.1939, 1.0,
//        .17f, 1.0f, -0.98f,		0.17f, 0.0f, -0.83f,	0.2216, 1.0,
//        .17f, 0.0f, -0.98f,		0.08f, 0.0f, -0.92f,	0.2216, 0.0,
//        0.0f, 0.0f, -1.0f,		0.08f, 0.0f, -0.92f,	0.2493, 0.0,
//        .17f, 1.0f, -0.98f,		0.08f, 0.0f, -0.92f,	0.2216, 1.0,
//        0.0f, 1.0f, -1.0f,		0.0f, 0.0f, -1.0f,		0.2493, 1.0,
//        0.0f, 0.0f, -1.0f,		0.0f, 0.0f, -1.0f,		0.2493, 0.0,
//        -.17f, 0.0f, -0.98f,	0.0f, 0.0f, -1.0f,		0.277, 0.0,
//        0.0f, 1.0f, -1.0f,		0.08f, 0.0f, -1.08f,	0.2493, 1.0,
//        -.17f, 1.0f, -0.98f,	-0.08f, 0.0f, -0.92f,	0.277, 1.0,
//        -.17f, 0.0f, -0.98f,	-0.08f, 0.0f, -0.92f,	0.277, 0.0,
//        -.34f, 0.0f, -0.94f,	-0.08f, 0.0f, -0.92f,	0.3047, 0.0,
//        -.17f, 1.0f, -0.98f,	-0.08f, 0.0f, -0.92f,	0.277, 1.0,
//        -.34f, 1.0f, -0.94f,	-0.17f, 0.0f, -0.83f,	0.3047, 1.0,
//        -.34f, 0.0f, -0.94f,	-0.17f, 0.0f, -0.83f,	0.3047, 0.0,
//        -.5f, 0.0f, -0.87f,		-0.17f, 0.0f, -0.83f,	0.3324, 0.0,
//        -.34f, 1.0f, -0.94f,	-0.25f, 0.0f, -0.75f,	0.3047, 1.0,
//        -.5f, 1.0f, -0.87f,		-0.25f, 0.0f, -0.75f,	0.3324, 1.0,
//        -.5f, 0.0f, -0.87f,		-0.25f, 0.0f, -0.75f,	0.3324, 0.0,
//        -.64f, 0.0f, -0.77f,	-0.33f, 0.0f, -0.67f,	0.3601, 0.0,
//        -.5f, 1.0f, -0.87f,		-0.33f, 0.0f, -0.67f,	0.3324, 1.0,
//        -.64f, 1.0f, -0.77f,	-0.33f, 0.0f, -0.67f,	0.3601, 1.0,
//        -.64f, 0.0f, -0.77f,	-0.42f, 0.0f, -0.58f,	0.3601, 0.0,
//        -.77f, 0.0f, -0.64f,	-0.42f, 0.0f, -0.58f,	0.3878, 0.0,
//        -.64f, 1.0f, -0.77f,	-0.42f, 0.0f, -0.58f,	0.3601, 1.0,
//        -.77f, 1.0f, -0.64f,	-0.5f, 0.0f, -0.5f,		0.3878, 1.0,
//        -.77f, 0.0f, -0.64f,	-0.5f, 0.0f, -0.5f,		0.3878, 0.0,
//        -.87f, 0.0f, -0.5f,		-0.5f, 0.0f, -0.5f,		0.4155, 0.0,
//        -.77f, 1.0f, -0.64f,	-0.58f, 0.0f, -0.42f,	0.3878, 1.0,
//        -.87f, 1.0f, -0.5f,		-0.58f, 0.0f, -0.42f,	0.4155, 1.0,
//        -.87f, 0.0f, -0.5f,		-0.58f, 0.0f, -0.42f,	0.4155, 0.0,
//        -.94f, 0.0f, -0.34f,	-0.67f, 0.0f, -0.33f,	0.4432, 0.0,
//        -.87f, 1.0f, -0.5f,		-0.67f, 0.0f, -0.33f,	0.4155, 1.0,
//        -.94f, 1.0f, -0.34f,	-0.67f, 0.0f, -0.33f,	0.4432, 1.0,
//        -.94f, 0.0f, -0.34f,	-0.75f, 0.0f, -0.25f,	0.4432, 0.0,
//        -.98f, 0.0f, -0.17f,	-0.75f, 0.0f, -0.25f,	0.4709, 0.0,
//        -.94f, 1.0f, -0.34f,	-0.75f, 0.0f, -0.25f,	0.4432, 1.0,
//        -.98f, 1.0f, -0.17f,	-0.83f, 0.0f, -0.17f,	0.4709, 1.0,
//        -.98f, 0.0f, -0.17f,	-0.83f, 0.0f, -0.17f,	0.4709, 0.0,
//        -1.0f, 0.0f, 0.0f,		-0.83f, 0.0f, -0.17f,	0.4986, 0.0,
//        -.98f, 1.0f, -0.17f,	-0.92f, 0.0f, -0.08f,	0.4709, 1.0,
//        -1.0f, 1.0f, 0.0f,		-0.92f, 0.0f, -0.08f,	0.4986, 1.0,
//        -1.0f, 0.0f, 0.0f,		-0.92f, 0.0f, -0.08f,	0.4986, 0.0,
//        -.98f, 0.0f, 0.17f,		-1.0f, 0.0f, 0.0f,		0.5263, 0.0,
//        -1.0f, 1.0f, 0.0f,		-1.0f, 0.0f, 0.0f,		0.4986, 1.0,
//        -.98f, 1.0f, 0.17f,		-1.0f, 0.0f, 0.0f,		0.5263, 1.0,
//        -.98f, 0.0f, 0.17f,		-0.92f, 0.0f, 0.08f,	0.5263, 0.0,
//        -.94f, 0.0f, 0.34f,		-0.92f, 0.0f, 0.08f,	0.554, 0.0,
//        -.98f, 1.0f, 0.17f,		-0.92f, 0.0f, 0.08f,	0.5263, 1.0,
//        -.94f, 1.0f, 0.34f,		-0.83f, 0.0f, 0.17f,	0.554, 1.0,
//        -.94f, 0.0f, 0.34f,		-0.83f, 0.0f, 0.17f,	0.554, 0.0,
//        -.87f, 0.0f, 0.5f,		-0.83f, 0.0f, 0.17f,	0.5817, 0.0,
//        -.94f, 1.0f, 0.34f,		-0.75f, 0.0f, 0.25f,	0.554, 1.0,
//        -.87f, 1.0f, 0.5f,		-0.75f, 0.0f, 0.25f,	0.5817, 1.0,
//        -.87f, 0.0f, 0.5f,		-0.75f, 0.0f, 0.25f,	0.5817, 0.0,
//        -.77f, 0.0f, 0.64f,		-0.67f, 0.0f, 0.33f,	0.6094, 0.0,
//        -.87f, 1.0f, 0.5f,		-0.67f, 0.0f, 0.33f,	0.5817, 1.0,
//        -.77f, 1.0f, 0.64f,		-0.67f, 0.0f, 0.33f,	0.6094, 1.0,
//        -.77f, 0.0f, 0.64f,		-0.58f, 0.0f, 0.42f,	0.6094, 0.0,
//        -.64f, 0.0f, 0.77f,		-0.58f, 0.0f, 0.42f,	0.6371, 0.0,
//        -.77f, 1.0f, 0.64f,		-0.58f, 0.0f, 0.42f,	0.6094, 1.0,
//        -.64f, 1.0f, 0.77f,		-0.5f, 0.0f, 0.5f,		0.6371, 1.0,
//        -.64f, 0.0f, 0.77f,		-0.5f, 0.0f, 0.5f,		0.6371, 0.0,
//        -.5f, 0.0f, 0.87f,		-0.5f, 0.0f, 0.5f,		0.6648, 0.0,
//        -.64f, 1.0f, 0.77f,		-0.42f, 0.0f, 0.58f,	0.6371, 1.0,
//        -.5f, 1.0f, 0.87f,		-0.42f, 0.0f, 0.58f,	0.6648, 1.0,
//        -.5f, 0.0f, 0.87f,		-0.42f, 0.0f, 0.58f,	0.6648, 0.0,
//        -.34f, 0.0f, 0.94f,		-0.33f, 0.0f, 0.67f,	0.6925, 0.0,
//        -.5f, 1.0f, 0.87f,		-0.33f, 0.0f, 0.67f,	0.6648, 1.0,
//        -.34f, 1.0f, 0.94f,		-0.33f, 0.0f, 0.67f,	0.6925, 1.0,
//        -.34f, 0.0f, 0.94f,		-0.25f, 0.0f, 0.75f,	0.6925, 0.0,
//        -.17f, 0.0f, 0.98f,		-0.25f, 0.0f, 0.75f,	0.7202, 0.0,
//        -.34f, 1.0f, 0.94f,		-0.25f, 0.0f, 0.75f,	0.6925, 1.0,
//        -.17f, 1.0f, 0.98f,		-0.17f, 0.0f, 0.83f,	0.7202, 1.0,
//        -.17f, 0.0f, 0.98f,		-0.17f, 0.0f, 0.83f,	0.7202, 0.0,
//        0.0f, 0.0f, 1.0f,		-0.17f, 0.0f, 0.83f,	0.7479, 0.0,
//        -.17f, 1.0f, 0.98f,		-0.08f, 0.0f, 0.92f,	0.7202, 1.0,
//        0.0f, 1.0f, 1.0f,		-0.08f, 0.0f, 0.92f,	0.7479, 1.0,
//        0.0f, 0.0f, 1.0f,		-0.08f, 0.0f, 0.92f,	0.7479, 0.0,
//        .17f, 0.0f, 0.98f,		-0.0f, 0.0f, 1.0f,		0.7756, 0.0,
//        0.0f, 1.0f, 1.0f,		-0.0f, 0.0f, 1.0f,		0.7479, 1.0,
//        .17f, 1.0f, 0.98f,		-0.0f, 0.0f, 1.0f,		0.7756, 1.0,
//        .17f, 0.0f, 0.98f,		0.08f, 0.0f, 0.92f,		0.7756, 0.0,
//        .34f, 0.0f, 0.94f,		0.08f, 0.0f, 0.92f,		0.8033, 0.0,
//        .17f, 1.0f, 0.98f,		0.08f, 0.0f, 0.92f,		0.7756, 1.0,
//        .34f, 1.0f, 0.94f,		0.17f, 0.0f, 0.83f,		0.8033, 1.0,
//        .34f, 0.0f, 0.94f,		0.17f, 0.0f, 0.83f,		0.8033, 0.0,
//        .5f, 0.0f, 0.87f,		0.17f, 0.0f, 0.83f,		0.831, 0.0,
//        .34f, 1.0f, 0.94f,		0.25f, 0.0f, 0.75f,		0.8033, 1.0,
//        .5f, 1.0f, 0.87f,		0.25f, 0.0f, 0.75f,		0.831, 1.0,
//        .5f, 0.0f, 0.87f,		0.25f, 0.0f, 0.75f,		0.831, 0.0,
//        .64f, 0.0f, 0.77f,		0.33f, 0.0f, 0.67f,		0.8587, 0.0,
//        .5f, 1.0f, 0.87f,		0.33f, 0.0f, 0.67f,		0.831, 1.0,
//        .64f, 1.0f, 0.77f,		0.33f, 0.0f, 0.67f,		0.8587, 1.0,
//        .64f, 0.0f, 0.77f,		0.42f, 0.0f, 0.58f,		0.8587, 0.0,
//        .77f, 0.0f, 0.64f,		0.42f, 0.0f, 0.58f,		0.8864, 0.0,
//        .64f, 1.0f, 0.77f,		0.42f, 0.0f, 0.58f,		0.8587, 1.0,
//        .77f, 1.0f, 0.64f,		0.5f, 0.0f, 0.5f,		0.8864, 1.0,
//        .77f, 0.0f, 0.64f,		0.5f, 0.0f, 0.5f,		0.8864, 0.0,
//        .87f, 0.0f, 0.5f,		0.5f, 0.0f, 0.5f,		0.9141, 0.0,
//        .77f, 1.0f, 0.64f,		0.58f, 0.0f, 0.42f,		0.8864, 1.0,
//        .87f, 1.0f, 0.5f,		0.58f, 0.0f, 0.42f,		0.9141, 1.0,
//        .87f, 0.0f, 0.5f,		0.58f, 0.0f, 0.42f,		0.9141, 0.0,
//        .94f, 0.0f, 0.34f,		0.67f, 0.0f, 0.33f,		0.9418, 0.0,
//        .87f, 1.0f, 0.5f,		0.67f, 0.0f, 0.33f,		0.9141, 1.0,
//        .94f, 1.0f, 0.34f,		0.67f, 0.0f, 0.33f,		0.9418, 1.0,
//        .94f, 0.0f, 0.34f,		0.75f, 0.0f, 0.25f,		0.9418, 0.0,
//        .98f, 0.0f, 0.17f,		0.75f, 0.0f, 0.25f,		0.9695, 0.0,
//        .94f, 1.0f, 0.34f,		0.75f, 0.0f, 0.25f,		0.9418, 0.0,
//        .98f, 1.0f, 0.17f,		0.83f, 0.0f, 0.17f,		0.9695, 1.0,
//        .98f, 0.0f, 0.17f,		0.83f, 0.0f, 0.17f,		0.9695, 0.0,
//        1.0f, 0.0f, 0.0f,		0.83f, 0.0f, 0.17f,		1.0, 0.0,
//        .98f, 1.0f, 0.17f,		0.92f, 0.0f, 0.08f,		0.9695, 1.0,
//        1.0f, 1.0f, 0.0f,		0.92f, 0.0f, 0.08f,		1.0, 1.0,
//        1.0f, 0.0f, 0.0f,		0.92f, 0.0f, 0.08f,		1.0, 0.0
//    };
//
//
//    const GLuint floatsPerVertex = 3;
//    const GLuint floatsPerNormal = 3;
//    const GLuint floatsPerUV = 2;
//
//    /*mesh.n3Indices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal));*/
//
//        // store vertex and index count
//    mesh.nVertices = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
//    mesh.n4Indices = 0;
//
//    // Create VAO
//    glGenVertexArrays(1, &mesh.vao); // we can also generate multiple VAOs or buffers at the same time
//    glBindVertexArray(mesh.vao);
//
//    // Create VBO
//    glGenBuffers(1, mesh.vbos);
//    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]); // Activates the buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
//
//    // Strides between vertex coordinates
//    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);
//
//    // Create Vertex Attribute Pointers
//    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, floatsPerNormal, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex)));
//    glEnableVertexAttribArray(1);
//
//    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
//    glEnableVertexAttribArray(2);
//
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////cylinder points
////#//Shape creation
//
//
////destroy meshes from GPU
//void UDestroyMesh(GLMesh& mesh)
//{
//    glDeleteVertexArrays(1, &mesh.vao);
//    glDeleteBuffers(1, mesh.vbos);
//}
//
////Generate and load the texture
//bool UCreateTexture(const char* filename, GLuint& textureId)
//{
//    int width, height, channels;
//    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
//    if (image)
//    {
//        flipImageVertically(image, width, height, channels);
//
//        glGenTextures(1, &textureId);
//        glBindTexture(GL_TEXTURE_2D, textureId);
//
//        // set the texture wrapping parameters
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        // set texture filtering parameters
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//        if (channels == 3)
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//        else if (channels == 4)
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//        else
//        {
//            cout << "Not implemented to handle image with " << channels << " channels" << endl;
//            return false;
//        }
//
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        stbi_image_free(image);
//        glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture
//
//        return true;
//    }
//
//    // Error loading the image
//    return false;
//}
//
////destroy textures
//void UDestroyTexture(GLuint textureId)
//{
//    glGenTextures(1, &textureId);
//}
//
//
//// Implements the UCreateShaders function
//bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId)
//{
//    // Compilation and linkage error reporting
//    int success = 0;
//    char infoLog[512];
//
//    // Create a Shader program object.
//    programId = glCreateProgram();
//
//    // Create the vertex and fragment shader objects
//    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
//    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
//
//    // Retrive the shader source
//    glShaderSource(vertexShaderId, 1, &vtxShaderSource, NULL);
//    glShaderSource(fragmentShaderId, 1, &fragShaderSource, NULL);
//
//    // Compile the vertex shader, and print compilation errors (if any)
//    glCompileShader(vertexShaderId); // compile the vertex shader
//    // check for shader compile errors
//    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//
//        return false;
//    }
//
//    glCompileShader(fragmentShaderId); // compile the fragment shader
//    // check for shader compile errors
//    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShaderId, sizeof(infoLog), NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//
//        return false;
//    }
//
//    // Attached compiled shaders to the shader program
//    glAttachShader(programId, vertexShaderId);
//    glAttachShader(programId, fragmentShaderId);
//
//    glLinkProgram(programId);   // links the shader program
//    // check for linking errors
//    glGetProgramiv(programId, GL_LINK_STATUS, &success);
//    if (!success)
//    {
//        glGetProgramInfoLog(programId, sizeof(infoLog), NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//
//        return false;
//    }
//
//    glUseProgram(programId);    // Uses the shader program
//
//    return true;
//}
//
//
//void UDestroyShaderProgram(GLuint programId)
//{
//    glDeleteProgram(programId);
//}