#include "gears.hpp"

#include <iostream>
#include <cmath>

void gears::gear(GLfloat inner_radius, GLfloat outer_radius, GLfloat width,
                       GLint teeth, GLfloat tooth_depth) {
    //How to create the gear
    GLint i;
    GLfloat r0, r1, r2;
    GLfloat angle, da;
    GLfloat u, v, len;

    r0 = inner_radius;
    r1 = outer_radius - tooth_depth / 2.f;
    r2 = outer_radius + tooth_depth / 2.f;

    da = 2.f * (float) M_PI / teeth / 4.f;

    glShadeModel(GL_FLAT);

    glNormal3f(0.f, 0.f, 1.f);

    /* draw front face */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), width * 0.5f);
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), width * 0.5f);
        if (i < teeth) {
            glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), width * 0.5f);
            glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), width * 0.5f);
        }
    }
    glEnd();

    /* draw front sides of teeth */
    glBegin(GL_QUADS);
    da = 2.f * (float) M_PI / teeth / 4.f;
    for (i = 0; i < teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + da), r2 * (float) sin(angle + da), width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + 2 * da), r2 * (float) sin(angle + 2 * da), width * 0.5f);
        glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), width * 0.5f);
    }
    glEnd();
    
    glNormal3f(0.0, 0.0, -1.0);

    /* draw back face */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), -width * 0.5f);
        glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), -width * 0.5f);
        if (i < teeth) {
            glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), -width * 0.5f);
            glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), -width * 0.5f);
        }
    }
    glEnd();

    /* draw back sides of teeth */
    glBegin(GL_QUADS);
    da = 2.f * (float) M_PI / teeth / 4.f;
    for (i = 0; i < teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        
        glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), -width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + 2 * da), r2 * (float) sin(angle + 2 * da), -width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + da), r2 * (float) sin(angle + da), -width * 0.5f);
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), -width * 0.5f);
    }
    glEnd();

    /* draw outward faces of teeth */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), width * 0.5f);
        glVertex3f(r1 * (float) cos(angle), r1 * (float) sin(angle), -width * 0.5f);
        u = r2 * (float) cos(angle + da) - r1 * (float) cos(angle);
        v = r2 * (float) sin(angle + da) - r1 * (float) sin(angle);
        len = (float) sqrt(u * u + v * v);
        u /= len;
        v /= len;
        glNormal3f(v, -u, 0.0);
        glVertex3f(r2 * (float) cos(angle + da), r2 * (float) sin(angle + da), width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + da), r2 * (float) sin(angle + da), -width * 0.5f);
        glNormal3f((float) cos(angle), (float) sin(angle), 0.f);
        glVertex3f(r2 * (float) cos(angle + 2 * da), r2 * (float) sin(angle + 2 * da), width * 0.5f);
        glVertex3f(r2 * (float) cos(angle + 2 * da), r2 * (float) sin(angle + 2 * da), -width * 0.5f);
        u = r1 * (float) cos(angle + 3 * da) - r2 * (float) cos(angle + 2 * da);
        v = r1 * (float) sin(angle + 3 * da) - r2 * (float) sin(angle + 2 * da);
        glNormal3f(v, -u, 0.f);
        glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), width * 0.5f);
        glVertex3f(r1 * (float) cos(angle + 3 * da), r1 * (float) sin(angle + 3 * da), -width * 0.5f);
        glNormal3f((float) cos(angle), (float) sin(angle), 0.f);
    }
    
    glVertex3f(r1 * (float) cos(0), r1 * (float) sin(0), width * 0.5f);
    glVertex3f(r1 * (float) cos(0), r1 * (float) sin(0), -width * 0.5f);
    
    glEnd();
    
    glShadeModel(GL_SMOOTH);
    
    /* draw inside radius cylinder */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        angle = i * 2.f * (float) M_PI / teeth;
        glNormal3f(-(float) cos(angle), -(float) sin(angle), 0.f);
        glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), -width * 0.5f);
        glVertex3f(r0 * (float) cos(angle), r0 * (float) sin(angle), width * 0.5f);
    }
    glEnd();
}

/* OpenGL draw function & timing */
void gears::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
    
    glRotatef(view_rotx, 1.0, 0.0, 0.0);
    glRotatef(view_roty, 0.0, 1.0, 0.0);
    glRotatef(view_rotz, 0.0, 0.0, 1.0);
    
    glPushMatrix();
    glTranslatef(-3.0, -2.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glCallList(gear1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3.1f, -2.f, 0.f);
    glRotatef(-2.f * angle - 9.f, 0.f, 0.f, 1.f);
    glCallList(gear2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3.1f, 4.2f, 0.f);
    glRotatef(-2.f * angle - 25.f, 0.f, 0.f, 1.f);
    glCallList(gear3);
    glPopMatrix();
    
    glPopMatrix();
}

void gears::animate(void) {
    angle = 100.f * (float) glfwGetTime();
}

void gears::onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action != GLFW_PRESS) {
        return;
    }

    switch(key) {
    case GLFW_KEY_Z:
        if(mods & GLFW_MOD_SHIFT) {
            view_rotz -= 5.0;
        } else {
            view_rotz += 5.0;
        }
        break;
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GL_TRUE);
        break;
    case GLFW_KEY_UP:
        view_rotx += 5.0;
        break;
    case GLFW_KEY_DOWN:
        view_rotx -= 5.0;
        break;
    case GLFW_KEY_LEFT:
        view_roty += 5.0;
        break;
    case GLFW_KEY_RIGHT:
        view_roty -= 5.0;
        break;
    default:
        return;
    }
}

void gears::onResize(GLFWwindow* window, int width, int height) {
    GLfloat h = (GLfloat) height / (GLfloat) width;
    GLfloat xmax, znear, zfar;

    znear = 5.0f;
    zfar  = 30.0f;
    xmax  = znear * 0.5f;

    glViewport( 0, 0, (GLint) width, (GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum( -xmax, xmax, -xmax*h, xmax*h, znear, zfar );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0, 0.0, -20.0 );
}

void gears::init(int argc, char* argv[]) {
    static GLfloat pos[4] = {5.f, 5.f, 10.f, 0.f};
    static GLfloat red[4] = {0.8f, 0.1f, 0.f, 1.f};
    static GLfloat green[4] = {0.f, 0.8f, 0.2f, 1.f};
    static GLfloat blue[4] = {0.2f, 0.2f, 1.f, 1.f};
    GLint i;
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    /* make the gears */
    gear1 = glGenLists(1);
    glNewList(gear1, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    gear(1.f, 4.f, 1.f, 20, 0.7f);
    glEndList();
    
    gear2 = glGenLists(1);
    glNewList(gear2, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
    gear(0.5f, 2.f, 2.f, 10, 0.7f);
    glEndList();
    
    gear3 = glGenLists(1);
    glNewList(gear3, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    gear(1.3f, 2.f, 0.5f, 10, 0.7f);
    glEndList();
    
    glEnable(GL_NORMALIZE);
    
    for ( i=1; i<argc; i++ ) {
        if (strcmp(argv[i], "-info")==0) {
            printf("GL_RENDERER   = %s\n", (char *) glGetString(GL_RENDERER));
            printf("GL_VERSION    = %s\n", (char *) glGetString(GL_VERSION));
            printf("GL_VENDOR     = %s\n", (char *) glGetString(GL_VENDOR));
            printf("GL_EXTENSIONS = %s\n", (char *) glGetString(GL_EXTENSIONS));
        }
        else if ( strcmp(argv[i], "-exit")==0) {
            autoexit = 30;
            printf("Auto Exit after %i seconds.\n", autoexit );
        }
    }
}

void gears::glloop() {
    // Draw gears
    draw();

    // Update animation
    animate();

    // Buffer swap happens in base class!
}
