#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


// 에러 콜백 함수
void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
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
   

    // 렌더링 루프
    while (!glfwWindowShouldClose(window))
    {
        // 이벤트 처리
        glfwPollEvents();

        // 화면 지우기
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 화면 전환
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}