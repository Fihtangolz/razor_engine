#include <cstdio>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar *vertexShaderSource = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "}\0";
const GLchar *fragmentShaderSource = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\n\0";

int main()
{
    // OpenGL init
    if (glfwInit() != GL_TRUE)
    {
        printf("OpenGL initialization failed\n");
        return -1;
    }

    // Init OpenGL requiments
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Razor Editor", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set OpenGL window callback function
    glfwSetKeyCallback(window, key_callback);

    // Init GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    // Init Viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    GLint success;
    GLchar error[512];

    /** NOTE: VertexShader
     * Вершинный шейдер принимает на вход данные из буфера GPU обрабатывает их если нужно
     * и отдает данные на выход для того что бы их подхватил фрагментный или другой вершинный шейдер
     */
    // Create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Bind vertex shader source to shader object
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compile shader
    glCompileShader(vertexShader);
    // Get compilation failures is exists
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, error);
        printf("error vertexShader compilation: %s", error);
        return -1;
    }

    /** NOTE: FragmentShader
     * Фрагментный шейдер занимается вычисление цветов пикселей
     */
    // Create fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Bind fragment shader source to shader object
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // Compile shader
    glCompileShader(fragmentShader);
    // Get compilation failures is exists
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, error);
        printf("error fragmentShader compilation: %s", error);
        return -1;
    }

    /** NOTE: Shader Program
     * Шейдерная программа - объект который объединяет шейдеры в одну программу
     * для дальнейшей отрисовки
     */
    // Create shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, error);
        printf("error shaderProgram compilation: %s", error);
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        0.5f, 0.5f, 0.0f,   // Верхний правый угол
        0.5f, -0.5f, 0.0f,  // Нижний правый угол
        -0.5f, -0.5f, 0.0f, // Нижний левый угол
        -0.5f, 0.5f, 0.0f   // Верхний левый угол
    };
    GLuint indexes[] = {
        0, 1, 3,
        1, 2, 3
    };

    // Define VertexBufferObject - it's objects that links with GPU buffer data
    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    // Create VertexBufferObject
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // Bind VertexBufferObject to GPU Buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Copy array data with vertices to GPU vertex buffer wich link to VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

    // Combine the vertix attributes
    // 1. number of location in shader
    // 2. size of shader attribute (vec3)
    // 3. type of shader attribute (GLfloat)
    // 4. attribute normalization off (GL_FALSE)
    // 5. step - it is length between datasets
    // 6. data begin point in shader (0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
}
