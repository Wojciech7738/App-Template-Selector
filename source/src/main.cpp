#include "../mainwindow.h"
#include "Utils/globals.h"

#if RUN_TESTS
#include "tst_directoryexiststest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
#include "Controllers/WindowOrganiser.h"

int main(int argc, char *argv[])
{
    Argc = argc;
    Argv = argv;
    WindowOrganiser w;
    if (w.scan_for_templates() == 0)
        w.show_Gui();
    // TODO: implement cases when files are empty
}
#endif
