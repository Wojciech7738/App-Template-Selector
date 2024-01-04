#include "../mainwindow.h"

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
    WindowOrganiser w;
    w.run(argc, argv);
}
#endif
