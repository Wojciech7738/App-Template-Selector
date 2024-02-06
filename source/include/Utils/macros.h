#ifndef MACROS_H
#define MACROS_H

#define CONFIG_FILE_NAME "programming_languages"
#define PURE_CONFIG_FILE_NAME "programming_languages_only"

#ifdef __unix__

#define PATH_SEP "/"
#define CONFIG_PATH (std::string(std::getenv("HOME")) + "/.config/AppTemplateSelector/" CONFIG_FILE_NAME)

#else
// Windows file system

#define PATH_SEP "\\"
#define CONFIG_PATH "%USERPROFILE%\\AppData\\Local\\AppTemplateSelector\\"##CONFIG_FILE_NAME

#endif

#endif // MACROS_H
