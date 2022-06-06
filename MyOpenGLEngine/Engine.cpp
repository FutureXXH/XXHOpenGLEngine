#include "Engine.h"


MyEngine* __MyEngine = new MyEngine();


bool MyEngine::EngineInit()
{

    myOpenGL->OpenGLInit(600, 600);







    return false;
}

void MyEngine::EngineRun()
{
    myOpenGL->OpenGLRun();

    int OpenGLState = 1;
    while (true)
    {
        MyWorldManager->WorldUpdate();
        OpenGLState = myOpenGL->OpenGLUpdate(MyWorldManager);


        if (OpenGLState == -1)break;

    }
    if (OpenGLState == -1)
    {
        cout << "OpenGL �ر�" << endl;
    }
}

bool MyEngine::AddObject(Object* obj)
{
    auto rp = obj->GetComponent<Rendering>();
    if (rp != nullptr)
    {
        myOpenGL->AddRenderingObj(obj);
    }
    MyWorldManager->RegObject(obj);

    return true;
}

Shader* MyEngine::CreateShader(string ShaderName, const char* vertexPath, const char* fragmentPath)
{
   
    return  myOpenGL->RegShader(ShaderName,vertexPath,fragmentPath);
}

Shader* MyEngine::GetShader(string ShaderName)
{
    return myOpenGL->GetShader(ShaderName);
}



GLuint MyEngine::RegTexture(string TextureName, const char* texImagePath)
{
    return myOpenGL->RegTexture(TextureName,texImagePath);
}

bool MyEngine::RegModel(string ModelName, string ModelPath)
{
    return myOpenGL->RegModel(ModelName,ModelPath);
}


