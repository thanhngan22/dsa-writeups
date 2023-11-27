#include <bits/stdc++.h>
#include <dirent.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int main()
{
    // get currunt path
    LPSTR buffer = new char[MAX_PATH];

#ifdef _WIN32
    GetCurrentDirectory(MAX_PATH, buffer);
#else
    getcwd(buffer, MAX_PATH);
#endif

    // cout << "Current directory: " << buffer << endl;

    // declare map to store name folder and list name files
    map<string, vector<string>> listFiles;

    // folder need to ignore
    vector<string> ignoreFolder = {".", "..", ".git", "docs", "node_modules"};

    // get dir name in this path
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(buffer)) != NULL)
    {
        string fileName;
        while ((ent = readdir(dir)) != NULL)
        {
            int type = ent->d_type;
            switch (type)
            {
            case DT_DIR:
                if (find(ignoreFolder.begin(), ignoreFolder.end(), ent->d_name) != ignoreFolder.end()) {
                    break;
                }
                listFiles[ent->d_name] = vector<string>();
                break;
            default:
                break;
            }
        }
        closedir(dir);
    }
    else
    {
        perror("");
        return EXIT_FAILURE;
    }

    // open dir and get folder name
    for (auto &folder : listFiles)
    {
        if ((dir = opendir(folder.first.c_str())) != NULL)
        {
            string fileName;
            // cout << "Title: " << folder.first << endl;

            while ((ent = readdir(dir)) != NULL)
            {
                int type = ent->d_type;
                switch (type)
                {
                case DT_DIR:
                    folder.second.push_back(ent->d_name);
                    break;
                default:
                    break;
                }
            }
            closedir(dir);
        }
        else
        {
            perror("");
            // perror("Cannot open directory\n");
            return EXIT_FAILURE;
        }
    }

    // open README.md
    ofstream fout("README.md", ios::app);
    if (!fout.is_open())
    {
        cout << "Cannot open file README.md" << endl;
        return EXIT_FAILURE;
    }

    // print list files with format
    for (auto &folder : listFiles)
    {
        string title = folder.first;
        if (title == "Others")
        {
            continue;
        }
        for (int i = 0; i < title.length(); i++)
        {
            if (title[i] == '.')
            {
                title[i] = ' ';
            }
        }
        fout << "#### " << title << endl;

        // get just name folder, not path
        string folderName = folder.first;
        int pos = title.find_last_of("/");
        if (pos != string::npos)
        {
            folderName = title.substr(pos + 1);
        }
        

        for (auto &file : folder.second)
        {
            if (file  == "." || file == "..") {
                // fout << endl;
                continue;
            }
            string name = file;
            for (int i = 0; i < name.length(); i++)
            {
                if (name[i] == '.')
                {
                    name[i] = ' ';
                }
            }
            fout << "- [" << name << "](./" << folderName << "/" << file << ")" << endl;
        }
        fout << endl << endl;
        
    }

    // write for others
    fout << "#### Others" << endl;
    for (auto &file : listFiles["Others"])
    {
        if (file  == "." || file == "..") {
            // fout << endl;
            continue;
        }
        string name = file;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] == '.')
            {
                name[i] = ' ';
            }
        }
        fout << "- [" << name << "](./Others/" << file << ")" << endl;
    }

    fout.close();

    return 225;
}