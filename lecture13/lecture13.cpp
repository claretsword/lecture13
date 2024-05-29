#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


// 전역 변수로 playerY 선언
float playerY = 0.0f; // 플레이어의 y축 위치 초기값

// 에러 콜백 함수
void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        playerY += 0.2f;
    }
}


int render()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(10.0f, -0.5f);
    glVertex2f(-10.0f, -0.5f);
    glVertex2f(10.0f, -10.0f);
    glVertex2f(-10.0f, -10.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.5f+ playerY);
    glVertex2f(-0.1f, -0.4f+ playerY);
    glVertex2f(0.1f, -0.4f+ playerY);
    glVertex2f(0.1f, -0.5f+ playerY);
    glEnd();

    return 0;
}



int main(void)
{
    // GLFW 초기화
    if (!glfwInit())
        return -1;

    // 윈도우 생성
    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 현재 윈도우로 설정
    glfwMakeContextCurrent(window);

    // GLFW 콜백 함수 설정
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    // 렌더링 루프
    while (!glfwWindowShouldClose(window))
    {
        // 이벤트 처리
        glfwPollEvents();
        
        // 화면 지우기
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //랜더링 함수 호출
        render();
       

        // 화면 전환
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}