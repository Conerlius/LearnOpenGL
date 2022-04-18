#pragma once
#include <string>
#include <fstream>

using namespace std;
/**
 * \brief 应用配置
 */
class Configure
{
public:
    static void LoadConfigure()
    {
        string myText;
        ifstream infile;
        infile.open("config.txt");
        auto config = Instance();
        while (getline(infile, myText))
        {
            string content = trim(myText);
            if (content.find_first_of("Course:") != -1)
            {
                config.DefaultClassIndex = stoi(content.substr(7));
            }
            else if(content.find_first_of("EnableOpenGLCore:") != -1)
            {
                config.EnableOpenGLCore = stoi(content.substr(17))?true:false;
            }
            else
            {
                
            }
        }
        infile.close();
    }

    /**
     * \brief 获取单例
     * \return 单例
     */
    static Configure Instance()
    {
        static Configure config;
        return config;
    }

    static std::string& trim(std::string& s)
    {
        if (s.empty())
        {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }

public:
    int DefaultClassIndex;
    bool EnableOpenGLCore;
};
