#include"opengl.hpp"

void render(void);
void keyboard(unsigned char c, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Game window! :)");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutDisplayFunc(render);
    glutMainLoop();
}

void render(void)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    float offset = 0.0;
    while(1)
    {
        if(offset >= 1) offset = 0;
        glBegin(GL_TRIANGLES);
            glColor3f(1, 0, 0);
            glVertex2f(-1 + offset, -1 + offset);
            
            glColor3f(0, 1, 0);
            glVertex2f(0 + offset, -1 + offset);

            glColor3f(0, 0, 1);
            glVertex2f(-0.5 + offset, 0 + offset);
        glEnd();
        glutSwapBuffers();
        usleep(250 * 1000);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        offset += 0.01;
    }
}

void keyboard(unsigned char c, int x, int y)
{
    if(c == 27)
    {
        exit(0);
    }
}
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_RIGHT_BUTTON)
    {
        exit(0);
    }
}
