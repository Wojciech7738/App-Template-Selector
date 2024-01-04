#ifndef ERRORMACROS_H
#define ERRORMACROS_H

#define ERR_DIR_NOT_EXISTS(dir) "Directory " + dir + " does not exists. Make sure the \"Template\" directory is in the same location as the application."
#define ERR_FILE_NOT_EXIST(file) "File " + file + " does not exists."
#define ERR_DIR_EMPTY(dir) "Directory " + dir + " is empty."
#define ERR_DIR_CONTAINS_FILES(dir) "Directory " + dir + " contains files." + MESSAGE_PUT_FOLDERS

#define MESSAGE_PUT_FOLDERS " Put some folders representing each programming language."

#endif // ERRORMACROS_H
