#include "main.h"
extern "C" __declspec(dllexport) int open_another_window(char* caption)
{
    std::string newest, winfile;
    struct tm* time_newest = (struct tm*)malloc(sizeof(struct tm));
    *time_newest=(struct tm){0};
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);
    std::stringstream ss;
    ss<<"C:\\Users\\"<<username<<"\\AppData\\Local\\GameMakerStudio2\\GMS2TEMP\\";

    DIR *dir;
    DIR *subdir;
    struct dirent *ent;
    if ((dir = opendir (ss.str().c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if(!( (ent->d_name[0]=='.' && strlen(ent->d_name)==1)  || (ent->d_name[0]=='.' && ent->d_name[1]=='.' && strlen(ent->d_name)==2))){

//                printf("%s : ", ent->d_name);
                std::stringstream dire;
                dire<<ss.str()<<ent->d_name;
                if((subdir = opendir (dire.str().c_str())) != NULL){
                    struct stat t_stat;
                    stat(dire.str().c_str(), &t_stat);
                    struct tm * timeinfo = localtime(&t_stat.st_ctime);
                    int yr, day, h, min, sec;
                    yr=timeinfo->tm_year - time_newest->tm_year;
                    day=timeinfo->tm_yday- time_newest->tm_yday;
                    h=timeinfo->tm_hour  - time_newest->tm_hour;
                    min=timeinfo->tm_min - time_newest->tm_min;
                    sec=timeinfo->tm_sec - time_newest->tm_sec;
                    if(yr==0){
                        if(day==0){
                            if(h==0){
                                if(min==0 && sec>0){
                                    newest = dire.str();
                                    *time_newest=*timeinfo;
                                }
                                else if(min>0){
                                    newest = dire.str();
                                    *time_newest=*timeinfo;
                                }
                            }
                            else if(h>0){
                                newest = dire.str();
                                *time_newest=*timeinfo;
                            }
                        }
                        else if(day>0){
                            newest = dire.str();
                            *time_newest=*timeinfo;
                        }
                    }
                    else if(yr>0){
                        newest = dire.str();
                        *time_newest=*timeinfo;
                    }
                }
            }
        }
        closedir (dir);
    }
    else {
        perror ("Couldn't Open Directory GMS2TEMP");
        return EXIT_FAILURE;
    }
    if ((dir = opendir (newest.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::stringstream dire;
            dire<<newest << "\\" <<ent->d_name;
            if((subdir = opendir (dire.str().c_str())) == NULL){
                std::string file = dire.str();
                if(file.find(std::string(".win")) != std::string::npos){
                    winfile=file;
                    break;
                }
            }
        }
    }
    else {
        perror ("Couldn't Open Directory GMSTEMP2/PROJECT");
        return EXIT_FAILURE;
    }

    if ((dir = opendir ("C:\\ProgramData\\GameMakerStudio2\\Cache\\runtimes\\")) != NULL) {
        *time_newest=(struct tm){0};
        while ((ent = readdir (dir)) != NULL) {
            std::stringstream dire;
            dire<<"C:\\ProgramData\\GameMakerStudio2\\Cache\\runtimes\\" << ent->d_name;
            if(!( (ent->d_name[0]=='.' && strlen(ent->d_name)==1)  || (ent->d_name[0]=='.' && ent->d_name[1]=='.' && strlen(ent->d_name)==2))){
                struct stat t_stat;
                stat(dire.str().c_str(), &t_stat);
                struct tm * timeinfo = localtime(&t_stat.st_ctime);
                int yr, day, h, min, sec;
                yr=timeinfo->tm_year - time_newest->tm_year;
                day=timeinfo->tm_yday- time_newest->tm_yday;
                h=timeinfo->tm_hour  - time_newest->tm_hour;
                min=timeinfo->tm_min - time_newest->tm_min;
                sec=timeinfo->tm_sec - time_newest->tm_sec;
                if(yr==0){
                    if(day==0){
                        if(h==0){
                            if(min==0 && sec>0){
                                newest = dire.str();
                                *time_newest=*timeinfo;
                            }
                            else if(min>0){
                                newest = dire.str();
                                *time_newest=*timeinfo;
                            }
                        }
                        else if(h>0){
                            newest = dire.str();
                            *time_newest=*timeinfo;
                        }
                    }
                    else if(day>0){
                        newest = dire.str();
                        *time_newest=*timeinfo;
                    }
                }
                else if(yr>0){
                    newest = dire.str();
                    *time_newest=*timeinfo;
                }
            }
        }
    }
    else {
        perror ("Couldn't Open Directory RUNTIME");
        return EXIT_FAILURE;
    }
    ss.str("");
    std::stringstream runner;
    runner<<newest<<"\\windows\\Runner.exe";
    ss<<"-game "<<winfile << " " << caption;
//    printf("%s", ss.str().c_str());
//    system(ss.str().c_str());
    ShellExecute(NULL, "open", runner.str().c_str(),ss.str().c_str(),NULL,SW_SHOWDEFAULT);
    return 0;
}
