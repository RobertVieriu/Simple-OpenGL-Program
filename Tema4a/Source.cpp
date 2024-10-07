#include <GLFW/glfw3.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const double RECTANGLE_WIDTH = 50.0;
const double RECTANGLE_HEIGHT = 50.0;
double x = WINDOW_WIDTH / 2.0;
double y = WINDOW_HEIGHT / 2.0;

void drawScene() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2d(x - RECTANGLE_WIDTH / 2, y - RECTANGLE_HEIGHT / 2);
    glVertex2d(x + RECTANGLE_WIDTH / 2, y - RECTANGLE_HEIGHT / 2);
    glVertex2d(x + RECTANGLE_WIDTH / 2, y + RECTANGLE_HEIGHT / 2);
    glVertex2d(x - RECTANGLE_WIDTH / 2, y + RECTANGLE_HEIGHT / 2);
    glEnd();
    glfwSwapBuffers(glfwGetCurrentContext());
}

void moveLeft() 
{
    x -= 10.0;
}

void moveRight() 
{
    x += 10.0;
}

void moveUp() 
{
    y += 10.0;
}

void moveDown() 
{
    y -= 10.0;
}


int main() 
{

    if (!glfwInit()) 
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create window
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Move rectangle with arrow keys", NULL, NULL);
    if (!window) 
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
    {
        if (action == GLFW_PRESS) 
        {
            switch (key) 
            {
            case GLFW_KEY_LEFT:
                moveLeft();
                break;
            case GLFW_KEY_RIGHT:
                moveRight();
                break;
            case GLFW_KEY_UP:
                moveUp();
                break;
            case GLFW_KEY_DOWN:
                moveDown();
                break;
            }
        }
    });

    while (!glfwWindowShouldClose(window)) 
    {
        drawScene();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
