#include <iostream>
#include <GLFW/glfw3.h>



#include "../dependencies/IMGUI/imgui/imgui.h"
#include "../dependencies/IMGUI/imgui/imgui_impl_opengl3.h"
#include "../dependencies/IMGUI/imgui/imgui_impl_glfw.h"

int main(void)
{
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "GAME ENGINE", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    IMGUI_CHECKVERSION();    
    ImGui::CreateContext();    
    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window, true);    
    ImGui_ImplOpenGL3_Init("#version 330");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Faire la frame ici

        if (ImGui::Begin("Test window"))
        {
            if (ImGui::Button("Hello")) {
               // ImGui::Button("e");
            }
            
        }
        ImGui::End();

        // End the ImGui frame
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    

    glfwTerminate();
    return 0;
}